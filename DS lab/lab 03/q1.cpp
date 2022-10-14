#include <stdio.h>

int main() {
	
	int n;
	printf("Enter maximum size of queue: ");
	scanf("%d",&n);
	
	int q[n];
	int f = 0, r = 0;
	
	while (1) {
		int ch;
		printf("\n1. Enqueue\n2. Dequeue\n3. Print\n4. Front\n5. Rear\n6. Exit\nEnter your choice: ");
		scanf("%d",&ch);
		if (ch == 1) {
			if (r-f < n){
				int temp;
				printf("\nEnter element: ");
				scanf("%d",&temp);
				q[r] = temp;
				printf("%d is added.\n",q[r]);
				r ++;
			}
			else {
				printf("\nQueue is full.\n");
			}
		}
		else if (ch == 2){
			if (f != r){
				printf("%d is removed.\n",q[f]);
				f ++;
			}
			else {
				printf("\nQueue is empty.\n");
			}
		}
		else if (ch == 3){
			if (f != r){
				printf("\nQueue elements:\n");
				for (int i = f; i < r; i++){
					printf("%d ",q[i]);
				}
				printf("\n");
			}
			else {
				printf("\nQueue is empty.\n");
			}
		}
		else if (ch == 4){
			if (f != r){
				printf("\nFront element = %d\n",q[f]);
			}
			else {
				printf("\nQueue is empty.\n");
			}
		}
		else if (ch == 5){
			if (f != r){
				printf("\nRear element = %d\n",q[r-1]);
			}
			else {
				printf("\nQueue is empty.\n");
			}
		}
		else if (ch == 6){
			break;
		}
		else {
			printf("\nInvalid input.\n");
		}
	}return 0;
}
