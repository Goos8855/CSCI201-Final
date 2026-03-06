#include <book.h>
#include <iostream>
using namespace std;

//todo:
//setStatus()
//getStatus()
//operator==
//operator<<

Book::Book(string title, string author, Genre genre):title(title), author(author), genre(genre), status(BookStatus::Available) {}

void Book::displayInfo() const{
    cout << title << " by " << author << endl;
    string genreType;
    if(genre == Genre::Fiction){
        genreType = "Fiction";
    }   else if(genre == Genre::NonFiction){
        genreType = "Non-Fiction";
    }   else if(genre == Genre::Mystery){
        genreType = "Mystery";
    }   else if(genre == Genre::Science){
        genreType = "Science";
    }   else if(genre == Genre::Biography){
        genreType = "Biography";
    }

    string status;
    if(this->status == BookStatus::Available){
        status = "Available";
    }   else if(this->status == BookStatus::CheckedOut){
        status = "Checked Out";
    }
    cout << "Genre: " << genreType << endl << "Status: " << status << endl;
}

