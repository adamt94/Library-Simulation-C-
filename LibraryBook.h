/* 
 * File:   LibraryBook.h
 * Author: ypf12pxu
 *
 * Created on 03 March 2015, 14:40
 */

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "book.h"
using namespace std;

#ifndef LIBRARYBOOK_H
#define	LIBRARYBOOK_H

class LibraryBook : public Book {
public:
    //status of book
     enum Status {
        ON_LOAN,AVAILABLE_FOR_LENDING,REFERENCE_ONLY
    };
    //constructors
    LibraryBook();//default constructors
    LibraryBook(string title, string author, int pages,string code, string status);
    LibraryBook(const LibraryBook& orig);
    virtual ~LibraryBook();
    //get methods
    Status getStatus()const; 
    string getCode()const;
    //set methods
    void   setStatus(string status);//converts string to status
    string getStatusAsString();//return string of status
    void   setCode(string code);
    //operator
    friend ostream& operator <<(ostream& output, const LibraryBook& b);
    
    

private:
    string code; //classification code
    Status status;//book status
  
   

};

#endif	/* LIBRARYBOOK_H */

