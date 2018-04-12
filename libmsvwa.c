/*libmsadd.c

Shows all of information about an account, given its CMS ID and password.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libms.h"

int viewAccount(libaccount *head, int key, char *password);

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

	int error_status = viewAccount(head, atoi(CGIFindValue("scmsid")), CGIFindValue("spass"));

	if (error_status == ERR_NOT_FOUND)
	{
		printf("<p class=\"error\">Not found.</p>\n");
	}
	else if (error_status == ERR_WRONG_PASSWORD)
	{
		printf("<p class=\"error\">Wrong pssword.</p>\n");
	}
	else if (error_status != 0)
	{
		printf("<p class=\"error\">Unspecified error.</p>\n");
	}

	printf("<p><form method=\"get\" action=\"/index.html\"><input type=\"submit\" input value=\"Back\"></form></p>\n");

	printf("</div>\n");
	printf("\n\n</BODY>\n\n</HTML>\n");

	return 0;
}

int viewAccount(libaccount *head, int key, char *password)
{
	libaccount *current;
	current = head;

	if (findAccount(head, key))
	{	
		while (current->key != key)
		{
			current = current->next;
		}
		
		if (strcmp(password, current->password)==0)
		{

			printf("<table id=\"table1\" style=\"width:100%%\">\n\n");

			printf("<tr><th width=\"10%%\">ID</th> <td>%d</td></tr> <tr><th width=\"10%%\">Batch</th> <td>%d</td></tr> <tr><th width=\"10%%\">Department</th> <td>%s</td></tr> <tr><th width=\"10%%\">Name</th> <td>%s</td></tr> <tr><th width=\"10%%\">Book 1</th> <td>%s</td></tr> <tr><th width=\"10%%\">Book 2</th> <td>%s</td></tr> <tr><th width=\"10%%\">Book 3</th> <td>%s</td></tr> <tr><th width=\"10%%\">Password</th> <td>%s</td></tr>\n", current->key, current->batch, current->department, current->name, current->book1, current->book2, current->book3, current->password); 

			printf("\n</table>");
			return 0;
		}
		else
		{	
			return ERR_WRONG_PASSWORD;		
		}
	}
	else
	{
		return ERR_NOT_FOUND;
	}

}

int redrawPage()
{
	outHeaders();

	printf("<div>\n");

	printf("<form method=\"post\" action=\"/cgi-bin/libmsvwa\">\n"

	"<p>CMS ID<input type=\"number\" value=\"%s\" name=\"scmsid\" maxlength=90 size=\"25\" required></p>\n"
	"<p>Password <input type=\"password\" value=\"%s\" name=\"spass\" maxlength=90 SIZE=\"25\" required></p>\n"

	"<p><input type=\"submit\" name=\"submit\" value=\"View\"></p>\n"

	"</form>\n", CGIFindValue("scmsid"), CGIFindValue("spass"));
	
	return 0;
}
