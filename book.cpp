#include <book.h>
#include <iostream>
using namespace std;

//todo:
//operator==
//operator<<

//Book object: Stores title, author, genre, and status values
Book::Book(string title, string author, Genre genre):title(title), author(author), genre(genre), status(BookStatus::Available) {}

//Display Information: Outputs book title and author, and selects appropriate string for genre and status
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

//Status: Gets and sets status :I
void Book::setStatus(BookStatus setStatus){
    this->status = setStatus;
}

BookStatus Book::getStatus() const{
    return this->status;
}

