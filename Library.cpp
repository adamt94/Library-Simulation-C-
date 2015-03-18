/* 
 * File:   library.cpp
 * Author: adam
 * 
 * Created on March 15, 2015, 11:53 PM
 */

#include "Library.h"

Library::Library() {
}

Library::Library(vector<LibraryBook> librarybooks, vector<Borrower> borrowers) {
    this->librarybooks = librarybooks;
    this->borrowers = borrowers;
}

Library::Library(const Library& orig) {
    this->librarybooks = librarybooks;
    this->borrowers = borrowers;
}

Library::~Library() {
}

vector<LibraryBook> Library::getLibrarybooks() {
    return librarybooks;
}

vector<Borrower> Library::getBorrowers() {
    return borrowers;
}

void Library::setLibraybook(vector<LibraryBook> librarybooks) {
    this->librarybooks = librarybooks;
}

void Library::setBorrowers(vector<Borrower> borrowers) {
    this->borrowers = borrowers;
}

void Library::addBorrowers(Borrower borrower) {
    borrowers.push_back(borrower);
}

void Library::addLibrarybooks(LibraryBook book) {
    librarybooks.push_back(book);

}

void Library::processRequest(string request, string name, string author, string bookname) {



    int i = findBorrower(name);
    int j = findBook(author, bookname);



    if (request == "request") {
        if (librarybooks[j].getStatus() == LibraryBook::AVAILABLE_FOR_LENDING) {
            if (borrowers[i].getOnloan().size() < 3) { // make sure borrowers has not got max books onloan
                librarybooks[j].setStatus("ON_LOAN");
                borrowers[i].addOnloan(librarybooks[j]);
                borrowers[i].addTransaction(borrowers[i].getName(), librarybooks[j].getTitle());

            } else {
                throw string("Unable to request BOOK: "
                        + librarybooks[j].getTitle()
                        + " to BORROWER: "+borrowers[i].getName()
                        +" user has 3 books");
             


            }

        } else {
            throw string("Unable to request BOOK: "
                    + librarybooks[j].getTitle()
                    + " to BORROWER: " 
                    + borrowers[i].getName()
                    + " due to STATUS: "
                    + librarybooks[j].getStatusAsString());
           
        }

    } else if (request == "return") {
        for (int k = 0; k < borrowers[i].getOnloan().size(); k++) {
            if (bookname == borrowers[i].getOnloan()[k].getTitle()) {

                borrowers[i].removenloan(k);
                borrowers[i].addTransaction(borrowers[i].getName(), librarybooks[j].getTitle());
                librarybooks[j].setStatus("AVAILABLE FOR LENDING");
            }

        }

       



    }
}


int Library::findBorrower(string name) {
    for (int i = 0; i < borrowers.size(); i++) {
        if (name == borrowers[i].getName())
            return i;

    }
    throw string("error name not found");
   


}

int Library::findBook(string author, string bookname) {
    for (int j = 0; j < librarybooks.size(); j++) { // loop round books
        if (author == librarybooks[j].getAuthor() && bookname == librarybooks[j].getTitle()) {
            return j;
        }



    }
    throw string("error name not found");
    
}






