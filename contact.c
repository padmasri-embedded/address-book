#include <stdio.h>
#include <string.h>
#include "contact.h"

void initialize(AddressBook *addressBook)
 {
    addressBook->count = 0;
    loadDummyContacts(addressBook);
    printf("Dummy contacts loaded successfully.\n");
}
void addContact(AddressBook *addressBook)
 {
    if (addressBook->count >= MAX_CONTACTS)
     {
        printf("Address book is full!\n");
        return;
    }
    Contact *contact = &addressBook->contacts[addressBook->count];
    printf("Enter name: ");
    scanf(" %[^\n]", contact->name);
    printf("Enter phone: ");
    scanf(" %[^\n]", contact->phone);
    printf("Enter email: ");
    scanf(" %[^\n]", contact->email);
    addressBook->count++;
    printf("Contact added successfully!\n");
}
void searchContact(AddressBook *addressBook)
 {
    char query[50];
    printf("Enter name to search: ");
    scanf(" %[^\n]", query);
    int found = 0;
    for (int i = 0; i < addressBook->count; i++) {
        if (strstr(addressBook->contacts[i].name, query)) {
            printf("\nContact Found:\n");
            printf("Name: %s\n", addressBook->contacts[i].name);
            printf("Phone: %s\n", addressBook->contacts[i].phone);
            printf("Email: %s\n", addressBook->contacts[i].email);
            found = 1;
            break;
        }
    }
    if (!found)
     {
        printf("No contact found with name '%s'.\n", query);
    }
}
void editContact(AddressBook *addressBook)
 {
    char query[50];
    printf("Enter name to edit: ");
    scanf(" %[^\n]", query);
    for (int i = 0; i < addressBook->count; i++)
     {
        if (strstr(addressBook->contacts[i].name, query))
         {
            printf("Editing Contact:\n");
            printf("Enter new name: ");
            scanf(" %[^\n]", addressBook->contacts[i].name);
            printf("Enter new phone: ");
            scanf(" %[^\n]", addressBook->contacts[i].phone);
            printf("Enter new email: ");
            scanf(" %[^\n]", addressBook->contacts[i].email);
            printf("Contact updated successfully!\n");
            return;
        }
    }
printf("No contact found with name '%s'.\n", query);
}
void deleteContact(AddressBook *addressBook)
 {
    char query[50];
     printf("Enter name to delete: ");
    scanf(" %[^\n]", query);
    for (int i = 0; i < addressBook->count; i++) 
    {
        if (strstr(addressBook->contacts[i].name, query))
         {
            for (int j = i; j < addressBook->count - 1; j++)
             {
                addressBook->contacts[j] = addressBook->contacts[j + 1];
            }
            addressBook->count--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("No contact found with name '%s'.\n", query);
}
void listContacts(AddressBook *addressBook)
 {
    if (addressBook->count == 0) 
    {
        printf("No contacts in the address book.\n");
        return;
    }
    printf("\nContacts List:\n");
    for (int i = 0; i < addressBook->count; i++)
     {
        printf("Name: %s\n", addressBook->contacts[i].name);
        printf("Phone: %s\n", addressBook->contacts[i].phone);
        printf("Email: %s\n", addressBook->contacts[i].email);
    }
}