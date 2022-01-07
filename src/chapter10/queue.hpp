namespace YYDS
{
    template <typename T>
    class queue
    {
    private:
        int initSize;
        int front = -1, tail = -1;
        int *q;

    public:
        queue(int initSize = 10) : initSize(initSize)
        {
            q = new int[initSize];
        }

        void enqueue(T key)
        {
            if (size() == 0)
                front = (front + 1) % initSize;
            tail = (tail + 1) % initSize;
            if (front == tail)
            {
                //扩容
            }
            q[tail] = key;
        }

        int size()
        {
            if (front == tail && tail == -1)
                return 0;
            int len = tail - front + 1;
            return len >= 0 ? len : -len;
        }

        void deque()
        {
            front = (front + 1) % initSize;
        }

        T first()
        {
            return q[front];
        }

        T back()
        {
            return q[tail];
        }

        ~queue()
        {
            delete[] q;
        }
    };
} // namespace YYD
