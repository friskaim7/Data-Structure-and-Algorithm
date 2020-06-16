/*=======================================================================================
Program		: str.h
Author		: Friska Intan Muta'alliy
Description	: String ADT header file
Date		: Tuesday, 26 May 2020  11:37:34
Version		: 1.1
Compiler	: gcc (tdm64-1) 5.1.0
Reference   : string.h by Rey Rizki
Note		: insertChar() bug fixed.
-----------------------------------------------------------------------------------------
Version History :
1.0     23 May 2020 14:32:31    (+ doubleCapacity())
=========================================================================================*/

#ifndef string_H
#define string_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct String
{
    char *arr;
    unsigned int size, capacity;
}String;


/*=========================*/
/*        CONSTRUCTOR      */
/*=========================*/

// Description		: Function to create a String
// Input			: -
// Output			: String
String createString();

/*=========================*/
/*          MUTATOR        */
/*=========================*/

// Description		: Procedure to multiply the capacity of String by two
// Initial State	: The String  capacity has not been doubled
// Final State		: The String  capacity has been doubled
void doubleCapacity(String *string);

// Description		: Procedure to insert a character to a String
// Initial State	: The targeted String exists and the character has not been inserted.
// Final State		: The character has been inserted.
void insertChar(String *string, char newChar);

// Description		: Procedure to append an array of characters to a String
// Initial State	: The array of characters has not been appended to the string.
// Final State		: The array of characters has been appended to the string.
void appendString(String *string, char *newString);

// Description		: Procedure to concatenate two Strings
// Initial State	: Both of the Strings exists and has not been concatenated.
// Final State		: The second String has been concatenated to the first String.
void concatenateString(String *target, String source);

// Description		: Procedure to reverse a String
// Initial State	: The String has not been reverse.
// Final State		: The String has been reverse.
void reverseString(String *S);

// Description		: Procedure to swap two characters
// Initial State	: The characters has not been swap.
// Final State		: The characters has been swap.
void swap(char *a, char *b);


/*=========================*/
/*       INPUT/OUTPUT      */
/*=========================*/

// Description		: Procedure to display the String to the screen
// Initial State	: The String has not been displayed.
// Final State		: The String has been displayed on the screen.
void printString(String string);


/*=========================*/
/*        DESTRUCTOR       */
/*=========================*/

// Description		: Procedure to delete and deallocate a String
// Initial State	: The String has not been deleted.
// Final State		: The String has been deleted and.
void deleteString(String *string);

#endif



/*
        WOOF!
        /
    กʕ•͡ᴥ•ʔ ก
*/