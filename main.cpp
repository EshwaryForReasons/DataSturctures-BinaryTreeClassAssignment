/**
 * In class activity, 11/30/2023
 * Change the implementation of the binary search tree from the:
 * 1) Implement the binary sarch tree using the template (i.e. template <typename T>)
 * 2) add private add_node member function is instead a member function of the Node class
 * 3) add private print member function is instead a member function of the Node class.
*/

#include <iostream>
#include "binarySearchTree.h"

using namespace std;

/*
   This program tests the binary search tree class.
*/
int main()
{
    BinarySearchTree<string> t;
    t.insert("D");
    t.insert("B");
    t.insert("A");
    t.insert("C");
    t.insert("F");
    t.insert("E");
    t.insert("I");
    t.insert("G");
    t.insert("H");
    t.insert("J");
    t.erase("A"); // Removing leaf
    t.erase("B"); // Removing element with one child
    t.erase("F"); // Removing element with two children
    t.erase("D"); // Removing root
    t.print();
    cout << "Expected: C E G H I J" << endl;
    cout << t.count("A") << " " << t.count("J") << endl;
    cout << "Expected: 0 1" << endl;
    return 0;
}




