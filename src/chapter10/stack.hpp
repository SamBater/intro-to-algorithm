namespace YYDS
{
    template <typename T>
    class stack
    {
    private:
        int initSize;
        int *stk;
        int tp = -1;

    public:
        stack(int initSize = 10) : initSize(initSize)
        {
            stk = new T[initSize];
        }

        void push(T key)
        {
            if (++tp >= initSize)
            {
                //扩容
            }
            stk[tp] = key;
        }

        void pop()
        {
            --tp;
        }

        T top()
        {
            return stk[tp];
        }

        ~stack()
        {
            delete[] stk;
        }
    };
}