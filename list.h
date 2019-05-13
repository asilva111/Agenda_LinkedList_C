#ifndef LIST_H_   /* Include guard */
#define LIST_H_

typedef struct
{
    char* name; //Members of the contact.
    char bday[8]; //31122000 format
    char phone[10]; //9151234567 format
	
	struct node* next;
} node;

typedef struct
{
    node* head;
    node* tail;
	node* cursor;
	
	unsigned int entries;
} list;

//Node Functions
node* newNode(char* name, char b[], char p[]);
void  setName(node* n, char name[]); //Names changed to match list.c ; 'name' used because 'n' is used by node*.
void  setBday(node* n, char b[]);
void  setPhone(node* n, char p[]);
void  setNext(node* n, node* nx);

char*  getName(node* n); //RETURN TYPES OF GETTERS MIGHT NOT BE CORRECT
char*  getBday(node* n);
char*  getPhone(node* n);
node* getNext(node* n);

//List Functions
void setHead(list* l, node* n);
void setTail(list* l, node* n);
void setCursor(list* l, node* n);
void addNode(list* l, node* n);
void addNodeAt(list* l, node* n, int i);


/*NEW FUNCTIONS -------------------------------*/
void printList(list* l);
void printEntries(list* l);

void printAll(node* n);
void printName(node* n);
void printBday(node* n);
void printPhone(node* n);

void CommandListener(list* l);
node* findNode(list* l, char* name);
void deleteNode(list* l, char* name);

/*---------------------------------------------*/

node* getHead(list* l);
node* getTail(list* l);
node* getCursor(list* l);
unsigned int getEntries(list* l);
void forward(list* l);

#endif 