#include <stdio.h>
#include <string.h>

// Struct definitions
struct Member {
    char name[100];
    int age;
    int phoneNumber;
    int memberID;
};

struct Book {
    char title[100];
    int bookID;
    char author[100];
    int copies;
};

struct IssuedBook {
    int bookID;
    char title[100];
    char author[100];
    int day;
    int month;
    int year;
};

// Global variables to store data
struct Member members[1000];
struct Book books[1000];
struct IssuedBook issuedBooks[1000];
int totalMembers = 0;
int totalBooks = 0;
int totalIssued = 0;

// Function prototypes
void librarianMenu();
void memberMenu();
void registerMember();
void addBook();
void viewBooks();
void issueBook();
void returnBook();
void payFine();
void viewMembers();
void viewIssuedBooks();

int main() {
    int choice;
    printf("-----------------------\n");
    printf("Library Management System \n");
    printf("-----------------------\n");
    printf("Enter Your Choice \n");
    printf("1. To enter as librarian \n");
    printf("2. To enter as a member  \n");
    printf("3. To exit \n");
    printf("-----------------------\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            librarianMenu();
            break;
        case 2:
            memberMenu();
            break;
        case 3:
            printf("-----------------------\n");
            printf(" You chose to exit \n Thank You \n");
            printf("-----------------------\n");
            break;
        default:
            printf("-----------------------\n");
            printf("Wrong choice \n");
            printf("-----------------------\n");
            break;
    }

    return 0;
}

// Librarian menu
void librarianMenu() {
    int choice;
    printf("-----------------------\n");
    printf("Librarian Menu \n");
    printf("-----------------------\n");
    printf("Enter your choice \n");
    printf("1. Register a member \n");
    printf("2. Add a book \n");
    printf("3. View available books \n");
    printf("4. View members \n");
    printf("5. View issued books \n");
    printf("6. Back \n");
    printf("-----------------------\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            registerMember();
            break;
        case 2:
            addBook();
            break;
        case 3:
            viewBooks();
            break;
        case 4:
            viewMembers();
            break;
        case 5:
            viewIssuedBooks();
            break;
        case 6:
            main();
            break;
        default:
            printf("-----------------------\n");
            printf("Wrong choice \n");
            printf("-----------------------\n");
            librarianMenu();
            break;
    }
}

// Member menu
void memberMenu() {
    int choice;
    printf("-----------------------\n");
    printf("Member Menu \n");
    printf("-----------------------\n");
    printf("Enter your choice \n");
    printf("1. View available books \n");
    printf("2. Issue a book \n");
    printf("3. Return a book \n");
    printf("4. Pay fine \n");
    printf("5. Back \n");
    printf("-----------------------\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            viewBooks();
            break;
        case 2:
            issueBook();
            break;
        case 3:
            returnBook();
            break;
        case 4:
            payFine();
            break;
        case 5:
            main();
            break;
        default:
            printf("-----------------------\n");
            printf("Wrong choice \n");
            printf("-----------------------\n");
            memberMenu();
            break;
    }
}

// Register a new member
void registerMember() {
    printf("Enter number of members to be added: ");
    int n,i;
    scanf("%d", &n);

    for (i = totalMembers; i < totalMembers + n; i++) {
        printf("-----------------------\n");
        printf("Member number: %d\n", i + 1);

        // Assigning member ID
        members[i].memberID = i + 1;

        printf("Enter name: ");
        scanf("%s", members[i].name);
        printf("Enter age: ");
        scanf("%d", &members[i].age);
        printf("Enter phone number: ");
        scanf("%d", &members[i].phoneNumber);
        printf("-----------------------\n");
        printf("Member registered successfully\n");
        printf("-----------------------\n");
    }

    totalMembers += n;
    printf("Returning to the librarian menu \n");
    librarianMenu();
}

// View all registered members
void viewMembers() {
    printf("Registered Members:\n");
    int i;
    for ( i = 0; i < totalMembers; i++) {
        printf("Member ID : %d\n", members[i].memberID);
        printf("Name : %s\n", members[i].name);
        printf("Age : %d\n", members[i].age);
        printf("Phone Number : %d\n", members[i].phoneNumber);
        printf("-----------------------\n");
    }

    librarianMenu(); // Return to the librarian menu
}

// Add a new book to the library
void addBook() {
    printf("Enter number of books to be added: ");
    int n,i;
    scanf("%d", &n);
    for ( i = totalBooks; i < totalBooks + n; i++) {
        printf("-----------------------\n");
        printf("Book number : %d \n ", i + 1);
        printf("Enter book title : ");
        scanf("%s", books[i].title);
        printf("Enter book author : ");
        scanf("%s", books[i].author);
        printf("Enter book id: ");
        scanf("%d", &books[i].bookID);
        printf("Enter total copies  : ");
        scanf("%d", &books[i].copies);
        printf("-----------------------\n");
        printf("Book registered successfully\n");
        printf("-----------------------\n");
    }
    totalBooks += n;
    printf("Returning to the librarian menu \n");
    librarianMenu();
}

// View all available books
void viewBooks() {
    printf("Available Books:\n");
    int i;
    for ( i = 0; i < totalBooks; i++) {
        printf("Book ID : %d\n", books[i].bookID);
        printf("Title : %s\n", books[i].title);
        printf("Author : %s\n", books[i].author);
        printf("Available Copies : %d\n", books[i].copies);
        printf("-----------------------\n");
    }
    librarianMenu();
}

// Issue a book to a member
void issueBook() {
    int memberID, bookID;
    printf("Enter your Member ID: ");
    scanf("%d", &memberID);
    printf("Enter Book ID to issue: ");
    scanf("%d", &bookID);

    // Check if the book is available
    int bookIndex = -1,i;
    for ( i = 0; i < totalBooks; i++) {
        if (books[i].bookID == bookID) {
            bookIndex = i;
            break;
        }
    }

    // Check if the member exists
    int memberIndex = -1;
    int i1;
    for (i1 = 0; i1 < totalMembers; i1++) {
        if (members[i1].memberID == memberID) {
            memberIndex = i1;
            break;
        }
    }

    if (bookIndex != -1 && memberIndex != -1) {
        if (books[bookIndex].copies > 0) {
            // Issue the book
            issuedBooks[totalIssued].bookID = books[bookIndex].bookID;
            strcpy(issuedBooks[totalIssued].title, books[bookIndex].title);
            strcpy(issuedBooks[totalIssued].author, books[bookIndex].author);
            // Assuming issuing date is today's date
            // You may want to use a library for date handling
            issuedBooks[totalIssued].day = 1; // Placeholder
            issuedBooks[totalIssued].month = 1; // Placeholder
            issuedBooks[totalIssued].year = 2024; // Placeholder

            // Decrease the available copies
            books[bookIndex].copies--;

            printf("Book issued successfully\n");
            printf("-----------------------\n");
            totalIssued++;
        } else {
            printf("Sorry, the book is not available\n");
        }
    } else {
        printf("Invalid Member ID or Book ID\n");
    }

    memberMenu();
}

// Return a book to the library
void returnBook() {
    int bookID;
    printf("Enter Book ID to return: ");
    scanf("%d", &bookID);

    int bookIndex = -1,j;
    for (j = 0; j < totalBooks; j++) {
        if (books[j].bookID == bookID) {
            bookIndex = j;
            break;
        }
    }

    if (bookIndex != -1) {
        // Increase the available copies
        books[bookIndex].copies++;
        printf("Book returned successfully\n");
    } else {
        printf("Book ID is invalid\n");
    }

    memberMenu();
}

//
void viewIssuedBooks() {
    printf("Issued Books:\n");
    int i;
    for (i = 0; i < totalIssued; i++) {
        printf("Book ID : %d\n", issuedBooks[i].bookID);
        printf("Title : %s\n", issuedBooks[i].title);
        printf("Author : %s\n", issuedBooks[i].author);
        printf("Issued Date : %d-%d-%d\n", issuedBooks[i].day, issuedBooks[i].month, issuedBooks[i].year);
        printf("-----------------------\n");
    }
    librarianMenu(); // Return to the librarian menu
}

void payFine() {
    int memberID;
    printf("Enter your Member ID: ");
    scanf("%d", &memberID);

    // Check if the member exists
    int memberIndex = -1;
    int i;
    for (i = 0; i < totalMembers; i++) {
        if (members[i].memberID == memberID) {
            memberIndex = i;
            break;
        }
    }

    if (memberIndex!= -1) {
        // Assume the fine is paid successfully
        printf("Fine paid successfully\n");
    } else {
        printf("Invalid Member ID\n");
    }

    memberMenu(); // Return to the member menu
}