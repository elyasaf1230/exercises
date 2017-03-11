/*
	Each Leaf will hold pointers to leafs that represents 
	the next posible letters of the key, and the value.
	The value can contain spaces (the user should know what to do with them..).
*/

#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

#define LETTERS 26
#define SUCCESS 1
#define ERROR   0
#define FATAL_ERROR -1
#define WORD_MAX_SIZE 50


typedef struct Leaf Leaf;

struct Leaf
{
	char *_value;  //string
	Leaf *_next[LETTERS];  //26 Leafs
};

/*
	initLeaf:
		This function init the given Leaf.

	INPUT:
		pointer to Leaf.

	OUTPUT:
		pointer to the given Leaf, NULL if error (malloc() failed).
*/
Leaf* initLeaf(Leaf* leaf);

/*
	killLeaf:
		This function destroy the given Leaf.

	INPUT:
		pointer to Leaf to kill (MUHAHAHA!).

	OUTPUT:
		None.
*/
void killLeaf(Leaf* leaf);

/*
	insertLeaf:
		This function insert the given 'key' into the given leaf with the value 'value'.

	INPUT:
		leaf - pointer to Leaf.
		key - string.
		value - string.

	OUTPUT:
		pointer to Leaf - the leaf that hold the value on success, NULL if failed (malloc() failed)
*/
Leaf* insertWord(Leaf* leaf, char* key, char* value);

/*
	getValue:
		This function find 'key' in 'leaf', if 'key' found it return the value.
		The return value is a pointer to 'value' of the given key, it will point
		to dynamic memory, so the user need to free it. (it will protect the original value in the leaf).

	INPUT: 
		leaf - pointer to leaf to search in.
		key - string to search for.

	OUTPUT:
		char* - string of the value. (NULL if not found or error)
*/
char* getValue(Leaf* leaf, char* key);

/*
	LoadFileIntoDic:
		This function load words from the given file into the given dictionary.

	INPUT:
		pointer to leaf (dictionary)
		pointer to file.

	OUTPUT:
		int - SUCCESS on success (da..?)
		FATAL_ERROR if dictionary/file is NULL of file is not openned.
		ERROR - if file is not is the format (key:value\n)
*/
int LoadFileIntoDic(Leaf* dictionary, FILE* file);
#endif