//Linked-list of accounts

typedef struct libaccount
{
	int key;

	int batch;
	char department[40];
	char name[60];
	char book1[100];
	char book2[100];
	char book3[100];

	char password[100];

	struct libaccount *next;
}libaccount;

//Organized data processed from HTML POST/GET request

typedef struct CGIIn
{
	char key[100];
	char value[100];

	struct CGIIn *next;
}CGIIn;


//Organizes HTML POST/GET request data in the linked-list
int organizeCGIInput(char *buffer);

//Add new node (key-value pair) to HTML input linked-list (CGIIn)
int CGIAddNode(CGIIn *head2, char *key, char *value);

//Finds value corrusponding to the given key in CGIIn
char *CGIFindValue(char *key);

//For debugging purpose
int CGIPrintNodes(CGIIn *head2);

//Outputs CGI and HTML/CSS headers
int outHeaders();

//Outputs headers via outHeaders() and draws form elements if necessary.
int redrawPage();

//Changes password of the account of given key valule to new password (newPass)
int changePass(libaccount *head, int key, char *password, char *newPass);

//Adds account with given key (CMS ID), department, name, batch, book 1, book 2, book 3, password
int addAccount(libaccount *head, int key, int batch, char *department, char *name, char *book1, char *book2, char *book3, char *password);

//Finds whether an account exists or not
//returns 1 if found, 0 if not found
int findAccount(libaccount *head, int key);

//Removes account with given key (CMD ID)
int removeAccount(libaccount *head, int key, char *password);

//Adds a book
int addBook(libaccount *head, int key, char *password, char *bookName);

//Removes a book
int removeBook(libaccount *head, int key, char *password, int bookN);

//Loads accounts info into the linked-list from acnts.bin file
int loadFile();

//Saves linked-list of accounts in acnts.bin file
int saveFile();


libaccount *head;	//Accounts linked-list's (libaccount) head
CGIIn *head2;		//HTML input linked-list's (CGIIn) head

#define ADMN_PASS "12341234"


#define ERR_NOT_FOUND 1
#define ERR_WRONG_PASSWORD 2
#define ERR_ALREADY_EXISTS 3
#define ERR_NOT_POSSIBLE 4
#define ERR_FILE_IO 5
#define ERR_ENOUGH_BOOKS 6
