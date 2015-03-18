/* 
 * File:   Book.cpp
 * Author: ypf12pxu
 * 
 * Created on 01 March 2015, 12:25
 */

#include "Book.h"


#include<iostream>

#include<fstream>
using namespace std;

Book::Book(string titles, string authors, int pages) {
    this->title = titles;
    this->author = authors;
    this->pages = pages;
}

Book::Book(const Book& orig) {
    this->title = orig.title;
    this->author = orig.author;
    this->pages = orig.pages;
}



Book::~Book() {
}

string Book::getTitle()const {
    return title;
}

string Book::getAuthor()const {
    return author;
}

int Book::getPages() const{
    return pages;
}

int Book::converInt(string number) {
    int value = 0;
    pages = value;
    return value = atoi(number.c_str());
}
ostream& operator <<(ostream& output, const Book& b){
    return output <<"title: "<< b.getAuthor()<<" author: "<<b.getAuthor()<<" pages"<<b.pages<<endl;
}

istream &operator>>( istream& input,const Book& b )
      { 
        // input >> b.setTitle() >> b.setAuthor()>>b.setPages();
        // return input;            
      }