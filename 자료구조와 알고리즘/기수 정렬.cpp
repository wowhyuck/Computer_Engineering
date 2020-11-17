#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000

void radixSort(int* a, int n)
{
	int res[MAX], maxValue = 0;
	int exp = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > maxValue) maxValue = a[i];
	}

	while (maxValue / exp > 0)		// 1�� �ڸ����� ���
	{
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++)
			bucket[a[i] / exp % 10]++;		// �ڸ��� �迭 ó��

		for (int i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];		// ���� ���

		for (int i = n - 1; i >= 0; i--)
			res[--bucket[a[i] / exp % 10]] = a[i];		// ���� �ڸ��� ������ ������ ����

		for (int i = 0; i < n; i++)
			a[i] = res[i];				// �⺻ �迭 ����

		exp *= 10;
	}
}


int main()
{
	int a[MAX];
	int i, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	radixSort(a, n);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	return 0;
}