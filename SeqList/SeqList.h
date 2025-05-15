//存放数据结构的声明
#pragma once
#include<stdio.h>
#include "stdlib.h"
#include "assert.h"
typedef int SLDataType;
#define N 10

typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL, SeqList;

//初始化
void SeqListInit(SL* ps);

//顺序表打印
void SeqListPrint(SL* ps);

//检查是否需要扩容
void SeqListCheckSize(SL* ps);

//尾插头插，，尾删头删
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);

////任意位置的插入删除
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);

//移除数组元素
int removeElement(SL* ps, int val);