#include <stdlib.h>
typedef int datatype;

typedef struct node{
  datatype data;
  struct node *next;
}linknode, *linklist;

linklist link_create();
int push(linklist h, datatype value);
int pop(linklist h);
void link_show(linklist p);
