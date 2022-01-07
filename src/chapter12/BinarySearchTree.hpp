namespace YYDS
{
    template <typename T>
    class BinarySearchTree
    {
    private:
        struct Node
        {
            T data;
            Node *left;
            Node *right;
        };

        T *root;

        bool _search(Node *root, T key)
        {
            if (root == nullptr)
                return false;
            if (root->data == key)
                return true;
            if (key < root->data)
                return _search(root->left, key);
            if (ke > root->data)
                return _search(root->right, key);
        }

    public:
        BinarySearchTree(int[] arr)
        {
        }

        bool search(T key)
        {
            search(root, key);
        }

        void clear(Node *root)
        {
            if (root == nullptr)
                return;
            clear(root->left);
            clear(root->right);
            delete root;
        }

        ~BinarySearchTree()
        {
            clear(root);
        }
    };
}