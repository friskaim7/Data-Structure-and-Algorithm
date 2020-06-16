/*=======================================================================================
Program		: tree.c
Author		: Friska Intan Muta'alliy
Description	: ADT Tree body implementation file
Date		: Thursday, 21 May 2020
Version		: 1.0
Compiler	: gcc (tdm64-1) 5.1.0
Note		: -
=========================================================================================*/
#include "tree.h"


/*=========================*/
/*        CONSTRUCTOR      */
/*=========================*/

Tree createTree()
{
    Tree T;         // declare the Tree
    T.Root = Nil;   // assign the root with Nil
    return T;
}

void makeTree(Tree *T)
{
    T->Root = Nil;  // assign the root with Nil
}

address newNode()
{
    address P = (address)malloc(sizeof(treeElement));   // allocate the memory for a new node
    if (P != Nil)   // if the alloacating process is success, then continue
    {
        // initialize all attributes with Nil
        P->info = charNil;
        P->left = Nil;
        P->right = Nil;
        P->parent = Nil;
    }
    else
        printf("Memory is full.\n");

    return P;
}
address newVNode(infotype info)
{
    address node = newNode();   // allocate the memory for a new node
    node->info = info;          // assign the info 
}

/*=========================*/
/*          MUTATOR        */
/*=========================*/

void insertNode(Tree *T, infotype parInfo, infotype newInfo, char position)
{
    address par = searchNode(T->Root, parInfo); // searching for the parent's address
    if (par == Nil)         // if the parent not found
    {
        printf("Parent not found.\n");
        if (isEmpty(*T))    // if the tree is empty
        {
            address newRoot = newVNode(newInfo);// allocate a new node
            setRoot(T, &newRoot);               // insert the node as root
        }
    }
    else
    {
        address node = newVNode(newInfo);               // allocate a new node
        node->parent = par;                             // set the parent
        if ((position == 'l') || (position == 'L'))
            par->left = node;                           // set as a left child
        else if ((position == 'r') || (position == 'R'))
            par->right = node;                          // set as a right child
    }
}

void setRoot(Tree *T, address *newRoot)
{
    if (isEmpty(*T)) // Tree is empty
    {
        T->Root = *newRoot; // newRoot menjadi root untuk Tree
        // printf("%c has been set as root.\n", T->Root->info);
    }
}

/*=========================*/
/*         ACCESSOR        */
/*=========================*/

void preOrder(address node)
{
    if (node != Nil)
    {
        visit(node);
        preOrder(node->left);   // go to the left child
        preOrder(node->right);  // go to the right child
    }
}

void postOrder(address node)
{
    if (node != Nil)
    {
        postOrder(node->left);  // go to the left child
        postOrder(node->right); // go to the right child
        visit(node);
    }
}

void inOrder(address node)
{
    if (node != Nil)
    {
        inOrder(node->left);    // go to the left child
        visit(node);
        inOrder(node->right);   // go to the right child
    }
}

void levelOrder(Tree T)
{
    int i, h = height(T);
    for(i = 0; i <= h; i++)     // visit every node in the i-th level
        visitLevel(T.Root, i);
}

void visitLevel(address node, unsigned int level)
{
    if (node == NULL)                       // if the node is Nil, then stop
        return; 
    if (level == 0)                         // if the node's level is 0, then visit the node
        visit(node);
    else if (level > 0)                     // if the node's level is more than 0, then visit the node(s) in 1 level above
    { 
        visitLevel(node->left, level-1);
        visitLevel(node->right, level-1); 
    } 
}

void visit(address node)
{
    if(node->info == charNil)
        printf("(n) ");         // to indicates that it is a null character
    else if(node->info == ' ')
        printf("(s) ");         // to indicates that it is a space character
    else
        printf("%c ", node->info);
}

address searchNode(address node, infotype info)
{
    if ((node == Nil) || (tolower(node->info) == tolower(info)))    // if the info is found, then return the address
        return node;

    address result;
    if ((result = searchNode(node->left, info)) != Nil) // if the info is found in the left, then return the address
        return result;

    if ((result = searchNode(node->right, info)) != Nil) // if the info is found in the right, then return the address
        return result;

    return result;  // if the info is not found then return Nil
}

unsigned int level(address node)
{
    unsigned int count = 0;
    address temp = node->parent;
    while (temp != Nil)     // while the node is not empty, back to the root and count the step(s)
    {
        temp = temp->parent;
        count++;
    }
    return count;
}

unsigned int height(Tree T)
{
    if (T.Root == Nil)          // if the Tree is empty, then the height is 0
        return 0;
    else
        return depth(T.Root);   // find the depth of the root
}

unsigned int depth(address node)
{
    if (node == Nil)
        return -1;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = depth(node->left);
        int rDepth = depth(node->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

unsigned int degree(address node)
{
    return ((node->left != Nil) + (node->right != Nil));
}

void deleteTree(Tree *T, address *node)
{
    if (*node != Nil)
    {
        deleteTree(T, &(*node)->left);  // delete the Tree of left child
        deleteTree(T, &(*node)->right); // delete the Tree of right child
        deleteLeaf(T, node);            // do deleteLeaf() when it comes to the leaf
    }
}

void deleteLeaf(Tree *T, address *node)
{
    if (isNodeLeaf(*node))  // if the node is leaf, then delete it
    {
        if (isNodeRoot(*node))  // if the node is a root, then assign the root with Nil
            T->Root = Nil;
        else
        {
            if ((*node)->parent->left == (*node))       // if the node is the parent's left child, then assign the parent's left child with Nil
                (*node)->parent->left = Nil;
            else if ((*node)->parent->right == (*node)) // if the node is the parent's right child, then assign the parent's right child with Nil
                (*node)->parent->right = Nil;

            (*node) = Nil;  // assign the node with Nil
            free(*node);    // deallocate the node
        }
    }
}

bool isEmpty(Tree T)
{
    return T.Root == Nil;       // return true if the root is Nil
}

bool isNodeRoot(address node)
{
    return node->parent == Nil; // return true if the node has no parent
}

bool isNodeLeaf(address node)
{
    return (((node->left) == Nil) && ((node->right) == Nil));   // return true if the node has no children
}



/*
        WOOF!
        /
    กʕ•͡ᴥ•ʔ ก
*/