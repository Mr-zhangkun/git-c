#include <stdio.h>
#include "stack.h"

linklist link_create(){
  linklist p;
  p = (linklist) malloc(sizeof(linknode));

  if (p == NULL){
    puts("error!");
    return 0;
  }
  p->data = 0;
  p->next = NULL;
  return p;
}

int push(linklist h, datatype value){
  linklist q;
  q = (linklist)malloc(sizeof(linknode));
  if(q == NULL){
    puts("error!");
    return -1;

  }
  q->data = value;
  q->next = h->next;
  h->next = q;

  return 0;
}
int pop(linklist h){
  if(h->next == NULL)
     puts("stack is empty!\n");
    return -1;
  }

  datatype num;
  linklist  p = h->next;
  num = p->data;
  h->next = p->next;
  free(p);

  return num;
}
void link_show(linklist p){
  linklist q;
  q = p->next;
  while(q != NULL){
    printf("%d ", q->data);
    q = q->next;
  }
  putchar(10);
}
