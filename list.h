#ifndef LIST_H_   /* Include guard */
#define LIST_H_

typedef struct
{
    char* name; 
    char* bday; 
    char* phone; 
	
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
node* newNode(char* f, char* b, char* p);
void  setName(node* n, char f[]); 
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
void deleteNodeBday(list* l);
void deleteNodePhone(list* l);

void saveList(list* l);
/*---------------------------------------------*/

node* getHead(list* l);
node* getTail(list* l);
node* getCursor(list* l);
unsigned int getEntries(list* l);
void forward(list* l);

#endif 
