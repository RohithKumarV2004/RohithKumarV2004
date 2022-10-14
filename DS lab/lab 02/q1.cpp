#include <stdio.h>

int main(){
    char s[100];
    printf("Enter post fix expression: \n");
    scanf("%s",s);
    int c =0;
    for (int i = 0; i < 100; i++){
        if (s[i] == '\0')
            break;
        else {
            c ++;
        }
    }
    int a[c];
    int num1 = (int)s[0] - 48;
    a[0] = num1;
    int num2 = (int)s[2] - 48;
    a[1] = num2;
    int k = 2;

    for (int i = 4; i < c; i++){
        if (s[i] == '+'){
            a[k-2] = a[k-2] + a[k-1];
            k --;
        }
        else if (s[i] == '-'){
            a[k-2] = a[k-2] - a[k-1];
            k --;
        }
        else if (s[i] == '*'){
            a[k-2] = a[k-2] * a[k-1];
            k --;
        }
        else if (s[i] == '/'){
            a[k-2] = a[k-2] / a[k-1];
            k --;
        }
        else if (s[i] != ','){
            a[k] = (int)s[i] - 48;
            k ++;
        }
        printf("\n");
    }
    printf("Answer = %d",a[0]);
    return 0;
}
