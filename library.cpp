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
    for(int i=0; i<patrons.size(); i++){
        if(patrons[i].id == patronId){
            patrons[i].borrowBook(title);
        } else {
            cout << "No user found" << endl;
        }
    }
    //this still needs finished
}