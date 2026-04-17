#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact {
    char name[50];
    char phone[15];
};

struct Contact contacts[MAX];
int count = 0;

// Add contact
void addContact() {
    if (count >= MAX) {
        printf("Contact list is full!\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", contacts[count].name);

    printf("Enter Phone: ");
    scanf(" %[^\n]", contacts[count].phone);

    count++;
    printf("Contact added successfully!\n");
}

// View contacts
void viewContacts() {
    if (count == 0) {
        printf("No contacts available.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s | Phone: %s\n", i + 1,
               contacts[i].name, contacts[i].phone);
    }
}

// Search contact
void searchContact() {
    char name[50];
    int found = 0;

    printf("Enter name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Found: %s - %s\n",
                   contacts[i].name, contacts[i].phone);
            found = 1;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Delete contact
void deleteContact() {
    char name[50];
    int found = 0;

    printf("Enter name to delete: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            printf("Contact deleted.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n--- Contact Book ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}