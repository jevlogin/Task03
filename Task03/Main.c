#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Main.h"
#define MaxN 100

int count = 0;

/*

	������� �������. 

1. ����������� �������������� ����������� ����������. �������� ���������� �������� ��������� ���������������� � �� ���������������� ���������. 
�������� ������� ����������, ������� ���������� ���������� ��������.
2. *����������� ��������� ����������.
3. ����������� �������� �������� ������ � ���� �������, ������� ���������� ��������������� ������. ������� ���������� ������ ���������� 
�������� ��� -1, ���� ������� �� ������.
4. *���������� ���������� �������� ��� ������ �� ���������� � �������� ��� � ��������������� ���������� ���������.
���������� ������ 3 ������. ����������� � ������ ��������� ������� � ���� �������. ��� ������� ���������� � ����� ���������. 
������ �� ����������� ���������� � ��� ������, ���� ������ �������. �������� ��������� ����.

*/
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");
	
	//	�������� ������
	int mas[MaxN];
	//	��������� ������ ���������������� �������
	//	������, ��������� �� � ������ ������?
	CreateMas(&mas);
	puts("������ �� ���������� �������.\n");
	Print(mas);

	/*	�������� ��������
	SortBuble(mas);
	puts("������ ����� ���������� �������.\n");
	Print(mas);
	*/

	/*
	SortBubleBest(mas);
	puts("������ ����� ���������� �������.\n");
	Print(mas);
	*/

	

	SortSheker(mas);
	puts("������ ����� ��������� ���������� �������.\n");
	Print(mas);

	return (0);
}

void SortSheker(int* mas)
{
	int left = 0; 
	int right = MaxN - 1;	// ����� ������� ����� - 1 ��� �����
	int flag = 1;

	while ((left < right) && flag > 0)
	{
		flag = 0;
		//	��������� �������
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
		for (int j = 0; j < MaxN - i - 1; j++)	//	"j < MaxN - i - 1" <== ��� � ���� ������� ������ ))
		{
			//	��� ��� �� ������ ������������ ����� �� ��������� �����, ��� ������ �� ���� ��� ���������, � ��� � ������ ������ )) ����� ���� �������...
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
	//	���� �� ����� ��� ��� �����...
	srand(time(NULL));
	for (int i = 0; i < MaxN; i++)
	{
		mas[i] = rand() % 101;
	}
}
