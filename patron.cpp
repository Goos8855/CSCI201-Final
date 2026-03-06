#include "patron.h"
#include <iostream>
using namespace std;

//patron object
//borrowBook()
//returnBook()
//displayPatron()
//operator==
//operator<<

Patron::Patron(string name, int id): name(name), id(id){}

void borrowBook(Book* b){
    if(b->getStatus()==BookStatus::Available){
        b->setStatus(BookStatus::CheckedOut);
        borrowBook.push_back(b);
    } else {
        cout << "Book Unavailable" << endl;
    }
}