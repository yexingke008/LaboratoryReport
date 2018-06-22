// LaboratoryReport.cpp : 定义控制台应用程序的入口点。
//

//1、查找算法
//（1）基本要求
//数据元素采用顺序表存储。输入n个数据元素，给定待查值key，编程实现顺序查找和二分查找。
//（2）算法描述
//参考教材第9章算法。
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

void create(SqList *l)//创建n个数据元素的顺序表
{
	int i;
	printf("请输入顺序表的表长即数据(整形数据)的个数：\n");
	scanf("%d", &l->size);
	printf("请输入顺序表的数据\n");
	for (i = 1; i < l->size + 1; i++)
		scanf("%d", &l->array[i]);
}

void seqSearch(SqList *l, int key)//顺序查找
{
	int i;
	for (i = 1; i <= l->size; i++)
	{
		if (l->array[i] == key)
		{
			printf("已查到该查到该下标[下标从1计数]为：  %d" ,i);   
			return;
		}
	}
	printf("未查到此数据");
}

void binSearch(SqList *l, int key)//折半查找
{
	int low, mid, high;
	low = 0;
	high = l->size;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (l->array[mid] == key)
		{
			printf("已查到该查到该下标[下标从1计数]为：  %d" , mid); //返回下坐标，查找成功  
			return;
		}
		else if (l->array[mid] > key)
			high = mid - 1;//左区间查找  
		else
			low = mid + 1;//右区间查找  
	}
	printf("未查到此数据");
}


void main()
{
	SqList *L;
	int num;
	L = (SqList *)malloc(sizeof(SqList));
	create(L);

	printf("请输入要查找的数据\n");
	scanf("%d", &num);
	
	printf("\n==========顺序查找\n");
	seqSearch(L, num);
	
	printf("\n\n==========折半查找\n");
	binSearch(L, num);
	printf("\n\n");
	system("pause");
}





