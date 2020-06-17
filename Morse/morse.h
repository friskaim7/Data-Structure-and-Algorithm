/*=======================================================================================
Program		: morse.h
Author		: Friska Intan Muta'alliy
Description	: Morse ADT header file
Date		: Friday, 29 May 2020  12:23:09
Version		: 1.0
Compiler	: gcc (tdm64-1) 5.1.0
Note		: -
=========================================================================================*/

#ifndef morse_H
#define morse_H

#include "../Lib/bintree/tree.h"
#include "../Lib/str/str.h"

#define available(X) ((X >= 'A' && X <= 'Z') || (X >= 'a' && X <= 'z') || (X >= '0' && X <= '9') ||(X == ' '))
typedef Tree Morse;



/*=========================*/
/*        CONSTRUCTOR      */
/*=========================*/

// Description		: Function to create a Tree of Morse Code
// Input			: -
// Output			: Tree of Morse
Morse createMorse();

// Description		: Procedure to make a tree of Morse Code
// Initial State	: Morse declared in the calling program.
// Final State		: Morse has been made.
void makeMorse(Morse *M);


/*=========================*/
/*         ACCESSOR        */
/*=========================*/
// Description		: Function to decode a string of Morse code
// Input			: Tree of Morse and the string of Morse code.
// Output			: A String of the decoding result.
String decode(Morse M, char *code);

// Description		: Function to record the path from a node to the root
// Input			: Tree of Morse and an address of a node.
// Output			: A stack of reversed Morse code.
String backToRoot(Morse M, address node);

// Description		: Function to encode a character to a String of Morse code
// Input			: Tree of Morse and a character.
// Output			: A String of Morse code.
String encodeChar(Morse M, char X);

// Description		: Function to encode an array of character to a String of Morse code
// Input			: Tree of Morse and an array of character.
// Output			: A String of Morse codes.
String encodeString(Morse M, char *arrayX);

// Description		: Procedure to encode a *.txt file
// Initial State	: The file has not been encoded.
// Final State		: The file has been encoded and written in a new file.
void encodeFile(Morse M, char *input, char *out);

#endif



/*
        Finally!
         /
        /
    ʕノಠᴥಠʔノ ︵
               ┻━┻
*/