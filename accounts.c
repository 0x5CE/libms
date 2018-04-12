#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libms.h"


int changePass(libaccount *head, int key, char *password, char *newPass)
{	
	libaccount *current;
	current = head;

	if (strlen(password) < 1)
	{
		return -1;
	}

	if (findAccount(head, key))
	{	
		while (current->key != key)
		{
			current = current->next;
		}

		if (strcmp(password, current->password)==0)
		{
			strcpy(current->password, newPass);
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

int addAccount(libaccount *head, int key, int batch, char *department, char *name, char *book1, char *book2, char *book3, char *password)
{
	libaccount *current, *newA;
	current = head;

	if (key == 0)
	{
		return ERR_NOT_POSSIBLE;
	}
	
	if (strlen(password) < 1)
	{
		return -1;
	}

	if (!findAccount(head, key))
	{
		while (current->next != NULL)
		{
			current = current->next;
		}

		current->next = malloc(sizeof(libaccount));
		newA = current->next;
		newA->key = key;
		newA->batch = batch;
	
		strcpy(newA->department, department);
		strcpy(newA->name, name);
		strcpy(newA->book1, book1);
		strcpy(newA->book2, book2);
		strcpy(newA->book3, book3);
		strcpy(newA->password, password);
		newA->next = NULL;
		
		return 0;
	}
	else
	{
		return ERR_ALREADY_EXISTS;
	}
}

int findAccount(libaccount *head, int key)
{
	libaccount *current;
	current = head;

	int found = 0;
	
	if (key == 0)
	{
		return 0;
	}
	
	while ((current->key != key) && (current->next != NULL))
	{
		current = current->next;
	}

	if (current->key == key)
		found = 1;

	return found;
}


int addBook(libaccount *head, int key, char *password, char *bookName)
{
	
	libaccount *current;
	current = head;

	if (strlen(password) < 1)
	{
		return -1;
	}

	if (findAccount(head, key))
	{	
		while (current->key != key)
		{
			current = current->next;
		}

		if (strcmp(password, current->password)==0)
		{
			if (strcmp(current->book1, bookName) == 0)
			{
				return ERR_ALREADY_EXISTS;
			}	
			else if (strlen(current->book1) == 0)
			{
				strcpy(current->book1, bookName);
				return 0;
			}
			

			if (strcmp(current->book2, bookName) == 0)
			{
				return ERR_ALREADY_EXISTS;
			}	
			else if (strlen(current->book2) == 0)
			{
				strcpy(current->book2, bookName);
				return 0;
			}

			if (strcmp(current->book3, bookName) == 0)
			{
				return ERR_ALREADY_EXISTS;
			}	
			else if (strlen(current->book3) == 0)
			{
				strcpy(current->book3, bookName);
				return 0;
			}

			return ERR_ENOUGH_BOOKS;	//No empty slot
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

int removeBook(libaccount *head, int key, char *password, int bookN)
{
	
	libaccount *current;
	current = head;

	if (strlen(password) < 1)
	{
		return -1;
	}

	if (findAccount(head, key))
	{	
		while (current->key != key)
		{
			current = current->next;
		}
	
		if (strcmp(password, current->password)==0)
		{
	
			switch(bookN)
			{	
				case 1:
				if (strlen(current->book1) != 0)
				{
					strcpy(current->book1, "");
					return 0;
				}
				else
				{
					return ERR_ALREADY_EXISTS;
				}
				break;
	
				case 2:
				if (strlen(current->book2) != 0)
				{
					strcpy(current->book2, "");
					return 0;
				}
				else
				{
					return ERR_ALREADY_EXISTS;
				}
				break;

				case 3:
				if (strlen(current->book3) != 0)
				{
					strcpy(current->book3, "");
					return 0;
				}
				else
				{
					return ERR_ALREADY_EXISTS;
				}
				break;

				default: 
					return ERR_NOT_FOUND;
				break;
			}
		}
		else
		{
				return ERR_WRONG_PASSWORD;	
		}
		return 0;
	}
	else
	{
		return ERR_NOT_FOUND;
	}
}

int removeAccount(libaccount *head, int key, char *password)
{	
	libaccount *current, *previous;
	previous = head;
	current = head;


	if (findAccount(head, key))
	{
		while (current->key != key)
		{	
			previous = current;
			current = current->next;
		}
		
		if (strcmp(password, current->password)==0)
		{
			previous->next = current->next;	
			free(current);
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
