/*=======================================================================================
Program		: str.c
Author		: Friska Intan Muta'alliy
Description	: String ADT body implementation file
Date		: Tuesday, 26 May 2020  11:37:34
Version		: 1.1
Compiler	: gcc (tdm64-1) 5.1.0
Reference   : string.c by Rey Rizki
Note		: insertChar() bug fixed.
-----------------------------------------------------------------------------------------
Version History :
1.0     23 May 2020 14:32:31    (+ doubleCapacity())
=========================================================================================*/
#include "str.h"

/*=========================*/
/*        CONSTRUCTOR      */
/*=========================*/

String createString()
{
    String string;
    string.arr = (char *)malloc(1 * sizeof(char));
    string.size = 0;
    string.capacity = 1;

    return string;
}

/*=========================*/
/*          MUTATOR        */
/*=========================*/

void doubleCapacity(String *string)
{
    string->capacity *= 2;
    string->arr = (char *)realloc(string->arr, string->capacity * sizeof(char));
}

void insertChar(String *string, char newChar)
{
    if (string->size == string->capacity)
        doubleCapacity(string);

    *(string->arr + string->size) = newChar;
    string->size += 1;
    *(string->arr + string->size + 1) = 0;
}

void appendString(String *string, char *newString)
{
    int length = strlen(newString);

    for (int i = 0; i < length; i++)
        insertChar(string, *(newString + i));
}

void concatenateString(String *target, String source)
{
    for (int i = 0; i < source.size; i++)
        insertChar(target, *(source.arr + i));
}

void reverseString(String *S)
{
    int mid = S->size/2;
    for (int i = 0; i < mid; i++)
        swap(S->arr + i, S->arr + S->size-1 - i);
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

/*=========================*/
/*       INPUT/OUTPUT      */
/*=========================*/

void printString(String string)
{
    printf("%s\n", string.arr);
}

/*=========================*/
/*        DESTRUCTOR       */
/*=========================*/

void deleteString(String *string)
{
    free(string->arr);
    string->arr = NULL;
    string->size = 0;
    string->capacity = 1;
}



/*
        WOOF!
        /
    กʕ•͡ᴥ•ʔ ก
*/