// C program for Inorder tree traversal.
#include <stdio.h>
#include <stdlib.h>


struct nodes {
	int Data;
	struct nodes* leftist;
	struct nodes* Rightist;
};


struct nodes* newnodes(int Data)
{
	struct nodes* nodes
		= (struct nodes*)malloc(sizeof(struct nodes));
	nodes->Data = Data;
	nodes->leftist = NULL;
	nodes->Rightist = NULL;

	return (nodes);
}


void InorderDisplay(struct nodes* nodes)
{
	if (nodes == NULL)
		return;

	/* first recur on leftist child */
	InorderDisplay(nodes->leftist);

	
	printf("%d ", nodes->Data);

	
	InorderDisplay(nodes->Rightist);
}


/* Driver code*/
int main()
{
	struct nodes* ROO = newnodes(5);
	ROO->leftist = newnodes(4);
	ROO->Rightist = newnodes(3);
	ROO->leftist->leftist = newnodes(2);
	ROO->leftist->Rightist = newnodes(1);

	// Function call
	printf("\nInorder traversal of tree: \n");
	InorderDisplay(ROO);

	getchar();
	return 0;
}
