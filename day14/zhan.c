#include <stdio.h>
#include <stdlib.h>

typedef struct Qnode{
  int x;
  struct Qnode *next;
}Qnode, *QueuePtr;
typedef struct{
  QueuePtr front;
  QueuePtr rear;
}linkQueue;

int initqueue(linkQueue *q){
  q->front = q->rear = (QueuePtr)malloc(sizeof(Qnode));
  if(q->front == NULL){
    printf("error");
  }
  q->front -> next = NULL;
  q->rear->next = NULL;
  return 0;
}
int inqueue(linkQueue *q,int e){
  QueuePtr p;
  p = (QueuePtr)malloc(sizeof(Qnode));
  if(p == NULL){
    printf("error");
  }
  p->x = e;
  p->next = NULL;
  q->rear->next = p;
  q->rear = p;
}

int dequeue(linkQueue *q, int *e){
  if(q->front == q->rear)
  return -1;
  QueuePtr p;
  p = q->front->next;
  *e = p->x;
  q->front->next = p->next;
  if(q->rear == p){
    q->rear = q->front;
  }
  free(p);
}
int show(linkQueue *q){
  QueuePtr p;
  p =  q->front->next;
  while(p != NULL){
    printf("%d", p->x);
    p = p->next;
  }
}

int main(int argc, char const *argv[]) {
  linkQueue * q;
  initqueue(q);
  int i;
  for(i = 0; i < 6; i++){
  inqueue(q, i);
  }
  int e;
  dequeue(q, &e);
  printf("%d\n", e);
  show(q);
  return 0;
}
