#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int x;
  struct node *pri, *next;
}Node;

Node * creat(int val){
  Node * h = NULL;
  h = (Node *)malloc(sizeof(Node));
  if(h == NULL){
    printf("error");
  }
  h->x = val;
  h->next = h;
  h->pri= h;
}
Node *insert(Node * h,int val){
  Node * p = NULL;
  p = (Node *)malloc(sizeof(Node));
  if(p == NULL){
    printf("error");
  }
  p->x = val;

  p->next = h->next;
  h->next->pri = p;
  p->pri = h;
  h->next = p;
  return p;
}
void show(Node * h){
  Node * p = h->pri;
  while(h != p){
    printf("%d\n", p->x);
    p = p->pri;
  }
}

Node *del(Node * h, int val){
  Node * p;
  p = h;
  while(p->x != val){
    p = p->next;
  }
  p->pri->next = p->next;
  p->next->pri = p->pri;
  free(p);
}

Node * insert_1(Node *h,int val,int val1){
  Node *q;
  q = (Node *)malloc(sizeof(Node));
  q->x = val1;

  while(h->x != val){
    h = h->next;
  }
  q->next = h->next;
  h->next->pri = q;
  q->pri = h;
  h->next = q;
  return q;
  }
int main(int argc, char const *argv[]) {
  Node * h;
  h = creat(0);
  insert(h, 1);
  insert(h, 2);
  insert(h, 3);
  insert(h, 4);
  insert(h, 5);
  show(h);
  //del(h,3);
  insert_1(h,3, 8);
  show(h);
  return 0;
}
