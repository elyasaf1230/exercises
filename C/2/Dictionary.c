#include "Dictionary.h"

Leaf* initLeaf(Leaf* leaf)
{
	int i;

	if (leaf == NULL) return NULL;

	for (i = 0; i < LETTERS; ++i)
	{
		leaf->_next[i] = NULL;
	}

	leaf->_value = NULL;

	return leaf;
}

void killLeaf(Leaf* leaf)
{
	int i;

	if (leaf == NULL) return;

	//delete the value:
	if (leaf->_value != NULL)
		free(leaf->_value);

	//delete the deeper leafs (recursion! :) ):
	if (leaf->_next != NULL)
	{
		for (i = 0; i < LETTERS; ++i)
		{
			if (leaf->_next[i] != NULL)
			{
				killLeaf(leaf->_next[i]);
			}
		}
	}

	return;
}

Leaf* insertWord(Leaf* leaf, char* key, char* value)
{
	int i;

	if (leaf == NULL || key == NULL || value == NULL) return NULL;
	
	//lower key
	for (i = 0; key[i]; i++){
		key[i] = tolower(key[i]);
	}
	//lower value
	for (i = 0; value[i]; i++){
		value[i] = tolower(value[i]);
	}


	//if the current leaf is the word...?
	if (strlen(key) == 0)
	{
		//if there is a value we need to delete it first.
		if (leaf->_value != NULL)
			free(leaf->_value);

		//create new place for 'value'
		leaf->_value = (char*)malloc(sizeof(char) * (strlen(value) + 1)); //+1 for null

		if (leaf->_value == NULL) return NULL;

		//copy
		strcpy_s(leaf->_value, strlen(value) + 1, value);

		return leaf;
	}
	else if (leaf->_next[key[0] - 'a'] == NULL)//if this isn't the end and the next leaf is null we need to create it.
	{
		leaf->_next[key[0] - 'a'] = (Leaf*)malloc(sizeof(Leaf));

		if (leaf->_next[key[0] - 'a'] == NULL) return NULL;

		initLeaf(leaf->_next[key[0] - 'a']);
	}

	//else
	return insertWord(leaf->_next[key[0] - 'a'], key + 1, value);
}

char* getValue(Leaf* leaf, char* key)
{
	int i;
	char* temp;

	if (leaf == NULL || key == NULL) return NULL;

	//lower it..
	for(i = 0; key[i]; i++){
		key[i] = tolower(key[i]);
	}

	//if reach to end - this leaf is the word
	if (strlen(key) == 0)
	{
		//copy and returning the value:
		temp = (char*)malloc(sizeof(char) * (strlen(leaf->_value) + 1));

		if (temp != NULL)
			strcpy_s(temp, strlen(leaf->_value) + 1, leaf->_value);

		return temp;
	}

	return getValue(leaf->_next[key[0] - 'a'], key + 1);
}

int LoadFileIntoDic(Leaf* dictionary, FILE* file)
{
	char keyBuffer[WORD_MAX_SIZE], valueBuffer[WORD_MAX_SIZE*5];

	if (dictionary == NULL || file == NULL) return FATAL_ERROR;

	//reading from file and insert to dictionary
	while (fscanf_s(file, "%s :%[^\n]s\n", keyBuffer, sizeof(keyBuffer), valueBuffer, sizeof(valueBuffer)) == 2)
	{
		insertWord(dictionary, keyBuffer, valueBuffer);
	}

	//if there was an error
	if (!feof(file)) return ERROR;

	return SUCCESS;
}