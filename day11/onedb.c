#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define M 32
#define N 128

int do_insert(sqlite3 *db);
int do_delete(sqlite3 *db);
int do_show(sqlite3 *db);
int do_update(sqlite3 *db);
//int call_back(void *param, int colum, char **value, char **name );

int main(int argc, char *argv[]) {
  sqlite3 *db;
  char *errmsg;
  char clean[M];
  int cmd;

  if (sqlite3_open("./one.db", &db ) != SQLITE_OK){
    printf("%s\n", sqlite3_errmsg(db));
    return -1;
  }

  int ret;
  if((ret = sqlite3_exec(db,"create table stu(id int, name vchar(32) not null, score int not null)", NULL, NULL, &errmsg)) != SQLITE_OK){
    if (ret != 1){
      printf("%s\n", errmsg);
      sqlite3_close(db);
      return -1;
    }
  }
  while(1){
    printf("\e[32m*** 1:insert  2:delete  3:show  4:update  5:quit ***\e[0m\n");
    printf("输入你的命令 > ");

    if(scanf("%d", &cmd) != 1){
      puts("input error");
      fgets(clean, sizeof(clean), stdin);
      continue;
    }

    switch (cmd){
      case 1:
      do_insert(db);
      break;
      case 2:
      do_delete(db);
      break;
      case 3:
      do_show(db);
      break;
      case 4:
      do_update(db);
      break;
      case 5:
      goto RET;
      default:
      break;
    }
  }

  RET:
    sqlite3_close(db);
  return 0;
}

int do_insert(sqlite3 *db){
  int id;
  char name[M] = {0};
  int score;
  char sql[N] = {0};
  char *errmsg;

  printf("input student id > ");
  scanf("%d", &id);

  printf("input student name > ");
  scanf("%s", name);

  printf("input student score > ");
  scanf("%d", &score);

  sprintf(sql,"insert into stu values(%d, '%s', %d)",id, name, score);
  if (sqlite3_exec(db,sql,NULL, NULL, &errmsg) != SQLITE_OK){
    printf("%s\n", errmsg);
    return -1;
  }
  printf("\e[32minsert OK !\e[0m\n");
  return 0;
}

int do_delete(sqlite3 *db){
  int id;
  char sql[N] = {0};
  char *errmsg;

  printf("please input student id > ");
  scanf("%d", &id);

  sprintf(sql,"delete from stu where id = %d",id);

  if (sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK){
    printf("%s\n", errmsg);
    return -1;
  }
  printf("\e[32mdelete OK!\e[0m\n");
  return 0;
}

int do_update(sqlite3 *db){
  int id;
  int score;
  char sql[N] = {0};
  char *errmsg;

  printf("please input student id >> ");
  scanf("%d",&id);

  printf("please input student score >> ");
  scanf("%d",&score);

  sprintf(sql,"update stu set score = %d where id = %d",score, id);

  if (sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK){
    printf("%s\n", errmsg);
    return -1;
  }
  puts("update OK !");
  return 0;
}

int do_show(sqlite3 *db){
  char *errmsg;
  char **result, **temp;
  int nrow, ncolumn, i, j;

  if(sqlite3_get_table(db, "select * from stu", &result, &nrow, &ncolumn, &errmsg) != SQLITE_OK){
    printf("%s",errmsg);
    return -1;
  }
  else{
    temp = result;
    for(i = 0; i < nrow + 1; i++){
      for(j = 0; j < ncolumn; j++){
        printf("%-15s", *(temp++));
      }
        putchar(10);
    }
    sqlite3_free_table(result);
    printf("\e[32mshow OK !\e[0m\n");
    return 0;
  }
}
