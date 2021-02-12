//
// Created by SWQXDBA on 2021/2/12.
//

#ifndef JCGLXT_HEADS_H
#define JCGLXT_HEADS_H

#endif //JCGLXT_HEADS_H
#include<string>
#include <iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
using namespace std;
int comparebookname(const void *bk1,const void *bk2);
int comparebooksubject(const void *bk1,const void *bk2);
class book {
public:
         string name;
         int number;
         double price;
         string subject;
         string author;
         string publishingHouse;
         string comments;
public:
    book(const string &name, int number, double price, const string &subject, const string &author,
         const string &publishingHouse, const string &comments) : name(name), number(number), price(price),
                                                                  subject(subject), author(author),
                                                                  publishingHouse(publishingHouse),
                                                                  comments(comments) {}

    friend ostream &operator<<(ostream &os, const book &book) ;
};
class coursebooks {
public:
    coursebooks() ;
    void addbook();
    void save();
    void printBooks();
    void clear();
    void Editbook();
    void deletebook();
    void searchallbook();
    void sort();
private:
         book *booksArray[100];
         int size;
         bool isFileEmpty;
         string FILEPATH ;
};
enum {
    ³õÊ¼»¯=1,
    ÏÔÊ¾,
    Ìí¼Ó,
    É¾³ý,
    ±à¼­,
    ²éÑ¯,
    ÅÅÐò,
    ±£´æ,
    ÍË³ö=0
};

