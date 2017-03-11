#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>
#include <time.h>
#include "Dictionary.h"

#define NEW_FILE_NAME "result.txt"

/*
	This function get a file and dictionary.
	the function open new file (with the name of NEW_FILE_NAME).
	The function run on all words in the file: if the word exists in the dictionary,
	it takes a random word from the dictionary (split the value of the word we took 
	from the file to words), and writes it to the new file.
	If the word doesn't exists in the dictionary it puts it in the new file as it is.
*/
void replaceWordsInFile(Leaf* dictionary, FILE* file);

int main(int argc, char* argv[])
{
	char *fileNameText[100], *fileNameDict[100];
	FILE *fileText = NULL, *fileDict = NULL;
	Leaf *dictionary = NULL;
	int temp;

	srand(time(NULL));

	if (argc != 3)
	{
		printf("Invalid arguments, format:\nlimitedVocabulary.exe dictionary.txt text.txt\n");
		exit(0);
	}

	//create new dictionary
	dictionary = (Leaf*)malloc(sizeof(Leaf));

	if (initLeaf(dictionary) == NULL)
	{
		printf("failed alloacte memory for dictionary!");
		exit(0);
	}

	//openning dictionary file:
	strcpy_s(fileNameDict, sizeof(fileNameDict), argv[1]);
	printf("%s\n", fileNameDict);
	fileDict = fopen(fileNameDict, "r");
	if (fileDict == NULL)
	{
		printf("failed open dictionary file!");
		exit(0);
	}

	//open text file
	strcpy_s(fileNameText, sizeof(fileNameText), argv[2]);
	printf("%s\n", fileNameText);
	fileText = fopen(fileNameText, "r");
	if (fileText == NULL)
	{
		printf("Failed to open text file!");
		//closing fileDict
		fclose(fileDict);
		exit(0);
	}

	//load the words from file.
	temp = LoadFileIntoDic(dictionary, fileDict);

	//close dictionary file, finished with it.
	fclose(fileDict);

	//check loadFileIntoDic result.
	if (temp == ERROR)
	{
		printf("dictionary file not in format (key:value)!");
	}
	else if (temp == SUCCESS)
	{
		replaceWordsInFile(dictionary, fileText);
	}
	else //FATAL_ERROR
	{
		printf("Couldn't open file, or malloc failed!");
	}

	killLeaf(dictionary);
	fclose(fileText);
	
	return 0;
}

void replaceWordsInFile(Leaf* dictionary, FILE* file)
{
	char word[WORD_MAX_SIZE];
	char *value = NULL, *offset = NULL, tempchar;
	int num = 0, count = 0, i = 0, isWordValid = 0;
	FILE* newFile;

	newFile = fopen(NEW_FILE_NAME, "w");

	if (dictionary == NULL || file == NULL || newFile == NULL) return;

	while (1)
	{
		isWordValid = fscanf_s(file, "%s", word, sizeof(word)); //need to be 1, if 0 there is problem
		
		//checking if word is valid 
		tempchar = word[0];
		i = 0;
		while (tempchar != '\0' && isWordValid == 1)
		{
			isWordValid = isalpha(word[i]);
			++i;
		}

		value = NULL;
		if (isWordValid)
		{
			value = getValue(dictionary, word);
		}
	
		if (value == NULL) //this word doesn't exists in the dictionary.
		{
			fputs(word, newFile);
		}
		else
		{
			//we may have multiple words in value so we will take a random word
			//counting the words:
			for (count = 1, i = 0; value[i]; ++i)
			{
				if (value[i] == ' ') //whitespace
				{
					++count;
				}
			}

			//make a random number
			num = (rand() % count) + 1;
			
			//offset to jump above what we read in the privious loops..
			offset = value;

			//taking the random word
			for (i = 0; i < num; ++i)
			{
				sscanf_s(offset, "%s", word, sizeof(word));
				offset += strlen(word) + 1;
			}

			//free the value
			free(value);

			//putting it in the new file
			fputs(word, newFile);
		}

		//checking the 
		tempchar = fgetc(file);
		if (tempchar == EOF) break;
		fputc(tempchar, newFile);
	}
}