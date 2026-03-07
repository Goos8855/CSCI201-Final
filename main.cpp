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
