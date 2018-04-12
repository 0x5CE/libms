/*libmsdta.c

Shows data from all accounts, including passwords, provided that correct admin password is given.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libms.h"

int printAccounts(libaccount *head, char *admnpass);

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

	int error_status = printAccounts(head, CGIFindValue("spass"));

	if (error_status == ERR_WRONG_PASSWORD)
	{
		printf("<p class=\"error\">Wrong pssword.</p>\n");
	}
	else if (error_status != 0)
	{
		printf("<p class=\"error\">Unspecified error.</p>\n");
	}

	printf("<p><form method=\"get\" action=\"/index.html\"><input type=\"submit\" input value=\"Back\" style=\";width:100px; display: block; margin: auto;\"></form></p>\n");

	printf("</div>\n");
	printf("\n\n</body>\n\n</html>\n");

	return 0;
}

int printAccounts(libaccount *head, char *admnpass)
{
	libaccount *current;
	current = head->next;

	if (strcmp(admnpass, ADMN_PASS) == 0)
	{
	printf("<table id=\"table1\">\n\n");

	printf("<tr><th>#</th> <th>Key</th> <th>Batch</th> <th>Department</th> <th>Name</th> <th>Book 1</th> <th>Book 2</th> <th>Book 3</th> <th>Password</th>\n");
	
	int n=1;
	while (current != NULL)
	{
		printf("<tr>\n");

		printf("<td>%d</td> <td>%d</td> <td>%d</td> <td>%s</td> <td>%s</td> <td>%s</td> <td>%s</td> <td>%s</td> <td>%s</td>\n", n, current->key, current->batch, current->department, current->name, current->book1, current->book2, current->book3, current->password); 
	
	
		printf("</tr>\n");
		current = current->next;
		n++;
	}
	printf("\n</table>");
	return 0;
	}
	else
	{
		return ERR_WRONG_PASSWORD;
	}
}

int redrawPage()
{
	outHeaders();

	return 0;
}
