#include <stdio.h>

int main() {
	int n;
    printf("Enter an integer:");
    scanf("%d",&n);
    int t = n;
    int k = 0;
    while (t>0){
        int rem = t%10;
        t /= 10;
        k = k*10 + rem;
    }
    if (k == n){
        printf("It is a palindrome.\n");
    }
    else {
        printf("It is not a palindrome.\n");
    }return 0;
}
