#include <stdio.h>
#include <malloc.h>

int *userArray;
int userArrayLen = 0;

int main()
{

	arrayInput();
	outputUserArray();

	finish();

	/*int max = 0;

	for (int i = 0; i < userArrayLength; i++)
	{
		userArray[i] = rand() % 5;
		printf("\t%d", userArray[i]);
	}
	printf("\n");

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
	FILE* file = NULL;
	char c;
	int txtArray[128];

	file = fopen("input.txt", "r");
	if (file == NULL)
	{
		printf("File not found");
		exit(0);
	}

	while (fscanf(file, "%c", &c) == 1)
	{
		fprintf(stdout, "%c", c);
		userArrayLen++;
	}
	printf("%d", userArrayLen);

	userArray = (int*)malloc(userArrayLen * sizeof(int));
	for (int i = 0; i < userArrayLen; i++)
	{
		fscanf(file, "%d", &userArray[i]);
	}

	fclose(file);
}

int outputUserArray(void)
{
	for (int i = 0; i < userArrayLen; i++)
	{
		printf("\t%d", userArray[i]);
	}
	printf("\n");
}

int finish(void)
{
	free(userArray);
}