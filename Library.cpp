/* 
 * File:   library.cpp
 * Author: adam
 * 
 * Created on March 15, 2015, 11:53 PM
 */

#include "Library.h"
//default constructor

Library::Library() {
}
//constructors

Library::Library(vector<LibraryBook> librarybooks, vector<Borrower> borrowers) {
    this->librarybooks = librarybooks;
    this->borrowers = borrowers;
}

Library::Library(const Library& orig) {
    this->librarybooks = orig.librarybooks;
    this->borrowers = orig.borrowers;
}

Library::~Library() {
}
//get methods

vector<LibraryBook> Library::getLibrarybooks() {
    return librarybooks;
}

vector<Borrower> Library::getBorrowers() {
    return borrowers;
}

//set methods

void Library::setLibraybook(vector<LibraryBook> librarybooks) {
    this->librarybooks = librarybooks;
}

void Library::setBorrowers(vector<Borrower> borrowers) {
    this->borrowers = borrowers;
}

/*add a borrower to vector*/
void Library::addBorrowers(Borrower borrower) {
    borrowers.push_back(borrower);
}

/*add a librarybooks to the vector*/
void Library::addLibrarybooks(LibraryBook book) {
    librarybooks.push_back(book);

}

//process the requests from the trasaction file txt

void Library::processRequest(string request, string name, string author, string bookname) {


    //check if the borrower is valid from vector
    int i = findBorrower(name);
    //check if the book is valid from librarybooks vector
    int j = findBook(author, bookname);



     //check if its a request
    if (request == "request") {
        /*check if the request for a book is available for lending otherwise
         catch error*/
        if (librarybooks[j].getStatus() == LibraryBook::AVAILABLE_FOR_LENDING) {
             // make sure borrowers has not got max books onloan or throw error
            if (borrowers[i].getOnloan().size() < 3) {
               //set the books status to on loan
                librarybooks[j].setStatus("ON_LOAN");
                //add the book to the borrowers onloan vector
                borrowers[i].addOnloan(librarybooks[j]);
                //add the request to the transaction log
                borrowers[i].addTransaction(request, author, bookname);
                //add the borrowers books total pages to read
                borrowers[i].setPagesread(librarybooks[j].getPages());

            } else {
                /*throw exception if the borrower already has 3 books
                 on loan*/
                throw string("Unable to request BOOK: "
                        + librarybooks[j].getTitle()
                        + " to BORROWER: " + borrowers[i].getName()
                        + " user has 3 books");



            }

        } else {
            /*throw exception if the book is reference only or is already
             on loan*/
            throw string("Unable to request BOOK: "
                    + librarybooks[j].getTitle()
                    + " to BORROWER: "
                    + borrowers[i].getName()
                    + " due to STATUS: "
                    + librarybooks[j].getStatusAsString());

        }

    }
    /*check if the transaction was a return*/
    else if (request == "return") {
        //iterate through the borrowers on loan
        for (int k = 0; k < borrowers[i].getOnloan().size(); k++) {
            //check if the return book matches the borrowers book
            if (bookname == borrowers[i].getOnloan()[k].getTitle()) {
                
                //remove the book from the users on loan vector
                borrowers[i].removenloan(k);
                //put the details of book to transaction log
                borrowers[i].addTransaction(request, author, bookname);
                //change the book status to available for lending
                librarybooks[j].setStatus("AVAILABLE FOR LENDING");

            }

        }





    } else {
        //check if the request doesnt match
        throw string("request unknown");
    }
}

//pass string check if name matches the name of the borrower
int Library::findBorrower(string name) {
    for (int i = 0; i < borrowers.size(); i++) {
        if (name == borrowers[i].getName())
            return i;

    }
    throw string("error name not found");



}
/*pass author and string iterate through to check if author and title matches
 the book in the library*/
int Library::findBook(string author, string bookname) {
    for (int j = 0; j < librarybooks.size(); j++) { // loop round books
        if (author == librarybooks[j].getAuthor() && bookname == librarybooks[j].getTitle()) {
            return j;
        }



    }
    throw string("error name not found");

}
/*iterate through the borrowers checking who has the most loans*/
int Library::mostLoans() {
    int maxtrans = 0;
    int user = 0;
    for (int i = 0; i < borrowers.size(); i++) {
        if (borrowers[i].getTransactions().size() > maxtrans) {
            maxtrans = borrowers[i].getTransactions().size();
            user = i; // record what user it was
        }


    }
    //print users name and how many loans he has
    cout << borrowers[user].getName() << " had: "
            << (maxtrans + 1) / 2 << " loans" << endl;
    return maxtrans;
}

/*iterate through the users check who has the least pages read 
 * by adding the books pages on loan*/
void Library::leastRead() {
    int leastpages = 0;
    int user = 0;
    for (int i = 0; i < borrowers.size(); i++) {
        if (borrowers[i].getPagesread() < leastpages || leastpages == 0) {
            leastpages = borrowers[i].getPagesread();
            user = i; // record what user it was
        }
    }
    //print name and the pages read
    cout << borrowers[user].getName() << " read  the least at: " << leastpages << endl;

    //sort(borrowers.begin(),borrowers.end(),sortByAuthor);

}
