#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node{
  datatype data;
  struct node *next;
}linknode, *linklist;

linklist link_create(){
  linklist p;
  p = (linklist) malloc(sizeof(linknode));

  if (p == NULL){
    puts("error!");
    return 0;
  }
  p->next = NULL;
  return p;
}

int link_headerin(linklist p, datatype value){
  linklist q;
  q = (linklist)malloc(sizeof(linknode));
  if(q == NULL){
    puts("error!");
    return 0;

  }
  q->data = value;
  q->next = NULL;
  q->next = p->next;
  p->next = q;

  return 1;
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

int main(){
  linklist p;
  if((p = link_create()) == NULL){
    puts("error!");
    return 0;
  }
  int i, a[5] = {6, 4, 3, 2, 1};
  for(i = 0; i < 5; i++){
    if(link_headerin(p,a[i]) == 0){
      return 0;
    }
  }
  link_show(p);
  return 0;
}
