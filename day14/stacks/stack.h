#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int x;
  struct node *pri, *next;
}Node;

Node * creat(int val);
Node *insert(Node * h,int val);
void show(Node * h);
Node *del(Node * h, int val);
Node * insert_1(Node *h,int val,int val1);
