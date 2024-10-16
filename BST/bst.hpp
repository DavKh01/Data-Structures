class BST {
    private:
        struct Node {
            int data;
            Node* right;
            Node* left;
            Node(int val) : data{val}, right{nullptr}, left{nullptr} {}
        };
        Node* root;
        Node* insert(Node* root, int val);
        Node* findMax(Node* root);
        Node* findMin(Node* root);
        Node* find(Node* root, int val);
        Node* remove(Node*  root, int val);
        void inorder(Node* root);
        Node* clear(Node* root);
    public:
        BST();
        ~BST();
        void insert(int x);
        void remove(int x);
        void display();
        void search(int x);
};