/*libmsrmb.c

Removes a book from the account.
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
	organizeCGIInput(CGIInData);

	redrawPage();

	int error_status = removeBook(head, atoi(CGIFindValue("scmsid")), CGIFindValue("spass"), atoi(CGIFindValue("sbookn")));

	if (error_status == 0)
	{
		printf("<p class=\"success\">Book removed.</p>\n");
	}
	else if (error_status == ERR_NOT_FOUND)
	{
		printf("<p class=\"error\">Account not found.</p>\n");
	}
	else if (error_status == ERR_WRONG_PASSWORD)
	{
		printf("<p class=\"error\">Wrong pssword.</p>\n");
	}
	else if (error_status == ERR_ALREADY_EXISTS)
	{
		printf("<p class=\"success\">Slot %d is already empty.</p>\n", atoi(CGIFindValue("sbookn")));
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

	printf("<form method=\"post\" action=\"/cgi-bin/libmsrmb\">\n"
	"\n"
	"<p>CMS ID<input type=\"number\" value=\"%s\" name=\"scmsid\" maxlength=90 size=\"25\" required></p>\n"
	"<p>Password<input type=\"password\" value=\"%s\" name=\"spass\" maxlength=90 SIZE=\"25\" required></p>\n"
	"\n"
	"<label>Book to remove</label>\n"
	"<select name=\"sbookn\">\n"
	"  <option value=\"1\">1</option>\n"
	"  <option value=\"2\">2</option>\n"
	"  <option value=\"3\">3</option>\n"
	"</select>\n"
	"\n"
	"<p><input type=\"submit\" name=\"submit\" value=\"Remove\"></p>\n"
	"</form>\n", CGIFindValue("scmsid"), CGIFindValue("spass"));

	return 0;
}
