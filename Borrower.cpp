/* 
 * File:   Borrower.cpp
 * Author: ypf12pxu
 * 
 * Created on 05 March 2015, 13:52
 */

#include <stdio.h>

#include "Borrower.h"

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

void Borrower::addOnloan(Book book) {
    onloan.push_back(book);
}

void Borrower::removenloan(int pos) {
    //cout<<pos<<endl;
   //return onloan[onloan.erase(onloan.begin()+pos-1, onloan.begin()+pos)];
    
    onloan.erase(onloan.begin()+pos);
   
    
 
}
    





void Borrower::addTransaction(string name, string title) {
    string s = name+" "+title;
    transactions.push_back(s);
   
}

ostream& operator<<(ostream& output, const Borrower& b) {
    return output << "ID: " << b.getIdnumber() << " name: " << b.getName() << " Address: " << b.getAddress() << endl;
}




