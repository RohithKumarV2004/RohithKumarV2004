#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void circular (struct Node* head, int n) {
	struct Node* cpy = head;
	for (int i = 0; i < n - 1; i++){
		cpy = cpy->next;
	}
	if (cpy->next != NULL){
		if (cpy->next == head){
			printf("\nIt is a circular linked-list.\n");
		}
	}
	else {
		printf("\nIt is not a circular linked-list.\n");
	}
}


int main(){
	int n;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	
	struct Node* head = NULL;
	struct Node* temp = NULL;
	struct Node* cpy = NULL;
	
	head = (struct Node*)malloc(sizeof(struct Node));
	cpy = head;
	
	printf("Enter elements:\n");
	
	for (int i = 0; i < n; i++){
		int num;
		scanf("%d",&num);
		if (i == 0){
			cpy->data = num;
			cpy->next = NULL;
		}
		else {
			temp = (struct Node*)malloc(sizeof(struct Node));
			temp->data = num;
			temp->next = NULL;
			cpy->next = temp;
			cpy = temp;
		}
	}
//	circular(head,n);
//	printf("Make the linked-list circular (Y/N)? ");
//	char ch;
//	scanf(" %c",&ch);
	if (n%2==0){
		cpy->next = head;
		circular(head,n);
	}
	else if (n%2!=0){
		circular(head,n);
	}
	
	
	free(head);
	return 0;
}
