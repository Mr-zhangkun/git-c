#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;
    int a;
    while((c = getchar()) != EOF){
        if (a == 0){
            if(c == '%'){
                a++;
            }
            else{
                putchar(c);
                a = 0;
            }
        }
        else if(a == 1){
            if(c == '1'){
                a++;
            }
            else{
                putchar('%');
                putchar(c);
                a = 0;
            }
        }
        else if (a == 2){
            if(c == '2'){
                a++;
            }
            else{
                putchar('%');
                putchar('1');
                putchar(c);
                a = 0;
            }
        }
        else if(a == 3){
            if(c == '3'){
                a++;
            }
            else{
                putchar('%');
                putchar('1');
                putchar('2');
                putchar(c);
                a = 0;
            }
        }
        else if(a == 4){
            if(c == '4'){
                printf(" * ");
            }
            else{
                putchar('%');
                putchar('1');
                putchar('2');
                putchar('3');
                putchar(c);
            }
            a = 0;
        }
    }
}
