#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
  int data;
  struct node *next;
}linknode, *linklist;

int main(int argc, char const *argv[]) {

struct node * head = NULL;
head = malloc(sizeof(struct node));
struct node * p = NULL;
p = malloc(sizeof(struct node));
if (head == NULL)
{}
  head->data = 10;
  p->data = 20;
  head->next = p;
  p->next = NULL;
  printf("%d",head->data);
  printf("%d",p->data);
  printf("%p",head->next);
  free(head);
  return 0;
}
