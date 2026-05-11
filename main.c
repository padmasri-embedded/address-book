#include<stdio.h>
#include"contact.h"
int main()
{
    AddressBook addressBook;
    initialize(&addressBook);
    for (;;)
    {
        int choice;
        printf("\nAddress Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. List Contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                addContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
                listContacts(&addressBook);
                break;
            case 6:
                printf("Exiting...\n");
                 return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}