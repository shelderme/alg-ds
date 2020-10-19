//#include "pch.h"
#include <stdlib.h>
//#include "vld.h"
#include <stdio.h>
#include "stack.h"


const int capacity = 10;

// Creats a stack 
ArrayStack_t* CreateArrayStack() {
	ArrayStack_t* stack = (ArrayStack_t*)malloc(sizeof(ArrayStack_t));
	if (stack == NULL)
		return NULL;
	stack->top = 0;
	stack->size = capacity;
	stack->data = (int*)malloc(sizeof(int) * capacity);
	return stack;
}
// Adds an item in the stack


void PushArrayStack(ArrayStack_t* stack, int elem) {
	
	if (stack->top == stack->size)
	{
		int* newData = (int*)malloc(sizeof(int) * (stack->size + capacity));
		for (int i = 0; i != stack->top; ++i)
			newData[i] = stack->data[i];
		stack->size += capacity;
		free(stack->data);
		stack->data = newData;
	}
	stack->data[stack->top] = elem;
	stack->top++;
}

// Removes an item from the stack and returnes removed item
int PopArrayStack(ArrayStack_t* stack) {
	if (stack->top == 0)
		return STACK_UNDERFLOW;
	return stack->data[(stack->top--) - 1];
}
// Destroys a stack
void DestroyArrayStack(ArrayStack_t* stack) {
	free(stack->data);
	free(stack);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

ListStack_t* CreateListStack() {
	ListStack_t* stack = (ListStack_t*)malloc(sizeof(ListStack_t));
	if (stack == NULL) 
		return NULL;
	stack->prev = NULL;
	return stack;
}
void PushListStack(ListStack_t** stack, int elem) {
	ListStack_t* tmp = (ListStack_t*)malloc(sizeof(ListStack_t));
	tmp->data = elem;
	tmp->prev = *stack;
	(*stack) = tmp;
}


int PopListStack(ListStack_t** stack) {
	ListStack_t* tmp;
	int elem;
	if ((*stack)->prev == NULL)
		return STACK_UNDERFLOW;
	tmp = *stack;
	elem = (*stack)->data;
	(*stack) = (*stack)->prev;
	free(tmp);
	return elem;
}

void DestroyListStack(ListStack_t** stek) {
	while ((*stek) != NULL) {
		PopListStack(&stek);
	}
}

struct ListStack* CreateLinkedListStack()
{
	ListStack_t* stek = (ListStack_t*)malloc(sizeof(ListStack_t));
	if (stek) {
		stek->data = 0;
		stek->prev = 0;
	}
	return stek;
}
