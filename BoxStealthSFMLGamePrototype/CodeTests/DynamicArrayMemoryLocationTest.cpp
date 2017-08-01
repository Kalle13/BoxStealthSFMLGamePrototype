// DynamicArrayMemoryLocationTest.cpp
#include <stdlib.h>
#include <stdio.h>


// Test question: Is a dynamic array that is a struct member always stored in memory immediately after other struct members?

// Answer:
// From code below, the address of the dynamic array that is part of the DynamicMemoryTestStruct is located a
// random (and very large) address offset away from the base struct address.

struct DynamicMemoryTestStruct
{
	int member1;
	int member2;
	int *dynamicArray;
};

void DynamicMemoryLocationTest()
{

	DynamicMemoryTestStruct memoryTestStruct;

	memoryTestStruct.member1 = 3;
	memoryTestStruct.member2 = 8;

	memoryTestStruct.dynamicArray = (int*)malloc(10 * sizeof(int));

	for (int i = 0; i < 10; ++i) {
		memoryTestStruct.dynamicArray[i] = i*i;
	}

	int memLocDiff = (int)(memoryTestStruct.dynamicArray) - (int)(&(memoryTestStruct.member2));

	printf("memoryTestStruct info:\nbase memory location:\t\t %p\nmember1 memory location:\t %p\nmember2 memory location:\t %p\ndynamicArray memory location:\t %p\n", &memoryTestStruct, &(memoryTestStruct.member1), &(memoryTestStruct.member2), memoryTestStruct.dynamicArray);
	printf("Memory location difference:\t %d\n", memLocDiff);
}