#include <iostream>
#include "BinaryTree.h"


int main()
{
    BinarySearchTree<int> BST;
    BST.insert(12);
    BST.insert(14);
    BST.insert(13);
    BST.insert(25);
    BST.deleteNode(25);
    BST.deleteNode(13);
    BST.deleteNode(14);
    BST.traverse();
    
}

