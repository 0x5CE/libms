#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libms.h"


int outHeaders()
{
	//CGI and HTML headers
	printf("Content-Type: text/html\n\n");

	printf("<!doctype html\n\n");
	printf("<html>\n\n");

	printf("<head>\n");
	printf("<title>Library Management System | FoCP Project</title>\n");

	//CSS code
	printf("<style>\n");
	printf("table, th, td { border: 1px solid black;\nborder-collapse: collapse;}\n");
	printf("th, td {\npadding: 5px; text-align: left;}\n");
	printf("p.error {color: red;}\n");
	printf("p.success {color: green;}\n");

	printf("input[type=text], input[type=number], input[type=password], select {"
	"width: 100%%;"
	"padding: 10px 10px;"
	"margin: 8px 0;"
	"display: inline-block;"
	"border: 1px solid #ccc;"
	"border-radius: 4px;"
	"box-sizing: border-box;"
	"}"
	""
	""
	"input[type=submit] {"
	"width: 100%%;"
	"background-color: #5ea8d1;"
	"color: white;"
	"border-radius: 4px;"
	"box-sizing: border-box;"
	"border: 1px solid #ccc;"
	"padding: 12px 20px;"
	"background-color: "
	"}"
	""
	"input[type=submit]:hover {"
	"background-color: #4b87a8;"
	"}"
	""
	"div {"
	"width: 400px;"
	"border-radius: 5px;"
	"margin: 0 auto;"
	"background-color: #f0f0f0;"
	"padding: 20px;"
	"}"
	""
	"html, body, h1, h2, h3, h4, h5, h6 {"
	"font-family: \"Helvetica\", cursive, sans-serif;}"
	""
	"table {"
	"margin: 0 auto;}"
	""
	"#table1 td, #table1 th {"
	"border: 1px solid #ddd;"
	"padding-left: 15px;"
	"padding-right: 15px;"
	"padding: px;"
	"}"
	""
	"#table1 tr:nth-child(even) {"
	"background-color: #f0f0f0;"
	"}"
	""
	"#table1 th {"
	"padding-top: 15px;"
	"padding-bottom: 15px;"
	"padding-left: 15px;"
	"padding-right: 15px;"
	"text-align: left;"
	"background-color: #5ea8d1;"
	"color: white;"
	"}"
	""
	"#table1 tr:hover {"
	"background-color: #ddd;"
	"}"
	""
	"\n");

	printf("</style>\n");
	printf("</head>\n\n");

	printf("<body>\n\n");

	return 0;
}

int organizeCGIInput(char *buffer)
{
	int bufferLength = strlen(buffer);


	char myKey[100];
	char myVal[100];


	int bufferPtr = 0;	//Roughly separates values/keys from each other by marking their starting value each time

	int token = 0; 		//when two tokens (=/&) are found, we have key-value pair

	for (int i=0; i<bufferLength; i++)
	{
		if (*(buffer+i) == '=')		//Before '=' is key
		{
			strncpy(myKey, (buffer+bufferPtr), (i-bufferPtr));
			myKey[i-bufferPtr] = '\0';

			bufferPtr = i+1;	//'=' not included in next token

			token++;
		}	

		else if (*(buffer+i) == '&')	//Before '&' is value
		{
			strncpy(myVal, (buffer+bufferPtr), (i-bufferPtr));
			myVal[i-bufferPtr] = '\0';

			bufferPtr = i+1;

			token++;
		}	

		else if (*(buffer+i+1) == '\0')	//Last token is value
		{
			strncpy(myVal, (buffer+bufferPtr), (i-bufferPtr+1));
			myVal[i-bufferPtr+1] = '\0';

			bufferPtr = i+1;

			token++;
		}

		else if (*(buffer+i) == '+')
		{
			*(buffer+i) = ' ';
		}

		if (token >= 2)
		{
			CGIAddNode(head2, myKey, myVal);
			token = 0;
		}		
	}
	return 0;	
}

int CGIAddNode(CGIIn *head2, char *key, char *value)
{
	CGIIn *current, *newA;
	current = head2;

	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = malloc(sizeof(CGIIn));
	newA = current->next;
	
	strcpy(newA->key, key);
	strcpy(newA->value, value);

	newA->next = NULL;
	
	return 0;
}

char *CGIFindValue(char *key)
{
	CGIIn *current;
	current = head2;

	int found = 0;

	while (strcmp(current->key, key) != 0 && (current->next != NULL))
	{
		current = current->next;
	}

	if (strcmp(current->key, key) == 0)
	{
		return current->value;
	}
	else
	{
		printf("Not found.<br>\n");
		return '\0';
	}
}

int CGIPrintNodes(CGIIn *head2)
{
	CGIIn *current, *newA;
	current = head2->next;

	while (current != NULL)
	{
		printf("%s, %s\n<br>", current->key, current->value);
		current = current->next;
	}

	return 0;
}

