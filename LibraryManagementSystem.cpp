#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isIssued = false;
    }
};

class Member {
public:
    int id;
    string name;

    Member(int memberId, string memberName) {
        id = memberId;
        name = memberName;
    }
};

class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:

    void addBook() {
        int id;
        string title, author;

        cout << "\nEnter Book ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));

        cout << "\nBook added successfully!\n";
    }

    void addMember() {
        int id;
        string name;

        cout << "\nEnter Member ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Member Name: ";
        getline(cin, name);

        members.push_back(Member(id, name));

        cout << "\nMember added successfully!\n";
    }

    void displayBooks() {

        if (books.empty()) {
            cout << "\nNo books available.\n";
            return;
        }

        cout << "\n----- BOOK LIST -----\n";

        for (int i = 0; i < books.size(); i++) {

            cout << "Book ID    : " << books[i].id << endl;
            cout << "Title      : " << books[i].title << endl;
            cout << "Author     : " << books[i].author << endl;

            if (books[i].isIssued)
                cout << "Status     : Issued\n";
            else
                cout << "Status     : Available\n";

            cout << "---------------------\n";
        }
    }

    void searchBook() {

        string search;
        bool found = false;

        cin.ignore();

        cout << "\nEnter title or author to search: ";
        getline(cin, search);

        for (int i = 0; i < books.size(); i++) {

            if (books[i].title.find(search) != string::npos ||
                books[i].author.find(search) != string::npos) {

                cout << "\nBook Found!\n";
                cout << "Book ID : " << books[i].id << endl;
                cout << "Title   : " << books[i].title << endl;
                cout << "Author  : " << books[i].author << endl;

                if (books[i].isIssued)
                    cout << "Status  : Issued\n";
                else
                    cout << "Status  : Available\n";

                found = true;
            }
        }

        if (!found) {
            cout << "\nBook not found.\n";
        }
    }

    void issueBook() {

        int bookId;

        cout << "\nEnter Book ID to issue: ";
        cin >> bookId;

        for (int i = 0; i < books.size(); i++) {

            if (books[i].id == bookId) {

                if (books[i].isIssued) {
                    cout << "\nBook is already issued.\n";
                }
                else {
                    books[i].isIssued = true;
                    cout << "\nBook issued successfully!\n";
                }

                return;
            }
        }

        cout << "\nBook ID not found.\n";
    }

    void returnBook() {

        int bookId;

        cout << "\nEnter Book ID to return: ";
        cin >> bookId;

        for (int i = 0; i < books.size(); i++) {

            if (books[i].id == bookId) {

                if (!books[i].isIssued) {
                    cout << "\nThis book was not issued.\n";
                }
                else {
                    books[i].isIssued = false;
                    cout << "\nBook returned successfully!\n";
                }

                return;
            }
        }

        cout << "\nBook ID not found.\n";
    }
};

int main() {

    Library library;

    int choice;

    do {

        cout << "\n==============================\n";
        cout << "   LIBRARY MANAGEMENT SYSTEM\n";
        cout << "==============================\n";

        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Display Books\n";
        cout << "4. Search Book\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                library.addBook();
                break;

            case 2:
                library.addMember();
                break;

            case 3:
                library.displayBooks();
                break;

            case 4:
                library.searchBook();
                break;

            case 5:
                library.issueBook();
                break;

            case 6:
                library.returnBook();
                break;

            case 7:
                cout << "\nThank you for using Library Management System!\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
