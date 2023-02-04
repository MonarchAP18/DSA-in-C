#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *Roots) {
  if (Roots != NULL) {
    inorder(Roots->left);
    printf("%d -> ", Roots->key);

    inorder(Roots->right);
  }
}

// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *Roots, int key) {
  // Return if the tree is empty
  if (Roots == NULL) return Roots;

  // Find the node to be deleted
  if (key < Roots->key)
    Roots->left = deleteNode(Roots->left, key);
  else if (key > Roots->key)
    Roots->right = deleteNode(Roots->right, key);

  else {
    // If the node is with only one child or no child
    if (Roots->left == NULL) {
      struct node *temp = Roots->right;
      free(Roots);
      return temp;
    } else if (Roots->right == NULL) {
      struct node *temp = Roots->left;
      free(Roots);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(Roots->right);

    // Place the inorder successor in position of the node to be deleted
    Roots->key = temp->key;

    // Delete the inorder successor
    Roots->right = deleteNode(Roots->right, temp->key);
  }
  return Roots;
}

// Driver code
int main() {
  struct node *Roots = NULL;
  printf("Inserting 8 \n");
  Roots = insert(Roots, 8);
  printf("Inserting 3 \n");
  Roots = insert(Roots, 3);
  printf("Inserting 1 \n");
  Roots = insert(Roots, 1);
  printf("Inserting 6 \n");
  Roots = insert(Roots, 6);
  printf("Inserting 7 \n");
  Roots = insert(Roots, 7);
  printf("Inserting 10 \n");
  Roots = insert(Roots, 10);
  printf("Inserting 14 \n");
  Roots = insert(Roots, 14);
  printf("Inserting 4 \n");
  Roots = insert(Roots, 4);

  printf("Inorder traversal: ");
  inorder(Roots);

  printf("\nAfter deleting 10\n");
  Roots = deleteNode(Roots, 10);
  printf("Inorder traversal: ");
  inorder(Roots);
}