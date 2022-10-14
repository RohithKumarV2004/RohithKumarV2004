#include <stdio.h>

int main() {
	int n;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int arr [n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; i++){
    	for (int j = 0; j < n-i-1; j++) {
    		if (arr[j] > arr[j+1]) {
    			int temp = arr[j+1];
    			arr[j+1] = arr[j];
    			arr[j] = temp;
    		}
    	}
    }
    int max = arr[n-1], secMax = 0;
    for (int i = n-2; i >= 0; i--){
        if (arr[i] < max){
        	secMax = arr[i];
        	break;
        }
    }
    printf("Second maximum element: %d\n",secMax);
    return 0;
}
