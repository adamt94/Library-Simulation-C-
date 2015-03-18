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
     enum Status {
        ON_LOAN,AVAILABLE_FOR_LENDING,REFERENCE_ONLY
    };
    LibraryBook();
    LibraryBook(string title, string author, int pages,string code, string status);
    LibraryBook(const LibraryBook& orig);
    virtual ~LibraryBook();
    Status getStatus()const; 
    string getCode()const;
    void   setStatus(string status);
    string getStatusAsString();
    void   setCode(string code);
    friend ostream& operator <<(ostream& output, const LibraryBook& b);

private:
    string code;
    Status status;
  
   

};

#endif	/* LIBRARYBOOK_H */

