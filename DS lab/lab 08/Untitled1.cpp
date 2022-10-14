#include <stdio.h>
#include <stdlib.h>

struct Node {
	char data;
	struct Node* left;
	struct Node* right;
};

int c = 0;
int n;
int k = 0;
char arr[10];
int ind = 0;

void inorder (struct Node* root) {
	if (root != NULL){
		inorder(root->left);
		printf("%c ",root->data);
		inorder(root->right);
	}
}

void preorder (struct Node* root) {
	if (root != NULL){
		printf("%c ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder (struct Node* root) {
	if (root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%c ",root->data);
	}
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

struct Node* sub(struct Node* node, char pre[], char post[], int br){
	if (c == n-1){
		return node;
	}
	
	while (post[ind] != pre[c-1]){
		arr[k] = post[ind];
		k ++;
		ind ++;
	}
	
	arr[k] = post[ind];
	k ++; 
	ind ++;

	if (br == 0){
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = pre[c];
		temp->left = NULL;
		temp->right = NULL;
		c ++;
		node = sub(node->left, pre, arr,c);
	}
	
}

int main() {
	struct Node* root = (struct Node*)malloc(sizeof(struct Node));
	root->left = NULL;
	root->right = NULL;
	
	printf("Enter number of elements: ");
	scanf("%d",&n);
	char pre[n], post[n], arr[n];
	printf("Enter elements in preorder:\n");
	for (int i = 0; i < n; i ++){
		scanf(" %c",&pre[i]);
	}
	printf("Enter elements in postorder:\n");
	for (int i = 0; i < n; i ++){
		scanf(" %c",&post[i]);
	}
	root->data = pre[c];
	c ++;
	root->left = NULL;
	root->right = NULL;
	sub(root, pre, post, 0);
}
