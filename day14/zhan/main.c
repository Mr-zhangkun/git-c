#include <stdio.h>
#include "zhan.h"

seqstack b;
seqstack *a=&b;

int main(int argc, char* argv[])
{
    int x , n=0;

    INITSTACK(a);
    printf("\n请输入数据，以-1结束:\n");
    scanf("%d",&x);
    while(x!=-1)
    {
        a=PUSH(a,x);
        n++;
        scanf("%d",&x);
    }
    printf("n=%d\n",n);
    while(EMPTY(a)!=1)
    {
        x=POP(a);
        printf("%d ",x);
        n--;
    }

    return 0;
}
