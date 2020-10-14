#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
int main() {
	ArrayStack_t* stek;
	int arra[4] = {3, 4, 2, 3};
	stek = CreateArrayStack();
	PushArrayStack(stek, 5);
	PushArrayStack(stek, 4);

	printf("%d\n", PopArrayStack(stek));

	printf("%d\n", PopArrayStack(stek));

	printf("%d\n", PopArrayStack(stek));
	for (int i = 0; i < 10; i++) {
		PushArrayStack(stek, i);
	}
	printf("%d\n", PopArrayStack(stek));
	printf("%d\n", PopArrayStack(stek));
	printf("%d\n", stek->size);
	DestroyArrayStack(stek);
	printf("New tests\n");
	ArrayStack_t str = {arra, 4, 4};
	printf("%d\n", PopArrayStack(&str));
	printf("%d\n", str.top);
	printf("%d\n", str.size);
	printf("Work with liststack\n");
	ListStack_t* skex;
	skex = CreateListStack();
	PushListStack(&skex, 23);
	for (int i = 0; i < 23; i++) {
		PushListStack(&skex, i);

	}
	
	for (int i = 0; i < 23; i++) {
		printf("%d\n", PopListStack(&skex));
		printf("%d\n", PopListStack(&skex));

	}
	printf("Work with array\n");
	int arr[5] = { 73, 54, 12, 23 };
	ArrayStack_t steak = { arr, 4, 5 };
	PushArrayStack(&steak, 39);

	printf("%d\n", PopArrayStack(&steak));
	printf("%d\n", PopArrayStack(&steak));
	printf("%d\n", PopArrayStack(&steak));
	printf("%d\n", PopArrayStack(&steak));
	printf("%d\n", PopArrayStack(&steak));
	printf("New work\n");
	

	return 0;
}

