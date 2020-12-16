#include "tree.h"

node_t* GetFreeNode(int value, node_t* parent) {
	node_t* tmp = (node_t*)malloc(sizeof(node_t));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}


char* ReadStr() {
	int i = 0;
	char* str = (char*)malloc(sizeof(char)), * tmp = NULL;
	if (str == NULL)
		return NULL;
	while ((str[i++] = fgetc(stdin)) != EOF) {
		tmp = realloc(str, (i + 1) * sizeof(char));
		if (tmp != NULL) {
			str = tmp;
		}
		else {
			return NULL;
		}
	}
	str[i - 1] = 0;
	return str;
}


void AddNode(node_t** root, int value) {
	node_t* tmp = NULL;
	node_t* ins = NULL;
	if (*root == NULL) {
		*root = GetFreeNode(value, NULL);
		return;
	}

	tmp = *root;
	while (tmp) {
		if (value > tmp->data) {
			if (tmp->right) {
				tmp = tmp->right;
				continue;
			}
			else {
				tmp->right = GetFreeNode(value, tmp);
				return;
			}
		}
		else if (value < tmp->data) {
			if (tmp->left) {
				tmp = tmp->left;
				continue;
			}
			else {
				tmp->left = GetFreeNode(value, tmp);
				return;
			}
		}
		// case when "value == tmp->data"
		else {
			return;
		}
	}
}

node_t* FindNodeByValue(node_t* root, int value) {
	while (root) {
		if (root->data > value) {
			root = root->left;
			continue;
		}
		else if (root->data < value) {
			root = root->right;
			continue;
		}
		// case when "value == root->data"
		else {
			return root;
		}
	}
	return NULL;
}


int DeleteNodeByElem(node_t** root, int elem) {
	node_t* tmp = NULL;
	node_t** leaf;
	if (root) {
		while (*root) {
			if (elem > (*root)->data) {
				root = &((*root)->right);
			}
			else if (elem < (*root)->data) {
				root = &((*root)->left);
			}
			else {
				tmp = *root;
				if (!(*root)->left && !(*root)->right)
					*root = NULL;
				else if (!(*root)->left)
					*root = (*root)->right;
				else if (!(*root)->right)
					*root = (*root)->left;
				else {
					leaf = &(*root)->left;
					while ((*leaf)->right)
						leaf = &(*leaf)->right;
					(*root)->data = (*leaf)->data;
					tmp = *leaf;
					*leaf = (*leaf)->left;
				}

				free(tmp);
			}

		}
	}
	return NULL_PTR;
}

void DestroyTree(node_t* tree) {
	if (tree) {
		DestroyTree(tree->left);
		DestroyTree(tree->right);
		free(tree);
	}
}

void PrintTree(node_t* root, char* dir, int level) {
	if (root) {
		printf("lvl %d %s = %d  order = %i\n", level, dir, root->data, root->diff);
		PrintTree(root->left, "left", level + 1);
		PrintTree(root->right, "right", level + 1);
	}
}

int Height(node_t* tree) {
	int left = 0, right = 0, height = 0;
	if (tree) {
		if (tree->left && tree->right) {
			return 0;
		}
		else {
			left = Height(tree->left);
			right = Height(tree->right);
			if (left > right)
				height = left + 1;
			else
				height = right + 1;
			tree->diff = abs(left - right);
			return height;
		}
	}
	else
		return 0;
}