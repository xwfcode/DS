//������ݽṹ������
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

//��ʼ��
void SeqListInit(SL* ps);

//˳����ӡ
void SeqListPrint(SL* ps);

//����Ƿ���Ҫ����
void SeqListCheckSize(SL* ps);

//β��ͷ�壬��βɾͷɾ
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);

////����λ�õĲ���ɾ��
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);

//�Ƴ�����Ԫ��
int removeElement(SL* ps, int val);