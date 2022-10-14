#include <stdio.h>

int main() {

    char s[100];
    printf("Enter brackets string: ");
    scanf("%s",s);
    int c = 0;

    for (int i = 0; i < 100; i++){
        if (s[i] == '\0')
            break;
        else {
            c ++;
        }
    }

    int a[c];
    a[0] = s[0];

    int k = 1;
    for (int i = 1; i < c; i++){
        if (s[i] == ')' && a[k-1] == '('){
            k --;
        }
        else if (s[i] == ']' && a[k-1] == '['){
            k --;
        }
        else if (s[i] == '}' && a[k-1] == '{'){
            k --;
        }
        else {
            a[k] = s[i];
            k ++;
        }
    }
    
    if (k == 0){
        printf("True\n");
    }
    else {
        printf("False\n");
    }return 0;
}
