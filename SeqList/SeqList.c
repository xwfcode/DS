//���ݽṹ��ʵ��
#include "SeqList.h"

//��ʼ��
void SeqListInit(SL* ps)
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
		exit(-1);
	ps->size = 0;
	ps->capacity = 4;
}

//˳����ӡ
void SeqListPrint(SL* ps)
{
	assert(ps);//ȷ��ps��Ϊ�գ�������ֹ����
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}printf("\n");
}

//β��
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);//ȷ��ps��ΪNULL������ֹ����
	//�������Ҫ����
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
		}

	}
	ps->a[ps->size] = x;
	ps->size++;
}

//ͷ��
void SeqListPushFront(SL* ps, SLDataType x) 
{
	assert(ps);
	if (ps->size >= ps->capacity)
	{

		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a,sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("����ʧ��\n");
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

//βɾ
void SeqListPopBack(SL* ps)
{
	assert(ps);
	ps->size--;
}
//void SeqListPopFront(SL* ps);

////����λ�õĲ���ɾ��
//void SeqListInsert(SL* ps, int pos, SLDataType x);
//void SeqListErase(SL* ps, int pos);

