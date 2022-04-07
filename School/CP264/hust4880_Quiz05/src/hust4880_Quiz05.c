/*
 ============================================================================
 Name        : hust4880_Quiz05.c
 Author      : Riley Huston
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int key;
	struct Node *left, *right;
};

struct Node* newNode(int key) {
	struct Node *root = malloc(sizeof(*root));

	root->key = key;
	root->left = NULL;
	root->right = NULL;

	return root;
}

void print_inorder(struct Node *root) {
	if (root == NULL) {
		return 0;
	}

	print_inorder(root->left);
	printf("%d ", root->key);
	print_inorder(root->right);
}

int valid_inorder(struct Node *root) {
	if (root == NULL) {
		return 1;
	} else if ((root->left != NULL && root->left->key > root->key)
			|| (root->right != NULL && root->right->key < root->key)) {
		return 0;
	}

	valid_inorder(root->left);
	valid_inorder(root->right);
}

struct Node* constructBST(int preorder[], int start, int end) {
	if (start > end) {
		return NULL;
	}

	struct Node *root = newNode(preorder[start]);
	int i = start;
	while (i <= end && preorder[i] <= root->key) {
		i++;
	}
	root->left = constructBST(preorder, start + 1, i - 1);
	root->right = constructBST(preorder, i, end);
	return root;
}

int isBST(struct Node *node) {
	int valid = valid_inorder(node);
	return valid;
}

int main(void) {

	int preorder[] = { 15, 10, 8, 12, 20, 16, 25 };
	int end = sizeof(preorder) / sizeof(int);

	struct Node *root = constructBST(preorder, 0, end - 1);
	printf("The inorder traversal of the BST is: ");

	print_inorder(root);

	printf("\nIs the BST valid: %d", isBST(root));

	return 0;
}
