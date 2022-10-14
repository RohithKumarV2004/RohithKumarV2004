#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void shift(struct Node* head, int k){
	struct Node* cpy = NULL;
	struct Node* temp = NULL;
	temp = head;
	cpy = temp;
	
	for (int i = 0; i < k; i++){
		cpy = temp;
		while (cpy->next->next != NULL) {
			cpy = cpy->next;
		}
		cpy->next->next = temp;
		temp = cpy->next;
		cpy->next = NULL;
	}
	
	printf("Linked list after shifting:\n");
	cpy = temp;
	while (cpy != NULL) {
		printf("%d ",cpy->data);
		cpy = cpy->next;
	}
	printf("\n");
}

int main() {
	int n;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	
	struct Node* temp = NULL;
	struct Node* cpy = NULL;
	struct Node* head = NULL;
	
	head = (struct Node*)malloc(sizeof(struct Node));
	cpy = head;
	
	for (int i = 0; i < n; i++){
		int num;
		printf("Enter element: ");
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
	printf("\nLinked list created successfully!\n");
	cpy = head;
	while (cpy != NULL) {
			printf("%d ",cpy->data);
			cpy = cpy->next;
		}
	printf("\n");
	int k;
	printf("\nEnter number of times to shift right: ");
	scanf("%d",&k);
	shift(head,k%n);	
	return 0;
}
