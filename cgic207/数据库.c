#if 1
#define SERVER_NAME cgiServerName
#endif
#if 0
#endif
#define SAVED_ENVIRONMENT "/tmp/cgicsave.env"
#include <stdio.h>
#include "cgic.h"
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>

int HandleSubmit();
void ShowForm();
int Name();
int do_insert(int *id, char *name, int *score);
int do_delet(int *id);
int do_updata(int *score, int *id);
void Show();
void showdata();
int flag = 0;
sqlite3 *db;
int cgiMain() {
	cgiHeaderContentType("text/html");
	fprintf(cgiOut, "<HTML><HEAD>\n");
	fprintf(cgiOut, "<meta charset=\"UTF-8\">\n");
	fprintf(cgiOut, "<TITLE>cgic test</TITLE></HEAD>\n");
	fprintf(cgiOut,"<body background=\"http://pic.90sjimg.com/design/00/36/23/81/55e1b9f78f25d.jpg\">");
	fprintf(cgiOut,"<body style=\"background-color:#f2f2f2\">");
	fprintf(cgiOut, "<BODY><H1 style=\"color:red;text-align:center\">学生管理系统</H1>\n");
	fprintf(cgiOut, "<font><img src=\"http://www.sxdtdx.edu.cn/images/hlogo.png\" width=\"318.99\" height=\"80\"></font>");
	fprintf(cgiOut, "<font><img src=\"http://www.sxdtdx.edu.cn/images/biaoyu.png\" width=\"400\" height=\"70\" align =\"right\"> </font>");
	if ((cgiFormSubmitClicked("testcgic") == cgiFormSuccess) ||
	cgiFormSubmitClicked("saveenvironment") == cgiFormSuccess)
	{
		HandleSubmit();
		fprintf(cgiOut, "<hr>\n");
	}
	if ((cgiFormSubmitClicked("showdata")) == cgiFormSuccess){
		showdata();
	}
	if ((cgiFormSubmitClicked("showdata")) != cgiFormSuccess){
		ShowForm();
	}

	fprintf(cgiOut, "</BODY></HTML>\n");
	return 0;
}

int HandleSubmit()
{
	char *errmsg;
	int ret;
	if (sqlite3_open("./db/my.db", &db ) != SQLITE_OK){
		printf("%s\n", sqlite3_errmsg(db));
		return -1;
	}
	if((ret = sqlite3_exec(db,"create table stu(id int, name vchar(32) not null, score int not null)", NULL, NULL, &errmsg)) != SQLITE_OK){
		if (ret != 1){
			printf("%s\n", errmsg);
			sqlite3_close(db);
			return -1;
		}

	}
	Name();

	sqlite3_close(db);
}

int Name() {
	char name[81];
	char id[81], delid[81], updataid[81];
	char score[81], updatascore[81];
	int idt, scoret, idtt, idttt,scorett;

	cgiFormStringNoNewlines("id", id, 81);
	cgiFormStringNoNewlines("name", name, 81);
	cgiFormStringNoNewlines("score", score, 81);
	cgiFormStringNoNewlines("delid", delid, 81);
	cgiFormStringNoNewlines("updatascore", updatascore, 81);
	cgiFormStringNoNewlines("updataid", updataid, 81);
	//cgiHtmlEscape(id);
	//cgiHtmlEscape(name);
	//cgiHtmlEscape(score);
	idt = atoi(id);
	idtt = atoi(delid);
	scoret = atoi(score);
	idttt = atoi(updataid);
	scorett = atoi(updatascore);

	fprintf(cgiOut, "<BR>\n")	;
	if(idt != 0 || idtt != 0 || idttt != 0){
		if(idt != 0){
			do_insert(&idt, name, &scoret);
		}

		do_delet(&idtt);
		do_updata(&scorett, &idttt);
	printf("<div class=\"center\"><h3 style=\"color:red;\">--------------------------------------------提交成功!--------------------------------------------</h3></div>");
	}
	else{
		flag = 1;
	printf("<div class=\"center\"><h3 style=\"color:red;\">--------------------------------------------提交失败!--------------------------------------------</h3></div>");
	}
	return 0;
}


int do_insert(int *id, char *name, int *score){
	char sql[1024];
	char *errmsg;
	sprintf(sql,"insert into stu values(%d, '%s', %d)",*id, name, *score);
	if (sqlite3_exec(db,sql,NULL, NULL, &errmsg) != SQLITE_OK){
		printf("%s\n", errmsg);
		return -1;
	}
}

int do_delet(int *id){
	char sql[1024] = {0};
	char *errmsg;
	sprintf(sql, "delete from stu where id = %d", *id);

	if (sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
	{
		printf("%s\n", errmsg);
		return -1;
	}
	return 0;
}

int do_updata(int *score, int *id){
	char *errmsg;
	char sql[1024];
	sprintf(sql, "update stu set score = %d  where id = %d", *score, *id);
	if (sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK){
		printf("%s\n", errmsg);
		return -1;
	}
}

void showdata() {
	char *errmsg;
	char **result, **temp;
	int nrow;
	int ncolumn;
	int i, j;
	if (sqlite3_open("./db/my.db", &db ) != SQLITE_OK){
		printf("%s\n", sqlite3_errmsg(db));
	}

	if (sqlite3_get_table(db, "select * from stu order by id", &result, &nrow, &ncolumn, &errmsg) != SQLITE_OK)
	{
		printf("%s\n", errmsg);
	}
	else
	{
		temp = result;
		printf("<table width=\"400\" border=\"1\" align=\"center\" bgcolor=\"#99CCCC\">");
		printf("<caption><h3>学生成绩查询</h3></caption>");
		for (i = 0; i < nrow + 1; i++)
		{
			printf("<tr>");
			for (j = 0; j < ncolumn; j++){
				fprintf(cgiOut,"<td align=\"center\">%-15s</td>", *(temp++));
			}
			fprintf(cgiOut,"<tr/>");
		}
		printf("</table>");
	}
	sqlite3_close(db);

	fprintf(cgiOut,"<div style=\"text-align:center;\">");
	fprintf(cgiOut, "<p>\n");
	fprintf(cgiOut,"<input type=\"button\"   value=\"返回\" onclick=\"window.location.href='http://localhost/cgi-bin/shujvku'\" >");
	//fprintf(cgiOut,"<a  href=\"http://localhost/cgi-bin/shujvku\">返回</a>");
	fprintf(cgiOut,"</div>");
}

void ShowForm()
{
	fprintf(cgiOut,"<style>.center{margin:auto;width:40%%;}</style>");
	fprintf(cgiOut,"<div class=\"center\">");
	fprintf(cgiOut, "<!-- 2.0: multipart/form-data is required for file uploads. -->");
	fprintf(cgiOut, "<form method=\"POST\" enctype=\"multipart/form-data\" ");
	fprintf(cgiOut, "action=\"");
	cgiValueEscape(cgiScriptName);
	fprintf(cgiOut, "\">\n");
	fprintf(cgiOut, "<p>\n");
	fprintf(cgiOut,"<ul><h3><li>插入数据</h3></ul>");
	fprintf(cgiOut, "学号:<input type=\"text\" name=\"id\"size=\"10\"\n>");
	if(flag){
		printf("<font style=\"color:red;\">*ID不能为空</font>\n");
}
	fprintf(cgiOut, "姓名:<input type=\"text\" name=\"name\" size=\"10\">\n");
	fprintf(cgiOut, "成绩:<input type=\"text\" name=\"score\" size=\"10\">\n");
	fprintf(cgiOut, "<ul><h3><li>修改数据</h3></ul>");
	fprintf(cgiOut, "更新学号为:<input type=\"text\" name=\"updataid\" size=\"10\">\n");
	fprintf(cgiOut, "的成绩为:<input type=\"text\" name=\"updatascore\" size=\"10\">\n");
	fprintf(cgiOut, "<ul><h3><li>删除数据</h3></ul>");
	fprintf(cgiOut, "删除学号:<input type=\"text\" name=\"delid\" size=\"10\">\n");
	fprintf(cgiOut,"<p>");
	fprintf(cgiOut,"<input type=\"submit\" name=\"saveenvironment\" value=\"提交\">\n");
	fprintf(cgiOut,"<input type=\"submit\" name=\"showdata\" value=\"查询\">\n");
	fprintf(cgiOut,"</form>\n");
	fprintf(cgiOut,"</div>");
}

