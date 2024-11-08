#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    int ISBN;
    float price;
};

struct Bookstore {
    struct Book* books;
    int bookCount;
};

// Function to add a book to the bookstore
void addBook(struct Bookstore* store, const char* title, const char* author, int ISBN, float price) {
    // Reallocate memory for a new book
    store->books = realloc(store->books, (store->bookCount + 1) * sizeof(struct Book));

    // Check for successful memory allocation
    if (store->books != NULL) {
        struct Book* newBook = &(store->books[store->bookCount]);
        strcpy(newBook->title, title);
        strcpy(newBook->author, author);
        newBook->ISBN = ISBN;
        newBook->price = price;

        store->bookCount++;
        printf("Book added successfully.\n");
    } else {
        printf("Memory allocation failed. Cannot add more books.\n");
    }
}

// Function to delete a book from the bookstore
void delBook(struct Bookstore* store, int ISBN) {
    int foundIndex = -1;

    // Search for the book with the given ISBN
    for (int i = 0; i < store->bookCount; ++i) {
        if (store->books[i].ISBN == ISBN) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        // Shift remaining books to fill the gap
        for (int i = foundIndex; i < store->bookCount - 1; ++i) {
            store->books[i] = store->books[i + 1];
        }

        // Reduce the book count
        store->bookCount--;

        // Reallocate memory to adjust the book array size
        store->books = realloc(store->books, store->bookCount * sizeof(struct Book));

        printf("Book with ISBN %d deleted successfully.\n", ISBN);
    } else {
        printf("Book with ISBN %d not found.\n", ISBN);
    }
}

// Function to display all books in the bookstore
void displayBooks(const struct Bookstore* store) {
    if (store->bookCount == 0) {
        printf("No books available in the bookstore.\n");
    } else {
        printf("Books in the bookstore:\n");
        for (int i = 0; i < store->bookCount; ++i) {
            printf("Title: %s\nAuthor: %s\nISBN: %d\nPrice: $%.2f\n\n",
                   store->books[i].title, store->books[i].author,
                   store->books[i].ISBN, store->books[i].price);
        }
    }
}

int main() {
    struct Bookstore bookstore;
    bookstore.books = NULL;
    bookstore.bookCount = 0;

    int choice;
    while(1) {
        printf("\n----- Online Bookstore System -----\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Display Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char title[100];
                char author[50];
                int ISBN;
                float price;

                printf("\nEnter details for the new book:\n");
                printf("Title: ");
                scanf("%s", title);
                printf("Author: ");
                scanf("%s", author);
                printf("ISBN: ");
                scanf("%d", &ISBN);
                printf("Price: $");
                scanf("%f", &price);

                addBook(&bookstore, title, author, ISBN, price);
                break;
            }
            case 2: {
                int deleteISBN;
                printf("Enter the ISBN of the book to delete: ");
                scanf("%d", &deleteISBN);

                delBook(&bookstore, deleteISBN);
                break;
            }
            case 3:
                displayBooks(&bookstore);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } 

    // Clean up memory
    free(bookstore.books);

    return 0;
}
