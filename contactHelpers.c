/* -------------------------------------------
Name:enock lubega
Email:elubega@myseneca.ca
Section:SSM
Date:3/18/2019
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contactHelpers.h"
#include "contacts.h"
#include "string.h"


// This source file needs to "know about" the functions you prototyped
//       in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:



//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition
void clearKeyboard(void)
{
    while (getchar() != '\n');
}

// pause: Empty function definition goes here:
void pause(void) {
    char c;
    do{
        printf("(Press Enter to Continue)");
        scanf("%c",&c);
    }while(c!='\n');


}


// getInt: Empty function definition goes here:
int getInt(void) {
    char nL = 'x';
    int out = 0;

    while (nL != '\n'){
        scanf("%d%c", &out, &nL);
        if (nL != '\n') {
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
    }
return out;
}


// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max) {
    int num = 0;
    num = getInt();
    while (!(num >= min && num <= max)) {
        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        num = getInt();
    }
    return num;
}


// yes: Empty function definition goes here:
int yes() {
    char nl = '\0';
    char yes = '\0';
    while (nl != '\n') {
        scanf("%c%c", &yes, &nl);
        if (nl != '\n') {
            clearKeyboard();
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        }
        else if (yes == 'y' || yes == 'Y') {
            return 1;
        }
        else if (yes == 'n' || yes == 'N') {
            return 0;
        }
    }
}


// menu: Empty function definition goes here:
int menu(void)
{
    int menu = 0;

    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n");
    printf("\n");
    printf("Select an option:> ");

    menu = getInt();

    while (menu < 0 || menu > 6)
    {
        printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
        menu = getInt();

    }

    return menu;
}


// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void) {
    int cFlag = 0;
    int pick;

    const struct Contact contact[] = { { { "Rick", {'\0'}, "Grimes" },{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },{ "4161112222", "4162223333", "4163334444" } },
    {{ "Maggie", "R.", "Greene" },{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },{ "9051112222", "9052223333", "9053334444" } },
    {{ "Morgan", "A.", "Jones" },{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },{ "7051112222", "7052223333", "7053334444" } }
    ,{{ "Sasha", {'\0'}, "Williams" },{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },{ "9052223333", "9052223333", "9054445555" } }};

    while (cFlag == 0) {
        pick = menu();
        switch (pick) {
        case 1:
            displayContactHeader();
            displayContacts(contact,4);
            displayContactFooter(4);
            pause();
            break;

        case 2:
            printf("\n<<< Feature 2 is unavailable >>>\n\n");
            pause();
            break;

        case 3:
            printf("\n<<< Feature 3 is unavailable >>>\n\n");
            pause();
            break;

        case 4:
            printf("\n<<< Feature 4 is unavailable >>>\n\n");
            pause();
            break;

        case 5:
            searchContacts(contact,4);
            pause();
            break;

        case 6:
            printf("\n<<< Feature 5 is unavailable >>>\n\n");
            pause();
            break;

        case 0:
            printf("\nExit the program? (Y)es/(N)o: ");
            cFlag = yes();
            break;

        default:
            break;
        }
        printf("\n");
    }
    printf("Contact Management System: terminated");
}

void getTenDigitPhone(char phoneNum[]) {
    int needInput = 1;


    while (needInput == 1) {
        // (String Length Function: validate entry of 10 characters)
       if (strlen(phoneNum) == 10){
           int pos = 0;
            needInput = 0;
            while(pos < 10 ){

                if(!(phoneNum[pos]>='0'&&phoneNum[pos]<='9')){
                    needInput = 1;
                }
                pos++;
            }
       }

        else
             needInput = 1;

        if(needInput) {
            printf("Enter a 10-digit phone number: ");
            scanf("%10s", phoneNum);
            clearKeyboard();
        }

     }

  }


// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
  {
      int pos = -1,i,cellIdx = 1;
      for(i=0;i<size;i++){

        cellIdx = strcmp(contacts[i].numbers.cell,cellNum);
        if(cellIdx==0){
            pos = i;
        }
    }
     return pos;
 }

void displayContactHeader(void){

    printf("+-----------------------------------------------------------------------------+\n|                              Contacts Listing                               |\n+-----------------------------------------------------------------------------+\n");


 }

void displayContactFooter(int count){
    printf("+-----------------------------------------------------------------------------+\nTotal contacts: %d\n\n",count);
}


void displayContact(const struct Contact *contact){


    if(contact->name.middleInitial!='\0'){
        printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
    }
    else {
        printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
    }
    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
    if (contact->address.apartmentNumber>0){
        printf("       %d %s, %d, %s, %s\n", contact->address.streetNumber,contact->address.street,contact->address.apartmentNumber,contact->address.city,contact->address.postalCode);
    }
    else{
        printf("       %d %s, %s, %s\n", contact->address.streetNumber,contact->address.street,contact->address.city,contact->address.postalCode);
    }


}

void displayContacts(const struct Contact contact[],int size){
    int i;
    for(i = 0;i<size;i++){
        if(contact[i].name.middleInitial!='\0'){
            printf(" %s %s %s\n", contact[i].name.firstName, contact[i].name.middleInitial, contact[i].name.lastName);
        }
        else {
            printf("%s %s\n", contact[i].name.firstName, contact[i].name.lastName);
        }
        printf("    C: %-10s   H: %-10s   B: %-10s\n", contact[i].numbers.cell, contact[i].numbers.home, contact[i].numbers.business);

        if (contact[i].address.apartmentNumber>0){
        printf("       %d %s, Apt# %d, %s, %s\n", contact[i].address.streetNumber,contact[i].address.street,contact[i].address.apartmentNumber,contact[i].address.city,contact[i].address.postalCode);
        }

        else{
            printf("       %d %s, %s, %s\n", contact[i].address.streetNumber,contact[i].address.street,contact[i].address.city,contact[i].address.postalCode);
        }

    }

}

void searchContacts(const struct Contact contact[], int size){
    char phoneNum[] = "9051112222";
    int pos =0;
    printf("\nEnter a 10-digit phone number: ");
    scanf("%10s", phoneNum);
    clearKeyboard();
    getTenDigitPhone(phoneNum);
    pos = findContactIndex(contact,size,phoneNum);
    if(pos>=0){
        displayContact(&contact[pos]);
    }
    else{
        printf("*** Contact NOT FOUND ***\n");
    }

}





