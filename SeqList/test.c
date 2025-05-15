//≤‚ ‘
#include"SeqList.h"

void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPrint(&s);
	SeqListPushFront(&s, 4);
	SeqListPrint(&s);
	SeqListErase(&s, 4);
	SeqListPrint(&s);
	SeqListInsert(&s, 1, 9);
	SeqListPrint(&s);
	int x;
	x = removeElement(&s, 9);
	SeqListPrint(&s);
	printf("%d", x);
}


int main()
{
	TestSeqList1();
	return 0;
}
