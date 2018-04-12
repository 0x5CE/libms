/*libmsadd.c

Adds new account, given its CMS ID, batch, name, department, book 1, book 2, book 3.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libms.h"

int main()
{
	char CGIInData[100];

	head = malloc(sizeof(libaccount));

	head->key = -1;
	head->next = NULL;

	head2 = malloc(sizeof(CGIIn));
	
	head2->key[0] = '\0';
	head2->value[0] = '\0';

	head2->next = NULL;

	scanf(" %s", CGIInData);	//Data from POST request

	loadFile();
	redrawPage();
	printf("<div>\n");

	organizeCGIInput(CGIInData);

	int error_status = addAccount(head, atoi(CGIFindValue("scmsid")), atoi(CGIFindValue("sbatch")), CGIFindValue("sdepartment"), CGIFindValue("sname"), CGIFindValue("sbook1"), CGIFindValue("sbook2"), CGIFindValue("sbook3"), CGIFindValue("spass"));


	if (error_status == 0)
	{
		printf("<p class=\"success\">Account created.</p>\n");
	}
	else if (error_status == ERR_ALREADY_EXISTS)
	{
		printf("<p class=\"error\">Account already exists.</p>\n");
	}
	else if (error_status == ERR_WRONG_PASSWORD)
	{
		printf("<p class=\"error\">Not allowed.</p>\n");
	}
	else
	{
		printf("<p class=\"error\">Unspecified error.</p>\n");
	}


	printf("<p><form method=\"get\" action=\"/index.html\"><input type=\"submit\" input value=\"Back\"></form></p>\n");

	printf("</div>\n");
	printf("\n\n</BODY>\n\n</HTML>\n");

	saveFile();

	return 0;
}

int redrawPage()
{
	outHeaders();

	return 0;
}
