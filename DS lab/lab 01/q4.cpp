#include <stdio.h>

int main() {
	int n;
    printf("Enter index:");
    scanf("%d",&n);
    int a = -1,b = 1,c=0;
    printf("The fibonacci series is \n");
    for (int i = 0; i < n; i++) {
        int temp;
        c = a + b;
        a = b;
        b = c;
        printf("%d ",c);
    }return 0;
}
