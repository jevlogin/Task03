#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// ќпредел€ем максимальный размер массива
#define MaxN 100

//int count = 0;	//	счетчик

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
// –аспечатываем массив
void print(int N, int* a)
{
	for (int i = 0; i < N; i++)
	{
		printf("%6i", a[i]);
	}
	printf("\n\n");
}

//void CreateMassivA(int* a)
//{
//	srand(time(NULL));
//	for (int i = 0; i < MaxN; i++)
//	{
//		a[i] = rand() % 101;
//	}
//}


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "RUS");

	int a[MaxN]; // создаЄм массив максимального размера
	
	//	Ќаполнили массив случайными числами
	//CreateMassivA(a);
	//srand(time(NULL));
	for (int i = 0; i < MaxN; i++)
	{
		a[i] = rand() % 101;
	}

	puts("вывели массив на печать до сортировки");
	print(MaxN, a);	// вывели массив на печать до сортировки.

	//	Ќачинаем проверку
	int j = 0;


	puts("вывели массив на печать после сортировки.");
	print(MaxN, a);	 // вывели массив на печать после сортировки.

	//printf("”совершенствованна€ верси€. ѕродуктивность равна %i", count);
	return 0;
}