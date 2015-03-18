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
    Borrower();//default constructor
    Borrower(int Idnumber, string name, string address);
    Borrower(const Borrower& orig);
    virtual ~Borrower();
    //get methods
    int getIdnumber()const;
    string getName()const;
    string getAddress()const;
    int getPagesread()const;
    vector<Book> getOnloan();
    vector<string> getTransactions();
    
    //set methods
    void   setName(string name);
    void   setNumber(int number);
    void   setAddress(string address);
    void   setPagesread(int pages);
    
    void   addOnloan(Book book);//add book to users books on loan
    void   addTransaction(string request,string author, string title);//record transaction
    void   removenloan(int pos);// remove book from users loan
    //operators
    friend ostream& operator <<(ostream& output, const Borrower& b);
    
    
        
    
  
    
    
private:
    int Idnumber;
    string name;
    int pagesread;//sum of all the pages user has loaned
 
   string address;
   vector<Book> onloan;//books that user has on loan
   vector<string> transactions;//records what books the user requested and returned
    

};

#endif	/* BORROWER_H */

