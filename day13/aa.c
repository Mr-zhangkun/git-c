#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node{
  datatype data;
  struct node *next;
}linknode, *linklist;
int main(){
  linklist p;
  p = (linklist) malloc(sizeof(linknode));

  if (p == NULL){
    puts("error!");
    return 0;
  }
  p->data = 10;
  p->next = NULL;

  linklist q;
  q = (linklist)malloc(sizeof(linknode));
  if(q == NULL){
    puts("error!");
    return 0;

  }
  q->data = 20;
  p->next = q;
  q->next = NULL;

  printf("%d", q->data);
  printf("%d", p->data);
  printf("%p", p->next);
  free(p);
  free(q);
  
  return 0;
}
