#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Books{
  int book_id;
  struct Books * next;
}node;
int insert(struct Books * head, int val);
void show(struct Books * head);
int del(struct Books * p, int val);

int main(){
  struct Books head;
  //struct Books * p2;
  //p2 = &head;
  head.book_id = 100;
  head.next = NULL;
  insert(&head, 101);
  insert(&head, 102);
  insert(&head, 103);
  insert(&head, 104);
  insert(&head, 105);
  show(&head);
  del(&head,104);
  show(&head);
  return 0;
}
int insert(struct Books * p1, int val){
  struct Books * p = NULL;
  p = malloc(sizeof(struct Books));
  if(NULL == p){
    printf("error");
  }
  p->book_id = val;
  p->next = NULL;
  while((p1->next) != NULL){
    p1 = p1->next;
}
  p1->next = p;
  return 0;
}
void show(struct Books * head){
  while((head) != NULL){
    printf("%d\n", head->book_id);
    head = head->next;
  }
}
int del(struct Books * p, int val){
  struct Books * cur, * pre;
  cur = p;
  if(cur->book_id == val){
    cur = cur->next;
    free(cur);
  }
  else{
    while(cur != NULL && cur->book_id != val){
      pre = cur;
      cur = cur->next;
    }
    if(cur != NULL){
      pre->next = cur->next;
      free(cur);
    }
  }
  return 0;
}
