#include <stdio.h>

int main()
{
    int i, j, c;
    for(i = 50; i <=100; i++){
        c = i;
        printf("%d = ",i);
        for(j = 1; j <= i; j++){
            if (c % j == 0){
                printf("%d * ",j);
                c = c / j;
                if(c <= j){
                    printf("%d",c );
                }

            }
        }
        printf("\n");
    }
}
