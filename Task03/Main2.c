#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// ���������� ������������ ������ �������
#define MaxN 100

//int count = 0;	//	�������

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
// ������������� ������
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

	int a[MaxN]; // ������ ������ ������������� �������
	
	//	��������� ������ ���������� �������
	//CreateMassivA(a);
	//srand(time(NULL));
	for (int i = 0; i < MaxN; i++)
	{
		a[i] = rand() % 101;
	}

	puts("������ ������ �� ������ �� ����������");
	print(MaxN, a);	// ������ ������ �� ������ �� ����������.

	//	�������� ��������
	int j = 0;


	puts("������ ������ �� ������ ����� ����������.");
	print(MaxN, a);	 // ������ ������ �� ������ ����� ����������.

	//printf("������������������� ������. �������������� ����� %i", count);
	return 0;
}