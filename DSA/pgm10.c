#include <stdio.h>
#include <stdlib.h>
struct node {
 int data;
 struct node* left;
 struct node* right;
};
typedef struct node* treeptr;
treeptr create(int x) {
 treeptr nn = (treeptr)malloc(sizeof(struct node));
 nn->data = x;
 nn->left = NULL;
 nn->right = NULL;
 return nn;
}
treeptr insert(treeptr root, int x) {
 if (root == NULL) {
 return create(x);
 }
 if (x < root->data) {
 root->left = insert(root->left, x);
 } else if (x > root->data) {
 root->right = insert(root->right, x);
 }
 return root;
}
void inorder(treeptr root) {
 if (root) {
 inorder(root->left);
 printf("%d ", root->data);
 inorder(root->right);
 }
}
void preorder(treeptr root) {
 if (root) {
 printf("%d ", root->data);
 preorder(root->left);
 preorder(root->right);
 }
}
void postorder(treeptr root) {
 if (root) {
 postorder(root->left);
 postorder(root->right);
 printf("%d ", root->data);
 }
}
void search(treeptr root, int x) {
 if (root == NULL) {
 printf("Key %d not found in the tree.\n", x);
 return;
 }
 if (root->data == x) {
 printf("Key %d found in the tree.\n", x);
 return;
 }
 if (x < root->data) {
 search(root->left, x);
 } else {
 search(root->right, x);
 }
}
void main() {
 treeptr root = NULL;
 int choice, x;
 while (1) {
 printf("\nMenu:\n1. Insert\n2. Display Inorder Traversal\n3. Display Preorder Traversal\n4.
Display Postorder Traversal\n5. Search\n6. Exit\nEnter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter value to insert: ");
 scanf("%d", &x);
 root = insert(root, x);
 break;
 case 2:
 printf("Inorder traversal: ");
 inorder(root);
 printf("\n");
 break;
 case 3:
 printf("Preorder traversal: ");
 preorder(root);
 printf("\n");
 break;
 case 4:
 printf("Postorder traversal: ");
 postorder(root);
 printf("\n");
 break;
 case 5:
 printf("Enter value to search: ");
 scanf("%d", &x);
 search(root, x);
 break;
 case 6:
 exit(0);
 default:
 printf("Invalid choice. Try again.\n");
 }
 }
}
