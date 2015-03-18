/* 
 * File:   Borrower.cpp
 * Author: ypf12pxu
 * 
 * Created on 05 March 2015, 13:52
 */

#include <stdio.h>

#include "Borrower.h"

Borrower::Borrower(){}

Borrower::Borrower(int Idnumber, string name, string address) {
    this->Idnumber = Idnumber;
    this->name = name;
    this->address = address;

}

Borrower::Borrower(const Borrower& orig) {
    this->Idnumber = orig.Idnumber;
    this->name = orig.name;
    this->address = orig.address;
}

Borrower::~Borrower() {
}

int Borrower::getIdnumber()const {
    return Idnumber;
}

string Borrower::getName()const {
    return name;
}

int Borrower::getPagesread() const{
    return pagesread;
}


vector<string> Borrower::getTransactions() {
    return transactions;
}

string Borrower::getAddress()const {
    return address;
}

vector<Book> Borrower::getOnloan() {
    return onloan;
}

void Borrower::setName(string name) {
    this->name = name;
}

void Borrower::setNumber(int number) {
    this->Idnumber = number;
}

void Borrower::setAddress(string address) {
    this->address = address;
}
/*add the book pages when book is on loan*/
void Borrower::setPagesread(int pages){
    pagesread+=pages;
}
/*when user requests a book add to on loan vector*/
void Borrower::addOnloan(Book book) {
    onloan.push_back(book);
}

/*when a user return a book remove from its onloan vector*/
void Borrower::removenloan(int pos) {

    
    onloan.erase(onloan.begin()+pos);
   
    
 
}
    




/*3 params adds to a string vector to record users transactions*/
void Borrower::addTransaction(string request, string author, string title) {
    string s = request+" "+author+" "+title;
   
    transactions.push_back(s);
   
    
}


/*print the Borrowers values*/
ostream& operator<<(ostream& output, const Borrower& b) {
    return output << "ID: " << b.getIdnumber() << " name: " << b.getName() <<
            " Address: " << b.getAddress() <<" pages read: "
            <<b.getPagesread() <<endl;
}






