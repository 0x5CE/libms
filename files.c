#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libms.h"

int loadFile()
{
	
	FILE *myFile;
	libaccount *current = malloc(sizeof(libaccount));
	
	char buffer[10];


	myFile = fopen("acnts.bin", "r");
	
	if (myFile != NULL)
	{
		//Reading signature
		fread(buffer, 9, 1, myFile);


		while (fread(current, 1, sizeof(libaccount), myFile) == sizeof(libaccount))
		{
			addAccount(head, current->key, current->batch, current->department, current->name, current->book1, current->book2, current->book3, current->password);
		}

		fclose(myFile);
	return 0;
	}
	else
	{
		return ERR_FILE_IO;
	}
}


int saveFile()
{
	FILE *myFile;
	libaccount *current;
	current = head->next;


	//Adding signature
	myFile = fopen("acnts.bin", "wb");

	if (myFile != NULL)
	{
		fwrite("SIGN3NO\n", sizeof(char), 9, myFile);
		fclose(myFile);


		myFile = fopen("acnts.bin", "ab");

		if (myFile != NULL)
		{
			while (current != NULL)
			{
				fwrite(current, sizeof(libaccount), 1, myFile);

				current = current->next;
			}
			fclose(myFile);
			return 0;
		}
		else
		{
			return ERR_FILE_IO;
		}
	}
	else
	{
		return ERR_FILE_IO;
	}
}
