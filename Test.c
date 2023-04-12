#include "Heap.h"

void TestHeap()
{
	HP hp;
	HeapPrint(&hp);

	HeapPush(&hp, 10);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);
}

//升序建大堆，降序建小堆
void HeapSort(int* a, int n)
{
    //建堆方式1：O(N*logN)
	//for (int i = 0; i < n; ++i)
	//{
	//	AdjustUp(a, i);
	//}

	//建堆方式2：O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	//O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

void TestHeapSort()
{
	//升序打印 - 小堆
	//降序打印 - 大堆
	HP hp;
	HeapInit(&hp);
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		HeapPush(&hp, a[i]);
	}

	while (!HeapEmpty(&hp))
	{
		printf("%d",HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");

	HeapSort(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestHeap();

	return 0;
}
