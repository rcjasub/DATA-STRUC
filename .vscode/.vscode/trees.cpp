// //Parent and Child Relationship

// Every child has exactly one parent (except the root, which has none).

// Siblings are nodes that share the same parent.

// A leaf is a node with no children.

// The root is the only node with no parent.

// Types of Binary Trees

// Complete Binary Tree:

// All levels are completely filled, except possibly the last level.

// Nodes on the last level are as far left as possible.

// Full Binary Tree:

// Every parent node has either 0 or exactly 2 children (never just one).

// Perfect Binary Tree:

// All internal nodes have exactly 2 children.

// All leaf nodes are at the same level.

// Binary Tree Traversal, less than go to left, greater than go to right (O(logn))- devide and conquer

// if a binary tree never devides, then it just becomes a linked list O(n)

// link list is o(1) to insert, binary tree is o(1) to insert, and remove

#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
public:
    Node *root;

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    bool insert(int value)
    {
        Node *newNode = new Node(value);

        if (root == nullptr)
        {
            root = newNode;
            return true;
        }

        Node *temp = root;

        while (true)
        {

            if (newNode->value == temp->value)
                return false;

            if (newNode->value < temp->value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }

                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return true;
                }

                temp = temp->right;
            }
        }
    }

    bool contains(int value)
    {
        Node *temp = root;

        while (temp)
        {
            if (value < temp->value)
            {
                temp = temp->left;
            }
            else if (value > temp->value)
            {
                temp = temp->right; // <-- fixed
            }
            else
            {
                return true;
            }
        }

        return false;
    }

    void printTree(Node *node)
    {
        if (!node)
            return;
        printTree(node->left);
        cout << node->value << " ";
        printTree(node->right);
    }

    Node *invertTree(Node *root)
    {
        if (!root)
            return nullptr;

        Node *leftSubTree = invertTree(root->left);
        Node *rightSubTree = invertTree(root->right);

        root->left = rightSubTree;
        root->right = leftSubTree;

        return root;
    }

    int findMin(Node *root)
    {
        if(root == nullptr) return -1;

        if(root->left == nullptr) 
        {
            return root->value;
        }

        // keep going left if there is a left child
        // if the value on the left is not null, then we re run the function again using recursion
        return findMin(root->left);
    }
};

int main()
{
    BinarySearchTree *tree = new BinarySearchTree();
    tree->insert(21);
    tree->insert(54);
    tree->insert(32);
    tree->insert(36);
    tree->insert(18);
    tree->insert(11);

    cout << "Original tree (in-order): ";
    tree->printTree(tree->root);
    cout << endl;

    // Invert the tree
    tree->root = tree->invertTree(tree->root);

    cout << "Inverted tree (in-order): ";
    tree->printTree(tree->root);
    cout << endl;

    return 0;
}