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
//constructor
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

//converts a string to an int
int Book::converInt(string number) {
    int value = 0;
    pages = value;
    return value = atoi(number.c_str());
}

//compares the value of books and sorts them alphabetically by author then title
bool operator< (Book &book1, Book &book2)
{
    if (book1.author == book2.author){
        return book1.title < book2.title;
    } else {
        return book1.author < book2.author;
    }
    
}

//print Book object
ostream& operator <<(ostream& output, const Book& b){
    return output <<"title: "<< b.getAuthor()<<" author: "<<b.getAuthor()<<" pages"<<b.pages<<endl;
}

istream &operator>>( istream& input,const Book& b )
      { 
        // input >> b.setTitle() >> b.setAuthor()>>b.setPages();
        // return input;            
      }