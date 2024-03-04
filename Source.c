#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int *userArray, *maskArray;
int userArrayLength = 0;
int max = 0;

int main()
{
	arrayInput();
	outputUserArray();
	//sortArray();
	finish();

	return 0;
}

int arrayInput(void)
{

	FILE* file = NULL;
	int d;

	file = fopen("input.txt", "r"); //открываем файл для чтения
	if (file == NULL) //если файл возвращает NULL, т.е. файла нет
	{
		printf("File not found\n");
		exit(0);
	}

	while (!feof(file)) //пока не достигнут конец файла, считываем числа и считаем их колличество
	{
		fscanf(file, "%d", &d);
		printf("\t%d", d);
		userArrayLength++;
	}
	printf("\n");
	printf("array length: %d\n", userArrayLength);

	printf("\nOriginal array:\n");
	userArray = (int*)malloc(userArrayLength * sizeof(int)); //выделяем память для массива, равное количеству чисел в файле

	for (int i = 0; i < userArrayLength; i++) //заполняем динамический массив числами из файла (ошибка тут)
	{
		fscanf(file, "%d", &userArray[i]);
	}
	printf("\n");

	fclose(file);
}

//вывод исходного массива
int outputUserArray(void) 
{
	for (int i = 0; i < userArrayLength; i++)
	{
		printf("\t%d", userArray[i]);
	}
	printf("\n");
}

//сортировка исходного массива
int sortArray(void) 
{
	max = userArray[0];
	for (int i = 0; i < userArrayLength; i++)
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
}

//освобождение памяти, завершение программы
int finish(void) 
{
	free(userArray);
	//free(maskArray);
	exit(0);
}