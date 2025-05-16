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

//����˳���
void SeqListDestory(SL* ps)
{
	free(ps->a);//��ָ����ָ��Ŀռ���ͷŵ�
	ps->a = NULL;//��ֹҰָ��
	ps->size = ps->capacity = 0;
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

//����Ƿ���Ҫ����
void SeqListCheckSize(SL* ps)
{
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
}



//β��
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);//ȷ��ps��ΪNULL������ֹ����
	//�������Ҫ����
	SeqListCheckSize(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//ͷ��
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

//βɾ
void SeqListPopBack(SL* ps)
{
	assert(ps);
	ps->size--;
}

//ͷɾ
void SeqListPopFront(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

//����λ�õĲ���
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	SeqListCheckSize(ps);
	if (pos < 0 || pos > ps->size)
	{
		printf("�������");
		exit(-1);
	}
	for (int i = ps->size; i >= pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos - 1] = x;
	ps->size++;
}

//����λ�õ�ɾ��
void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	if (pos<0 || pos > ps->size)
	{
		printf("ɾ������");
		exit(-1);
	}
	for (int i = pos - 1;i <= ps->size - 1;i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

//�Ƴ������е�Ԫ��
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