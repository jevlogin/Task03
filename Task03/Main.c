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

*/
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");
	
	//	объявили массив с размером MaxN
	int mas[MaxN];

	Menu(mas);

	return (0);
}

void Menu(int* mas)
{
	int solution;

	CreateMas(mas);
	puts("Печать до сортировки массива.\n");
	Print(mas);

	do
	{
		printf("Какое задание выполнить?\n");
		printf("1 - сортировка пузырьком\n");
		printf("2 - улучшенная сортировка пузырьком\n");
		printf("3 - Шейкерная сортировка\n");
		printf("4 - Бинарный поиск! (Возможен только после сортировки!)\nДля выхода введите 0\n");

		scanf("%d", &solution);
		switch (solution)
		{
		case 1:
			SortBuble(mas);
			puts("Печать после сортировки массива.\n");
			Print(mas);
			break;
		case 2:
			SortBubleBest(mas);
			puts("Печать после сортировки массива.\n");
			Print(mas);
			break;
		case 3:
			SortSheker(mas);
			puts("Печать после шейкерной сортировки массива.\n");
			Print(mas);
			break;
		case 4:
			BinnarySearch(mas);
			break;
		case 0:
			printf("Вы выбрали вход");
			break;
		default:
			printf("Вы ничего не выбрали");
			break;
		}
	} while (solution != 0);
	
}
void BinnarySearch(int* mas)
{
	int searchValue;
	int left = 0, right = MaxN - 1;	// указываем индексы элементов
	int middle;

	printf("Введите искомое число: ");
	scanf("%d", &searchValue);

	middle = left + (right - left) / 2;

	while (left < right && mas[middle] != searchValue)
	{
		if (mas[middle] <= searchValue)
		{
			left = middle + 1;
		}
		else
		{
			right = middle - 1;
		}
		middle = left + (right - left) / 2;
	}

	if (mas[middle] == searchValue)
	{
		printf("Значение %i найдено под индексом %i\n", searchValue, middle);
	}

	else
	{
		printf("Значение %i не найдено\n", searchValue);
	}
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
		//	двигаемся справа налево
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
	printf("\n\n");
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
