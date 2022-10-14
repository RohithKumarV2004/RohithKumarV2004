#include <stdio.h>

int main(){
    int n,max = 0;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int arr [n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; i++){
        if (arr[i] > max) {
        	max = arr[i];
        }
    }
    printf("Maximum element: %d",max);
    return 0;
}

