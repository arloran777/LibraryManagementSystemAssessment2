#include "Book.h"
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

// Default constructor
Book::Book() {
    title = "";
    author = "";
    isbn = "";
    availability = true;
    dateAdd = "";
}

// Assign and validate book details
void Book::setBookDetails(string bookTitle, string bookAuthor,
    string bookISBN, bool available,
    string bookDateAdd) {

    // Validate title and author
    if (bookTitle.empty() || bookAuthor.empty()) {
        cout << "Error: Title or author cannot be empty." << endl;
        return;
    }

    // Validate ISBN length
    if (bookISBN.length() != 13) {
        cout << "Error: ISBN must contain 13 digits." << endl;
        return;
    }

    // Validate ISBN characters
    for (char digit : bookISBN) {
        if (!isdigit(static_cast<unsigned char>(digit))) {
            cout << "Error: ISBN must contain only numbers." << endl;
            return;
        }
    }

    // Validate date
    if (bookDateAdd.empty()) {
        cout << "Error: Date cannot be empty." << endl;
        return;
    }

    // Assign valid book details
    title = bookTitle;
    author = bookAuthor;
    isbn = bookISBN;
    availability = available;
    dateAdd = bookDateAdd;
}

// Display book details
void Book::displayBookDetails() const {
    cout << "\nTitle: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Availability: "
        << (availability ? "Available" : "Borrowed") << endl;
    cout << "Date Added: " << dateAdd << endl;
}

// Borrow a book
void Book::borrowBook() {
    if (availability) {
        availability = false;
        cout << "Book successfully borrowed!" << endl;
    }
    else {
        cout << "Error: This book is currently unavailable." << endl;
    }
}

// Return a book
void Book::returnBook() {
    if (!availability) {
        availability = true;
        cout << "Book successfully returned!" << endl;
    }
    else {
        cout << "This book has not been borrowed." << endl;
    }
}

// Sort books by ISBN using Bubble Sort
void Book::sortBookData(Book books[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {

            if (books[j].isbn > books[j + 1].isbn) {
                swap(books[j], books[j + 1]);
            }
        }
    }
}

// Return ISBN
string Book::getISBN() const {
    return isbn;
}
