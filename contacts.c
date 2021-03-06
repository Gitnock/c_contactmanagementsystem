#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"




void clearB()
{
	while (getchar() != '\n'&&getchar() != EOF);
}

void setName(struct Name *name) {
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]s", name->firstName);
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	clearB();
	if (yes()) {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%7[^\n]s", name->middleInitial);
		clearB();
	}

	printf("Please enter the contact's last name: ");
	scanf("%30[^\n]s", name->lastName);
    clearKeyboard();
}

void setAddress(struct Address *address) {
	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();
	while(address->streetNumber <0){
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        address->streetNumber = getInt();
	}


	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]s", address->street);
	clearKeyboard();
	printf("Do you want to enter an apartment number? (y or n): ");
	if (yes()) {
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber=getInt();
		while(address->apartmentNumber <0){
        printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
        address->apartmentNumber = getInt();
	}

	}
	printf("Please enter the contact's postal code: ");
	scanf("%7[^\n]s", address->postalCode);
    clearKeyboard();
	printf("Please enter the contact's city: ");
	scanf("%40[^\n]s", address->city);
    clearKeyboard();
}

void setNumbers(struct Numbers *numbers) {
    printf("Please enter the contact's cell phone number: ");
    scanf("%10s",numbers->cell);
    clearKeyboard();
    getTenDigitPhone(numbers->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	if (yes()) {
		printf("Please enter the contact's home phone number: ");
		scanf("%10s",numbers->home);
        clearKeyboard();
        getTenDigitPhone(numbers->home);


	}

	printf("Do you want to enter a business phone number? (y or n): ");
	if (yes()) {
		printf("Please enter the contact's business phone number: ");
		scanf("%10s",numbers->business);
        clearKeyboard();
        getTenDigitPhone(numbers->business);

	}

}

void getContact(struct Contact *contact) {
    setName(&(*contact).name);
    setAddress(&(*contact).address);
    setNumbers(&(*contact).numbers);
}
