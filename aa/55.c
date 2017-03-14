#include <stdio.h>

int main()
{
    char c;
    int a = 0, j = 0;
    while((c = getchar()) != EOF){
        if (a == 0){
            if(c == 'a'){
                a++;
            }
            else{
                printf("%c",c);
                a = 0;
            }
        }
        else if(a == 1){
            if(c == 'b'){
                a++;
            }
            else{
                printf("a%c",c);
                a = 0;
            }
        }
        else if(a == 2){
            if(c == 'c'){
                a++;

            }
            else{
                printf("ab%c",c);
                a = 0;
            }
        }
        else if(a == 3){
            if(c == 'a'){
                a = 1;
            }
            else{
                printf("abc%c",c);
                a = 0;
            }
        }
        else if(a == 4){
            if(c == 'b'){

            }
        }
        
    }

}
