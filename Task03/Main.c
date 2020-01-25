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

*/
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");
	
	//	�������� ������ � �������� MaxN
	int mas[MaxN];

	Menu(mas);

	return (0);
}

void Menu(int* mas)
{
	int solution;

	CreateMas(mas);
	puts("������ �� ���������� �������.\n");
	Print(mas);

	do
	{
		printf("����� ������� ���������?\n");
		printf("1 - ���������� ���������\n");
		printf("2 - ���������� ���������� ���������\n");
		printf("3 - ��������� ����������\n");
		printf("4 - �������� �����! (�������� ������ ����� ����������!)\n��� ������ ������� 0\n");

		scanf("%d", &solution);
		switch (solution)
		{
		case 1:
			SortBuble(mas);
			puts("������ ����� ���������� �������.\n");
			Print(mas);
			break;
		case 2:
			SortBubleBest(mas);
			puts("������ ����� ���������� �������.\n");
			Print(mas);
			break;
		case 3:
			SortSheker(mas);
			puts("������ ����� ��������� ���������� �������.\n");
			Print(mas);
			break;
		case 4:
			BinnarySearch(mas);
			break;
		case 0:
			printf("�� ������� ����");
			break;
		default:
			printf("�� ������ �� �������");
			break;
		}
	} while (solution != 0);
	
}
void BinnarySearch(int* mas)
{
	int searchValue;
	int left = 0, right = MaxN - 1;	// ��������� ������� ���������
	int middle;

	printf("������� ������� �����: ");
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
		printf("�������� %i ������� ��� �������� %i\n", searchValue, middle);
	}

	else
	{
		printf("�������� %i �� �������\n", searchValue);
	}
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
		//	��������� ������ ������
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
	//	���� �� ����� ��� ��� �����...
	srand(time(NULL));
	for (int i = 0; i < MaxN; i++)
	{
		mas[i] = rand() % 101;
	}
}
