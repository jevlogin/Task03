#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "OtherMain.h"
#define MaxN 100



int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");
	
	//	объявили массив
	int mas[MaxN];
	//	Наполнили массив псевдослучайными числами
	CreateMas(&mas);
	puts("Печать до сортировки массива.\n");
	Print(mas);

	/*	временно скрываем
	SortBuble(mas);
	puts("Печать после сортировки массива.\n");
	Print(mas);
	*/

	//	пробуем новую сортировку
	SortBubleBest(mas);
	puts("Печать после сортировки массива.\n");
	Print(mas);

	

	return (0);
}
void SortBubleBest(int mas[100])
{
	for (int i = 0; i < MaxN; i++)
	{
		for (int j = 0; j < MaxN - i - 1; j++)	//	"j < MaxN - i - 1" <== Это и есть главный секрет ))
		{
			//	Так как мы ставим максимальное число на последнее место, нам больше не надо его проверять, и так с каждым циклом )) минус одна позиция...
			if (mas[j] > mas[j + 1])
			{
				swap(&mas[j], &mas[j + 1]);
			}
		}
	}
}


void SortBuble(int mas[100])
{
	for (int i = 0; i < MaxN; i++)
	{
		for (int j = 0; j < MaxN - 1; j++)
		{
			if (mas[j] > mas[j + 1])
			{
				swap(&mas[j], &mas[j + 1]);
			}
		}
	}
}

void Print(int  mas[100])
{
	for (int i = 0; i < MaxN; i++)
	{
		printf("mas[%i] = %i\t", i, mas[i]);
		if (i % 5 == 0)
		{
			printf("\n");
		}
	}
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void CreateMas(int*  mas)
{
	//	пока не понял что это такое...
	srand(time(NULL));
	for (int i = 0; i < MaxN; i++)
	{
		mas[i] = rand() % 101;
	}
}
