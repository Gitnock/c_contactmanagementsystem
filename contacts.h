#ifndef CONTACTS_H_
#define CONTACTS_H_
struct Name {

	char firstName[31];
	char middleInitial[7];
	char lastName[36];

};


struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};

struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};

struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;

};

void clearB();
void setName(struct Name *name);
void setAddress(struct Address *address);
void setNumbers(struct Numbers *numbers);
void getContact(struct Contact *Contact);
#endif // !CONTACTS_H_
