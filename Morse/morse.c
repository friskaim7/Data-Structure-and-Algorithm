/*=======================================================================================
Program		: morse.c
Author		: Friska Intan Muta'alliy
Description	: Morse ADT body implementation file
Date		: Friday, 29 May 2020  12:23:09
Version		: 1.0
Compiler	: gcc (tdm64-1) 5.1.0
Note		: -
=========================================================================================*/

#include "morse.h"

/*=========================*/
/*        CONSTRUCTOR      */
/*=========================*/

Morse createMorse()
{
    Morse M = createTree();
    address result, root;

    // set NULL as the root
    root = newVNode(charNil);
    setRoot(&M, &root);     //level 0

    // insert the child nodes
    insertNode(&M, charNil, 'E', 'L');  // level 1
    insertNode(&M, charNil, 'T', 'R');

    insertNode(&M, 'E', 'I', 'L');      //level 2
    insertNode(&M, 'E', 'A', 'R');
    insertNode(&M, 'T', 'N', 'L');
    insertNode(&M, 'T', 'M', 'R');

    insertNode(&M, 'I', 'S', 'L');      //level 3
    insertNode(&M, 'I', 'U', 'R');
    insertNode(&M, 'A', 'R', 'L');
    insertNode(&M, 'A', 'W', 'R');
    insertNode(&M, 'N', 'D', 'L');
    insertNode(&M, 'N', 'K', 'R');
    insertNode(&M, 'M', 'G', 'L');
    insertNode(&M, 'M', 'O', 'R');

    insertNode(&M, 'S', 'H', 'L');      //level 4
    insertNode(&M, 'S', 'V', 'R');
    insertNode(&M, 'U', 'F', 'L');
    insertNode(&M, 'U', charNil, 'R');
    insertNode(&M, 'R', 'L', 'L');
    insertNode(&M, 'R', charNil, 'R');
    insertNode(&M, 'W', 'P', 'L');
    insertNode(&M, 'W', 'J', 'R');

    insertNode(&M, 'D', 'B', 'L');
    insertNode(&M, 'D', 'X', 'R');
    insertNode(&M, 'K', 'C', 'L');
    insertNode(&M, 'K', 'Y', 'R');
    insertNode(&M, 'G', 'Z', 'L');
    insertNode(&M, 'G', 'Q', 'R');
    insertNode(&M, 'O', '0', 'L');
    insertNode(&M, 'O', charNil, 'R');
    
    insertNode(&M, 'H', '5', 'L');      //level 5
    insertNode(&M, 'H', '4', 'R');
    insertNode(&M, 'V', '3', 'R');

    result = searchNode(M.Root, 'U');               // search the address of 'U'
    result->right->right = newVNode('2');           // insert '2' as the right-grandchild of 'U' manually
    result->right->right->parent = result->right;   // set the right-child of 'U' as the parent of '2' manually

    result = searchNode(M.Root, 'R');               // search the address of 'R'
    result->right->left = newVNode(' ');           // insert ' ' (space) as the right-left-grandchild of 'R' manually
    result->right->left->parent = result->right;   // set the right-child of 'R' as the parent of ' ' manually

    insertNode(&M, 'J', '1', 'R');

    insertNode(&M, 'B', '6', 'L');
    insertNode(&M, 'Z', '7', 'L');
    insertNode(&M, '0', '8', 'L');

    result = searchNode(M.Root, 'O');               // search the address of 'O'
    result->right->left = newVNode('9');            // insert '9' as the right-left-grandchild of 'O' manually
    result->right->left->parent = result->right;    // set the right-child of 'R' as the parent of '9' manually

    return M;
} 
void makeMorse(Morse *M)
{
    makeTree(M);

    address result, root;

    // set NULL as the root
    root = newVNode(charNil);
    setRoot(M, &root);     //level 0

    // insert the child nodes
    insertNode(M, charNil, 'E', 'L');  // level 1
    insertNode(M, charNil, 'T', 'R');

    insertNode(M, 'E', 'I', 'L');      //level 2
    insertNode(M, 'E', 'A', 'R');
    insertNode(M, 'T', 'N', 'L');
    insertNode(M, 'T', 'M', 'R');

    insertNode(M, 'I', 'S', 'L');      //level 3
    insertNode(M, 'I', 'U', 'R');
    insertNode(M, 'A', 'R', 'L');
    insertNode(M, 'A', 'W', 'R');
    insertNode(M, 'N', 'D', 'L');
    insertNode(M, 'N', 'K', 'R');
    insertNode(M, 'M', 'G', 'L');
    insertNode(M, 'M', 'O', 'R');

    insertNode(M, 'S', 'H', 'L');      //level 4
    insertNode(M, 'S', 'V', 'R');
    insertNode(M, 'U', 'F', 'L');
    insertNode(M, 'U', charNil, 'R');
    insertNode(M, 'R', 'L', 'L');
    insertNode(M, 'R', charNil, 'R');
    insertNode(M, 'W', 'P', 'L');
    insertNode(M, 'W', 'J', 'R');

    insertNode(M, 'D', 'B', 'L');
    insertNode(M, 'D', 'X', 'R');
    insertNode(M, 'K', 'C', 'L');
    insertNode(M, 'K', 'T', 'R');
    insertNode(M, 'G', 'Z', 'L');
    insertNode(M, 'G', 'Q', 'R');
    insertNode(M, 'O', '0', 'L');
    insertNode(M, 'O', charNil, 'R');
    
    insertNode(M, 'H', '5', 'L');      //level 5
    insertNode(M, 'H', '4', 'R');
    insertNode(M, 'V', '3', 'R');

    result = searchNode(M->Root, 'U');              // search the address of 'U'
    result->right->right = newVNode('2');           // insert '2' as the right-grandchild of 'U' manually
    result->right->right->parent = result->right;   // set the right-child of 'U' as the parent of '2' manually

    result = searchNode(M->Root, 'R');              // search the address of 'R'
    result->right->left = newVNode(' ');            // insert ' ' (space) as the right-left-grandchild of 'R' manually
    result->right->left->parent = result->right;    // set the right-child of 'R' as the parent of ' ' manually

    insertNode(M, 'J', '1', 'R');

    insertNode(M, 'B', '6', 'L');
    insertNode(M, 'Z', '7', 'L');
    insertNode(M, '0', '8', 'L');

    result = searchNode(M->Root, 'O');              // search the address of 'O'
    result->right->left = newVNode('9');            // insert '9' as the right-left-grandchild of 'O' manually
    result->right->left->parent = result->right;    // set the right-child of 'R' as the parent of '9' manually
}

/*=========================*/
/*         ACCESSOR        */
/*=========================*/

String decode(Morse M, char *code)
{
    unsigned int len = strlen(code);
    address node = M.Root;
    String result = createString();

    for(int i = 0; i < len; i++)
    {
        if(code[i] == '.')      // if the code[i] is dot (.), then move to the left
            node = node->left;
        
        else if(code[i] == '-') // if the code[i] is dash (-), then move to the right
            node = node->right;
        
        // if the code[i] is space or the last charackter in the code
        // then insert the info of current node to the String
        if((code[i] == ' ') || (i == len - 1))  
        {
            if(node->info != charNil)
            {
                insertChar(&result, (node->info));
                node = M.Root;
            }
        }
    }
    return result;
}

String backToRoot(Morse M, address node)
{
    String result = createString();

    while (!isNodeRoot(node))
    {
        if(node == node->parent->left)          // if the current node is the left child of its parent, then insert dot (.)
            insertChar(&result, '.');
        else if(node == node->parent->right)    // if the current node is the right child of its parent, then insert dash (-)
            insertChar(&result, '-');
        node = node->parent;        // move to the parent
    }
    
    return result;
}

String encodeChar(Morse M, char X)
{
    String result = createString();
    address node;

    node = searchNode(M.Root, X);       // searching for the node that contains the X info

    if(node != Nil)
        result = backToRoot(M, node);   // back to the root and record the path

    reverseString(&result);             // reverse the recorded path

    return result;
}

String encodeString(Morse M, char *arrayX)
{
    String result = createString(), temp = createString();

    unsigned int len = strlen(arrayX);

    for (int i = 0; i < len; i++)           // encode the character one by one
    {
        if(available(arrayX[i]))            // if the collected character is available in the Morse tree, then encode it
        {
            temp = encodeChar(M, arrayX[i]);    // use a temporary String to hold the Morse code
            concatenateString(&result, temp);   // gather the Morse codes in the result String
            insertChar(&result, ' ');           // separate every Morse codes with space ( )
            deleteString(&temp);                // delete the temporary String
        }    
    }
    return result;
}

void encodeFile(Morse M, char *input, char *output)
{
    char X;
    String S = createString();
    FILE * in; 
    FILE * out;

    in = fopen(input, "r");     // open the input file in read only mode
    out = fopen(output, "w");   // open the output file in write only mode
    if((in != Nil) && (out != Nil))
    {
        while ((X = getc(in)) != EOF)   // collect every character one by one while the collected character is not the End of file
        {
            if(available(X))            // if the collected character is available in the Morse tree, then encode it
            {
                S = encodeChar(M, X);   // encode the character and assign them to a temporary String

                for (int i = 0; i < S.size; i++)    // write the Morse code character one by one to the output file
                    fputc(S.arr[i], out);           
                fputc(' ', out);                    // separate every Morse codes with space ( )

                deleteString(&S);       // delete the temporary String
            }
            else
            {
                if((X == '.') || (X == '-'))    // if the collected character is a dot (.) or a dash (-), then replace it with space ( )
                    X = ' ';
                fputc(X, out);          // write the character to the output file
            }
        }

    }
    else
        printf("Memory is full!\n");
    
    // close both the input and the output file
    fclose(in);
    fclose(out);
}



/*
        Finally!
         /
        /
    ʕノಠᴥಠʔノ ︵
               ┻━┻
*/