#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

int main() {
	int N;
	printf("Enter number of linked lists: ");
	scanf("%d",&N);
	struct Node* arr[N+1];
	
	for (int i = 1; i < N+1; i++){
		printf("Enter number of elements of linked list-%d:",i);
		int n;
		scanf("%d",&n);
		struct Node* temp = NULL;
		struct Node* cpy = NULL;
	
		struct Node* head = (struct Node*)malloc(sizeof(struct Node));
		cpy = head;
		arr[i] = cpy;
		
		for (int j = 0; j < n; j++){
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
	}
	
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head = arr[1]->next;
	
	struct Node* cpy2 = NULL;
	
	for (int i = 2; i < N+1; i++){
		
		struct Node* cpy = NULL;
		
		cpy = arr[i];
		cpy = cpy->next;
		
		cpy2 = head;
		
		while (cpy != NULL) {
			if (head->data > cpy->data){
					struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
					temp->data = cpy->data;
					temp->next = head;
					head = temp;
					cpy2 = head;
			}
			else {
			
			while (cpy2->next != NULL){
				if (cpy2->data <= cpy->data && cpy2->next->data >= cpy->data){
					struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
					temp->next = NULL;
					temp->data = cpy->data;
					temp->next = cpy2->next;
					cpy2->next = temp; 
					break;
				}
				
				cpy2 = cpy2->next;
			}
			if ((cpy2->data < cpy->data) && cpy2->next == NULL){
				struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
				temp->data = cpy->data;
				temp->next = NULL;
				cpy2->next = temp;
			}
			}
			cpy = cpy->next;
			
		}
		
	}
	
	struct Node* cpy = head;

	printf("\nFinal linked list:\n");
	while (cpy != NULL) {
		printf("%d ",cpy->data);
		cpy = cpy->next;
	}
	printf("\n");
	return 0;
}
