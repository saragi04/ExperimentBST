using namespace std;

template <typename T>

class BST {
    private:
        class Node{
            private:
                T data;
                Node* left;
                Node* right;

            public:
                Node() : data(), left(nullptr), right(nullptr) {}
                Node(T data1) : data(data1), left(nullptr), right(nullptr) {}

                Node* getLeft() { return left;}

                Node* getRight() {return right;}

                T getData() {return data;}

                void setRight(T data) { right = new Node(data); }

                void setLeft(T data) { left = new Node(data); }
        };

        void insert(T data, Node* n){

            if( empty() ){
                root = new Node(data);
            } else if( data > n->getData() ){
                if (n->getRight() == nullptr){
                    n->setRight(data);
                } else {
                    insert(data, n->getRight());
                }
            } else if( data < n->getData() ){
                if (n->getLeft() == nullptr){
                    n->setLeft(data);
                } else {
                    insert(data, n->getLeft());
                }
            } else {
                cout << "Elemento repetido, no es posible insertarlo." << endl;
            }

        }

        unsigned int get_size(Node* n){

            if ( n == nullptr ){ return 0; }

            unsigned int sizeLeft = get_size( n-> getLeft());
            unsigned int sizeRight = get_size( n-> getRight());

            return sizeLeft + sizeRight + 1; 
        }

        unsigned int get_height(Node* n){
            
            if( n == nullptr ){ return 0; }

            unsigned int heightLeft = get_height( n-> getLeft());
            unsigned int heightRight = get_height( n-> getRight());

            return max(heightLeft, heightRight) + 1;
        }

        unsigned int get_leafs(Node *n){

            if ( n == nullptr ){ return 0;}

            if (n->getLeft() == nullptr && n->getRight() == nullptr) {
                return 1;
            }
    
            return get_leafs(n->getLeft()) + get_leafs(n->getRight());
        }

        unsigned int get_right_nodes(Node* n) {
            if (root == nullptr || root->getRight() == nullptr) {
                return 0;
            }
            return get_size(root->getRight());
        }

        unsigned int get_left_nodes(Node* n) {
            if (root == nullptr || root->getLeft() == nullptr) {
                return 0;
            }
            return get_size(root->getLeft());
        }

        void preorder(Node* n){
            if( n == nullptr ){ return; }
            cout << n->getData() << " " ; 
            preorder(n->getLeft());
            preorder(n->getRight());
        }

        void postorder(Node* n){
            if( n == nullptr ){ return; }
            preorder(n->getLeft());
            preorder(n->getRight());
            cout << n->getData() << " " ; 
        }

        void inorder(Node* n){
            if( n == nullptr ){ return; }
            preorder(n->getLeft());
            cout << n->getData() << " " ; 
            preorder(n->getRight());
        }

        void print(Node* n, unsigned int cont){
            if( n == nullptr ){ 
                return; 
            } else {
                print(n->getRight(), cont+1);
                for(unsigned int i = 0; i<cont; i++){
                    cout<< "\t" ; 
                }
                cout << n->getData() << endl; 
                print(n->getLeft(), cont+1);
            }
        }

    public:
        Node* root; 
        BST() : root(nullptr) {} 

        bool empty() { return root == nullptr; }

        void insert(T data){
            insert(data, root);
        }

        unsigned int get_size(){
            return get_size(root);
        }

        unsigned int get_height(){
            return get_height(root);
        }

        unsigned int get_leafs(){
            return get_leafs(root);
        }

        unsigned int get_left_nodes(){
            return get_left_nodes(root);
        }

        unsigned int get_right_nodes(){
            return get_right_nodes(root);
        }

        void preorder(){
            preorder(root);
            cout << endl;
        }

        void postorder(){
            postorder(root);
            cout << endl;
        }

        void inorder(){
            inorder(root);
            cout << endl;
        }

        void print(){
            print(root, 0);
        }
            
};
