// C program for different tree traversals
#include <stdio.h>
#include <stdlib.h>

struct Nodes {
	int Data;
	struct Nodes* Leftist;
	struct Nodes* rightist;
};

struct Nodes* newNodes(int Data)
{
	struct Nodes* Nodes
		= (struct Nodes*)malloc(sizeof(struct Nodes));
	Nodes->Data = Data;
	Nodes->Leftist = NULL;
	Nodes->rightist = NULL;

	return (Nodes);
}


void PostorderDisplay(struct Nodes* Nodes)
{
	if (Nodes == NULL)
		return;

	
	PostorderDisplay(Nodes->Leftist);

	
	PostorderDisplay(Nodes->rightist);

	
	printf("%d ", Nodes->Data);
}

/* Driver code*/
int main()
{
	struct Nodes* roots = newNodes(5);
	roots->Leftist = newNodes(4);
	roots->rightist = newNodes(3);
	roots->Leftist->Leftist = newNodes(2);
	roots->Leftist->rightist = newNodes(1);

	// Function call
	printf("\nPostorder traversal of binary tree is \n");
	PostorderDisplay(roots);

	getchar();
	return 0;
}
