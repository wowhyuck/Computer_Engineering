#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

#define SIZE 1000

int a[SIZE];

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int n, min, index;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	/* 선택 정렬 */
	//for (int i = 0; i < n; i++)
	//{
	//	min = INT_MAX;
	//	for (int j = i; j < n; j++)
	//	{
	//		if (min > a[j])
	//		{
	//			min = a[j];
	//			index = j;
	//		}
	//	}

	//	swap(&a[i], &a[index]);
	//}

	/* 삽입 정렬 */
	for (int i = 0; i < n - 1; i++)
	{
		int j = i;
		while (j >= 0 && a[j] > a[j + 1])
		{
			swap(&a[j], &a[j + 1]);
			j--;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	return 0;
}


