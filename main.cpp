// CSCI 201 Final Project

// Notes:
// Use this to compile: g++ main.cpp library.cpp patron.cpp transaction.cpp book.cpp -o program
// Then use this to run: ./program
// (the vs code run button will not work)

//Books.txt is in this format:
//genre
//title
//author
//type
//size
//available

//Patrons.txt is in this format:
//id
//name

#include <iostream>
#include <vector>
#include <string>
#include "library.h"
#include "book.h"
#include "patron.h"

using namespace std;

//main function (hosts gui and calls all the other class functions)
int main(){

    Library library;
    string choice;

    cout << "Library Management System: Make a selection" << endl;
    cout << "quit" << endl << "patrons" << endl << "books" << endl << "checkout" << endl << "return" << endl << "load" << endl << "save" << endl;

    //Menu selection and calls selected functions
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
    
    //Testing code, though it should never get here since it breaks on quit  
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
