#include <stdio.h>

int main(void)
{
    int a[6] = {1,3,5,7,9,10};
    int i = 0;
    printf("{");
    for(i = 5; i >=0; i--){
        printf("%d,",a[i]);
    }
    printf("}\n");
}
