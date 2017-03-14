#include <stdio.h>
#include <ctype.h>

int main(){
    char c;
    char temp = ' ';
    int i = 0, j = 0;
    while((c = getchar()) != EOF){
        i += 1;
        if(!isspace(c) && isspace(temp)){
            j += 1;    
        }
        temp = c;
    }
    printf("%d, %d",i, j);
}
