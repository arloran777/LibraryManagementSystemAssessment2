#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool availability;
    string dateAdd;

public:
    // Constructor
    Book();

    // Assign book information
    void setBookDetails(string bookTitle, string bookAuthor,
        string bookISBN, bool available,
        string bookDateAdd);

    // Display book information
    void displayBookDetails() const;

    // Borrow a book
    void borrowBook();

    // Return a book
    void returnBook();

    // Sort books by ISBN
    static void sortBookData(Book books[], int size);

    // Get ISBN
    string getISBN() const;
};

#endif

