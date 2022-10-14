#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void palindrome (struct Node* head,int n){
	struct Node* start = head;
	struct Node* end = head;
	int c = 0;
	for (int i = 0; i < n-1; i++){
		end = head;
		for (int j = 0; j < n - i - 1; j++){
			end = end->next;
		}
		if (start == end || start == end->next){
			break;
		}
		if (start->data == end->data){
			c ++;
		}
		start = start->next;
	}
	if (c == n/2){
		printf("\nIt is a palindrome.\n");
	}
	else {
		printf("\nIt is not a palindrome.\n");
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
	palindrome(head,n);
	free(head);
	return 0;
}
