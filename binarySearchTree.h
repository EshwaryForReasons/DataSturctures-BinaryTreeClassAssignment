
#pragma once

#include <string>

using namespace std;

template<typename T>
class BinarySearchTree;

template<typename T>
class Node
{
private:

    T data;
    Node<T>* left;
    Node<T>* right;

    friend class BinarySearchTree<T>;
};

/*
   This class implements a binary search tree whose
   nodes hold Ts.
*/
template<typename T>
class BinarySearchTree
{
public:
    /**
       Constructs an empty tree.
    */
    BinarySearchTree();

    /**
       Inserts a new node into the tree.
       @param element the element to insert
    */
    void insert(T element);

    /**
       Tries to find an element in the tree.
       @param element the element to find
       @return 1 if the element is contained in the tree
    */
    int count(T element) const;

    /**
       Tries to remove an element from the tree. Does nothing
       if the element is not contained in the tree.
       @param element the element to remove
    */
    void erase(T element);
    
    /**
       Prints the contents of the tree in sorted order.
    */
    void print() const;

    void add_node(Node<T>* root, Node<T>* new_node);

private:

    Node<T>* root;

    void print(Node<T>* root) const;
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = nullptr;
}

template<typename T>
void BinarySearchTree<T>::insert(T element)
{
    Node<T>* new_node = new Node<T>;
    new_node->data = element;
    new_node->left = nullptr;
    new_node->right = nullptr;

    if (root == nullptr)
    {
        root = new_node;
    }
    else
    {
        add_node(root, new_node);
    }
}

template<typename T>
int BinarySearchTree<T>::count(T element) const
{
    Node<T>* current = root;
    while (current != nullptr)
    {
        if (element < current->data)
        {
            current = current->left;
        }
        else if (element > current->data)
        {
            current = current->right;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

template<typename T>
void BinarySearchTree<T>::erase(T element)
{
    // Find node to be removed

    Node<T>* to_be_removed = root;
    Node<T>* parent = nullptr;
    bool found = false;
    while (!found && to_be_removed != nullptr)
    {
        if (element == to_be_removed->data)
        {
            found = true;
        }
        else
        {
            parent = to_be_removed;
            if (element < to_be_removed->data)
            {
                to_be_removed = to_be_removed->left;
            }
            else
            {
                to_be_removed = to_be_removed->right;
            }
        }
    }

    if (!found)
    {
        return;
    }

    // to_be_removed contains element

    // If one of the children is empty, use the other

    if (to_be_removed->left == nullptr || to_be_removed->right == nullptr)
    {
        Node<T>* new_child;
        if (to_be_removed->left == nullptr)
        {
            new_child = to_be_removed->right;
        }
        else
        {
            new_child = to_be_removed->left;
        }

        if (parent == nullptr) // Found in root
        {
            root = new_child;
        }
        else if (parent->left == to_be_removed)
        {
            parent->left = new_child;
        }
        else
        {
            parent->right = new_child;
        }
        return;
    }

    // Neither subtree is empty

    // Find smallest element of the right subtree

    Node<T>* smallest_parent = to_be_removed;
    Node<T>* smallest = to_be_removed->right;
    while (smallest->left != nullptr)
    {
        smallest_parent = smallest;
        smallest = smallest->left;
    }

    // smallest contains smallest child in right subtree

    // Move contents, unlink child

    to_be_removed->data = smallest->data;
    if (smallest_parent == to_be_removed)
    {
        smallest_parent->right = smallest->right;
    }
    else
    {
        smallest_parent->left = smallest->right;
    }
}

template<typename T>
void BinarySearchTree<T>::print() const
{
	print(root);
}

template<typename T>
void BinarySearchTree<T>::print(Node<T>* _root) const
{
	if(!_root)
		return;
	
	print(_root->left);
	cout << _root->data << endl;
	print(_root->right);
}

template<typename T>
void BinarySearchTree<T>::add_node(Node<T>* _root, Node<T>* new_node)
{
	if (new_node->data < _root->data)
    {
        if (_root->left == nullptr)
        {
            _root->left = new_node;
        }
        else
        {
            add_node(_root->left, new_node);
        }
    }
    else if (new_node->data > _root->data)
    {
        if (_root->right == nullptr)
        {
            _root->right = new_node;
        }
        else
        {
            add_node(_root->right, new_node);
        }
    }
}