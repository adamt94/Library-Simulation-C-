/* 
 * File:   LibraryBook.cpp
 * Author: ypf12pxu
 * 
 * Created on 03 March 2015, 14:40
 */
#include "LibraryBook.h"
using namespace std;

LibraryBook::LibraryBook(string title, string author, int pages, string code, string status)
: Book(title, author, pages) {
    this->title = title;
    this->author = author;
    this->pages = pages;
    this->code = code;
    if (status == "REFERENCE ONLY") {
        this->status = REFERENCE_ONLY;
    } else if (status == "AVAILABLE FOR LENDING") {
        this->status = AVAILABLE_FOR_LENDING;


    }
}

LibraryBook::LibraryBook(const LibraryBook& orig) : Book(orig) {
    this->title = orig.title;
    this->author = orig.author;
    this->pages = orig.pages;
    this->code = orig.code;
    this->status = orig.status;
}

LibraryBook::~LibraryBook() {
}

LibraryBook::Status LibraryBook::getStatus() const {
    return this->status;
}

void LibraryBook::setStatus(string status) {
    if (status == "REFERENCE ONLY") {
        this->status = REFERENCE_ONLY;
    } else if (status == "AVAILABLE FOR LENDING") {
        this->status = AVAILABLE_FOR_LENDING;


    } else if (status == "ON_LOAN") {
        this->status = ON_LOAN;
    }
}
string LibraryBook::getStatusAsString(){
     if (status == REFERENCE_ONLY) {
        return "REFERENCE_ONLY";
    } else if (status == AVAILABLE_FOR_LENDING) {
        return "AVAILABLE_FOR_LENDING";


    } else if (status == ON_LOAN) {
        return  "ON_LOAN";
        
    }
    
}

string LibraryBook::getCode() const {
    return code;
}

void LibraryBook::setCode(string code) {
    this->code = code;
}

ostream& operator<<(ostream& output, const LibraryBook& b) {
    return output << " title: " << b.getTitle() << " author: " << b.getAuthor() << " pages: " << b.getPages() << " code: " << b.getCode() << " Status: " << b.getStatus() << endl;
}


