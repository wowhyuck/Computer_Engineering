#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TABLE_SIZE 10007
#define INPUT_SIZE 5000

// ���� ����� ����ü
typedef struct
{
	int id;
	char name[20];
} Student;

// �ؽ� ���̺��� �ʱ�ȭ�մϴ�.
//void init(Student** hashTable)
//{
//	for (int i = 0; i < TABLE_SIZE; i++)
//		hashTable[i] = NULL;
//}
//
//// �ؽ� ���̺��� �޸𸮸� ��ȯ�մϴ�.
//void destructor(Student** hashTable)
//{
//	for (int i = 0; i < TABLE_SIZE; i++)
//	{
//		if (hashTable[i] != NULL)
//			free(hashTable[i]);
//	}
//}
//
//// �ؽ� ���̺� �� �� ������ ���� Ž������ ã���ϴ�.
//int findEmpty(Student** hashTable, int id)
//{
//	int i = id % TABLE_SIZE;
//	while (1)
//	{
//		if (hashTable[i % TABLE_SIZE] == NULL)
//			return i % TABLE_SIZE;
//		i++;
//	}
//}
//
//// Ư���� ID ���� ��Ī�Ǵ� �����͸� �ؽ� ���̺� ������ ã���ϴ�.
//int search(Student** hashTable, int id)
//{
//	int i = id % TABLE_SIZE;
//	while (1)
//	{
//		if (hashTable[i % TABLE_SIZE] == NULL) return -1;
//		else if (hashTable[i % TABLE_SIZE]->id == id) return i;
//		i++;
//	}
//}
//
//// Ư���� Ű �ε����� �����͸� �����մϴ�.
//void add(Student** hashTable, Student* input, int key)
//{
//	hashTable[key] = input;
//}
//
//// �ؽ� ���̺��� Ư���� Ű�� �����͸� ��ȯ�մϴ�.
//Student* getValue(Student** hashTable, int key)
//{
//	return hashTable[key];
//}
//
//// �ؽ� ���̺� �����ϴ� ��� �����͸� ����մϴ�.
//void show(Student** hashTable)
//{
//	for (int i = 0; i < TABLE_SIZE; i++)
//	{
//		if (hashTable[i] != NULL)
//			printf("Ű: [%d] �̸�: [%s]\n", i, hashTable[i]->name);
//	}
//}

/*-------------------------------------------------------------------------*/

// ü�̴� ����ü ����
typedef struct
{
	Student* data;
	struct Bucket* next;
} Bucket;

// �ؽ� ���̺��� �ʱ�ȭ�մϴ�.
void init(Bucket** hashTable)
{
	for (int i = 0; i < TABLE_SIZE; i++)
		hashTable[i] = NULL;
}

// �ؽ� ���̺��� �޸𸮸� ��ȯ�մϴ�.
void destructor(Bucket** hashTable)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (hashTable[i] != NULL)
			free(hashTable[i]);
	}
}

int isExist(Bucket** hashTable, int id)
{
	int i = id % TABLE_SIZE;
	if (hashTable[i] == NULL) return 0;
	else
	{
		Bucket* cur = hashTable[i];
		while (cur != NULL)
		{
			if (cur->data->id == id) return 1;
			cur = cur->next;
		}
	}
	return 0;
}

// Ư���� Ű �ε����� �����͸� �����մϴ�.
void add(Bucket** hashTable, Student* input)
{
	int i = input->id & TABLE_SIZE;
	if (hashTable[i] == NULL)
	{
		hashTable[i] = (Bucket*)malloc(sizeof(Bucket));
		hashTable[i]->data = input;
		hashTable[i]->next = NULL;
	}
	else
	{
		Bucket* cur = (Bucket*)malloc(sizeof(Bucket));
		cur->data = input;
		cur->next = hashTable[i];
		hashTable[i] = cur;
	}
}

// �ؽ� ���̺� �����ϴ� ��� �����͸� ����մϴ�.
void show(Bucket** hashTable)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (hashTable[i] != NULL)
		{
			Bucket* cur = hashTable[i];
			while (cur != NULL)
			{
				printf("Ű: [%d] �̸�: [%s]\n", i, cur->data->name);
				cur = cur->next;
			}
		}
	}
}

int main()
{
	// ���� ����� ����ü
	//Student** hashTable;
	//hashTable = (Student**)malloc(sizeof(Student) * TABLE_SIZE);
	//init(hashTable);

	//for (int i = 0; i < INPUT_SIZE; i++)
	//{
	//	Student* student = (Student*)malloc(sizeof(Student));
	//	student->id = rand() % 1000000;
	//	sprintf(student->name, "���%d", student->id);

	//	if (search(hashTable, student->id) == -1)		// �ߺ��Ǵ� ID�� �������� �ʵ��� ��.
	//	{
	//		int index = findEmpty(hashTable, student->id);
	//		add(hashTable, student, index);
	//	}
	//}

	//show(hashTable);
	//destructor(hashTable);

	/*-------------------------------------------------------------------------*/

	// ü�̴� ����ü ����
	Bucket** hashTable;
	hashTable = (Bucket**)malloc(sizeof(Bucket) * TABLE_SIZE);
	init(hashTable);

	for (int i = 0; i < INPUT_SIZE; i++)
	{
		Student* student = (Student*)malloc(sizeof(Student));
		student->id = rand() & 1000000;
		sprintf(student->name, "���%d", student->id);

		if (isExist(hashTable, student->id))		// �ߺ��Ǵ� ID�� �������� �ʵ��� ��.
			add(hashTable, student);
	}

	show(hashTable);
	destructor(hashTable);

	return 0;
}
