/* 
 * File:   main.cpp
 * Author: ypf12pxu
 *
 * Created on 16 March 2015, 12:11
 */


#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "Book.h"
#include "Borrower.h"
#include "LibraryBook.h"
#include "Library.h"
using namespace std;

/*
 * 
 */



int main(int argc, char** argv) {

    Book b = Book("n", "ab", 22);

    cin>>b;




    string line;
    int ID;
    vector<Borrower> users;
    vector<LibraryBook> lBooks;
    ifstream myfile("users.txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            stringstream linestream(line);
            string name;
            string address;
            string line2;
            string region;
            string country;

            linestream >>ID;

            getline(linestream, name, ':');
            name.erase(name.begin());
            name.erase(name.end() - 1);
            getline(linestream, address);
            address.erase(address.begin());
            // getline(linestream, line2, ',');
            //  line2.erase(line2.begin());
            // getline(linestream, region, ',');
            //  region.erase(region.begin());
            //  getline(linestream, country);
            Borrower bor = Borrower(ID, name, address);

            users.push_back(bor);



            //cout << ID << " " << name << "" << address  << endl;
        }
        myfile.close();
        for (int i = 0; i < users.size(); i++) {
            // cout<<users[i]<<endl;;
        }
    } else cout << "Unable to open file";

    ifstream myfile2("librarybooks.txt");
    if (myfile2.is_open()) {
        while (getline(myfile2, line)) {
            stringstream linestream(line);
            string author;
            string name;
            int pages;
            string code;
            string status;
            getline(linestream, author, ',');
            getline(linestream, name, '(');
            name.erase(name.begin());
            name.erase(name.begin());
            name.erase(name.end() - 2, name.end());
            linestream >> pages;
            getline(linestream, code, '[');
            getline(linestream, code, ']');
            string::size_type pos = code.find(' ');
            status = code.substr(pos + 1);
            code = code.substr(0, pos);


            LibraryBook lb = LibraryBook(name, author, pages, code, status);
            

            lBooks.push_back(lb);



        }

        myfile2.close();
        for (int i = 0; i < users.size(); i++) {
            //  cout<<lBooks[i]<<endl;;
        }
    } else cout << "Unable to open file";


    Library lbrary = Library(lBooks, users);
     ofstream errorlog;
     errorlog.open("errorlog.txt");
    ifstream myfile3("transactions.txt");
    if (myfile3.is_open()) {
        while (getline(myfile3, line)) {
            stringstream linestream(line);
            string request;
            string name;
            string author;
            string bookname;

            getline(linestream, request, ':');
           
            getline(linestream, name, ':');
            name.erase(name.begin());
            name.erase(name.end() - 1);

            getline(linestream, author, ',');
            author.erase(author.begin());
            getline(linestream, bookname);
            bookname.erase(bookname.begin());
            bookname.erase(bookname.begin());
            bookname.erase(bookname.end() - 1);
            bookname.erase(bookname.end() - 1);
          
            try {
                lbrary.processRequest(request, name, author, bookname);
            } catch (string exception) {
                
                
               
                errorlog <<exception<<"\r\n";
                cerr<<exception<<endl;
             
                

            }
               
            

            // cout<<request<<" "<<name<<" "<<author<<" "<<bookname<<endl;




        }
        errorlog.close();
    }
    
    //largest number of loans
    lbrary.mostLoans();
    
    
    //person that has read the least
    lbrary.leastRead();

// sort the book list in order
  sort(lBooks.begin(), lBooks.end());
  cout<<"=====SORTED BOOK LIST======="<<endl;
  for(int i =0; i<lBooks.size(); i++)
  {
      cout<<lBooks[i]<<endl;
  }
 
    
   




}

