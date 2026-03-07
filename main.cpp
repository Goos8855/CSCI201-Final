// CSCI 201 Final Project

// Notes:
// Use this to compile: g++ main.cpp library.cpp patron.cpp transaction.cpp book.cpp -o program
// Then use this to run: ./program
// (the vs code run button will not work)


//todo:
//add txt files for books and patrons
//add more data to said text files
//test

#include <iostream>
#include <vector>
#include <string>
#include "library.h"
#include "book.h"
#include "patron.h"

using namespace std;

int main(){

    Library library;
    string choice;

    cout << "Library Management System: Make a selection" << endl;
    cout << "quit" << endl << "patrons" << endl << "books" << endl << "checkout" << endl << "return" << endl << "load" << endl << "save" << endl;

    while(true){
        cin >> choice;
        if(choice == "quit"){
            return 0;
        } else if (choice == "patrons"){
            library.displayPatrons();
        } else if (choice == "books"){
            library.displayBooks();
        } else if (choice == "checkout"){
            cout << "Enter ID and book Title: ";
            int id;
            string title;
            cin >> id >> title;
            library.checkoutBook(id, title);
        } else if (choice == "return"){
            cout << "Enter ID and book Title: ";
            int id;
            string title;
            cin >> id >> title;
            library.returnBook(id, title);
        } else if (choice == "load"){
            library.loadData();
        } else if (choice == "save"){
            library.saveData();
        } else {
            cout << "Invalid Command" << endl;
        }
    }

    try {
        library.loadData();
        library.displayBooks();
        library.displayPatrons();

        library.checkoutBook(1, "The Great Gatsby");
        library.returnBook(1, "The Great Gatsby");
        library.saveData();
    }
    catch (const std::exception& e) {
        std::cerr << "Application Error: " << e.what() << std::endl;
    }
    cout << "Program has ran";
    return 0;
}
