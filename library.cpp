#include "library.h"
#include "patron.h"
#include <iostream>
#include <fstream>
using namespace std;

//Object
Library::~Library(){}

//addBook/Patron: adds book to list in the book class and patrons to patron list in patron class
void Library::addBook(Book* b){
    books.push_back(b);
}
void Library::addPatron(const Patron& p){
    patrons.push_back(p);
}

//checkout & return: adds and removes books from available library and personal libraries
void Library::checkoutBook(int patronId, string title){
    int checkOut;
    for(int i=0; i<books.size(); i++){
        if(books[i]->title == title && books[i]->getStatus() == BookStatus::Available){
            books[i]->setStatus(BookStatus::CheckedOut); 
            cout << "Book checked out" << endl;
            checkOut = i;
        }
    }
    for(int i=0; i<patrons.size(); i++){
        if(patrons[i].id == patronId){
            patrons[i].borrowBook(books[checkOut]);
        }
    }
}

void Library::returnBook(int patronId, string title){ //also has errors for some reason
    Book* returnBook;
    for(int i=0; i<books.size(); i++){
        if(books[i]->title == title && books[i]->getStatus() == BookStatus::CheckedOut){
            books[i]->setStatus(BookStatus::Available); 
            cout << "Book returned" << endl;
            returnBook = books[i];
        }
    }
    for(int i=0; i<patrons.size(); i++){
        if(patrons[i].id == patronId){
            patrons[i].returnBook(returnBook);
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

//reads data in the sequence, in the order of title, author, genre, type, size, then status, before appending it to the books list
void Library::loadData(){
    string loadBooks = "books.txt";
    ifstream inputBooks(loadBooks);

    if(inputBooks.is_open()){
        string tempTitle;
        string tempAuthor;
        string tempGenre;
        string type;
        Genre genre;
        string tempStatus;
        BookStatus status;
        string tempSize;
        double size;
        while(!inputBooks.eof()){
            try{
                getline(inputBooks, tempGenre);
                getline(inputBooks, tempTitle);
                getline(inputBooks, tempAuthor);
                getline(inputBooks, type);
                getline(inputBooks, tempSize);
                getline(inputBooks, tempStatus);

                if(tempGenre == "Fiction"){
                    genre = Genre::Fiction;
                }   else if(tempGenre == "Non-Fiction"){
                    genre = Genre::NonFiction;
                }   else if(tempGenre == "Mystery"){
                    genre = Genre::Mystery;
                }   else if(tempGenre == "Science"){
                    genre = Genre::Science;
                }   else if(tempGenre == "Biography"){
                    genre = Genre::Biography;
                }
                if(tempStatus == "Available"){
                    status = BookStatus::Available;
                }   else if(tempStatus == "Checked Out"){
                    status = BookStatus::CheckedOut;
                }
            }
            catch(exception& e){
                cout << "Error loading book data: " << e.what() << endl;
                continue;
            }
            
            if(type == "printedbook"){
                books.push_back(new PrintedBook(tempTitle, tempAuthor, genre, int(size)));
            } else if (type == "ebook"){
                books.push_back(new EBook(tempTitle, tempAuthor, genre, size));
            } else {
                cout << "Error loading book types" << endl;
            }

        }
        inputBooks.close();

    }
    string loadPatrons = "patrons.txt";
    ifstream inputPatrons(loadPatrons);
    if(inputPatrons.is_open()){
        string tempName;
        string tempId;
        int id;
        while(!inputPatrons.eof()){
            try{
                getline(inputPatrons, tempId);
                id = stoi(tempId);
                getline(inputPatrons, tempName);
            }
            catch(exception& e){
                cout << "Error loading patron data: " << e.what() << endl;
                break;
            }
            patrons.push_back(Patron(tempName, id));
        }
        inputPatrons.close();
    }
}
void Library::saveData(){

}

