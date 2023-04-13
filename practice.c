Top-K排序，一般情况下数据量比较大
时间复杂度O(K+(N-K)*logK)

void PrintTopK(int* a, int n, int k)
{
	//1、建堆-用a中前k个元素建小堆
	int* KMinHeap = (int*)malloc(sizeof(int) * k);
	assert(KMinHeap);
	for (int i = 0; i < k; ++i)
	{
		KMinHeap[i] = a[i];
	}
	for (int i = (k - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(KMinHeap, k, i);
	}

	//2、将剩余n-k个元素依次与堆顶元素交换
	for (int j = k; j < n; ++j)
	{
		if (a[j] > KMinHeap[0])
		{
			KMinHeap[0] = a[j];
			AdjustDown(KMinHeap, k, 0);
		}
	}

	for (int i = 0; i < k; ++i)
	{
		printf("%d ", KMinHeap[i]);
	}
	printf("\n");
}

void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 1000000;
	}

	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[120] = 1000000 + 5;
	a[99] = 1000000 + 6;
	a[0] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
}
