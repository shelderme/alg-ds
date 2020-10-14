#pragma once

typedef enum {
	ERROR_NO,
	STACK_OVERFLOW = -4,
	STACK_UNDERFLOW,
	OUT_OF_MEMORY,
	STACK_IS_EMPTY
} error_t;

typedef struct ArrayStack {
	int* data;
	int top;
	int size;
} ArrayStack_t;

ArrayStack_t* CreateArrayStack();

int PopArrayStack(ArrayStack_t* stack);

void PushArrayStack(ArrayStack_t* stack, int elem);

void DestroyArrayStack(ArrayStack_t* stack);



typedef struct ListStack {
	int data;
	struct ListStack* prev;
} ListStack_t;

struct ListStack* CreateListStack();

void PushListStack(ListStack_t** stack, int newData);

int PopListStack(ListStack_t** stack);

void DestroyListStack(ListStack_t** stack);