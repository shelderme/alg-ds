#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define NULL_PTR 1

typedef struct node_t {
	int data;
	int diff;
	struct node_t* left;
	struct node_t* right;
	struct node_t* parent;
}node_t;

node_t* GetFreeNode(int value, node_t* parent);

char* ReadStr();

void AddNode(node_t** root, int value);

node_t* FindNodeByValue(node_t* root, int value);

int DeleteNodeByElem(node_t** root, int elem);

void DestroyTree(node_t* tree);

void PrintTree(node_t* root, char* dir, int level);

int Height(node_t* tree);
