#include <stdio.h>
#include <malloc.h>


FILE* file = NULL;
int *userArray;
int userArrayLen = 0;
int maxElement = 0;

int main()
{
	arrayInput();
	outputUserArray();

	finish();
	
	/*

	max = userArray[0];
	for (int i = 0; i < userArrayLength; i++)
	{
		if (max < userArray[i])
		{
			max = userArray[i];
		}
	}

	max++;

	int *maskArray;
	maskArray = (int*)malloc(max * sizeof(int));

	for (int i = 0; i < max; i++)
	{
		maskArray[i] = 0;
	}
	printf("\n");

	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < userArrayLength; j++)
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

	free(maskArray);*/
}

int arrayInput(void)
{
	char c;

	file = fopen("input.txt", "r");
	if (file == NULL)
	{
		printf("File not found\n");
		exit(0);
	}

	while (fscanf(file, "%c", &c) == 1)
	{
		fprintf(stdout, "%c", c);
		userArrayLen += 1;
	}
	printf("\n");
	//printf("\n%d\n", userArrayLen);

	userArrayLen /= 2;
	userArray = (int*)malloc(userArrayLen * sizeof(int));
	printf("Original array:\n");
	for (int i = 0; i < userArrayLen; i++)
	{
		fscanf(file, "%d", &userArray[i]); //why the bunch of fucking fucks???
	}
}

int outputUserArray(void)
{
	for (int i = 0; i < userArrayLen; i++)
	{
		printf("\t%d", userArray[i]);
	}
	printf("\n");
}

int sortArray(void)
{

}

int finish(void)
{
	fclose(file);
	free(userArray);
}