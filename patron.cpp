#include "patron.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//operator==
//operator<<

//Patron Object: stores name, id , and books borrowed
Patron::Patron(string name, int id): name(name), id(id){}

//borrowBook: checks for availability then removes from available library to add it to patron's library
void Patron::borrowBook(Book* b){
    if(b->getStatus()==BookStatus::Available){
        b->setStatus(BookStatus::CheckedOut);
        borrowedBooks.push_back(b);
    }
}

//returnBook: checks for book in patron's library then adds it back to the available library
void Patron::returnBook(Book* b){
    for(int i=0; i<borrowedBooks.size(); i++){
        if(borrowedBooks[i] == b){
            b->setStatus(BookStatus::Available);
            borrowedBooks.erase(borrowedBooks.begin() + i);
            break;
        }
    }
}

//displayPatron: prints name, id, and books borrowed in terminal
void Patron::displayPatron() const{
    cout << "Patron #" << id << ": " << name << endl;
    cout << borrowedBooks.size() << " Borrowed Books: " << endl;
    for(int i=0; i<borrowedBooks.size(); i++){
        cout << borrowedBooks[i] << endl;
    }
}