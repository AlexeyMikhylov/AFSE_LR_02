#include <stdio.h>
#include <malloc.h>


FILE* file = NULL;
int *userArray, *maskArray;
int userArrayLength = 0;
int max = 0;

int main()
{
	arrayInput();
	outputUserArray();
	//sortArray();
	finish();
}

int arrayInput(void)
{
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
		printf("%d \n", d);
		userArrayLength++;
	}
	printf("\n");
	printf("%d\n", userArrayLength);

	printf("Original array:\n");
	userArray = (int*)malloc(userArrayLength * sizeof(int)); //выделяем память для массива, равное количеству чисел в файле
	for (int i = 0; i < userArrayLength; i++) //заполняем динамический массив числами из файла (ошибка тут)
	{
		fscanf(file, "%d", &userArray[i]); //why the bunch of fucking fucks???
	}
}

int outputUserArray(void) //вывод исходного массива
{
	for (int i = 0; i < userArrayLength; i++)
	{
		printf("\t%d", userArray[i]);
	}
	printf("\n");
}

int sortArray(void) //сортировка исходного массива
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

int finish(void) //освобождение памяти, завершение программы
{
	fclose(file);
	free(userArray);
	//free(maskArray);
	exit(0);
}