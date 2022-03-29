#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define  MIN(v1,v2) (((v1) <  (v2))? (v1):(v2))        // Return the less    of v1 and v2
#define  MAX(v1,v2) (((v1) >  (v2))? (v1):(v2)) 		 // Return the greater of v1 and v2

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

void inorder(struct Node *root) {
	if (root == NULL) {
		return;
	}

	inorder(root->left);
	printf("%d ", root->key);
	inorder(root->right);
}

// Returns tree if the Binary tree is balanced like a Red-Black
// tree.
bool isBalanced(struct Node *root, int *maxh, int *minh) {
	if (root == NULL) {
		*maxh = *minh = 0;
		return true;
	}
	int left_maxh, left_minh, right_maxh, right_minh;

	if (isBalanced(root->left, &left_maxh, &left_minh) == false) {
		return false;
	}
	if (isBalanced(root->right, &right_maxh, &right_minh) == false) {
		return false;
	}
	*maxh = MAX(left_maxh, right_maxh) + 1;
	*minh = MIN(left_minh, right_minh) + 1;
	if ((*maxh) <= 2 * (*minh)) {
		return true;
	}
	return false;
}

// A wrapper over isBalanced()
bool isHeightBalanced(struct Node *root) {
	int maxh, minh;
	return isBalanced(root, &maxh, &minh);
}

void testCase1() {

	struct Node *root = newNode(40);
	root->left = newNode(10);
	root->right = newNode(100);
	root->right->left = newNode(60);
	root->right->right = newNode(150);

	if (isHeightBalanced(root)) {
		printf("\nBalanced\n");
		inorder(root);
	} else {
		printf("\nNot Balanced\n");
		inorder(root);
	}
}

void testCase2() {

	struct Node *root = newNode(12);
	root->left = newNode(14);
	root->left->left = newNode(16);

	if (isHeightBalanced(root)) {
		printf("\nBalanced\n");
		inorder(root);
	} else {
		printf("\nNot Balanced\n");
		inorder(root);
	}
}

void testCase3() {

	struct Node *root = newNode(70);
	root->left = newNode(40);
	root->right = newNode(90);
	root->right->left = newNode(80);
	root->right->right = newNode(110);
	root->right->left->left = newNode(79);
	root->left->left = newNode(30);
	root->left->right = newNode(50);
	root->left->left->left = newNode(10);

	if (isHeightBalanced(root)) {
		printf("\nBalanced\n");
		inorder(root);
	} else {
		printf("\nNot Balanced\n");
		inorder(root);
	}
}

/* Driver program to test above functions*/
int main() {
	testCase1();
	testCase2();
	testCase3();

	return 0;
}
