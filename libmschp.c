/*libmschp.c

Changes the password.
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


	if (strcmp(CGIFindValue("spass1"), CGIFindValue("spass2")) == 0)
	{
		int error_status = changePass(head, atoi(CGIFindValue("scmsid")), CGIFindValue("spass"), CGIFindValue("spass1"));
	
		if (error_status == 0)
		{
			printf("<p class=\"success\">Password changed.</p>\n");
		}
		else if (error_status == ERR_NOT_FOUND)
		{
			printf("<p class=\"error\">CMS ID not found.</p>\n");
		}
		else if (error_status == ERR_WRONG_PASSWORD)
		{
			printf("<p class=\"error\">Wrong pssword.</p>\n");
		}
		else
		{
			printf("<p class=\"error\">Unspecified error.</p>\n");
		}
	}
	else
	{
		printf("<p class=\"error\">New passwords do not match.</p>\n");
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
