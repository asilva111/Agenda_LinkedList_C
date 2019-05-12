#include <stdio.h>
#include <string.h>
#include "list.h"

int main()
{
	list results;
	setCursor(&results, getHead(&results));
	CommandListener(&results);
	
	/*char* MyName = "Jeff";
	char date[8] = "08091998";
	char MyPhone[10] = "9152049068";
	addNode(&results,newNode(&MyName,date,MyPhone));*/
    
    //printList(&results);

    // addNode(&results,newNode("Luis","10101996", "915xxxxxxx"));
    // addNode(&results,newNode("Pedro","11112000", "915xxxxxxx"));
    // addNode(&results,newNode("Diana","14141998", "915xxxxxxx"));
    // addNode(&results,newNode("Satan","00000001", "6666666666"));
    


	

}