#include <iostream>
#include <vector>
#include <queue>
//WEEK 11 TREE EXERCISES | SOME LEETCODE FOR EXAM PREP | TODO BFS
template <typename T>
struct Node
{
    T value;
    Node *left;
    Node *right;
    Node(T value) : value(value), left(nullptr), right(nullptr){}
};

template <typename T>
void insertNode(Node<T> *root, T element)
{
    if (root == nullptr)
    {
        root = new Node(element);
    }
    std::queue<Node<T>*> que;
    que.push(root);
    while (!que.empty())
    {
        Node<T> *temp = que.front();
        que.pop();
        if (temp->left != nullptr)
        {
            que.push(temp->left);
        }
        else
        {
            temp->left = new Node(element);
        }
        if (temp->right != nullptr)
        {
            que.push(temp->right);
        }
        else
        {
            temp->right = new Node(element);
        }
    }
}
//get the leaves as elements of a given tree
template <typename T>
void listLeaves(Node<T> *temp)
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

//sum of all elems in tree
template <typename T>
int sumOfElements(Node<T> *temp)
{
    int sum = 0;
    if (temp == nullptr)
    {
        return 0;
    }
    sum = temp->value + sumOfElements(temp->left) + sumOfElements(temp->right);
    return sum;
}

//get max depth of tree
template <typename T>
size_t height(Node<T> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    size_t leftHeight = height(root->left);
    size_t rightHeight = height(root->right);
    if (leftHeight >= rightHeight)
    {
        return leftHeight+1;
    }
    else
    {
        return rightHeight+1;
    }
}

//dfs
template <typename T>
void inorderTraversal(Node<T> *root)
{
    if (root==nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->value << " ";
    inorderTraversal(root->right);
}

//dfs
template <typename T>
void preorderTraversal(Node<T> *root)
{
    if (root==nullptr)
    {
        return;
    }
    std::cout << root->value << " ";
    preorderTraversal(root->left);
    inorderTraversal(root->right);
}

//dfs
template <typename T>
void postorderTraversal(Node<T> *root)
{
    if (root==nullptr)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->value << " ";
}

//bfs
template <typename T>
void traverseBFS(Node<T> *root)
{
    std::queue<Node<T>*> que;
    que.push(root);
    while (!que.empty())
    {
        Node<T> *node = que.front();
        std::cout << node->value << " ";
        que.pop();
        if (node->left != NULL)
            que.push(node->left);
        if (node->right != NULL)
            que.push(node->right);
    }
}
//kinda like a filter
template <typename T>
int searchCount(bool (*pred)(const T&), Node<T> *temp)
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
//use this for searchCount
template <typename T>
bool greater3(T x)
{
    return x>=3;
}

//check if its a binary search tree
template <typename T>
bool checkBST(Node<T> *root, Node<T> *&previous)
{
    if (root)
    {
        if (!checkBST(root->left, previous))
        {
            return false;
        }
        if (previous != nullptr && root->value <= previous->value)
        {
            return false;
        }
        previous = root;
        return checkBST(root->right, previous);
    }
    return true;
}
//check if its a valid bst
template <typename T>
bool isValidBST(Node<T> *root) {
    Node<T> *prev = nullptr;
    return checkBST(root,prev);
}

//recover binary tree
std::vector<int> vect;
int i = 0;
template <typename T>
void toVector(Node<T> *root)
{
    if(root==nullptr)
    {
        return;
    }
    toVector(root->left);
    vect.push_back(root->value);
    toVector(root->right);
}
//inordert traversal but pushing elements into a vector
template <typename T>
void inOrderTraversal(Node<T> *root) {
    if(root == nullptr)
    {
        return;
    }
    inOrderTraversal(root->left);
    root->value = vect[i];
    i++;
    inOrderTraversal(root->right);
}
//RECOVER TREE
template <typename T>
void recoverTree(Node<T> *root)
{
    toVector(root);
    sort(vect.begin(),vect.end());
    inOrderTraversal(root);
}

//if 2 trees have the same structure and elements
template <typename T>
bool isSameTree(Node<T>* p, Node<T>* q)
{
    if(p == nullptr && q == nullptr)
    {
        return true;
    }
    if(p == nullptr || q == nullptr)
    {
        return false;
    }
    if(p->value == q->value)
    {
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    return false;
}

//is symmetric tree
template <typename T>
bool helper(Node<T> *p, Node<T> *q)
{
    if(p == nullptr && q == nullptr)
    {
        return true;
    }
    if(p == nullptr || q == nullptr)
    {
        return false;
    }
    if(p->value != q->value)
    {
        return false;
    }
    
    return helper(p->left,q->right) && helper(p->right, q->left);
}
template <typename T>
bool isSymmetric(Node<T>* root)
{
    if(root == nullptr)
    {
        return true;
    }
    return helper(root->left,root->right);
}

//MINIMUM DEPTH
template <typename T>
int minDepth(Node<T>* root) {
    if(root == nullptr)
    {
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }
    if(!root->left)
    {
        return 1 + minDepth(root->right);
    }
    else if(!root->right)
    {
        return 1 + minDepth(root->left);
    }
    else
    {
        return 1 + std::min(minDepth(root->left), minDepth(root->right));
    }
}

//has a sum of a given path equal to our target sum
template <typename T>
bool hasPathSum(Node<T>* root, int targetSum) {
    if(root==nullptr)
    {
        return false;
    }
    bool flag = false;
    int subSum = targetSum - root->value;
    if (subSum == 0 && root->left == NULL && root->right == NULL)
    {
        return true;
    }
    if(root->left != nullptr)
    {
        flag = flag || hasPathSum(root->left, subSum);
    }
    if(root->right != nullptr)
    {
        flag = flag || hasPathSum(root->right, subSum);
    }
    return flag;
}

template <typename T>
Node<T>* invertTree(Node<T>* root) {
    if(root == nullptr)
    {
        return 0;
    }
    std::swap(root->left,root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}


//check if element is a leaf
template <typename T>
bool isLeaf(Node<T> *root)
{
    if(root==nullptr)
    {
        return false;
    }
    if(root->left == nullptr && root->right == nullptr)
    {
        return true;
    }
    return false;
}
//sum of left only leaves (root->right->left counts as well for exmpl)
template <typename T>
int sumOfLeftLeaves(Node<T>* root) {
    int sum = 0;
    if(root == nullptr)
    {
        return 0;
    }
    if(isLeaf(root->left))
    {
        sum += root->left->value;
    }
    else
    {
        sum += sumOfLeftLeaves(root->left);
    }
    sum += sumOfLeftLeaves(root->right);
    return sum;
}
//diameter of BT
template <typename T>
int diameterOfBinaryTree(Node<T>* root) {
    if(root==nullptr)
    {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    int lDia = diameterOfBinaryTree(root->left);
    int rDia = diameterOfBinaryTree(root->right);
    return std::max((lheight + rheight),std::max(lDia,rDia));
}


template <typename T>
std::string findTrace(Node<T> *temp,const T& x)
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

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    Node<int> *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(3);
    traverseBFS(root);
    std::cout << findTrace(root, 3);
    return 0;
}
