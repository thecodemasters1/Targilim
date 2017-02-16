#include <stdio.h>
#include <ctype.h>
#include "queue.h"

#define WRONG_ARGS -1;
#define CANNOT_OPEN_INPUT -2
#define CANNOT_CLOSE_INPUT -3
#define CANNOT_OPEN_OUTPUT -4
#define CANNOT_CLOSE_OUTPUT -5
#define FILL_DICT_ERROR -6
#define DUPE_MEMORY -7

#define MAX_VOCA_LINE 128
#define MAX_VOCA_WORDS 32

Queue * fillDict(FILE * vocaFile, int size);
int get_amount_of_lines(FILE * file);
char * analyzeWord(char * word, Queue * dict, Queue * originalDict, int length);
void fputword(char * word, FILE * output);

int main(int argc, char * argv[])
{
	if (argc < 3)
	{
		printf("\nWrong Arguments!\n");
		printf("Usage: Voca.exe input.txt voca.txt\n");
		return WRONG_ARGS;
	}

	FILE * vocaFile = fopen(argv[2], "r+");

	if (vocaFile == NULL)
	{
		printf("Cant open input file.");
		return CANNOT_OPEN_INPUT;
	}

	int nLines = get_amount_of_lines(vocaFile);
	Queue * dict = fillDict(vocaFile, nLines);

	if(dict == NULL)
	{
		return FILL_DICT_ERROR;
	}

	//Duplicate Dict
	Queue * originalDict = NULL;
	originalDict = (Queue *)malloc(sizeof(Queue) * nLines);

	if (originalDict == NULL)
	{
		printf("No Memory, Duplicate Dict!!!");
		return DUPE_MEMORY;
	}

	for (int i = 0; i < nLines; i++)
	{
		originalDict[i] = *duplicateQueue(dict[i]);
	}

	print_queue(originalDict[1]);
	
	FILE * input = fopen(argv[1], "r+");

	if (input == NULL)
	{
		printf("Cant open input file.");
		return CANNOT_OPEN_INPUT;
	}

	FILE * output = fopen("output.txt", "w");

	if (output == NULL)
	{
		printf("Cant open output file.");
		return CANNOT_OPEN_OUTPUT;
	}

	char c;
	unsigned index = 0;
	char buffer[MAX_WORD_LEN];
	memset(buffer, 0, sizeof(buffer));
	
	while ((c = fgetc(input)))
	{
		if(c == EOF || isspace(c))
		{
			char * altWord = analyzeWord(buffer, dict, originalDict, nLines);
			if (altWord != NULL)
			{
				printf("Replacing %s with %s\n", buffer, altWord);
				int wordLength = strlen(buffer);
				fputword(altWord, output);
			}
			else
			{
				fputword(buffer, output);
			}
			memset(buffer, 0, sizeof(buffer));
			index = 0;
			if (c == EOF)
			{
				break;
			}
			else
			{
				fputc(c, output);
			}
		}
		else
		{
			buffer[index] = c;
			index++;
		}
	}
	

	for (int i = 0; i < nLines; i++)
	{
		deleteQueue(&dict[i]);
		//free(&dict[i]); //Crashing for some reason
	}

	free(dict);

	
	if(fclose(input) != 0)
	{
		printf("Could not close input file\n");
		return CANNOT_CLOSE_INPUT;
	}
	
	return 0;
}

void fputword(char * word, FILE * output)
{
	int length = strlen(word);
	for (int i = 0; i < length; i++)
	{
		fputc(word[i], output);
	}
}

char * analyzeWord(char * word, Queue * dict, Queue * originalDict, int length)
{
	unsigned i = 0;
	for (i = 0; i < length; ++i)
	{
		if(is_in_queue(originalDict[i], word) == 1 && get_queue_length(dict[i]) > 0)
		{
			char * alt = (char *)pop(&dict[i]);
			if (strcmp(alt, word) == 0) //Same Word
			{
				add_to_queue(&dict[i], (void *)alt); //Add same word to the last place in queue
				if (get_queue_length(dict[i]) > 1) //If another word in the dict, get it
				{
					alt = (char *)pop(&dict[i]);
				}
			}

			return alt;

		}
	}
	return NULL;
}

Queue * fillDict(FILE * vocaFile, int size)
{	
	Queue * dict = NULL;
	dict = (Queue *)malloc(sizeof(Queue) * size);
	if (dict == NULL)
	{
		printf("No Memory, Dict!!!");
		return NULL;
	}

	char line[MAX_VOCA_LINE];

	unsigned lineIndex = 0;
	unsigned bufferIndex = 0;
	unsigned dictIndex = 0;
	while(fgets(line, sizeof(line), vocaFile) != NULL)
	{
		char buffer[MAX_WORD_LEN];
		lineIndex = 0;
		bufferIndex = 0;
		memset(buffer, 0, sizeof(buffer));
		dict[dictIndex] = initQueue();
		int lineLength = strlen(line);
		for (lineIndex = 0; lineIndex < lineLength; ++lineIndex)
		{
			char c = line[lineIndex];
			if (c == ',' || c == '\n' || lineIndex == lineLength-1)
			{
				//Word detected
				//Duplicate buffer to new string pointer
				char * realValue = NULL;
				realValue = malloc(sizeof(char) * MAX_WORD_LEN);

				if (realValue == NULL)
				{
					printf("No Memory, Buffer!!!");
					return NULL;
				}
				
				strcpy(realValue, buffer);

				//Add buffer to queue
				add_to_queue(&dict[dictIndex], (void *)realValue);
				bufferIndex = 0;
				memset(buffer, 0, sizeof(buffer));
			}
			else
			{
				buffer[bufferIndex] = c;
				bufferIndex++;
			}
		}
		dictIndex++;
	}

	if(fclose(vocaFile) != 0)
	{
		printf("Could not close voca file\n");
		return NULL;
	}

	return dict;
}

int get_amount_of_lines(FILE * file)
{
	char c;
	int amount = 1;
	while (EOF != (c = fgetc(file)))
	{
		if(c == '\n')
		{
			amount++;
		}
	}
	fseek(file, 0, SEEK_SET);
	return amount;
}