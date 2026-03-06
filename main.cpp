#include <iostream>
#include <vector>
#include <string>
#include "library.h"

using namespace std;

int main(){

    Library library;
    try {
        library.loadData();
        library.displayBooks();
        library.displayPatrons();

        library.checkoutBook(1, "The Great Gatsby");
        library.returnBook(1, "The Great Gatsby");
        library.saveData();
    }
    catch (const std::exception& e) {
        std::cerr << "Application Error: " << e.what() << std::endl;
    }
    return 0;
}
