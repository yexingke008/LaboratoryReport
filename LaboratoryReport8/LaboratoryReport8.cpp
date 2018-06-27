// LaboratoryReport.cpp : 定义控制台应用程序的入口点。
//

//1、输入n个整数，编程实现排序，并输出排序序列。
//（1）基本要求
//编写顺序表生成函数存储待排序序列，编写排序函数和输出函数。在主函数中调用上述函数，实现对输入的序列排序。
//（2）算法描述
//参考教材第10章算法。
//（3）算法实现


//主文件
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "stdafx.h"
#include <iostream>  

#pragma warning(disable:4996)
using namespace std;

//定义头文件
typedef struct list
{
	int array[100];
	int size;
}SqList;

void create(SqList *l)//创建待排序序列的存储结构
{
	int i;
	printf("请输入顺序表的表长即数据(整形数据)的个数：\n");
	scanf("%d", &l->size);
	printf("请输入顺序表的数据\n");
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

void display(SqList *l)//显示排序结果
{
	int i;
	for (i = 1; i < l->size + 1; i++)
		printf("%d\t", l->array[i]);
	printf("\n");
}

void main()
{
	printf("\n==========第一种排序方法\n");
	SqList *L;
	L = (SqList *)malloc(sizeof(SqList));
	create(L);
	selectSort(L);
	display(L);
	
	printf("\n==========第二种排序方法\n");
	SqList *L2;
	L2 = (SqList *)malloc(sizeof(SqList));
	create(L2);
	bubbleSort(L2);
	display(L2);

	system("pause");
}
