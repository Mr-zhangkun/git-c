#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
  int x;
  struct node * prior, * next;
}DNode;

 DNode * create_Dist(){
 DNode *p, *h, *l;
  int n = 3, i, x;
  h = ( DNode *)malloc(sizeof(DNode));
  h->prior = h;
  h->next = h;
  p = h;

  for(i = 0; i < n; i++){
    scanf("%d", &x);
    l = (DNode *)malloc(sizeof(DNode));
    l->x = x;
    p->next = l;
    l->prior = p;
    l->next = h;
    h->prior = l;
    p = l;

  }
  return(h);
}
int show(DNode * p){
  DNode * q;
  q = p;
  q = q->next;

  while(p != q){
    printf("%d\n", q->x);
    q = q->next;
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  DNode * p;
  p = create_Dist();
  show(p);
  return 0;
}
