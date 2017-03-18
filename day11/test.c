#include <stdio.h>

void max_min(int b[5], int *max, int *min);
int main(void){
  int a[5] = {1,3,4,5,6};
  int sml, big;
  max_min(a, &big, &sml);
  printf("最大是%d",big);
  printf("最小是%d",sml);
  return 0;
}

void max_min(int b[], int *max, int *min ){
  int i;
  *min = *max = b[0];
  for(i = 0; i < 5; i++){
    if (b[i] > *max){
      *max = b[i];
    }
    else if(b[i] < *min){
      *min = b[i];
    }
  }
}
