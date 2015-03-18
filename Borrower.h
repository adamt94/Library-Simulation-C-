/* 
 * File:   Borrower.h
 * Author: ypf12pxu
 *
 * Created on 05 March 2015, 13:51
 */
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>

#include "Book.h"
using namespace std;

#ifndef BORROWER_H
#define	BORROWER_H

class Borrower {
public:
    
    Borrower(int Idnumber, string name, string address);
    Borrower(const Borrower& orig);
    virtual ~Borrower();
    int getIdnumber()const;
    string getName()const;
    string getAddress()const;
    vector<Book> getOnloan();
    vector<string> getTransactions();
    void   setName(string name);
    void   setNumber(int number);
    void   setAddress(string address);
    
    void   addOnloan(Book book);
    void   addTransaction(string name, string title);
    void   removenloan(int pos);
    friend ostream& operator <<(ostream& output, const Borrower& b);
    
        
    
  
    
    
private:
    int Idnumber;
    string name;
 
   string address;
   vector<Book> onloan;
   vector<string> transactions;
    

};

#endif	/* BORROWER_H */

