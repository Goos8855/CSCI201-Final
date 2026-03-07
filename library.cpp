#include "library.h"
#include "patron.h"
#include "patron.cpp"
#include <iostream>
using namespace std;

//todo:
//library object
//loadData()
//saveData()
//checkoutBook()
//returnBook()
//displayBooks() 
//displayPatrons()

Library::~Library(){}

void Library::addBook(Book* b){
    books.push_back(b);
}
void Library::addPatron(const Patron& p){
    patrons.push_back(p);
}

void Library::checkoutBook(int patronId, string title){
    Book* checkOut;
    for(int i=0; i<books.size(); i++){
        if(books[i].title == title && books[i].getStatus() == BookStatus::Available){
            books[i].setStatus(BookStatus::CheckedOut); //still needs fixed
            checkOut = &books[i];
        } else {
            cout << "Book Unavailable" << endl;
            return;

        }
    }
    for(int i=0; i<patrons.size(); i++){
        if(patrons[i].id == patronId){
            patrons[i].borrowBook(checkOut);
        } else {
            cout << "No user found" << endl;
            return;
        }
    }
}