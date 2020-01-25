#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Main.h"
#define MaxN 100

int count = 0;

/*

	Логинов Евгений. 

1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной и не оптимизированной программы. 
Написать функции сортировки, которые возвращают количество операций.
2. *Реализовать шейкерную сортировку.
3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. Функция возвращает индекс найденного 
элемента или -1, если элемент не найден.
4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.
Достаточно решить 3 задачи. Записывайте в начало программы условие и свою фамилию. Все решения создавайте в одной программе. 
Задачи со звездочками выполняйте в том случае, если решили базовые. Снабдите программу меню.

*/
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");
	
	//	объявили массив
	int mas[MaxN];
	//	Наполнили массив псевдослучайными числами
	//	Кстати, правильно ли я создаю массив?
	CreateMas(&mas);
	puts("Печать до сортировки массива.\n");
	Print(mas);

	/*	временно скрываем
	SortBuble(mas);
	puts("Печать после сортировки массива.\n");
	Print(mas);
	*/

	/*
	SortBubleBest(mas);
	puts("Печать после сортировки массива.\n");
	Print(mas);
	*/

	

	SortSheker(mas);
	puts("Печать после шейкерной сортировки массива.\n");
	Print(mas);

	return (0);
}

void SortSheker(int* mas)
{
	int left = 0; 
	int right = MaxN - 1;	// сразу сделаем здесь - 1 для ситля
	int flag = 1;

	while ((left < right) && flag > 0)
	{
		flag = 0;
		//	двигаемся направо
		for (int i = left; i < right; i++)
		{
			if (mas[i] > mas[i + 1])
			{
				swap(&mas[i], &mas[i + 1]);
				flag++;
			}
		}
		right--;
		for (int i = right; i > left; i--)
		{
			if (mas[i-1] > mas[i])
			{
				swap(&mas[i - 1], &mas[i]);
				flag++;
			}
		}
		left--;
	}
}
void SortBubleBest(int* mas)
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


void SortBuble(int* mas)
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

void Print(int*  mas)
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
