#include "transaction.h"
#include <iostream>
using namespace std;

//todo:
//change display message/make it prettier?

//Transaction Object: Stores ID, title, and sets stored time to the time chekced out (which is the time when the object is created, thus the time being set to now)
Transaction::Transaction(int id, string title): patronId(id), bookTitle(title){
    time_t t = time(0);
    date = ctime(&t);
}

//exports object data to terminal
void Transaction::displayTransaction() const{
    cout << "PatronId:" << patronId << endl;
    cout << "bookTitle" << bookTitle << endl;
    cout << "date: " << date << endl;
}