#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

int c = 0;

void inorder (struct Node* root) {
	if (root != NULL){
		inorder(root->left);
		printf("%d->",root->data);
		inorder(root->right);
	}
}

void preorder (struct Node* root) {
	if (root != NULL){
		printf("%d->",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

int search (struct Node* root, int num){
	if (root != NULL) {
	if (num < root->data){
		int k = search(root->left, num);
		if (k == 1){
			return 1;
		}
	}
	else if (num > root->data) {
		int k = search(root->right, num);
		if (k == 1){
			return 1;
		}
	}
	else {
		return 1;
	}
	}
	return 0;
}


struct Node* insert(struct Node* node, int data){
	if (node == NULL) {
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		temp->left = NULL;
		temp->right = NULL;
		temp->data = data;
		return temp;
	}
	if (data < node->data){
		node->left = insert(node->left, data);
	}
	else {
		node->right = insert(node->right, data);
	}
	return node;
}

int main() {
	struct Node* root = NULL;
	
	int n;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	for (int i = 0; i < n; i ++){
		int num;
		printf("Enter element: ");
		scanf("%d",&num);
		root = insert(root, num);
	}
	
	printf("\nBinary search tree created successfully!\n");
	printf("\nBinary search tree elements (inorder):\n");
	inorder(root);
	printf("\nBinary search tree elements (preorder):\n");
	preorder(root);
	printf("\n\nEnter element to search: ");
	int num;
	scanf("%d",&num);
	search(root,num) ? printf("\n%d is present!\n",num) : printf("\n%d is not present!\n",num);
}

