## C-SQlite
### 打开/创建一个数据库
sqlite3_open("test.db", &db)
```c
sqlite3 *db;
  if (sqlite3_open("./one.db", &db ) != SQLITE_OK){
    printf("%s\n", sqlite3_errmsg(db));
    return -1;
  }
```
### 关闭一个数据库
sqlite3_close()

### 创建一个表
sqlite3_exec()
```c
  if((ret = sqlite3_exec(db,"create table stu(id int, name vchar(32) not null, score int not null)", NULL, NULL, &errmsg)) != SQLITE_OK){
    if (ret != 1){
      printf("%s\n", errmsg);
      sqlite3_close(db);
      return -1;
    }
  }
```
### 插入数据
do_insert()
```c
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
```
### 删除数据
do_delete()
```c
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
```
### 更新数据
do_update()
```c
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
```
### 显示数据
do_show()
sqlite3_get_table()
```c
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

```

















