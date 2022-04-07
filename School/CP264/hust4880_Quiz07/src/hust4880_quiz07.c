/*
 ============================================================================
 Name        : hust4880_quiz07.c
 Author      : Riley Huston
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#define False	0
#define True	1

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key, height;
	struct node *left, *right;
}node;

node* newNode(int key) {
	node *root = malloc(sizeof(*root));

	root->key = key;
	root->height = 1;
	root->left = NULL;
	root->right = NULL;

	return root;
}

node *rotateRight(node *n){
	node *pivot;
	pivot = n->left;
	n->left = pivot->right;
	pivot->right = n;
	pivot->height = getTreeHeight(pivot);
	n->height = getTreeHeight(n);
	return pivot;
}
node *rotateLeft(node *n){
	node *pivot;
	pivot = n->right;
	n->right = pivot->left;
	pivot->left = n;
	pivot->height = getTreeHeight(pivot);
	n->height = getTreeHeight(n);
	return pivot;
}

node *rrRotation(node *root){
	root = rotateLeft(root);
	return root;
}
node *llRotation(node *root){
	root = rotateRight(root);
	return root;
}
node *lrRotation(node *root){
	root->left = rotateLeft(root->left);
	root = rotateRight(root);
	return root;
}
node *rlRotation(node *root){
	root->right = rotateRight(root->right);
	root = rotateLeft(root);
	return root;
}

int balanceFactor(node *root){
	int height_l = 0, height_r = 0;
	if(root != NULL){
		if(root->left != NULL){
			height_l = 1 + root->left->height;
		}
		if(root->right != NULL){
			height_r = 1 + root->right->height;
		}
	}
	return (height_l - height_r);
}

void inorder(node *root) {
	if (root == NULL) {
		return;
	}

	inorder(root->left);
	printf("%d (%d) ", root->key, balanceFactor(root));
	inorder(root->right);
}

node *insertInTree(node *root, int key){
	if(root == NULL)
		root = newNode(key);
	else if(key > root->key){
		root->right = insertInTree(root->right, key);
		if(balanceFactor(root) < -1){
			if(key > root->right->key){
				root = rrRotation(root);
			} else{
				root = rlRotation(root);
			}
		}

	}else if(key < root->key){
		root->left = insertInTree(root->left, key);
		if(balanceFactor(root) > 1){
			if(key < root->left->key){
				root = llRotation(root);
			} else{
				root = lrRotation(root);
			}
		}
	}
	root->height = getTreeHeight(root);
	return root;
}
node *deleteFromTree(node *root, int key){
	node *n;
	if(root == NULL)
			return NULL;
		else if(key > root->key){
			root->right = insertInTree(root->right, key);
			if(balanceFactor(root) < -1){
				if(key > root->right->key){
					root = rrRotation(root);
				} else{
					root = rlRotation(root);
				}
			}

		}else if(key < root->key){
			root->left = insertInTree(root->left, key);
			if(balanceFactor(root) > 1){
				if(key < root->left->key){
					root = llRotation(root);
				} else{
					root = lrRotation(root);
				}
			}
		} else{
			if(root->right != NULL){
				n = root->right;
				while(n->left != NULL)
					n = n->left;
				root->key = n->key;
				root->right = deleteFromTree(root->right, n->key);

				if(balanceFactor(root) > 1)
						if(balanceFactor(root->left) >= 0)
							root = llRotation(root);
						else
							root = lrRotation(root);
			}
			else{
				return(root->left);
			}
		}
	return root;
}

int getTreeHeight(node *root){
	int height_r = 0, height_l = 0, max = 0;
	if(root != NULL){
		if(root->left != NULL){
			height_l = 1 + root->left->height;
		}
		if(root->right != NULL){
			height_r = 1 + root->right->height;
		}
		if(height_l > height_r){
			max = height_l;
		} else{
			max = height_r;
		}
	}
	return max;
}




int main(void) {
	setbuf(stdout, NULL);           // turns standard output buffering off

	int input, key, exit = False;
	char str[231];
	node *tree = NULL;
	while(exit != True){
		printf("==============================\n");
		printf("1) Create a tree:\n");
		printf("2) Insert into the tree:\n");
		printf("3) Delete from tree:\n");
		printf("4) Print the tree:\n");
		printf("5) Quit the program:\n");
		printf("==============================\n");
		printf("Input your selection: ");
		scanf("%d", &input);
		switch(input){
			case 1:
				printf("\nEnter character to insert into tree: ");
				scanf("%c", str);
				key = str[0];
				tree = newNode(key);
				break;
			case 2:
				if(tree != NULL){
					printf("\nEnter character to insert into tree: ");
					scanf("%s", &str);
					key = 0;
					while(str[key] != NULL){
						tree = insertInTree(tree, str[key]);
						key++;
					}

				} else{
					printf("ERROR: TREE HAS NOT BEEN CREATED\n");
				}
				break;
			case 3:
				if(tree != NULL){
					printf("\nEnter character to delete from tree: ");
					scanf("%c", str);
					tree = deleteFromTree(tree, str);
				} else{
					printf("ERROR: TREE HAS NOT BEEN CREATED\n");
				}
				break;
			case 4:
				if(tree != NULL){
					printf("\nInorder Traversal of tree : ");
					inorder(tree);
					printf("\n");
				} else{
					printf("ERROR: TREE HAS NOT BEEN CREATED\n");
				}
				break;
			case 5:
				printf("\n---EXITING PROGRAM---\n");
				exit = True;
				break;
			default:
				printf("\nERROR: INVALID INPUT\n");
		}
	}

	return 0;
}
