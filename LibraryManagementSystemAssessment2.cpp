#include <iostream>
#include "Book.h"

using namespace std;

int main() {
{
    //Initialise an array of five books
	Book books[5];

	books[0].setBookDetails(
		"Harry Potter and the Chamber of Secrets", "J.K. Roling",
		"9781408855669", true, "2025-09-20");
	books[1].setBookDetails(
		"The Hunger Games", "Suzanne Collins",
		"9780439023481", true, "2025-05-14");
	books[2].setBookDetails(
		"The Maze Ruuner", "James Dashner",
		"9780385737951", false, "2025-08-31");
	books[3].setBookDetails(
		"A Game of Thrones", "George R. R. Martin",
		"9780553593716", true, "2025-04-19");
	books[4].setBookDetails(
		"The Name of Wind", "Patrick Rothfuss",
		"9780756404079", true, "2025-12-24");
	

	Book::sortBookData(books, 5);

	int choice;
	string requestedISBN;
	bool found;

	cout << "================================" << endl;
	cout << " AIT Library Management System" << endl;
	cout << "================================" << endl;

	do {
        cout << "\n1. Borrow a book" << endl;
        cout << "2. Return a book" << endl;
        cout << "0. Exit program" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "\nThank you for using the Library System!"
                << endl;
            break;
        }

        if (choice != 1 && choice != 2) {
            cout << "Invalid option. Please try again." << endl;
            continue;
        }

        cout << "Enter the ISBN of the book: ";
        cin >> requestedISBN;

        found = false;

        // Search for the requested ISBN
        for (int i = 0; i < 5; i++) {

            if (books[i].getISBN() == requestedISBN) {
                found = true;

                books[i].displayBookDetails();

                if (choice == 1) {
                    books[i].borrowBook();
                }
                else {
                    books[i].returnBook();
                }

                break;
            }
        }

        if (!found) {
            cout << "Error: Book not found in the library."
                << endl;
        }

    } while (true);

    return 0;
}
	}


