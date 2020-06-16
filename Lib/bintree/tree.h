/*=======================================================================================
Program		: tree.h
Author		: Friska Intan Muta'alliy
Description	: ADT Tree header file
Date		: Thursday, 21 May 2020
Version		: 1.0
Compiler	: gcc (tdm64-1) 5.1.0
Note		: -
=========================================================================================*/
#ifndef tree_H
#define tree_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define Nil NULL
#define charNil 0

typedef char infotype;
typedef struct treeElement *address;
typedef struct treeElement
{
    infotype  info;
   	address right, left, parent;
}treeElement;

typedef struct Tree
{
	address Root;
}Tree;



/*=========================*/
/*        CONSTRUCTOR      */
/*=========================*/

// Description		: Function to create an empty Tree
// Input			: -
// Output			: Tree
Tree createTree();

// Description		: Procedure to make an empty Tree
// Initial State	: Tree has been declared in the calling program.
// Final State		: Tree is empty
void makeTree(Tree *T);

// Description		: Function to allocate an empty new node and initialize all attributes with Nil.
// Input			: -
// Output			: An address of Tree node.
address newNode();

// Description		: Function to allocate an empty new node and initialize all attributes with Nil, except the info.
// Input			: info
// Output			: An address of Tree node.
address newVNode(infotype info);


/*=========================*/
/*          MUTATOR        */
/*=========================*/

// Description		: Procedure to insert a new node as a left/right child of a parent node
// Initial State	: The new node has not been inserted.
// Final State		: The new node inserted.
void insertNode(Tree *T, infotype par, infotype newInfo, char position);

// Description		: Procedure to set a node as the root of a tree
// Initial State	: The root of the tree should be empty.
// Final State		: The new root setted as root of the tree.
void setRoot(Tree *T, address *newRoot);


/*=========================*/
/*         ACCESSOR        */
/*=========================*/

// Description		: Procedure to visit every node once by Preorder recursively
// Initial State	: The nodes has not been visited.
// Final State		: Every node has been visited and printed on the screen.
void preOrder(address node);

// Description		: Procedure to visit every node once by Postorder recursively
// Initial State	: The nodes has not been visited.
// Final State		: Every node has been visited and printed on the screen.
void postOrder(address node);

// Description		: Procedure to visit every node once by Inorder recursively
// Initial State	: The nodes has not been visited.
// Final State		: Every node has been visited and printed on the screen.
void inOrder(address node);

// Description		: Procedure to visit every node once by Level Order.
// Initial State	: The nodes has not been visited.
// Final State		: Every node has been visited and printed on the screen.
// Reference		: https://www.geeksforgeeks.org/level-order-tree-traversal/
void levelOrder(Tree T);

// Description		: Procedure to print the info of the visited node
// Initial State	: The info of the node has not been printed on the screen.
// Final State		: The info of the node printed on the screen.
void visit(address node);

// Description		: Procedure to print the info of the given level node recursively
// Initial State	: The info of the node has not been printed on the screen.
// Final State		: The info of the node printed on the screen.
// Reference		: https://www.geeksforgeeks.org/level-order-tree-traversal/
void visitLevel(address node, unsigned int level);

// Description		: Function to search the address of node with the given info recursively
// Input			: address of root and info
// Output			: address of the node
address searchNode(address node, infotype info);

// Description		: Function to find the level of a node
// Input			: address of node
// Output			: positive integer
unsigned int level(address node);

// Description		: Function to find the height (max. depth) of a tree
// Input			: Tree
// Output			: positive integer
// Reference		: https://www.geeksforgeeks.org/level-order-tree-traversal/
unsigned int height(Tree T);

// Description		: Function to find the depth of a node recursively
// Input			: address of node
// Output			: positive int
// Reference		: https://www.geeksforgeeks.org/level-order-tree-traversal/
unsigned int depth(address node);

// Description		: Function to find the degree (number of child(s)) of a node
// Input			: address of node
// Output			: positive integer
unsigned int degree(address node);


/*=========================*/
/*        DESTRUCTOR       */
/*=========================*/

// Description		: Procedure to delete and deallocate a tree recursively
// Initial State	: The tree has not been deleted.
// Final State		: The tree has been deleted.
void deleteTree(Tree *T, address *node);

// Description		: Procedure to delete and deallocate a leaf node
// Initial State	: The leaf node has not been deleted.
// Final State		: The leaf node has been deleted.
void deleteLeaf(Tree *T, address *node);


/*=========================*/
/*        VALIDATOR        */
/*=========================*/

// Description		: Function to validate if a tree is empty
// Input			: Tree
// Output			: True/False
bool isEmpty(Tree T);

// Description		: Function to to validate if a node is a root
// Input			: Address of node
// Output			: True/False
bool isNodeRoot(address node);

// Description		: Function to validate if a node is a leaf
// Input			: Address of node
// Output			: True/False
bool isNodeLeaf(address node);

#endif

/*
		WOOF!
		/
	กʕ•͡ᴥ•ʔ ก
*/