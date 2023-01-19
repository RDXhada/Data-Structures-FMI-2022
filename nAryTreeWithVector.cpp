#include <iostream>
#include <vector>

template <typename T>
struct Node
{
    T value;
    std::vector<Node<T>*> children;
};


template <typename T>
void deleteNode(Node<T>* &root)
{
    if (root == nullptr)
    {
        return;
    }
    
    for (Node<T> *element :  root->children)
    {
        deleteNode(element);
    }
    
    delete root;
    root = nullptr;
}

template <typename T>
void addElement(Node<T>* root,const T& value,const T& element)
{
    if (root == nullptr)
    {
        return;
    }
    
    if(root->value == value)
    {
        root->children.push_back(new Node<T>{element, std::vector<Node<T>*> ()});
    }
    
    for (Node<T>* el :  root->children)
    {
        addElement(el, value, element);
    }
}

template <typename T>
void printTree(Node<T> *root)
{
    if (root== nullptr)
    {
        return;
    }
    
    std::cout << root->value << "(";
    for (auto el : root->children)
    {
        printTree(el);
    }
    std::cout << ")";
}

template <typename T>
void removeElement(Node<T>* root, const T& toRemove) {
    if (root == nullptr)
    {
        return;
    }
    
    for (int i = 0; i < root->children.size(); ++i)
    {
        if (root->children[i]->value == toRemove)
        {
            
            deleteNode(root->children[i]);
            for (int j = i; j < root->children.size() - 1; ++j)
            {
                root->children[j] = root->children[j + 1];
            }
            root->children.pop_back();
            
            return;
        }
        removeElement(root->children[i], toRemove);
    }
}

template <typename T>
std::vector<T> preorder(Node<T>* root)
{
    std::vector<T> vect;
    if (root == nullptr) return {};
    vect.push_back(root->value);
    for (int i=0; i<root->children.size(); i++)
    {
        std::vector<T>v1 = preorder(root->children[i]);
        vect.insert(vect.end(), v1.begin(), v1.end());
    }
    return vect;
}

template <typename T>
int maxDepth(Node<T>* root) {
    if(root==nullptr)
        return 0;
    int max_depth = 1;
    for(int i=0;i<root->children.size();i++){
        max_depth = max(max_depth, 1 + maxDepth(root->children[i]));
    }
    return max_depth;
}



int main()
{
    Node<int> *root = new Node<int>{1};
    addElement(root, 1, 2);
    addElement(root, 1, 3);
    addElement(root, 3, 4);
    addElement(root, 1, 7);
    printTree(root);
    std::cout << '\n';
    std::cout << "Testing vector output: \n";
    std::vector<int> vect = preorder(root);
    for (int i = 0; i < vect.size(); i++) {
        std::cout << vect[i] << " ";
    }
    std::cout << "Hello, World!\n";
    return 0;
}
