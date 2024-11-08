# Online-Bookstore-Management-System
### Table of Contents
- Project Overview
- Features
- Technologies Used
- Usage
- Sample Output
 
Project Overview:

The Online Bookstore Management System is a console-based application written in C. This project is designed to manage a bookstore inventory, allowing users to add, delete, and display books. It leverages       dynamic memory allocation to efficiently handle a growing list of books and provides input validation to ensure data integrity.


Features:

- Add New Book: Enter details like title, author, ISBN, and price to add a new book to the inventory.
- Delete Book: Remove a book from the inventory using its ISBN.
- Display All Books: View the list of all books currently available in the bookstore.
- Input Validation: Handles invalid inputs for integer and floating-point data.
- Memory Management: Uses dynamic memory allocation and ensures memory is released properly.


Technologies Used:

- Programming Language: C

Concepts:
- Dynamic Memory Allocation (malloc, realloc, free)
- Structures (struct)


Usage:

----- Online Bookstore System -----
1. Add Book
2. Delete Book
3. Display Books
4. Exit
1. Add a Book
Enter the book's details, such as title, author, ISBN, and price.
If the ISBN already exists, the book won't be added.
2. Delete a Book
Provide the ISBN of the book to be deleted.
If the book is found, it will be removed from the inventory.
3. Display Books
Displays a list of all books currently in the inventory along with their details.
4. Exit
Exits the application, releasing all allocated memory.


Sample Output:

Copy code
----- Online Bookstore System -----
1. Add Book
2. Delete Book
3. Display Books
4. Exit
Enter your choice: 1

Enter details for the new book:
Title: C Programming Language
Author: Dennis Ritchie
ISBN: 12345
Price: $29.99
Book added successfully.

----- Online Bookstore System -----
1. Add Book
2. Delete Book
3. Display Books
4. Exit
Enter your choice: 3

--- Books in the Bookstore ---
Title: C Programming Language
Author: Dennis Ritchie
ISBN: 12345
Price: $29.99
