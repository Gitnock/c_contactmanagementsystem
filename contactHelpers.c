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

#define MAXCONTACTS 5


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
    scanf("%c%c", &yes, &nl);
    while (1) {
        if (nl == '\n') {
            if (yes == 'y' || yes == 'Y') {
                return 1;
            }
            else if (yes == 'n' || yes == 'N') {
                return 0;
            }

        }


        printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        clearKeyboard();
        scanf("%c%c", &yes, &nl);
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

void space(){
    printf("\n");
}


// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void) {
    int flag = 0;

    struct Contact contact[MAXCONTACTS] = { { { "Rick", {'\0'}, "Grimes" },{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },{ "4161112222", "4162223333", "4163334444" } },
    {{ "Maggie", "R.", "Greene" },{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },{ "9051112222", "9052223333", "9053334444" } },
    {{ "Morgan", "A.", "Jones" },{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },{ "7051112222", "7052223333", "7053334444" } }
    ,{{ "Sasha", {'\0'}, "Williams" },{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },{ "9052223333", "9052223333", "9054445555" } }};

    while (flag == 0||flag >1) {

        switch (menu()) {
        case 1:
            displayContactHeader();
            displayContacts(contact,MAXCONTACTS);
            displayContactFooter(arraySize(contact,MAXCONTACTS));
            pause();
            break;

        case 2:
            addContact(contact,MAXCONTACTS);
            pause();
            break;

        case 3:
            updateContact(contact,MAXCONTACTS);
            pause();
            break;

        case 4:
            deleteContact(contact,MAXCONTACTS);
            pause();
            break;

        case 5:
            searchContacts(contact,MAXCONTACTS);
            pause();
            break;

        case 6:
            sortContacts(contact,MAXCONTACTS);
            pause();
            break;

        case 0:
            printf("\nExit the program? (Y)es/(N)o: ");
            flag = yes();
            break;

        default:
            break;
        }
        printf("\n");
    }
    printf("Contact Management System: terminated\n");
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

    printf("\n+-----------------------------------------------------------------------------+\n|                              Contacts Listing                               |\n+-----------------------------------------------------------------------------+\n");


 }

void displayContactFooter(int count){
    printf("+-----------------------------------------------------------------------------+\nTotal contacts: %d\n\n",count);
}


void displayContact(const struct Contact *contact){


    if(contact->name.middleInitial[0]!='\0'){
        printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
    }
    else {
        printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
    }
    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
    if (contact->address.apartmentNumber>0){
        printf("       %d %s, Apt# %d, %s, %s\n", contact->address.streetNumber,contact->address.street,contact->address.apartmentNumber,contact->address.city,contact->address.postalCode);
    }
    else{
        printf("       %d %s, %s, %s\n", contact->address.streetNumber,contact->address.street,contact->address.city,contact->address.postalCode);
    }


}

void displayContacts(const struct Contact contact[],int size){
    int i;
    for(i = 0;i<size;i++){

            if(strlen(contact[i].numbers.cell) > 0){
                displayContact(&contact[i]);
            }
    }

}

void searchContacts(const struct Contact contact[], int size){
    char phoneNum[] = "9051112222";
    int pos =0;
    printf("\nEnter the cell number for the contact: ");
    scanf("%10s", phoneNum);
    clearKeyboard();
    getTenDigitPhone(phoneNum);
    pos = findContactIndex(contact,size,phoneNum);
    if(pos>=0){
        space();
        displayContact(&contact[pos]);
        space();
    }
    else{
        printf("*** Contact NOT FOUND ***\n\n");
    }

}

void addContact(struct Contact contact[], int size){
    int pos = 0;
    if(arraySize(contact,size)>=size){
        printf("\n*** ERROR: The contact list is full! ***\n\n");
    }
    else{
        pos = emptySlot(contact,MAXCONTACTS);
        space();
        getContact(&contact[pos]);
        printf("--- New contact added! ---\n\n");
    }
}

void updateContact(struct Contact contact[], int size){
    char num[11];
    int pos=0;
	space();
    printf("Enter the cell number for the contact: ");
    scanf("%10s",num);
    clearKeyboard();
    getTenDigitPhone(num);
    if(findContactIndex(contact,size,num)!= -1){
        printf("\nContact found:\n");
        pos = findContactIndex(contact,size,num);
        displayContact(&contact[pos]);
        printf("\nDo you want to update the name? (y or n): ");
        if (yes()) {
            *contact[pos].name.middleInitial = '\0';
            setName(&contact[pos].name);
        }

        printf("Do you want to update the address? (y or n): ");
        if (yes()) {
            setAddress(&contact[pos].address);
        }
        printf("Do you want to update the numbers? (y or n): ");
        if (yes()) {
            *contact[pos].numbers.business = '\0';
			*contact[pos].numbers.home = '\0';
            setNumbers(&contact[pos].numbers);
        }
        printf("--- Contact Updated! ---\n\n");
        }
    else
        printf("*** Contact NOT FOUND ***\n\n");

}

void deleteContact(struct Contact contact[], int size){
    char num[11];
    int pos;
    space();
    printf("Enter the cell number for the contact: ");
    scanf("%10s",num);
    clearKeyboard();
    getTenDigitPhone(num);
    if(findContactIndex(contact,size,num)!= -1){
        printf("\nContact found:\n");
        pos = findContactIndex(contact,size,num);
        displayContact(&contact[pos]);
        printf("\nCONFIRM: Delete this contact? (y or n): ");
        if (yes()) {
            *contact[pos].numbers.cell = '\0';
            *contact[pos].numbers.home = '\0';
            *contact[pos].numbers.business = '\0';
            printf("--- Contact deleted! ---\n");
        }
        space();
        }
    else
        printf("*** Contact NOT FOUND ***\n\n");

}

void sortContacts(struct Contact contacts[], int size) {
    int i, j;
    for (i = size - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (strcmp(contacts[j].numbers.cell, contacts[j + 1].numbers.cell) > 0) {
                struct Contact temp = contacts[j];
                (contacts[j] = contacts[j + 1]);
                (contacts[j + 1] = temp);
            }
        }
    }


    space();
    printf("--- Contacts sorted! ---\n");
    space();
}

int arraySize(const struct Contact contact[],int max){
    int i,size=0;
    for(i=0;i<max;i++){
        if(contact[i].numbers.cell[0]>'0'){
            size++;
        }

    }
    return size;
}

int emptySlot(const struct Contact contact[],int size){
    int i;
    for(i=0;i<size;i++){
        if(!strlen(contact[i].numbers.cell)){
            return i;
        }

    }
    return 5;

}


