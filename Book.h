/* 
 * File:   Book.h
 * Author: ypf12pxu
 *
 * Created on 01 March 2015, 12:25
 */

#ifndef BOOK_H
#define	BOOK_H

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>


using namespace std;

class Book {
public:
    Book ();//default constructor
    Book(string title, string author, int pages);
    Book(const Book& orig);
    virtual ~Book();
    //get methods
    string getTitle()const;
    string getAuthor()const;
    int getPages()const;
    
    //set methods
    void setTitle(string setTitle);
    void setAuthor(string setAuthor);
    void setPages(int setPages);
    
    int converInt(string number);
    //operators
    friend ostream& operator <<(ostream& output, const Book& b);
    friend istream& operator >>(istream& output, const Book& b);
    friend bool operator< (Book &cC1, Book &cC2);



protected:
    string title;
    string author;
    int pages;

};

#endif	/* BOOK_H */

