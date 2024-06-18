# Library Management System in C

This project is a simple implementation of a library management system in C language. It allows librarians to manage books and members, and members to view and issue books.

## Table of Contents

1. [Struct Definitions](#struct-definitions)
2. [Global Variables](#global-variables)
3. [Function Prototypes](#function-prototypes)
4. [Main Function](#main-function)
5. [Librarian Menu](#librarian-menu)
6. [Member Menu](#member-menu)
7. [Register Member](#register-member)
8. [View Members](#view-members)
9. [Add Book](#add-book)
10. [View Books](#view-books)
11. [Issue Book](#issue-book)
12. [Return Book](#return-book)
13. [View Issued Books](#view-issued-books)
14. [Pay Fine](#pay-fine)

---

### Struct Definitions

```c
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
```

These structures define the data structures used in the library management system.

### Global Variables

```c
struct Member members[1000];
struct Book books[1000];
struct IssuedBook issuedBooks[1000];
int totalMembers = 0;
int totalBooks = 0;
int totalIssued = 0;
```

These variables store the data for members, books, issued books, and maintain counts of total members, books, and issued books.

### Function Prototypes

```c
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
```

These are the function prototypes for various functionalities provided by the library management system.

### Main Function

```c
int main() {
    // Main menu for the program
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
```

This is the main entry point of the program where users choose to enter as a librarian, member, or exit.

### Librarian Menu

The `librarianMenu()` function allows librarians to perform operations such as registering members, adding books, and viewing information.

### Member Menu

The `memberMenu()` function provides options for members to view available books, issue and return books, and pay fines.

### Register Member

The `registerMember()` function allows librarians to register new members by entering their details.

### View Members

The `viewMembers()` function displays all registered members and their details.

### Add Book

The `addBook()` function enables librarians to add new books to the library collection by entering book details.

### View Books

The `viewBooks()` function shows all available books in the library.

### Issue Book

The `issueBook()` function allows members to issue a book from the library after entering their member ID and the book ID.

### Return Book

The `returnBook()` function lets members return a book to the library by entering the book ID.

### View Issued Books

The `viewIssuedBooks()` function displays all books that have been issued to members along with the issue date.

### Pay Fine

The `payFine()` function allows members to pay fines associated with late returns or other penalties.

---
