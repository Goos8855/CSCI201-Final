#include <transaction.h>
#include <iostream>
using namespace std;

//todo:
//change display message/make it prettier?

Transaction::Transaction(int id, string title): patronId(id), bookTitle(title){
    time_t t = time(0);
    date = ctime(&t);
}

void Transaction::displayTransaction() const{
    cout << "PatronId:" << patronId << endl;
    cout << "bookTitle" << bookTitle << endl;
    cout << "date: " << date << endl;
}