#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


//Node Functions
node* newNode(char* f, char* b, char* p){
	node* n = (node*)malloc(sizeof(node)); //malloc returns void pointer, we cast it to node pointer

    short i = 0; /*Clone the given name to n's member----------------*/
    
    while(f[i]!= '\0'){ //Count size of name
        i++;
    }

    i++;

    n -> name = (char*)malloc(i*sizeof(char)); //allocate memory
    i = 0;

    while(*f){ //clone.
        n -> name[i] = *f;
        i++;
        f++;
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

void setName(node* n, char* f)
{
    short i = 0;
    
    while(f[i]!= '\0'){
        i++;
    }

    i++;

    n -> name = (char*)malloc(i*sizeof(char));
    i = 0;

    while(*f){
        n -> name[i] = *f;
        i++;
        f++;
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

void setNext(node* n, node* nx)
{
	n-> next = (struct node*)nx;
}

char* getName(node* n) //MIGHT NEED TO CHANGE RETURN TYPE OF GETTERS
{
	return n->name;
}

char* getBday(node* n)
{
	return n-> bday;
}

char* getPhone(node* n)
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
void addNode(list* l, node* n){ 
	if(getEntries(l) == 0){ //If node first in list, make it head and tail.
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
    
    printf("load    - load predetermined data into agenda\n");
    printf("add     - insert contact in the phonebook\n");
    printf("delete  - delete contact from the phonebook\n");
    printf("print   - print contact list\n");
    printf("find    - print contact info by name, birthady, or phone.\n");
    printf("exit    - choose to save / terminate.\n");

    
    
    
    char* add =     "add";
    char* delete =  "delete";
    char* print =   "print";
    char* find =    "find";
    char* ex =      "exit";
    char* load =    "load";
    
    while(x == 0){
        
        char input[10];
 
        printf("\n\nPlease enter a command:\n");
        scanf(" %s", &input);

        if(strcmp(input,load) == 0){
            
            addNode(l,newNode("Diana","01021993", "9151234567"));
            addNode(l,newNode("Andres","03141998", "9151612276"));
            addNode(l,newNode("Lucy","02151999", "9154441111"));
            addNode(l,newNode("Sabrina","09161995", "9152735273"));
            addNode(l,newNode("Miguel","11122004","3098015191"));

            printf("\nData loaded.");
        }
        else if(strcmp(input,add) == 0){ //Add Node
            printf("\nPlease enter information of the node to add.\n\n");

            char f[20];
            char b[20];
            char p[20];
        
            printf("enter name:\n");
            scanf("%s", f); //printf("\nname: %s\n", &f);
        
            printf("enter birthday:\n");
            scanf("%s", b); //printf("\nbday: %s\n", &b);
            
            printf("enter phone number:\n");
            scanf("%s", p); //printf("\nphone: %s\n", &p);

            node* n = newNode(f, b, p);

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
           
            printf("\nFind by <name> <birthday> <phone>?\n"); //Ask user for find method.
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

            if(n != NULL){ //if contact exists, print it.
                printAll(n);
            }
            
            else{
                printf("\n\n"); 
            }
        
        }
        
        else if(strcmp(input,delete) == 0){ //Delete Node
            char choice[10];
            
            char* na = "name";
            char* bd = "birthday";
            char* ph = "phone";
            
            printf("\nDelete by <name> <birthday> <phone>?\n");
            scanf("%s", &choice);

            (strcmp(choice,na) == 0 ? deleteNodeName(l) : //Depending on choice, call correct method. 
                (strcmp(choice,bd) == 0) ? deleteNodeBday(l) : 
                    (strcmp(choice,ph) == 0) ? deleteNodePhone(l) :
                         printf("\nChoice not available.\n")); //Else print wrong input.
            

        }
        
        else if(strcmp(input,ex) == 0){


            printf("\nSave to .txt before exiting?\nyes/no\n");
            
            char* save[5];
            scanf(" %s", &save);
            char* yes = "yes";


            if(strcmp(save,yes) == 0){
                saveList(l);
            }

            printf("\nTerminating.\n");
            x++;

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
    while(n -> name[i] != NULL){
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
    printf(
        "\n Phone: ");
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
    char nme[20];
    
    printf("\nenter name\n");
    scanf("%s", &nme);

    node* n = findNodeName(l, &nme); //Find node to be deleted

    if(getEntries(l) == 0){ //Deleting on an empty list.
    
        printf("\nList is Empty");
        return;
    
    }
    else if(getEntries(l) == 1){
        
        setHead(l,NULL);
    
    }
    else if(n == getHead(l)){ //If head to be deleted, replace it by moving head to next.
     
        setHead(l,getNext(n));
        
    }
    else if(n == getTail(l)){ //If tail to be deleted,
        
        short i = 1;
        
        while(i < getEntries(l)){ //Move until before tail
            forward(l);
            i++;
        }

        setTail(l,getCursor(l)); //Make current node the new tail

    } 
    else if(n != NULL){ //Node to be deleted IS in list.

        short i = 0;
        
        while(  strcmp(  getName(getCursor(l))  , nme) != 0)  { //Get to desired node to be deleted
            i++; //Count possition.
            forward(l);
        }
        
        node* temp = getNext(getCursor(l)); //Store next of node to be deleted.
        
        short j = 0;
        
        setCursor(l,getHead(l)); //Reset cursor.
        
        while(j < i){ //Move cursor to exactly before node to be deleted.
            forward(l);
            j++;
        }
        
        setNext(getCursor(l), temp); //Make cursor's next the node AFTER deletee.

        free(temp);

    }
    else{
        printf("\nContact cannot be deleted - not found.\n");
    }

    l -> entries--;
    printf("\nContact deleted.\n");
    
}

void deleteNodeBday(list* l){ //delete node by birthday.
    setCursor(l,getHead(l));
    char bdy[20];
    
    printf("\nenter birthday\n");
    scanf("%s", &bdy);

    node* n = findNodeBday(l, &bdy); //Find node to be deleted

    if(getEntries(l) == 0){ //Deleting on an empty list.
    
        printf("\nList is Empty");
        return;
    
    }
    else if(getEntries(l) == 1){
        
        setHead(l,NULL);
    
    }
    else if(n == getHead(l)){ //If head to be deleted, replace it by moving head to next.
     
        setHead(l,getNext(n));
        
    }
    else if(n == getTail(l)){ //If tail to be deleted,
        
        short i = 1;
        
        while(i < getEntries(l)){ //Move until before tail
            forward(l);
            i++;
        }

        setTail(l,getCursor(l)); //Make current node the new tail

    } 
    else if(n != NULL){ //Node to be deleted IS in list.

        short i = 0;
        
        while(  strcmp(  getBday(getCursor(l))  , bdy) != 0)  { //Get to desired node to be deleted
            i++; //Count possition.
            forward(l);
        }
        
        node* temp = getNext(getCursor(l)); //Store next of node to be deleted.
        
        short j = 0;
        
        setCursor(l,getHead(l)); //Reset cursor.
        
        while(j < i){ //Move cursor to exactly before node to be deleted.
            forward(l);
            j++;
        }
        
        setNext(getCursor(l), temp); //Make cursor's next the node AFTER deletee.

        free(temp);

    }
    else{
        printf("\nContact cannot be deleted - not found.\n");
    }

    l -> entries--;
    printf("\nContact deleted.\n");
    
}

void deleteNodePhone(list* l){ //delete node by phone.
    setCursor(l,getHead(l));
    char phn[20];
    
    printf("\nenter phone\n");
    scanf("%s", &phn);

    node* n = findNodePhone(l, &phn); //Find node to be deleted

    if(getEntries(l) == 0){ //Deleting on an empty list.
    
        printf("\nList is Empty");
        return;
    
    }
    else if(getEntries(l) == 1){
        
        setHead(l,NULL);
    
    }
    else if(n == getHead(l)){ //If head to be deleted, replace it by moving head to next.
     
        setHead(l,getNext(n));
        
    }
    else if(n == getTail(l)){ //If tail to be deleted,
        
        short i = 1;
        
        while(i < getEntries(l)){ //Move until before tail
            forward(l);
            i++;
        }

        setTail(l,getCursor(l)); //Make current node the new tail

    } 
    else if(n != NULL){ //Node to be deleted IS in list.

        short i = 0;
        
        while(  strcmp(  getPhone(getCursor(l))  , phn) != 0)  { //Get to desired node to be deleted
            i++; //Count possition.
            forward(l);
        }
        
        node* temp = getNext(getCursor(l)); //Store next of node to be deleted.
        
        short j = 0;
        
        setCursor(l,getHead(l)); //Reset cursor.
        
        while(j < i){ //Move cursor to exactly before node to be deleted.
            forward(l);
            j++;
        }
        
        setNext(getCursor(l), temp); //Make cursor's next the node AFTER deletee.

        free(temp);

    }
    else{
        printf("\nContact cannot be deleted - not found.\n");
    }

    l -> entries--;
    printf("\nContact deleted.\n");
    
}

void saveList(list* l){
   if(getEntries(l) == 0){
       printf("\nList is empty.\n");
       return;
   }
    
   
   setCursor(l, getHead(l));
   FILE * fp;
   
   /* open the file for writing*/
   fp = fopen ("phonebook.txt","w");
 
   /*Print in txt file*/

    for(int i = 0; i < getEntries(l); i++){
        
        fprintf(fp, "\nName: %s\nBirthday: %s\nPhone: %s\n", getName(getCursor(l)), getBday(getCursor(l)), getPhone(getCursor(l)) );
        forward(l);

    }
 
   /* close the file*/  
   fclose(fp);
   printf("\nPhonebook saved into .txt file\n");
}
