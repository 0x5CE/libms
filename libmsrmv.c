/*libmsadd.c

Removes an account, given its CMS ID and password.
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

	organizeCGIInput(CGIInData);

	int error_status = removeAccount(head, atoi(CGIFindValue("scmsid")), CGIFindValue("spass"));
	
	if (error_status == 0)
	{
		printf("<p class=\"success\">Account removed.</p>\n");
	}
	else if (error_status == ERR_NOT_FOUND)
	{
		printf("<p class=\"error\">Not found.</p>\n");
	}
	else if (error_status == ERR_WRONG_PASSWORD)
	{
		printf("<p class=\"error\">Wrong pssword.</p>\n");
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

	printf("<div>\n");

	printf("<form method=\"post\" action=\"/cgi-bin/libmsrmv\">\n");
	printf("<p>CMS ID<input type=\"number\" name=\"scmsid\" maxlength=90 size=\"25\" required></p>\n");
	printf("<p>Password <input type=\"password\" name=\"spass\" maxlength=90 SIZE=\"25\" required></p>\n");
	printf("<p><input type=\"submit\" name=\"submit\" value=\"Remove\"></p>\n");
	printf("</form>\n");

	return 0;
}
