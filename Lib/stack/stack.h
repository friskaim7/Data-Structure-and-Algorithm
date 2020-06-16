/*=======================================================================================
Program		: stack.h
Author		: Friska Intan Muta'alliy
Description	: Stack ADT header file
Date		: Tuesday, 26 May 2020  18:49:21
Version		: 1.0
Compiler	: gcc (tdm64-1) 5.1.0
Note		: -
=========================================================================================*/
#ifndef stack_H
#define stack_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Nil NULL
#define charNil 0

typedef char infotype;
typedef struct stackElement *stackAddrs;
typedef struct stackElement
{
    infotype info;
    stackAddrs next;
}stackElement;

typedef struct Stack
{
    stackAddrs Top;
}Stack;

/*=========================*/
/*        CONSTRUCTOR      */
/*=========================*/

// Description		: Function to create an empty Stack
// Input			: -
// Output			: An Empty  Stack
Stack createStack();

// Description		: Procedure to make an empty Stack
// Initial State	: The Stack has been declared in the calling module.
// Final State		: The Stack.Top is point to Nil.
void makeStack(Stack *S);

// Description		: Function to allocate an empty new node and initialize all attributes with Nil.
// Input			: -
// Output			: An stackAddrs of Stack node.
stackAddrs newNodeStack();

// Description		: Function to allocate an empty new node and initialize all attributes with Nil, except info.
// Input			: info
// Output			: An stackAddrs of Stack node.
stackAddrs newVNodeStack(infotype info);

/*=========================*/
/*          MUTATOR        */
/*=========================*/

// Description		: Procedure to insert a node to the Stack
// Initial State	: The new node's address is not null and has not been inserted
// Final State		: The new node has been inserted
void insert(Stack *S, stackAddrs node);

// Description		: Procedure to insert a new node that contain an info to the Stack
// Initial State	: The new node has not been inserted.
// Final State		: The new node has been inserted.
void push(Stack *S, infotype newInfo);

/*=========================*/
/*       INPUT/OUTPUT      */
/*=========================*/

// Description		: Procedure to display the info(s) of the Stack to the screen
// Initial State	: The info(s) of the Stack has not been displayed.
// Final State		: The info(s) of the Stack displayed on the screen.
void printStack(Stack S);

/*=========================*/
/*        VALIDATOR        */
/*=========================*/

// Description		: Function to validate if a Stack is empty or not
// Input			: Stack
// Output			: true/false
bool isEmptyStack(Stack S);

/*=========================*/
/*        DESTRUCTOR       */
/*=========================*/

// Description		: Procedure to delete a node from a Stack
// Initial State	: The node has not been deleted.
// Final State		: The node has been deleted.
void delete(stackAddrs *node);

// Description		: Procedure to pop up an info of a node in the top of the Stack
// Initial State	: The info of the node has not been popped up.
// Final State		: The info of the node has been popped up.
infotype pop(Stack *S);


#endif



/*
        WOOF!
        /
    กʕ•͡ᴥ•ʔ ก
*/