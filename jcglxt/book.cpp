//
// Created by SWQXDBA on 2021/2/12.
//
#include "heads.h"
ostream &operator<<(ostream &os, const book &book) {
    os << "����: " << book.name << " ����: " << book.number << " �۸�: " << book.price << " ��Ŀ: "
       << book.subject << " ����: " << book.author << " ������: " << book.publishingHouse
       << " ��ע: " << book.comments;
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
