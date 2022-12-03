#ifndef BinaryTree_h
#define BinaryTree_h


template <typename T>
class BinarySearchTree
{
private:
    struct Node
    {
        T value;
        Node *left;
        Node *right;
        Node(T value) : value(value), left(nullptr), right(nullptr) {}
    };
    
    Node *root;
    void insert(Node *temp, T element);
    Node* deleteNode(Node *temp, T element);
    Node *minimum(Node *temp);
    void copy(Node *temp);
    void clear(Node *temp);
    //print
    void traverse(Node *temp);
    
    //func
    size_t getHeight(Node *temp);
    size_t getSize(Node *temp);
    size_t countEvens(Node *temp);
    size_t countLeaves(Node *temp);
    int maxLeaf(Node *temp);
    int minLeaf(Node *temp);
    int sumOfElements(Node *temp);
    int searchCount(bool (*pred)(const T&), Node *temp);
    void prettyPrint(Node *temp, int indent);
    void serializeSchemeFormat(Node *temp);
    void serializeHaskellFormat(Node *temp);
    void listLeaves(Node *temp);
    Node *search(Node *temp, int key);
    std::string findTrace(Node *temp,const T& x);
    bool checkBalanced(Node *temp);
public:
    //newNode
    Node *newNode(T elem);
    //constructor/destuctor
    BinarySearchTree();
    ~BinarySearchTree();
    
    //basic actions
    void insert(T elem){insert(root, elem);}
    void deleteNode(T elem){deleteNode(root, elem);}
    void copy(){return copy(root);}
    void clear(){return clear(root);}
    void traverse(){traverse(root);}
    void prettyPrint(int indent) {return prettyPrint(root, indent);}
    void listLeaves() {return listLeaves(root);}
    bool checkBlanced() {return checkBalanced(root);}
    
    //func
    size_t getHeight() {return getHeight(root);}
    size_t getSize() {return getSize(root);}
    size_t countEvens() {return countEvens(root);}
    size_t countLeaves() {return countLeaves(root);}
    int maxLeaf() {return maxLeaf(root);}
    int minLeaf() {return minLeaf(root);}
    int sumOfElements() {return sumOfElements(root);}
    int searchCount(bool (*pred)(const T&)) {return searchCount(pred, root);}
    bool greater3(T x);
    void serialiseScheme() {return serializeSchemeFormat(root);}
    void serialiseHaskell() {return serializeHaskellFormat(root);}
    Node *search(int key) {return search(root, key);}
    std::string findTrace(const T& X) {return findTrace(root, X);}
    
};


#include "BinaryTree.inl"
#endif /* BinaryTree_h */
