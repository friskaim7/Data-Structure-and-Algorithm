/*=======================================================================================
Program		: stack.c
Author		: Friska Intan Muta'alliy
Description	: Stack ADT body implementation file
Date		: Tuesday, 26 May 2020  18:49:21
Version		: 1.0
Compiler	: gcc (tdm64-1) 5.1.0
Note		: -
=========================================================================================*/

#include "stack.h"

/*=========================*/
/*        CONSTRUCTOR      */
/*=========================*/

Stack createStack()
{
    Stack S;
    S.Top = Nil;

    return S;
}

void makeStack(Stack *S)
{
    S->Top = Nil;
}

stackAddrs newNodeStack()
{
    stackAddrs node = (stackElement *)malloc(sizeof(stackElement));

    if (node != Nil)
    {
        node->info = charNil;
        node->next = Nil;
    }
    return node;
}
stackAddrs newVNodeStack(infotype info)
{
    stackAddrs node = newNodeStack();
    node->info = info;

    return node;
}

/*=========================*/
/*          MUTATOR        */
/*=========================*/

void insert(Stack *S, stackAddrs node)
{
    node->next = S->Top;
    S->Top = node;
}

void push(Stack *S, infotype newInfo)
{
    stackAddrs node = newVNodeStack(newInfo);
    if (node != Nil)
        insert(S, node);
    else
        printf("Memory is full!\n");
}

/*=========================*/
/*       INPUT/OUTPUT      */
/*=========================*/

void printStack(Stack S)
{
    stackAddrs temp = S.Top;
    if (!isEmptyStack(S))
    {
        do
        {
            printf("%c ", temp->info);
            temp = temp->next;
        } while (temp != Nil);
        printf("\n");
    }
    else
        printf("Stack is empty.\n");
}

/*=========================*/
/*        VALIDATOR        */
/*=========================*/

bool isEmptyStack(Stack S)
{
    return S.Top == Nil;
}

/*=========================*/
/*        DESTRUCTOR       */
/*=========================*/

void delete (stackAddrs *node)
{
    (*node)->next = Nil;
    free(node);
}

infotype pop(Stack *S)
{
    infotype out;

    if (!isEmptyStack(*S)) // if the Stack is not empty
    {
        stackAddrs temp;

        out = S->Top->info; // copy the value of top to the output variable

        temp = S->Top;
        S->Top = S->Top->next; // make the top pointing the next node
        delete (&temp);        // delete the old top
    }
    else
        printf("Underflow!\n");

    return out;
}



/*
        WOOF!
        /
    กʕ•͡ᴥ•ʔ ก
*/