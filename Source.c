#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define MAX_SIZE 128 // Максимальный размер массива

int *maskArray;
int userArray[MAX_SIZE], userArrayLength = 0;
int max = 0, size = 0;

int main()
{
	arrayInput();
	outputUserArray();
	sortArray();
	finish();

	return 0;
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
	else {
		printf("error opening file.\n");
	}
}

//вывод исходного массива
int outputUserArray(void) 
{
	printf("Original array:\n");
	for (int i = 0; i < size; i++)
	{
		printf("\t%d", userArray[i]);
	}
	printf("\n");

	return 0;
}

//сортировка исходного массива
int sortArray(void) 
{
	max = userArray[0];
	for (int i = 0; i < size; i++)
	{
		if (max < userArray[i])
		{
			max = userArray[i];
		}
	}
	max++;

	maskArray = (int*)malloc(max * sizeof(int));

	for (int i = 0; i < max; i++)
	{
		maskArray[i] = 0;
	}

	printf("\n");
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == userArray[j])
			{
				maskArray[i] += 1;
			}
		}
	}

	printf("Sorted array:\n");
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < maskArray[i]; j++)
		{
			printf("\t%d", i);
		}
	}
	printf("\n");
}

int finish(void) 
{
	free(maskArray);
	exit(0);
}