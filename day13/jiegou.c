#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
struct {
  int number;
  char name [81];
  int on_hand;
}part1 = {528, "Disk drive", 10},
 part2 = {914, "Printer cable", 5};

int main(int argc, char const *argv[]) {
  printf("Part number: %d\n", part1.number);
  return 0;
}
*/


struct Books{
  char title[50];
  int book_id;
};

int main(int argc, char const *argv[]) {
  struct Books book = {"xxxxxxx", 1234};
  struct Books book1;
  book1.book_id = 1235;
  strcpy(book1.title,"yyyy");
  printf("%d", book.book_id);
  printf("%ld", sizeof(book));

  return 0;
}
