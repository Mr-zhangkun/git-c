#include <stdio.h>
#include <stdlib.h>

//#define NULL 0
//#define LEN sizeof(struct student)

struct student{
  long num;
  struct student * next;
};
int n;

struct student * creat(void){
  struct student * head;
  struct student * p1, * p2;
  n = 0;
  p1 =  p2 = (struct student *) malloc(sizeof(struct student));
  scanf("%ld",&p1->num);
  head = NULL;
  while(p1->num != 0){
    n = n + 1;
    if(n == 1)
      head = p1;
    else
      p2->next = p1;
    p2 = p1;
    p1 = (struct student *) malloc(sizeof(struct student));
    scanf("%ld", &p1->num);
  }
  p2->next = NULL;
  return(head);
}


void Prt(struct student * head){
  struct student * p;
  p  = head;
  if(head != NULL)
  do{
    printf("%ld\n", p->num);
    p = p->next;
  }while(p != NULL);
}


int main(int argc, char const *argv[]) {
  struct student * p;
  p = creat();
  Prt(p);
  return 0;
}
