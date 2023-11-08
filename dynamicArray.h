#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FAIL		0
#define SUCCEED		!FAIL

#define CAPACITY_CHECK(P)	if (p->size == p->capacity || (p->size == (p->capacity - 1))) \
									if (!changeCapacity(p, p->size * 2))  \
											return FAIL;

typedef struct{
	int* startingPoint;
	size_t size;
	size_t capacity;
}dynamicArray;

dynamicArray* createDynamicArray(size_t size);
int pushBack(dynamicArray* p, int data);
int popBack(dynamicArray* p);
int pushData(dynamicArray* p, int data, size_t index);
void popData(dynamicArray* p, size_t index);
size_t changeCapacity(dynamicArray* p, size_t newCapacity);
int shrinkToFit(dynamicArray* p);
void clearDynamicArray(dynamicArray* p);
void freeDynamicArray(dynamicArray* p);
void printDynamicArray(dynamicArray* p);