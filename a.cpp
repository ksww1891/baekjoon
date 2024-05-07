#include<stdio.h>

int main(){
    int n;
    printf("입력 : ");
    scanf_s("%d", &n);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            int tmp = i;
            for (int k = 1; k < j; k++){
                tmp *= i;
            }
            printf("%d ", tmp);
        }
        printf("\n");
    }
}