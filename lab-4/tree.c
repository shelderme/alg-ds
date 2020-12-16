#include "tree.h"
#pragma warning(disable: 4996)

int main(void) {
	char* str, * tmpStr, ch = 0;
	int num = 0, i = 0;
	node_t* tree = NULL;
	str = ReadStr();
	tmpStr = strtok(str, "\n");
	while (tmpStr != NULL) {
		if (sscanf(tmpStr + i++, "%c", &ch));
		if (sscanf(tmpStr + i, "%i", &num));
		i = 0;
		switch (ch)
		{
		case 'a':
			AddNode(&tree, num);
			break;
		case 'f':
			if (FindNodeByValue(tree, num))
				printf("yes\n");
			else
				printf("no\n");
			break;
		case 'r':
			DeleteNodeByElem(&tree, num);
			break;
		}
		tmpStr = strtok(NULL, "\n");
	}

	free(str);
	DestroyTree(tree);
	return 0;
}