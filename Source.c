#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define MAX_SIZE 128

int userArray[MAX_SIZE];
int max = 0, min = 0, size = 0;
int* maskArrayPos;
int* maskArrayNeg;

int main()
{
	arrayInput();
	outputUserArray();
	sortArray();
	finish();
}

int arrayInput(void)
{
	FILE* file = fopen("input.txt", "r");

	if (file != NULL)
	{
		while (fscanf(file, "%d", &userArray[size]) == 1 && size < MAX_SIZE) {
			size++;
		}
		fclose(file);
	}
	else 
	{
		printf("error opening file.\n");
	}
}

int outputUserArray(void) 
{
	printf("Original array:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d  ", userArray[i]);
	}
	printf("\n");
}

int sortArray(void) 
{
	max = userArray[0];
	min = userArray[0];
	for (int i = 0; i < size; i++)
	{
		if (max < userArray[i])
		{
			max = userArray[i];
		}
	}
	max++;

	maskArrayPos = (int*)malloc(max * sizeof(int));

	maskArrayNeg = (int*)malloc(max * sizeof(int));

	for (int i = 0; i < max; i++)
	{
		maskArrayPos[i] = 0;
		maskArrayNeg[i] = 0;
	}

	printf("\n");
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == userArray[j])
			{
				maskArrayPos[i] += 1;
			}
		}
	}

	printf("\n");
	for (int i = 1; i < max; i++)
	{
		for (int j = 1; j < size; j++)
		{
			if ((- 1 * i) == userArray[j])
			{
				maskArrayNeg[i] += 1;
			}
		}
	}

	printf("Sorted array:\n");
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < maskArrayNeg[i]; j++)
		{
			printf("%d  ", -i);
		}
	}

	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < maskArrayPos[i]; j++)
		{
			printf("%d  ", i);
		}
	}
	printf("\n");
}

int finish(void) 
{
	free(maskArrayPos);
}