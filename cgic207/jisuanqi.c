#if 1
#define SERVER_NAME cgiServerName
#endif
#if 0
#define SERVER_NAME "www.boutell.com"
#endif
#define SAVED_ENVIRONMENT "/tmp/cgicsave.env"

#include <stdio.h>
#include "cgic.h"
#include <string.h>
#include <stdlib.h>


void HandleSubmit();
void ShowForm();
void CookieSet();
void Name();
void RadioButtons();
void Cookies();
void LoadEnvironment();
void SaveEnvironment();

int cgiMain() {
#ifdef DEBUG
	LoadEnvironment();
#endif /* DEBUG */
	/* Load a previously saved CGI scenario if that button
		has been pressed. */
	if (cgiFormSubmitClicked("loadenvironment") == cgiFormSuccess) {
		LoadEnvironment();
	}
	/* Set any new cookie requested. Must be done *before*
		outputting the content type. */
	CookieSet();
	/* Send the content type, letting the browser know this is HTML */
	cgiHeaderContentType("text/html");
	/* Top of the page */
	fprintf(cgiOut, "<HTML><HEAD>\n");
	fprintf(cgiOut, "<TITLE>cgic test</TITLE></HEAD>\n");
	fprintf(cgiOut, "<BODY><H1>cgic test</H1>\n");
	/* If a submit button has already been clicked, act on the
		submission of the form. */
	if ((cgiFormSubmitClicked("testcgic") == cgiFormSuccess) ||
		cgiFormSubmitClicked("saveenvironment") == cgiFormSuccess)
	{
		HandleSubmit();
		fprintf(cgiOut, "<hr>\n");
	}
	/* Now show the form */
	ShowForm();
	/* Finish up the page */
	fprintf(cgiOut, "</BODY></HTML>\n");
	return 0;
}

void HandleSubmit()
{
	Name();
 RadioButtons();
  if (cgiFormSubmitClicked("saveenvironment") == cgiFormSuccess) {
		SaveEnvironment();
	}
}

void Name() {
	char name[81];
	cgiFormStringNoNewlines("name", name, 81);
	//fprintf(cgiOut, "Name: ");
	cgiHtmlEscape(name);
	fprintf(cgiOut, "<BR>\n");
}

char *ages[] = {
	"0",
	"1",
	"2",
	"3"
};
void RadioButtons() {
	int ageChoice,i, j, k;
	char ageText[10];
	char m[32];
	char n[32];

  cgiFormRadio("age", ages, 4, &ageChoice, 0);
	k = atoi(ages[ageChoice]);
	cgiFormString("oo",m, 82);
	i = atoi(m);
	cgiFormString("pp",n, 82);
	j = atoi(n);
	if (k == 0){
		fprintf(cgiOut,"a + b = %d", i + j);
	}
	else if(k == 1){
		fprintf(cgiOut,"a - b = %d", i - j);
	}
	else if(k == 2){
		fprintf(cgiOut,"a * b = %d", i * j);
	}
	else {
		fprintf(cgiOut,"a / b = %d", i / j);
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
	fprintf(cgiOut, "ji suan qi\n");
	fprintf(cgiOut, "<p>\n");
	fprintf(cgiOut, "a=<input type=\"text\" name=\"oo\">\n");
  fprintf(cgiOut, "<p>\n");
  fprintf(cgiOut, "<input type=\"radio\" name=\"age\" value=\"0\">+\n");
	fprintf(cgiOut, "<input type=\"radio\" name=\"age\" value=\"1\">-\n");
	fprintf(cgiOut, "<input type=\"radio\" name=\"age\" value=\"2\" checked>*\n");
	fprintf(cgiOut, "<input type=\"radio\" name=\"age\" value=\"3\">/\n");
  fprintf(cgiOut, "<p>\n");
	fprintf(cgiOut, "b=<input type=\"text\" name=\"pp\">\n");
	fprintf(cgiOut, "<input type=\"submit\" name=\"saveenvironment\" value=\"=\">\n");
	fprintf(cgiOut, "<p>\n");
  fprintf(cgiOut, "</form>\n");
}

  void CookieSet()
  {
  	char cname[1024];
  	char cvalue[1024];

  	cgiFormString("cname", cname, sizeof(cname));
  	cgiFormString("cvalue", cvalue, sizeof(cvalue));
  	if (strlen(cname)) {

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
  		fprintf(cgiOut, /*"<p>Environment saved. Click this button "
  			"to restore it, playing back exactly the same "
  			"scenario: "*/
  			"<form method=POST action=\"");
  		cgiValueEscape(cgiScriptName);

  	}
  }
