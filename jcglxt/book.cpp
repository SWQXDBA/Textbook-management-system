//
// Created by SWQXDBA on 2021/2/12.
//
#include "heads.h"
ostream &operator<<(ostream &os, const book &book) {
    os << "书名: " << book.name << " 数量: " << book.number << " 价格: " << book.price << " 科目: "
       << book.subject << " 作者: " << book.author << " 出版社: " << book.publishingHouse
       << " 备注: " << book.comments;
    return os;
}
int comparebookname(const void *bk1,const void *bk2){
    book *b1 =(book*) *((book**)bk1);
    book *b2 = (book*) *((book**)bk2);
    return strcmp((b1->name).c_str(),(b2->name).c_str());
}
int comparebooksubject(const void *bk1,const void *bk2){
    book *b1 =(book*) *((book**)bk1);
    book *b2 = (book*) *((book**)bk2);
    return strcmp((b1->subject).c_str(),(b2->subject).c_str());
}
