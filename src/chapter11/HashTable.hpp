#include <string>

template <typename KeyType, typename ValueType>
class HashTable
{
private:
    struct HashObj
    {
        KeyType key;
        ValueType value;
        HashObj *next;
    };
    int size;
    HashObj **slots;

    int hash(const int &x)
    {
        return x % size;
    }

    int hash(const std::string &s)
    {
        int len = s.size();
        int hashCode = 0;
        const int seed = 131;
        for (int i = 0; i < len; i++)
        {
            hashCode += (s[i] * seed) + s[i];
        }
        return hashCode % size;
    }

public:
    HashTable(const int slotSize = 13)
    {
        size = slotSize;
        slots = new HashObj *[slotSize];
        for (int i = 0; i < size; i++)
        {
            slots[i] = new HashObj();
        }
    }

    void insert(KeyType key, ValueType element)
    {
        int hashCode = hash(key);
        auto slot = slots[hashCode];
        auto s = new HashObj();
        s->key = key;
        s->value = element;
        auto tmp = slot->next;
        slot->next = s;
        s->next = tmp;
    }

    ValueType &operator[](KeyType key)
    {
        int index = hash(key);
        auto &slot = slots[index];
        auto &result = slot->next;
        while (result && result->key != key)
            result = result->next;
        int defaultValue = 0;
        return result ? result->value : defaultValue;
    }

    void remove(KeyType key)
    {
        int index = hash(key);
        auto slot = slots[index];
        auto result = slot;
        while (result && result->next && result->next->key != key)
        {
            result = result->next;
        }
        auto next = result->next ? result->next->next : nullptr;
        delete result->next;
        result->next = next;
    }

    ~HashTable()
    {
        delete[] slots;
    }
};
