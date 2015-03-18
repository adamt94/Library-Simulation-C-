/* 
 * File:   library.h
 * Author: adam
 *
 * Created on March 15, 2015, 11:52 PM
 */

#ifndef LIBRARY_H
#define	LIBRARY_H
#include "Book.h"
#include "Borrower.h"
#include "LibraryBook.h"
class Library {
public:
    Library();
    Library(vector<LibraryBook> librarybooks, vector<Borrower> borrowers);
    Library(const Library& orig);
    virtual ~Library();
    vector<LibraryBook> getLibrarybooks();
    vector<Borrower> getBorrowers();
    void setLibraybook(vector<LibraryBook> librarybooks);
    void setBorrowers(vector<Borrower> borrowers);
    void addLibrarybooks(LibraryBook book);
    void addBorrowers(Borrower borrower);
    void processRequest(string request, string name,string author, string bookname);
    int findBorrower(string name);
    int findBook(string author,string bookname);
    Book returnBook();
    
   
    
private:
    vector<LibraryBook> librarybooks;
    vector<Borrower> borrowers;
    

};

#endif	/* LIBRARY_H */

