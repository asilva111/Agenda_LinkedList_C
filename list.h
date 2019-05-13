#ifndef LIST_H_   /* Include guard */
#define LIST_H_

typedef struct
{
    char* name; //Members of the contact.
    char* bday; //31122000 format
    char* phone; //9151234567 format
	
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
node* newNode(char* name, char* b, char* p);
void  setName(node* n, char name[]); //Names changed to match list.c ; 'name' used because 'n' is used by node*.
void  setBday(node* n, char b[]);
void  setPhone(node* n, char p[]);

void  setNext(node* n, node* nx);

char*  getName(node* n); 
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

node* findNodeName(list* l, char* name);
node* findNodeBday(list* l, char* bday);
node* findNodePhone(list* l, char* phone);

void deleteNodeName(list* l);

/*---------------------------------------------*/

node* getHead(list* l);
node* getTail(list* l);
node* getCursor(list* l);
unsigned int getEntries(list* l);
void forward(list* l);

#endif 