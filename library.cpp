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

Library::~Library(){}

void Library::addBook(Book* b){
    books.push_back(b);
}
void Library::addPatron(const Patron& p){
    patrons.push_back(p);
}

void Library::checkoutBook(int patronId, string title){ //still needs fixed
    int checkOut;
    for(int i=0; i<books.size(); i++){
        if(books[i]->title == title && books[i]->getStatus() == BookStatus::Available){
            books[i]->setStatus(BookStatus::CheckedOut); 
            checkOut = i;
        } else {
            cout << "Book Unavailable" << endl;
            return;

        }
    }
    for(int i=0; i<patrons.size(); i++){
        if(patrons[i].id == patronId){
            patrons[i].borrowBook(books[checkOut]);
        } else {
            cout << "No user found" << endl;
            return;
        }
    }
}

void Library::returnBook(int patronId, string title){ //also has errors for some reason
    Book* returnBook;
    for(int i=0; i<books.size(); i++){
        if(books[i]->title == title && books[i]->getStatus() == BookStatus::CheckedOut){
            books[i]->setStatus(BookStatus::Available); 
            returnBook = books[i];
        } else {
            cout << "Book Unavailable" << endl;
            return;

        }
    }
    for(int i=0; i<patrons.size(); i++){
        if(patrons[i].id == patronId){
            patrons[i].returnBook(returnBook);
        } else {
            cout << "No user found" << endl;
            return;
        }
    }
}

//these two just prints the data in their respective lists
void Library::displayBooks() const{
    for(int i=0; i<books.size(); i++){
        books[i]->displayInfo();
    }
}
void Library::displayPatrons() const{
    for(int i=0; i<patrons.size(); i++){
        patrons[i].displayPatron();
    }
}

