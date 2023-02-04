/*Write a program to construct a binary search tree and count the number of leaf nodes
and display them in the given binary search tree.*/

#include <stdio.h>
#include <stdlib.h>

    struct node
{
    int value;
    struct node *left;
    struct node *right;
} *start = NULL;

void insert(struct node *q, struct node *start)
{
    // checking for empty tree

    // LEFT SUBTREE
    if (q->value < start->value)
    {
        if (start->left == NULL)
        {
            start->left = q;
        }
        else
        {
            insert(q, start->left);
        }
    }

    // RIGHT SUBTREE
    else
    {
        if (start->right == NULL)
        {
            start->right = q;
        }
        else
        {
            insert(q, start->right);
        }
    }
}
int count = 0;
void display(struct node *p)
{
    if (p == NULL)
        return;
    if (p->left == NULL && p->right == NULL)
    {
        
    }
    else{
        printf("%d ", p->value);
        count += 1;
    }

    display(p->left);
    display(p->right);
}

int main()
{

    int first;
    start = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &first);
    start->value = first;
    start->left = NULL;
    start->right = NULL;
    for (int i = 0; i < 5; i++)
    {
        struct node *q = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &q->value);
        q->left = NULL;
        q->right = NULL;
        insert(q, start);
    }
    struct node *p = start;
    display(p);
    printf("\nThere are %d Non-Leaf nodes present in the tree", count);
}