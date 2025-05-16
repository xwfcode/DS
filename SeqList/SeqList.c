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

//销毁顺序表
void SeqListDestory(SL* ps)
{
	free(ps->a);//给指针所指向的空间给释放掉
	ps->a = NULL;//防止野指针
	ps->size = ps->capacity = 0;
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

//检查是否需要扩容
void SeqListCheckSize(SL* ps)
{
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
}



//尾插
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);//确保ps不为NULL否则终止程序
	//如果满了要增容
	SeqListCheckSize(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//头插
void SeqListPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SeqListCheckSize(ps);
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

//头删
void SeqListPopFront(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

//任意位置的插入
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	SeqListCheckSize(ps);
	if (pos < 0 || pos > ps->size)
	{
		printf("插入出错！");
		exit(-1);
	}
	for (int i = ps->size; i >= pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos - 1] = x;
	ps->size++;
}

//任意位置的删除
void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	if (pos<0 || pos > ps->size)
	{
		printf("删除错误！");
		exit(-1);
	}
	for (int i = pos - 1;i <= ps->size - 1;i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

//移除数组中的元素
int removeElement(SL* ps, int val)
{
	int i = 0;
	int j = 0;
	int sum = 0;
	while (i < ps->size)
	{
		j = i;
		if (ps->a[i] != val)
		{
			i++;
			j++;
		}
		while (ps->a[i] == val)
		{
			i++;
			sum++;
		}
		while (i < ps->size && ps->a[i] != val)
		{
			ps->a[j] = ps->a[i];
			j++;i++;
		}
	}
	ps->size = ps->size - sum;
	return ps->size;
}