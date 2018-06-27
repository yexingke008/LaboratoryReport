// LaboratoryReport.cpp : �������̨Ӧ�ó������ڵ㡣
//

//1������n�����������ʵ�����򣬲�����������С�
//��1������Ҫ��
//��д˳������ɺ����洢���������У���д��������������������������е�������������ʵ�ֶ��������������
//��2���㷨����
//�ο��̲ĵ�10���㷨��
//��3���㷨ʵ��


//���ļ�
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "stdafx.h"
#include <iostream>  

#pragma warning(disable:4996)
using namespace std;

//����ͷ�ļ�
typedef struct list
{
	int array[100];
	int size;
}SqList;

void create(SqList *l)//�������������еĴ洢�ṹ
{
	int i;
	printf("������˳���ı�������(��������)�ĸ�����\n");
	scanf("%d", &l->size);
	printf("������˳��������\n");
	for (i = 1; i < l->size + 1; i++)
		scanf("%d", &l->array[i]);
}


void insertSort(SqList *l)
{
	int i, j;
	for (i = 1; i <= l->size; i++) {
		l->array[0] = l->array[i]; j = i - 1;
		while (l->array[0] < l->array[j]) {


			l->array[j + 1] = l->array[j];
			j = j - 1;
		}
		l->array[j + 1] = l->array[0];
	}
}

void selectSort(SqList *l)
{
	int i, j, small, temp;
	for (i = 0; i < l->size - 1; i++)
	{
		small = i;
		for (j = i + 1; j <= l->size; j++)
			if (l->array[j] < l->array[small])
				small = j;
		if (small != i) {
			temp = l->array[i];
			l->array[i] = l->array[small];
			l->array[small] = temp;
		}
	}
}

void bubbleSort(SqList *l) 
{
	int i, j,temp;
	for (i = 1; i < l->size; i++) {

		for (j = 1; j < l->size; j++)
		{
			if (l->array[j] > l->array[j + 1])
			{
				temp = l->array[j];
				l->array[j] = l->array[j + 1];
				l->array[j + 1] = temp;
			}
		}
	}
}

void display(SqList *l)//��ʾ������
{
	int i;
	for (i = 1; i < l->size + 1; i++)
		printf("%d\t", l->array[i]);
	printf("\n");
}

void main()
{
	printf("\n==========��һ�����򷽷�\n");
	SqList *L;
	L = (SqList *)malloc(sizeof(SqList));
	create(L);
	selectSort(L);
	display(L);
	
	printf("\n==========�ڶ������򷽷�\n");
	SqList *L2;
	L2 = (SqList *)malloc(sizeof(SqList));
	create(L2);
	bubbleSort(L2);
	display(L2);

	system("pause");
}
