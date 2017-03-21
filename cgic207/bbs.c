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
void CookieSet();
void Name();
void LoadEnvironment();
void SaveEnvironment();
int do_insert(int *id, char *name, int *score);
int do_delet(int *id);
int do_update(int *score, int *id);
void Show();
sqlite3 *db;

int cgiMain() {

	#ifdef DEBUG
	LoadEnvironment();
	#endif /* DEBUG */
	if (cgiFormSubmitClicked("loadenvironment") == cgiFormSuccess) {
		LoadEnvironment();
	}
	CookieSet();
	cgiHeaderContentType("text/html");
	fprintf(cgiOut, "<HTML><HEAD>\n");
	fprintf(cgiOut, "<TITLE>cgic test</TITLE></HEAD>\n");
	fprintf(cgiOut, "<BODY><H1>BBS</H1>\n");
	if ((cgiFormSubmitClicked("testcgic") == cgiFormSuccess) ||
	cgiFormSubmitClicked("saveenvironment") == cgiFormSuccess)
	{
		HandleSubmit();
		fprintf(cgiOut, "<hr>\n");
	}
	ShowForm();
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
	if (cgiFormSubmitClicked("saveenvironment") == cgiFormSuccess) {
		SaveEnvironment();
	}
	sqlite3_close(db);
}

void Name() {
	char name[81];
	char id[81], delid[81], updateid[81];
	char score[81], updatescore[81];
	int idt, scoret, idtt, idttt,scorett;

	cgiFormStringNoNewlines("id", id, 81);
	cgiFormStringNoNewlines("name", name, 81);
	cgiFormStringNoNewlines("score", score, 81);
	cgiFormStringNoNewlines("delid", delid, 81);
	cgiFormStringNoNewlines("updatescore", updatescore, 81);
	cgiFormStringNoNewlines("updateid", updateid, 81);
	idt = atoi(id);
	idtt = atoi(delid);
	scoret = atoi(score);
	idttt = atoi(updateid);
	scorett = atoi(updatescore);

	fprintf(cgiOut, "<BR>\n")	;
  if(idt != 0){
	do_insert(&idt, name, &scoret);
	}
	if(idt == 0){
	do_delet(&idtt);
	}
	do_update(&scorett, &idttt);
	Show();
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

int do_update(int *score, int *id){
	char *errmsg;
	char sql[1024];
	sprintf(sql, "update stu set score = %d  where id = %d", *score, *id);
if (sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
{
	printf("%s\n", errmsg);
	return -1;
}
}

void Show() {
	if (cgiFormCheckboxSingle("show") == cgiFormSuccess) {

	char *errmsg;
	char **result, **temp;
	int nrow;
	int ncolumn;
	int i, j;

	if (sqlite3_get_table(db, "select * from stu", &result, &nrow, &ncolumn, &errmsg) != SQLITE_OK)
	{
		printf("%s\n", errmsg);
	}
	else
	{
		temp = result;
		printf("<table border=\"1\">");
		for (i = 0; i < nrow + 1; i++)
		{
			printf("<tr>");
			for (j = 0; j < ncolumn; j++){
				fprintf(cgiOut,"<td>%-15s<td/>", *(temp++));
			}
			fprintf(cgiOut,"<tr/>");
		}
		printf("</table>");
	}
}
	else {
		fprintf(cgiOut, "<BR>\n");
	}
}
void ShowForm()
{
	fprintf(cgiOut, "<!-- 2.0: multipart/form-data is required for file uploads. -->");
	fprintf(cgiOut, "<form method=\"POST\" enctype=\"multipart/form-data\" ");
	fprintf(cgiOut, "	action=\"");
	cgiValueEscape(cgiScriptName);
	fprintf(cgiOut, "\">\n");
	fprintf(cgiOut, "<p>\n");
	fprintf(cgiOut, "ID:<input type=\"text\" name=\"id\">\n");
	fprintf(cgiOut, "Name:<input type=\"text\" name=\"name\">\n");
	fprintf(cgiOut, "Score:<input type=\"text\" name=\"score\">\n");
	fprintf(cgiOut,"<p>");
	fprintf(cgiOut, "Delete id:<input type=\"text\" name=\"delid\">\n");
	fprintf(cgiOut, "<p>\n");
	fprintf(cgiOut, "Update score:<input type=\"text\" name=\"updatescore\">\n");
	fprintf(cgiOut, "Where id:<input type=\"text\" name=\"updateid\">\n");
	fprintf(cgiOut, "<input type=\"checkbox\" name=\"show\" checked>Show\n");
	fprintf(cgiOut, "<p>\n");


	fprintf(cgiOut, "<input type=\"submit\" name=\"saveenvironment\" value=\"Save Environment\">\n");
	fprintf(cgiOut, "</form>\n");
}

void CookieSet()
{
	char cname[1024];
	char cvalue[1024];
	/* Must set cookies BEFORE calling cgiHeaderContentType */
	cgiFormString("cname", cname, sizeof(cname));
	cgiFormString("cvalue", cvalue, sizeof(cvalue));
	if (strlen(cname)) {
		/* Cookie lives for one day (or until browser chooses
		to get rid of it, which may be immediately),
		and applies only to this script on this site. */
		cgiHeaderCookieSetString(cname, cvalue,
			86400, cgiScriptName, SERVER_NAME);
		}
	}

	void LoadEnvironment()
	{
		if (cgiReadEnvironment(SAVED_ENVIRONMENT) !=
		cgiEnvironmentSuccess)
		{
			cgiHeaderContentType("text/html");
			fprintf(cgiOut, "<head>Error</head>\n");
			fprintf(cgiOut, "<body><h1>Error</h1>\n");
			fprintf(cgiOut, "cgiReadEnvironment failed. Most "
			"likely you have not saved an environment "
			"yet.\n");
			exit(0);
		}
		/* OK, return now and show the results of the saved environment */
	}

	void SaveEnvironment()
	{
		if (cgiWriteEnvironment(SAVED_ENVIRONMENT) !=
		cgiEnvironmentSuccess)
		{
			fprintf(cgiOut, "<p>cgiWriteEnvironment failed. Most "
			"likely %s is not a valid path or is not "
			"writable by the user that the CGI program "
			"is running as.<p>\n", SAVED_ENVIRONMENT);
		} else {
		fprintf(cgiOut, "<p>Environment saved. Click this button "
			"to restore it, playing back exactly the same "
			"scenario: "
			"<form method=POST action=\"");
		cgiValueEscape(cgiScriptName);
		fprintf(cgiOut, "\">"
			"<input type=\"submit\" "
			"value=\"Load Environment\" "
			"name=\"loadenvironment\"></form><p>\n");
	}
}
