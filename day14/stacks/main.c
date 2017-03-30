#include "stack.h"

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
