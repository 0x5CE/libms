/*libmsadb.c

Adds a book to the account.
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

	int error_status = addBook(head, atoi(CGIFindValue("scmsid")), CGIFindValue("spass"), CGIFindValue("sbook"));
	
	if (error_status == 0)
	{
		printf("<p class=\"success\">\"%s\" added.</p>\n", CGIFindValue("sbook"));
	}
	else if (error_status == ERR_NOT_FOUND)
	{
		printf("<p class=\"error\">Account not found.</p>\n");
	}
	else if (error_status == ERR_WRONG_PASSWORD)
	{
		printf("<p class=\"error\">Wrong pssword.</p>\n");
	}
	else if (error_status == ERR_ENOUGH_BOOKS)
	{
		printf("<p class=\"error\">Books limit (3) reached.</p>\n");
	}
	else if (error_status == ERR_ALREADY_EXISTS)
	{
		printf("<p class=\"error\">Book \"%s\" already in the list.</p>\n", CGIFindValue("sbook"));
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

	printf("<form method=\"post\" action=\"/cgi-bin/libmsadb\">\n"

	"<p>CMS ID<input type=\"number\" value=\"%s\" name=\"scmsid\" maxlength=90 size=\"25\" required></p>\n"
	"<p>Password<input type=\"password\" value=\"%s\" name=\"spass\" maxlength=90 SIZE=\"25\" required></p>\n"

	"<p>Book<input type=\"text\" value=\"%s\" name=\"sbook\" maxlength=90 SIZE=\"25\" required></p>\n"

	"<p><input type=\"submit\" name=\"submit\" value=\"Add\"></p>\n"

	"</form>\n", CGIFindValue("scmsid"), CGIFindValue("spass"), CGIFindValue("sbook"));

	return 0;
}
