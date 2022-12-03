#include "BinaryTree.h"
#include <queue>
#include <iomanip>

//constructor
template <typename T>
inline BinarySearchTree<T>::BinarySearchTree() { root = nullptr; }


//destructor
template <typename T>
inline BinarySearchTree<T>::~BinarySearchTree()
{
    clear();
}


//delete tree
template <typename T>
inline void BinarySearchTree<T>::clear(Node *temp)
{
    if (temp == nullptr)
    {
        return;
    }
    
    clear (temp->left);
    clear (temp->right);
    delete temp;
}


//copy constructor
template <typename T>
inline void BinarySearchTree<T>::copy(Node *temp)
{
    if (temp == nullptr) {
        return;
    }
    Node *root_copy = new Node(root->value);
    root_copy->left = cloneBinaryTree(root->left);
    root_copy->right = cloneBinaryTree(root->right);
}


//create new node
template <typename T>
inline typename BinarySearchTree<T>::Node *BinarySearchTree<T>::newNode(T elem)
{
    Node *temp = new Node(elem);
    temp->value = elem;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


//insert elements
template <typename T>
inline void BinarySearchTree<T>::insert(Node *temp, T element)
{
    if (temp == nullptr)
    {
        temp = new Node(element);
        root = temp;
    }
    if (element < temp->value)
    {
        if (!temp->left)
        {
            Node *treeTemp = new Node(element);
            temp->left = treeTemp;
        }
        else
            insert(temp->left, element);
    }
    //fixed it here where i used only else, instead of else if (which is the correct way) : problem is that it was checking for element >= temp->value if its only else
    else if(element > temp->value)
    {
        if (!temp->right)
        {
            Node *treeTemp = new Node(element);
            temp->right = treeTemp;
        }
        else
            insert(temp->right, element);
    }
}


//delete element
template <typename T>
inline typename BinarySearchTree<T>::Node *BinarySearchTree<T>::minimum(Node *temp)
{
    while (temp!= nullptr)
    {
        temp = temp->right;
    }
    return temp->right;
}

//delete elemement
template <typename T>
inline typename BinarySearchTree<T>::Node *BinarySearchTree<T>::deleteNode(Node *temp, T element)
{
    if (temp == nullptr)
    {
        return temp;
    }
    
    if (element < temp->value){
        temp->left = deleteNode(temp->left, element);
    }
    
    else if (element > temp->value){
        temp->right = deleteNode(temp->right, element);
    }
    else
    {
        if (temp->left == nullptr && temp->right == nullptr)
        {
            return nullptr;
        }
        else if (temp->left == nullptr)
        {
            Node *current = temp->right;
            delete temp;
            temp = nullptr;
            return current;
        }
        else if (temp->right == nullptr)
        {
            Node *current = temp->left;
            delete temp;
            temp = nullptr;
            return current;
        }
        
        Node *current = minimum(temp->right);
        
        temp->value = current->value;
        
        temp->right = deleteNode(temp->right, current->value);
    }
    return temp;
}


//print
template <typename T>
inline void BinarySearchTree<T>::traverse(Node *temp)
{
    if (temp == nullptr)
    {
        return;
    }
    std::cout << temp->value << ' ';
    traverse(temp->left);
    traverse(temp->right);
}


//max height
template <typename T>
inline size_t BinarySearchTree<T>::getHeight(Node *temp)
{
    if (temp == nullptr)
    {
        return 0;
    }
    size_t leftHeight = getHeight(temp->left);
    size_t rightHeight = getHeight(temp->right);
    if (leftHeight >= rightHeight)
    {
        return leftHeight+1;
    }
    else
    {
        return rightHeight+1;
    }
}


//get size of tree / number of elements
template <typename T>
inline size_t BinarySearchTree<T>::getSize(Node *temp)
{
    if (temp == NULL)
    {
        return 0;
    }
    size_t l = getSize(temp->left);
    size_t r = getSize(temp->right);
    
    return 1 + l + r;
}


//count even nodes of a tree
template <typename T>
inline size_t BinarySearchTree<T>::countEvens(Node *temp)
{
    size_t counter;
    if (temp == nullptr)
    {
        return 0;
    }
    counter = countEvens(temp->left) + countEvens(temp->right);
    if (temp->value % 2 == 0)
    {
        counter++;
    }
    return counter;
}

//max number of a leaf
template <typename T>
inline int BinarySearchTree<T>::maxLeaf(Node *temp)
{
    Node *current = temp;
    while (current->right != nullptr)
    {
        current = current->right;
    }
    return (current->value);
}

//min number of leaf
template <typename T>
inline int BinarySearchTree<T>::minLeaf(Node *temp)
{
    Node *current = temp;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return (current->value);
}

//sum of all elements in tree
template <typename T>
inline int  BinarySearchTree<T>::sumOfElements(Node *temp)
{
    int sum = 0;
    if (temp == nullptr)
    {
        return 0;
    }
    sum = temp->value + sumOfElements(temp->left) + sumOfElements(temp->right);
    return sum;
}


//searchCount by using predicate (somekind of condition)
//TODO ;((
template <typename T>
inline int BinarySearchTree<T>::searchCount(bool (*pred)(const T&), Node *temp)
{
    int result = 0;
    if (temp == nullptr)
    {
        return 0;
    }
    if (pred(temp->value))
    {
        result  = 1 +  searchCount(pred, temp->left) + searchCount(pred, temp->right);
    }
    return result;
}
//condition for searchCount
template <typename T>
bool greater3(T x)
{
    return x>=3;
}

//idk??? useless excercise
template <typename T>
inline void BinarySearchTree<T>::prettyPrint(Node *temp, int indent)
{
    if (temp != nullptr)
    {
        prettyPrint(temp->right, indent + 3);
        std::cout << std::setw(indent);
        std::cout << temp->value << std::endl;
        prettyPrint(temp->left, indent + 3);
    }
}

//scheme :((
template <typename T>
inline void BinarySearchTree<T>::serializeSchemeFormat(Node *temp)
{
    if (temp == nullptr)
    {
        return;
    }
    std::cout << " (";
    std::cout << temp->value;
    if (temp->left == nullptr && temp->right == nullptr)
    {
        std::cout << " () ()";
    }
    serializeSchemeFormat(temp->left);
    serializeSchemeFormat(temp->right);
    std::cout << ")";
}

//haskell :))
template <typename T>
inline void BinarySearchTree<T>::serializeHaskellFormat(Node *temp)
{
    if (temp == nullptr)
    {
        return;
    }
    std::cout << " Node ";
    std::cout << temp->value;
    if (temp->left == nullptr && temp->right == nullptr)
    {
        std::cout << " Empty Empty";
    }
    serializeHaskellFormat(temp->left);
    serializeHaskellFormat(temp->right);
}

//get the leaves as elements of a given tree
template <typename T>
inline void BinarySearchTree<T>::listLeaves(Node *temp)
{
    if (temp == nullptr)
    {
        return;
    }
    if (temp->left == nullptr && temp->right == nullptr) {
        std::cout << temp->value << " ";
    }
    listLeaves(temp->left);
    listLeaves(temp->right);
}

template <typename T>
inline typename BinarySearchTree<T>::Node * BinarySearchTree<T>::search(Node *temp, int key)
{
    if (temp == nullptr || temp->value == key)
    {
        return temp;
    }
    if (temp->value < key)
        return search(temp->right, key);
    else
        return search(temp->left, key);
}


template <typename T>
inline std::string BinarySearchTree<T>::findTrace(Node *temp,const T& x)
{
    if (temp == nullptr)
    {
        return "_";
    }
    if (temp->value == x)
    {
        return "";
    }
    std::string lhs = findTrace(temp->left, x);
    std::string rhs = findTrace(temp->right, x);
    if (lhs != "_")
    {
        return lhs.insert(0, 1,'L');
    }
    if (rhs != "_")
    {
        return rhs.insert(0, 1, 'R');
    }
    return "_";
}

template <typename T>
inline bool BinarySearchTree<T>::checkBalanced(Node *temp)
{
    if (temp == nullptr)
    {
        return true;
    }
    if (temp->left != nullptr && temp->right != nullptr)
    {
        if (getHeight(temp->left) == getHeight(temp->right) || getHeight(temp->left) + 1 == getHeight(temp->right) || getHeight(temp->left) == getHeight(temp->right) + 1)
        {
            return true;
        }
    }
    return false;
}
