#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 무방향 비가중치 그래프
//int a[1001][1001];
//int n, m;
//
//int main()
//{
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < m; i++)
//	{
//		int x, y;
//		scanf("%d %d", &x, &y);
//		a[x][y] = 1;
//		a[y][x] = 1;
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//			printf("%d ", a[i][j]);
//		printf("\n");
//	}
//
//	return 0;
//}

/*----------------------------------------------------*/

// 방향 가중치 그래프
typedef struct
{
	int index;
	int distance;
	struct Node* next;
} Node;

void addFront(Node* root, int index, int distance)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->distance = distance;
	node->next = root->next;
	root->next = node;
}

void showAll(Node* root)
{
	Node* cur = root->next;
	while (cur != NULL)
	{
		printf("%d(거리: %d) ", cur->index, cur->distance);
		cur = cur->next;
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	Node** a = (Node**)malloc(sizeof(Node*) * (n + 1));
	for (int i = 1; i <= n; i++)
	{
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->next = NULL;
	}

	for (int i = 0; i < m; i++)
	{
		int x, y, distance;
		scanf("%d %d %d", &x, &y, &distance);
		addFront(a[x], y, distance);
	}

	for (int i = 1; i <= n; i++)
	{
		printf("원소 [%d]: ", i);
		showAll(a[i]);
		printf("\n");
	}

	return 0;
}