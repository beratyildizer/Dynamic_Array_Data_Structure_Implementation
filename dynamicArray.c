#include "dynamicArray.h"
#include <stdlib.h>

dynamicArray* createDynamicArray(size_t size)
{
	dynamicArray* p;

	if ((p = ((dynamicArray*)malloc(sizeof(dynamicArray)))) == NULL)
		return NULL;
	
	if ((p->startingPoint = ((int*)malloc(sizeof(int) * size * 2))) == NULL) {
		free(p);
		return NULL;
	}

	(void)memset(p->startingPoint, 0, sizeof(int) * size * 2);

	p->size = 0;
	p->capacity = size * 2;

	return p;
}

int pushBack(dynamicArray* p, int data)
{
	if (!p)
		return FAIL;

	CAPACITY_CHECK(p);

	p->startingPoint[p->size] = data;

	return p->size++;

}

int popBack(dynamicArray* p)
{
	if (!p || !p->startingPoint)
		return FAIL;

	p->startingPoint[p->size] = 0;

	return --p->size;

}

int pushData(dynamicArray* p, int data, size_t index)
{
	if (!p)
		return FAIL;

	CAPACITY_CHECK(p);

	(void)memmove(&p->startingPoint[index + 1], &p->startingPoint[index], (p->size++ - index) * sizeof(int));
	

	p->startingPoint[index] = data;

	return index;
	
}

void popData(dynamicArray* p, size_t index)
{
	memmove(&p->startingPoint[index], &p->startingPoint[index + 1], (p->size - index) * sizeof(int));
	
	p->size--;
}

size_t changeCapacity(dynamicArray* p, size_t newCapacity)
{
	dynamicArray* p1;

	if ((p1 = ((dynamicArray*)malloc(sizeof(dynamicArray)))) == NULL)
		return NULL;
	p1->startingPoint = p->startingPoint;
	p1->size = p->size;

	if (!(p->startingPoint = ((int*)malloc(sizeof(int) * newCapacity))))
		return FAIL;

	(void)memcpy(p->startingPoint, p1->startingPoint, p1->size * sizeof(int));
	p->size = p1->size;
	p->capacity = newCapacity;

	free(p1->startingPoint);

	return newCapacity;

}

int shrinkToFit(dynamicArray* p)
{
	if (!(p->size * 2 < p->capacity))
		return FAIL;

	return changeCapacity(p, p->size ? p->size * 2 : 20);
}

void clearDynamicArray(dynamicArray* p)
{
	(void)memset(p->startingPoint, 0, p->size * sizeof(int));
	p->size = 0;
}

void freeDynamicArray(dynamicArray* p)
{
	free(p->startingPoint);
	free(p);
}

void printDynamicArray(dynamicArray* p)
{
	printf("\n..................................................................\n");

	printf("starting address: %p\n", p->startingPoint);
	printf("size value: %zu \n", p->size);

	printf("capacity value: %zu\n", p->capacity);

	for (size_t i = 0; i < p->size; ++i)
		printf("%zu nci deger %d\n", i, p->startingPoint[i]);


}