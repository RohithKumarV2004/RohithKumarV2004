#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void reverse (struct Node* head,int n){
	struct Node* curr = head;
	struct Node* prev = head;
	struct Node* tail = head;
	
	for (int i = 0; i < n-1; i++){
		tail = tail->next;
	}
		
	for (int i = 0; i < n-1; i++){
		prev = head;
		for (int j = 0; j < n - i - 2; j++){
			prev = prev->next;
		}
		curr = prev->next;
		curr->next = prev;
		prev->next = NULL;
	}
	head->next = tail;
	head = tail;
	
	printf("\nCircular linked list after reversing:\n");
	for (int i = 0; i < n; i++){
		printf("%d ",tail->data);
		tail = tail->next;
	}
	printf("\n");
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
	cpy->next = head;
	cpy = head;
	
	printf("Circular linked list before reversing:\n");
	for (int i = 0; i < n; i++){
		printf("%d ",cpy->data);
		cpy = cpy->next;
	}
	
	reverse(head,n);
	return 0;
}
