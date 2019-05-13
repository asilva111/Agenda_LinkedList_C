#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


//Node Functions
node* newNode(char* name, char* b, char* p){
	node* n = (node*)malloc(sizeof(node)); //malloc returns void pointer, we cast it to node pointer

    short i = 0; /*Clone the given name to n's member----------------*/
    while(name[i]!= '\0'){ //Count size of name
        i++;
    }

    i++;

    n -> name = (char*)malloc(i*sizeof(char)); //allocate memory
    i = 0;

    while(*name){ //clone.
        n -> name[i] = *name;
        i++;
        name++;
    }/*--------------------------------------------------------------*/

    i = 0; /*Clone the given birthday to n's member----------------*/
    while(b[i] != '\0'){ //Count size of birthday
        i++;
    }

    i++;

    n -> bday = (char*)malloc(i*sizeof(char)); //allocate memory
    i = 0;

    while(*b){ //clone.
        n -> bday[i] = *b;
        i++;
        b++;
    }/*--------------------------------------------------------------*/

    i = 0; /*Clone the given phone to n's member----------------*/
    while(p[i]!= '\0'){ //Count size of phone
        i++;
    }

    i++;

    n -> phone = (char*)malloc(i*sizeof(char)); //allocate memory
    i = 0;

    while(*p){ //clone.
        n -> phone[i] = *p;
        i++;
        p++;
    }/*--------------------------------------------------------------*/


	return n; 
}

void  setName(node* n, char* name)
{
    short i = 0;
    
    while(name[i]!= '\0'){
        i++;
    }

    i++;

    n -> name = (char*)malloc(i*sizeof(char));
    i = 0;

    while(*name){
        n -> name[i] = *name;
        i++;
        name++;
    }

}

void setBday(node* n, char* b)
{
    short i = 0;
    
    while(b[i]!= '\0'){
        i++;
    }

    i++;

    n -> bday = (char*)malloc(i*sizeof(char));
    i = 0;

    while(*b){
        n -> bday[i] = *b;
        i++;
        b++;
    }

}

void setPhone(node* n, char* p)
{
    short i = 0;
    
    while(p[i]!= '\0'){
        i++;
    }

    i++;

    n -> phone = (char*)malloc(i*sizeof(char));
    i = 0;

    while(*p){
        n -> phone[i] = *p;
        i++;
        p++;
    }

}

void  setNext(node* n, node* nx)
{
	n->next = (struct node*)nx;
}

char*  getName(node* n) //MIGHT NEED TO CHANGE RETURN TYPE OF GETTERS
{
	return n->name;
}

char*   getBday(node* n)
{
	return n-> bday;
}

char*   getPhone(node* n)
{
	return n-> phone;
}

node* getNext(node* n)
{
	return (node*) n-> next;
}

//List Functions
void setHead(list* l, node* n)
{
	l->head = n;
}

void setTail(list* l, node* n)

{
	l->tail = n;
}

void setCursor(list* l, node* n)
{
	l->cursor = n;
}




void addNodeAt(list* l, node* n, int i) //Insert after i
{
	if(i == 0){ //if desired index is begining of list and list is empty.
		
        setNext(n, getHead(l)); //Make n's next the current head
		setHead(l,n); //point the head to n
		
        //setTail(l,n); //REMOVED TO MATCH LL SOLUTION 
		// setCursor(l,n); //REMOVED TO MATCH LL SOLUTION 

		l -> entries++;
		return;
	}

	setCursor(l, getHead(l)); //Make cursor point to begining of list
	
	for(int e = 0; e < i; e++){ //move cursor until reaching i
		forward(l);
	}

	setNext(n, getNext(getCursor(l))); //make n's next the next element of the current index
	setNext(getCursor(l), n); 
	l -> entries++;

}

node* getHead(list* l)
{
	return l->head;
}

node* getTail(list* l)
{
	return l->tail;
}

node* getCursor(list* l)
{
	return l-> cursor;
}

unsigned int getEntries(list* l)
{
	return l->entries;
}

void forward(list* l) //Move cursor to next
{
	if(getNext(getCursor(l)) != NULL){ //If cursor next is not null, move it.
		l -> cursor = getNext(getCursor(l));
	}
}
/*PROJECT METHODS --------------------------------------------------------------*/
void addNode(list* l, node* n){ //Push
	if(getEntries(l) == 0){
		setHead(l,n);
		setTail(l,n);


		l -> entries++;

        printf("\nFirst node added.\n");
        
        return;
		
	}else{

        setNext(getTail(l), n); 
        setTail(l,n);
        l -> entries++;

        printf("\nNode added.\n");
    }
	
}

void CommandListener(list* l){
    l -> entries = 0;
    short x = 0;

    printf("Commands available:\n");
    
    printf("add     - insert contact in the phonebook\n");
    printf("delete  - delete contact from the phonebook\n");
    printf("print   - print contact list\n");
    printf("find    - print contact info by name.\n");
    printf("exit    - choose to save / terminate.\n");
    
    
    
    char* add =     "add";
    char* delete =  "delete";
    char* print =   "print";
    char* find =    "find";
    char* ex =      "exit";
    
    addNode(l,newNode("Diana","14141998", "915xxxxxxx"));
    addNode(l,newNode("Andres","14141998", "915xxxxxxx"));
    addNode(l,newNode("Lucy","14141998", "915xxxxxxx"));
    addNode(l,newNode("IamSabrinaSpellman","14141998", "915xxxxxxx"));
    

    while(x == 0){
        
        char input[10];
 
        printf("\n\nPlease enter a command:\n");
        scanf(" %s", &input);

        if(strcmp(input,add) == 0){ //Add Node
            printf("\nPlease enter information of the node to add.\n\n");

            char* name;
            char* b;
            char* p;
        
            printf("enter name:\n");
            scanf("%s", &name);
        
            printf("enter birthday:\n");
            scanf("%s", &b);
            
            printf("enter phone number:\n");
            scanf("%s", &p);

            node* n = newNode(&name,&b,&p);

            addNode(l,n);

        }
        
        else if(strcmp(input,print) == 0){ //Print List
            
            printf("\nPrinting entire list...\n");
            printList(l);
    
        }
        
        else if(strcmp(input,find) == 0){ //Find and print Node

            char* choice[10];
            
            char* na = "name";
            char* bd = "birthday";
            char* ph = "phone";

            node* n;
           
            printf("\nDelete by <name> <birthday> <phone>?\n"); //Ask user for find method.
            scanf("%s", &choice);

            if(strcmp(choice,na) == 0){ //Check choice.
                
                char* name;
                
                printf("\nenter name:\n");
                scanf("%s", &name);

                n = findNodeName(l, &name);   //Retrieve node. 
            }
           
            else if(strcmp(choice,bd) == 0){

                char* birthday;
                
                printf("\nenter birthday:\n");
                scanf("%s", &birthday);

                n = findNodeBday(l, &birthday);   //Retrieve node. 

            }
           
            else{
                
                char* phone;
                
                printf("\nenter phone:\n");
                scanf("%s", &phone);

                n = findNodePhone(l, &phone);   //Retrieve node. 

            }

            if(n != NULL){
                printAll(n);
            }
            
            else{
                printf("\n\n"); //if contact exists, print it.
            }
        
        }
        
        else if(strcmp(input,delete) == 0){ //Delete Node

            deleteNodeName(l);

        }
        
        else if(strcmp(input,ex) == 0){
            printf("\nTerminating.\n");
            x++;

            // printf("Save to .txt before exiting?\n  Y/N");
            // char Save = 'N'; //Save = input of user

            // if(Save == 'Y'){
            //     //Save
            // }
        }
        
        else{
            printf("\nPlease enter a valid command.\n");
        }
        
    }  //Close while loop.
    
}//Close command Listener.


void printList(list* l){//Print list.
    printf("There are %i entries.\n", getEntries(l));
    
    if(getEntries(l) != 0){
        
        setCursor(l,getHead(l)); //Set cursor to head of list. ADD '&s' a lo pendejo

        for(int i = 0; i < getEntries(l); i++){ 
            
            printAll(getCursor(l));

            forward(l); //Move current 

        }

        printf("\nList printed.\n");

    }
    else{
        
        printf("\nError - Cannot print empty list.\n");
    
    }

}

void printEntries(list* l){ //Print L's entries.
    if(getEntries(l) < 1){
        printf("There are no entries in the list.\n");
    }
    else if (getEntries(l) == 1){
        printf("There is 1 contact in the list.\n");
    }
    else{
        printf("There are %i contacts in the list.\n", l -> entries);
    }
}

void printAll(node* n){
    printName(n);
    printBday(n);
    printPhone(n);
}

void printName(node* n){
    printf("\n Name: "); 
    int i = 0;
    while(n -> name[i] != '\0'){
        printf("%c", n -> name[i]);
        i++;
    }
}

void printBday(node* n){
    printf("\n Birthday: ");
    for(int i = 0; i < 8; i++){ //Print char array 'bday'
        printf("%c", n -> bday[i]);
    } 
}

void printPhone(node* n){
    printf("\n Phone: ");
    for(int i = 0; i < 10; i++){
        printf("%c", n -> phone[i]); //Print char array 'phone'
    }
}



node* findNodeName(list* l, char* name){ //Find node by name.
    setCursor(l,getHead(l));
    printf("\nSearching...");

    while(getCursor(l) != NULL){
        
        if (getCursor(l) == getTail(l)){ //if last node is not the one to be found, stop.

            if((strcmp(getName(getCursor(l)), name) != 0) ){
                break;
            }
            
        }
        
        if (strcmp(getName(getCursor(l)), name) == 0){ 
            
            printf("\nContact found.\n");
            return getCursor(l);

        }
       
        forward(l);
    }

    printf("\nContact not found.\n");
    return NULL; //!!!

}

node* findNodeBday(list* l, char* birthday){ //Find node by birthday.
    setCursor(l,getHead(l));
    printf("\nSearching...");

    while(getCursor(l) != NULL){
        
        if (getCursor(l) == getTail(l)){ //if last node is not the one to be found, stop.

            if((strcmp(getBday(getCursor(l)), birthday) != 0) ){
                break;
            }
            
        }
        
        if (strcmp(getBday(getCursor(l)), birthday) == 0){ 
            
            printf("\nContact found.\n");
            return getCursor(l);

        }
       
        forward(l);
    }

    printf("\nContact not found.\n");
    return NULL; //!!!

}

node* findNodePhone(list* l, char* phone){ //Find node by phone.
    setCursor(l,getHead(l));
    printf("\nSearching...");

    while(getCursor(l) != NULL){
        
        if (getCursor(l) == getTail(l)){ //if last node is not the one to be found, stop.

            if((strcmp(getPhone(getCursor(l)), phone) != 0) ){
                break;
            }
            
        }
        
        if (strcmp(getPhone(getCursor(l)), phone) == 0){ 
            
            printf("\nContact found.\n");
            return getCursor(l);

        }
       
        forward(l);
    }

    printf("\nContact not found.\n");
    return NULL; //!!!
}

void deleteNodeName(list* l){ //delete node by name.
    setCursor(l,getHead(l));
    char* name;
    
    printf("\nenter name\n");
    scanf("%s", &name);

    node* n = findNodeName(l, &name);
    
    if(n != NULL){
        short i = 0;
        
        while(getNext(getCursor(l) != n && i <= getEntries(l))){ //Move until before the node to be deleted
            printf("\n %i", i);
            forward(l);
            i++;
        }
        
        setNext(getCursor(l), getNext(getNext(getCursor(l)))); //Make the cursor's next the next node of the node to be deleted.
        printf("\nContact deleted.\n");
        l -> entries--;

    }
    else{
        printf("\nContact cannot be deleted - not found.\n");
    }
    

}




//--------------------------------------------------------------------------
// gotoStart(); //go to start of list -set cursor to start of list
// gotoEnd(); //go to end of list - set cursor to end of list
// deleteNode(); //remove last node
// deleteNodeAt(); //delete node at specified index
// getNodeAt(); //retrieve node from specified index

// void deleteNode(list* l){
// 	while(getCursor(l) -> next != NULL ){
// 		forward(l);
// 	}

// }



//Use -> instead of calling other functions