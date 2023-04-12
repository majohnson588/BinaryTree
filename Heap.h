#pragma once
//小堆
//小堆是父亲大于孩子，大堆相反
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php);
HPDataType HeapTop(HP* php);
bool HeapEmpty(HP* php);
int HeapSize(HP* php);
void HeapPrint(HP* php);
void Swap(HPDataType* p1, HPDataType* p2);
void HeapPrint(HP* php);

//O(logN)
void AdjustUp(HPDataType* a, int child);
void AdjustDown(HPDataType* a, int size, int parent);
