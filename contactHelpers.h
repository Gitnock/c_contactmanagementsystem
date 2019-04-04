#pragma once
/* -------------------------------
Name:enock lubga
Student number: 154192181
Email:enocklubega@gmail.com
Section:ssm
Date:3/29/2019
----------------------------------
Assignment: 2
Milestone:  3
---------------------------------------------------------------------
Description: This header file modularizes general helper functions to
			 help reduce redundant coding for common repetitive tasks.
---------------------------------------------------------------------*/

#include "contacts.h"


// HINT:
// You will most likely want to include this header file
// in other files of the project since it provides general
// helper functions that can be used throughout.


//--------------------------------
// Function Prototypes
//--------------------------------

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// Clear the standard input buffer
void clearKeyboard(void);

// pause:
// Put function prototype below:
void pause(void);
// getInt:
// Put function prototype below:
int getInt(void);
// getIntInRange:
// Put function prototype below:
int getIntInRange(int min, int max);
// yes:
// Put function prototype below:
int yes(void);
// menu:
// Put function prototype below:
int menu(void);
// contactManagerSystem:
// Put function prototype below:
void contactManagerSystem(void);

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 3 ======= |
// +-------------------------------------------+

// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char phoneNum[]);

// findContactIndex (provided for you)
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);


// displayContactHeader
// put function prototype here:
void displayContactHeder(void);

// displayContactFooter:
// put function prototype here:
void displayContactFooter(int count);

// displayContact:
// put function prototype here:
void displayContact(const struct Contact *contact);

// displayContacts:
// put function prototype here:
void displayContacts(const struct Contact contact[], int size);

// searchContacts:
// put function prototype here:
void searchContacts(const struct Contact contact[], int size);

// addContact:
// put function prototype here:
void addContact(struct Contact contact[], int size);

// updateContact:
// put function prototype here:
void updateContact(struct Contact contact[], int size);

// deleteContact:
// put function prototype here:
void deleteContact(struct Contact contact[], int size);

// sortContacts:
// put function prototype here:
void sortContacts(struct Contact contact[], int size);
