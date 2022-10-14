#include <stdio.h>

int main(){
    int arr[100];
    int c = 0;
    while (1){
        printf("\n\nEnter choice:\n1.Push\n2.Pop\n3.Print\n4.Top\n5.Exit\n");
        char ch;
        scanf(" %c",&ch);
        if (ch == '1'){
            if (c == 99) {
                printf("Stack is full!\n");
            }
            else {
                printf("Enter element: ");
                scanf(" %d",&arr[c]);
                c ++;
            }
        }
        else if (ch == '2'){
            if (c == 0) {
                printf("Stack is empty!\n");
            }
            else {
                arr[c] = -1;
                c --;
            }
        }
        else if (ch == '3'){
            if (c == 0) {
                printf("Stack is empty!\n");
            }
            else {
                printf("Stack elements:\n");
                for (int i = 0; i < c; i++){
                    printf("%d ",arr[i]);
                }
            }
        }
        else if (ch == '4'){
            if (c == 0) {
                printf("Stack is empty!\n");
            }
            else {
                printf("Top element = %d\n",arr[0]);
            }
        }
        else if (ch == '5'){
            break;
        }
        else {
            printf("Invalid choice!");
        }
    }return 0;
}
