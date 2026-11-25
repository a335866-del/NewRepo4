#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;
    string dateAdd;

public:
    // Constructor
    Book() : available(true) {}

    // Assign book details
    void setBookDetails(const string& bookTitle,
        const string& bookAuthor,
        const string& bookISBN,
        bool isAvailable,
        const string& dateAdded) {
        title = bookTitle;
        author = bookAuthor;
        isbn = bookISBN;
        available = isAvailable;
        dateAdd = dateAdded;
    }

    // Get ISBN
    string getISBN() const {
        return isbn;
    }

    // Display book information
    void displayBookDetails() const {
        cout << "\nTitle: " << title
            << "\nAuthor: " << author
            << "\nISBN: " << isbn
            << "\nAvailability: "
            << (available ? "Available" : "Borrowed")
            << "\nDate added: " << dateAdd << "\n";
    }

    // Borrow book
    bool borrowBook() {
        if (!available) {
            return false;
        }

        available = false;
        return true;
    }

    // Return book
    void returnBook() {
        available = true;
    }

    // Sort books by ISBN
    static void sortBookData(Book books[], int size) {
        sort(books, books + size,
            [](const Book& a, const Book& b) {
                return a.isbn < b.isbn;
            });
    }
};

// MAIN APPLICATION
int main() {

    const int SIZE = 5;
    Book books[SIZE];

    // Initialise five books
    books[0].setBookDetails(
        "The Hobbit", "J.R.R. Tolkien",
        "9780007525492", true, "2025-02-10");

    books[1].setBookDetails(
        "1984", "George Orwell",
        "9780451524935", true, "2025-02-12");

    books[2].setBookDetails(
        "Pride and Prejudice", "Jane Austen",
        "9780141439518", false, "2025-02-15");

    books[3].setBookDetails(
        "Dune", "Frank Herbert",
        "9780441172719", true, "2025-02-18");

    books[4].setBookDetails(
        "The Alchemist", "Paulo Coelho",
        "9780061122415", true, "2025-02-20");

    // Sort books by ISBN
    Book::sortBookData(books, SIZE);

    cout << "========================================\n";
    cout << " COMMUNITY LIBRARY - BOOK BORROWING\n";
    cout << "========================================\n";

    cout << "Enter 0 at any time to exit.\n";

    string requestedISBN;

    while (true) {

        cout << "\nEnter the ISBN of the book to borrow: ";
        cin >> requestedISBN;

        // Exit condition
        if (requestedISBN == "0") {
            cout << "\nThank you for using the library system.\n";
            cout << "Goodbye!\n";
            break;
        }

        bool found = false;

        // Search for the requested book
        for (int i = 0; i < SIZE; i++) {

            if (books[i].getISBN() == requestedISBN) {

                found = true;

                // Check availability and borrow
                if (books[i].borrowBook()) {
                    cout << "\nSUCCESS: Book borrowed successfully!\n";
                }
                else {
                    cout << "\nERROR: This book is currently unavailable.\n";
                }

                // Display book details
                books[i].displayBookDetails();

                break;
            }
        }

        // Book not found
        if (!found) {
            cout << "\nERROR: No book found with this ISBN.\n";
            cout << "Please check the ISBN and try again.\n";
        }
    }

    return 0;
}