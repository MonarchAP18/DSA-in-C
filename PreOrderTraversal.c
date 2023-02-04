#include <stdio.h>
#include <stdlib.h>


struct Nodes {
	int Data;
	struct Nodes* leftist;
	struct Nodes* rightist;
};


struct Nodes* newNodes(int Data)
{
	struct Nodes* Nodes
		= (struct Nodes*)malloc(sizeof(struct Nodes));
	Nodes->Data = Data;
	Nodes->leftist = NULL;
	Nodes->rightist = NULL;

	return (Nodes);
}


void PreorderDisplay(struct Nodes* Nodes)
{
	if (Nodes == NULL)
		return;

	
	printf("%d ", Nodes->Data);

	
	PreorderDisplay(Nodes->leftist);

	
	PreorderDisplay(Nodes->rightist);
}

/* Driver code*/
int main()
{
	struct Nodes* roots = newNodes(1);
	roots->leftist = newNodes(5);
	roots->rightist = newNodes(6);
	roots->leftist->leftist = newNodes(4);
	roots->leftist->rightist = newNodes(3);

	
	printf("\nPreorder traversal of binary tree is \n");
	PreorderDisplay(roots);

	getchar();
	return 0;
}
