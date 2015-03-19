/* 
 * File:   library.h
 * Author: adam
 *
 * Created on March 15, 2015, 11:52 PM
 */

#ifndef LIBRARY_H
#define	LIBRARY_H
#include "Book.h"
#include <algorithm>
#include "Borrower.h"
#include "LibraryBook.h"
class Library {
public:
    Library();//default constructor
    Library(vector<LibraryBook> librarybooks, vector<Borrower> borrowers);
    Library(const Library& orig);
    virtual ~Library();
    //get methods
    vector<LibraryBook> getLibrarybooks();
    vector<Borrower> getBorrowers();
    //set methods
    void setLibraybook(vector<LibraryBook> librarybooks);
    void setBorrowers(vector<Borrower> borrowers);
    
    void addLibrarybooks(LibraryBook book);//add librarybook
    void addBorrowers(Borrower borrower);// add user
    void processRequest(string request, string name,string author, string bookname);
    
    int findBorrower(string name);//check borrower is in vector
    int findBook(string author,string bookname);//check borrower is in book
    Book returnBook();
    
    int mostLoans();//check which user had the most loans
    void leastRead();//check which user read the least pages
    void sortBooks();//sort books in order (author and name) and prints them
    
   
    
private:
    vector<LibraryBook> librarybooks;
    vector<Borrower> borrowers;
    

};

#endif	/* LIBRARY_H */

