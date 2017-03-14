#include <stdio.h>

int main(){
    int i, j, tmp;
    int a[7] = {11,3,5,2,4,6,1};

    for(i = 0;i < 7; i++){
        for(j = 0; j < 6 - i; j++){
            if(a[j] > a[j + 1]){
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;


            }
        }
    }
    for(i = 0; i < 7; i++){
        printf("a[%d] = %d  |  ", i, a[i]);
    }
    printf("\n");
}
