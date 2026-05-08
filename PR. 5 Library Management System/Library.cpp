#include <iostream>
#include <string>
using namespace std;


class LibraryItem {
private:
    string title;
    string author;
    string dueDate;

public:
   
    virtual ~LibraryItem() {}

    string getTitle() const { 
        return title; 
    }
    string getAuthor() const {
         return author; 
        }
    string getDueDate() const { 
        return dueDate;
     }
    
    void setTitle(string newTitle) {
         title = newTitle;
         }
    void setAuthor(string newAuthor) {
         author = newAuthor;
         }
    void setDueDate(string newDueDate) {
         dueDate = newDueDate;
         }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;
};

class Book : public LibraryItem {
private:
    int pages;

public:
    Book(string t, string a, int p) {
        setTitle(t);
        setAuthor(a);
        pages = p;
    }

    void checkOut() override {
        setDueDate("10 Days");
        cout << "Book Checked Out Successfully\n";
    }

    void returnItem() override {
        setDueDate("None");
        cout << "Book Returned Successfully\n";
    }

    void displayDetails() const override {
        cout << "\n[BOOK]";
        cout << "\nTitle   : " << getTitle();
        cout << "\nAuthor  : " << getAuthor();
        cout << "\nPages   : " << pages;
        cout << "\nDueDate : " << getDueDate() << endl;
    }
};

class DVD : public LibraryItem {
private:
    int duration;

public:
    DVD(string t, string a, int d) {
        setTitle(t);
        setAuthor(a);
        duration = d;
    }

    void checkOut() override {
        setDueDate("7 Days");
        cout << "DVD Checked Out Successfully\n";
    }

    void returnItem() override {
        setDueDate("None");
        cout << "DVD Returned Successfully\n";
    }

    void displayDetails() const override {
        cout << "\nDVD";
        cout << "\nTitle    : " << getTitle();
        cout << "\nDirector : " << getAuthor();
        cout << "\nDuration : " << duration << " mins";
        cout << "\nDueDate  : " << getDueDate() << endl;
    }
};

class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(string t, string a, int i) {
        setTitle(t);
        setAuthor(a);
        issueNumber = i;
    }

    void checkOut() override {
        setDueDate("5 Days");
        cout << "Magazine Checked Out Successfully!\n";
    }

    void returnItem() override {
        setDueDate("None");
        cout << "Magazine Returned Successfully!\n";
    }

    void displayDetails() const override {
        cout << "\nMAGAZINE";
        cout << "\nTitle     : " << getTitle();
        cout << "\nPublisher : " << getAuthor();
        cout << "\nIssue No. : " << issueNumber;
        cout << "\nDueDate   : " << getDueDate() << endl;
    }
};

int main() {

    int MAX;
    MAX =50;

    LibraryItem* libraryItems[MAX];
    int count = 0;
    int choice;

    try {
        do {
            cout << "\n---LIBRARY MANAGEMENT SYSTEM ---";
            cout << "\n1. Add Book";
            cout << "\n2. Add DVD";
            cout << "\n3. Add Magazine";
            cout << "\n4. Display All Items";
            cout << "\n5. Check Out Item";
            cout << "\n6. Return Item";
            cout << "\n0. Exit";
            cout << "\nEnter Choice: ";
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid Input! Please enter a number.\n";
                continue;
            }

    
            if (choice == 1) {
                if (count >= MAX) {
                    cout << "Library is full! Cannot add more items.\n";
                } else {
                    string t, a;
                    int p;
                    cout << "Enter Title: ";
                    cin >> t;
                    cout << "Enter Author: ";
                    cin >> a;
                    cout << "Enter Pages: ";
                    cin >> p;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        throw invalid_argument("Invalid input for pages!");
                    }
                    if (p <= 0) throw invalid_argument("Pages must be positive!");

                    libraryItems[count++] = new Book(t, a, p);
                    cout << "Book added successfully!\n";
                }
            }
            else if (choice == 2) {
                if (count >= MAX) {
                    cout << "Library is full! Cannot add more items.\n";
                } else {
                    string t, a;
                    int d;
                    cout << "Enter Title: ";
                    cin >> t;
                    cout << "Enter Director: ";
                    cin >> a;
                    cout << "Enter Duration (mins): ";
                    cin >> d;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        throw invalid_argument("Invalid input for duration!");
                    }
                    if (d <= 0) throw invalid_argument("Duration must be positive!");

                    libraryItems[count++] = new DVD(t, a, d);
                    cout << "DVD added successfully!\n";
                }
            }
            else if (choice == 3) {
                if (count >= MAX) {
                    cout << "Library is full! Cannot add more items.\n";
                } else {
                    string t, a;
                    int i;
                    cout << "Enter Title: ";
                    cin >> t;
                    cout << "Enter Publisher: ";
                    cin >> a;
                    cout << "Enter Issue Number: ";
                    cin >> i;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        throw invalid_argument("Invalid input for issue number!");
                    }
                    if (i <= 0) throw invalid_argument("Issue number must be positive!");

                    libraryItems[count++] = new Magazine(t, a, i);
                    cout << "Magazine added successfully!\n";
                }
            }
            else if (choice == 4) {
                if (count == 0) {
                    cout << "\nNo items in the library!\n";
                } else {
                    cout << "\n---ALL LIBRARY ITEMS ---";
                    for (int i = 0; i < count; i++) {
                        cout << "\n[Index: " << i << "]";
                        libraryItems[i]->displayDetails();
                    }
                }
            }
            else if (choice == 5) {
                if (count == 0) {
                    cout << "No items in the library\n";
                } else {
                    int index;
                    cout << "Enter Item Index (0-" << count - 1 << "): ";
                    cin >> index;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid input\n";
                    }
                    else if (index < 0 || index >= count) {
                        cout << "Invalid index " << count - 1 << ".\n";
                    }
                    else {
                        libraryItems[index]->checkOut();
                    }
                }
            }
            else if (choice == 6) {
                if (count == 0) {
                    cout << "No items in the library\n";
                } else {
                    int index;
                    cout << "Enter Item Index (0-" << count - 1 << "): ";
                    cin >> index;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid input!\n";
                    }
                    else if (index < 0 || index >= count) {
                        cout << "Invalid index " << count - 1 << ".\n";
                    }
                    else {
                        libraryItems[index]->returnItem();
                    }
                }
            }
            else if (choice == 0) {
                cout << "Exiting Program...\n";
            }
            else {
                cout << "Invalid Choice\n";
            }
      

        } while (choice != 0);

    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
        for (int i = 0; i < count; i++) {
            delete libraryItems[i];
        }
        return 1;
    }

    for (int i = 0; i < count; i++) {
        delete libraryItems[i];
    }

    return 0;
}