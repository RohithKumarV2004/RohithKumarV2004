#include <stdio.h>

int main(){
	
	int n;
	printf("Enter maximum size of queue: ");
	scanf("%d",&n);
	
	int s1[n];
	int s2[n];
	int k1 = 0;
	int k2 = 0;

	while (1) {
		int ch;
		printf("\n1. Enqueue\n2. Dequeue\n3. Print\n4. Front\n5. Rear\n6. Exit\nEnter your choice: ");
		scanf("%d",&ch);
		if (ch == 1) {
			if (k1 < n){
				int temp;
				printf("\nEnter element: ");
				scanf("%d",&temp);
				s1[k1] = temp;
				printf("\n%d is added.\n",s1[k1]);
				k1 ++;
			}
			else {
				printf("\nQueue is full.\n");
			}
		}
		else if (ch == 2){
			if (k1 > 0){
				
				for (int i = 0; i < k1; i++){
					s2[k2] = s1[k1-i-1];
					k2 ++;
				}
				
				printf("\n%d is removed.\n",s2[k2-1]);
				k2 --;
				k1 = 0;
				for (int i = 0; i < k2; i++){
					s1[k1] = s2[k2-i-1];
					k1 ++;
				}
				k2 = 0;
			}
			else {
				printf("\nQueue is empty.\n");
			}
		}
		else if (ch == 3){
			if (k1 > 0){
				printf("\nQueue elements:\n");
				for (int i = 0; i < k1; i++){
					printf("%d ",s1[i]);
				}
				printf("\n");
			}
			else {
				printf("\nQueue is empty.\n");
			}
		}
		else if (ch == 4){
			if (k1 > 0){
			
				for (int i = 0; i < k1; i++){
					s2[k2] = s1[k1-i-1];
					k2 ++;
				}
				
				printf("\nFront element = %d\n",s2[k2-1]);
				k2 = 0;
			}
			else {
				printf("\nQueue is empty.\n");
			}
		}
		else if (ch == 5){
			if (k1 > 0){
				printf("\nRear element = %d\n",s1[k1-1]);
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
