//数据结构的实现
#include "SeqList.h"

//初始化
void SeqListInit(SL* ps)
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
		exit(-1);
	ps->size = 0;
	ps->capacity = 4;
}

//顺序表打印
void SeqListPrint(SL* ps)
{
	assert(ps);//确保ps不为空，否则终止程序
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}printf("\n");
}

//尾插
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);//确保ps不为NULL否则终止程序
	//如果满了要增容
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}

	}
	ps->a[ps->size] = x;
	ps->size++;
}

//头插
void SeqListPushFront(SL* ps, SLDataType x) 
{
	assert(ps);
	if (ps->size >= ps->capacity)
	{

		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a,sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
	}
	for (int i = ps->size; i > 0;i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}

//尾删
void SeqListPopBack(SL* ps)
{
	assert(ps);
	ps->size--;
}
//void SeqListPopFront(SL* ps);

////任意位置的插入删除
//void SeqListInsert(SL* ps, int pos, SLDataType x);
//void SeqListErase(SL* ps, int pos);

