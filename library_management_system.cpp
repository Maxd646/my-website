#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Book Class
class Book {
public:
    int id;
    string title;
    string author;
    int copies;

    Book(int bookId, string bookTitle, string bookAuthor, int bookCopies) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        copies = bookCopies;
    }
};

// Member Class
class Member {
public:
    int memberId;
    string name;

    Member(int id, string memberName) {
        memberId = id;
        name = memberName;
    }
};

// Library Class
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    void addBook() {
        int id, copies;
        string title, author;
        cout << "Enter book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter book author: ";
        getline(cin, author);
        cout << "Enter number of copies: ";
        cin >> copies;
        books.push_back(Book(id, title, author, copies));
        cout << "Book added successfully.\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }
        cout << setw(5) << "ID" << setw(30) << "Title" << setw(20) << "Author" << setw(10) << "Copies\n";
        for (const auto& book : books) {
            cout << setw(5) << book.id << setw(30) << book.title << setw(20) << book.author << setw(10) << book.copies << "\n";
        }
    }

    void searchBook() {
        int id;
        cout << "Enter book ID to search: ";
        cin >> id;
        for (const auto& book : books) {
            if (book.id == id) {
                cout << "Book found: " << book.title << " by " << book.author << " (Copies: " << book.copies << ")\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void addMember() {
        int id;
        string name;
        cout << "Enter member ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter member name: ";
        getline(cin, name);
        members.push_back(Member(id, name));
        cout << "Member added successfully.\n";
    }

    void borrowBook() {
        int bookId, memberId;
        cout << "Enter member ID: ";
        cin >> memberId;
        cout << "Enter book ID: ";
        cin >> bookId;

        for (auto& book : books) {
            if (book.id == bookId) {
                if (book.copies > 0) {
                    book.copies--;
                    cout << "Book borrowed successfully by member " << memberId << ".\n";
                } else {
                    cout << "No copies available to borrow.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook() {
        int bookId;
        cout << "Enter book ID to return: ";
        cin >> bookId;

        for (auto& book : books) {
            if (book.id == bookId) {
                book.copies++;
                cout << "Book returned successfully.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\n=== Library Management System ===\n";
        cout<<"Please see bellow that u want and choice the number"<<endl;
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Add Member\n";
        cout << "5. Borrow Book\n";
        cout << "6. Return Book\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            library.addBook();
            break;
        case 2:
            library.displayBooks();
            break;
        case 3:
            library.searchBook();
            break;
        case 4:
            library.addMember();
            break;
        case 5:
            library.borrowBook();
            break;
        case 6:
            library.returnBook();
            break;
        case 7:
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
