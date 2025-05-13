//≤‚ ‘
#include"SeqList.h"

void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPrint(&s);
	SeqListPushFront(&s, 6);
	SeqListPrint(&s);
}


int main()
{
	TestSeqList1();
	return 0;
}
