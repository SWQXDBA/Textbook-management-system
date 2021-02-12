//
// Created by SWQXDBA on 2021/2/12.
//
#include "heads.h"
void coursebooks::addbook() {
    {
        string name;
        int number;
        double price;
        string subject;
        string author;
        string publishingHouse;
        string comments;
        cout<<"����������"<<endl;
        cin>>name;
        cout<<"����������"<<endl;
        cin>>number;
        cout<<"������۸�"<<endl;
        cin>>price;
        cout<<"�������Ŀ"<<endl;
        cin>>subject;
        cout<<"����������"<<endl;
        cin>>author;
        cout<<"�����������"<<endl;
        cin>>publishingHouse;
        cout<<"�����뱸ע"<<endl;
        cin>>comments;
        book *newbook = new book(name, number, price, subject, author, publishingHouse, comments);
        booksArray[size]=newbook;
        this->size++;
        isFileEmpty=false;

    }
}
void coursebooks::printBooks() {
    cout<<"����"<<size<<"����"<<endl;
        for(int i=0;i<this->size;i++){
            cout<<"���:"<<i<<" "<<*booksArray[i]<<endl;
        }

}
void coursebooks::save() {
    if(isFileEmpty){
        cout<<"�޷�����յ����ݣ�"<<endl;
        return;
    }
    ofstream F;
    F.open(FILEPATH,ios::out);
    for(int i=0;i<this->size;i++){
        F<<booksArray[i]->name<<" ";
        F<<booksArray[i]->number<<" ";
        F<<booksArray[i]->price<<" ";
        F<<booksArray[i]->subject<<" ";
        F<<booksArray[i]->author<<" ";
        F<<booksArray[i]->publishingHouse<<" ";
        F<<booksArray[i]->comments<<endl;

    }
}
coursebooks::coursebooks() {
    FILEPATH ="testfile.txt";
    this->isFileEmpty = false;
    ifstream f;
    f.open(FILEPATH, ios::in);
    if (!f.is_open()) {
        cout << "δ�ҵ��ļ�" << endl;
        this->isFileEmpty = true;
        f.close();
    } else {
        char ch;
        f.get(ch);
        if (f.eof()) {
            this->isFileEmpty = true;
            cout << "�ļ�Ϊ��" << endl;
        }
        f.close();
    }
    if (!this->isFileEmpty) {
        f.open(FILEPATH, ios::in);
        cout<<"��ʼ�����ļ�"<<endl;
        this->size = 0;
        string name;
        int number;
        double price;
        string subject;
        string author;
        string publishingHouse;
        string comments;
        while (f >> name && f >> number && f >> price && f >> subject && f >> author &&
               f >> publishingHouse && f >> comments) {
            book *newbook = new book(name, number, price, subject, author, publishingHouse, comments);
            booksArray[size] = newbook;
            this->size++;
        }
    }
    else{
        size=0;
    }
}
void coursebooks::clear() {
    long int key;
    cout<<"�������ʼ������:"<<endl;
    cin>>key;
    if(key!=12345){
        cout<<"�������"<<endl;
        return;
    }

      for(int i=0;i<size;i++){
          delete booksArray[i];
          booksArray[i]=NULL;
      }
      size=0;
      isFileEmpty=true;
}

void coursebooks::Editbook() {
       int n;
       cout<<"������Ҫ�޸ĵ��鼮���"<<endl;
       cin>>n;
       if(n>=size){
           cout<<"������ŷ�Χ"<<endl;
           return;
       }
       cout<<"Ҫ�޸ĵ��鼮��ϢΪ��"<<endl<<*booksArray[n]<<endl;

       delete booksArray[n];
       booksArray[n] = NULL;
    string name;
    int number;
    double price;
    string subject;
    string author;
    string publishingHouse;
    string comments;
    cout<<"����������"<<endl;
    cin>>name;
    cout<<"����������"<<endl;
    cin>>number;
    cout<<"������۸�"<<endl;
    cin>>price;
    cout<<"�������Ŀ"<<endl;
    cin>>subject;
    cout<<"����������"<<endl;
    cin>>author;
    cout<<"�����������"<<endl;
    cin>>publishingHouse;
    cout<<"�����뱸ע"<<endl;
    cin>>comments;
    book *newbook = new book(name, number, price, subject, author, publishingHouse, comments);
    booksArray[n]=newbook;

}

void coursebooks::deletebook() {
       if(isFileEmpty){
           cout<<"�鼮Ϊ�գ�"<<endl;
           return;
       }
       int n;
    cout<<"������Ҫɾ�����鼮���"<<endl;
    cin>>n;
    if(n>=size){
        cout<<"������ŷ�Χ"<<endl;
        return;
    }
    delete booksArray[n];
    booksArray[n]=NULL;
    if(n!=size-1)
    {
        for(int i=n;i<size-1;i++){
            booksArray[i]=booksArray[i+1];
        }
        booksArray[size-1]=NULL;
    }
    size--;
    if(size==0)
        isFileEmpty=true;
    cout<<"ɾ�����"<<endl;

}

void coursebooks::searchallbook() {
          int opt;
          int count=0;
          cout<<"��������ҵ����ݣ�1���� 2רҵ"<<endl;

          cin>>opt;
          if(opt!=1&&opt!=2){
              cout<<"�������"<<endl;
              return;
          }
          if(opt==1){
              string srchname;
              cout<<"�������ѯ���鼮����"<<endl;
              cin>>srchname;
              for(int i=0;i<size;i++){
                    if(booksArray[i]->name==srchname){
                        cout<<*booksArray[i]<<endl;
                        count++;
                    }
              }
          }
    if(opt==2){
        string srchname;
        cout<<"�������ѯ���鼮רҵ"<<endl;
        cin>>srchname;
        for(int i=0;i<size;i++){
            if(booksArray[i]->subject==srchname){
                cout<<*booksArray[i]<<endl;
                count++;
            }
        }
    }
    if(count==0)
    cout<<"�Ҳ���Ŀ���鼮��"<<endl;
    else
        cout<<"���ҵ���"<<count<<"����"<<endl;


}

void coursebooks::sort() {
    int opt;
    cout<<"��������������ݣ�1���� 2������"<<endl;
    cin>>opt;
    if(opt!=1&&opt!=2){
        cout<<"�������"<<endl;
        return;
    }
    if(opt==1){
        qsort(&this->booksArray[0],size-1,sizeof(book*),comparebookname);
    }
    else{
        qsort(&this->booksArray[0],size-1,sizeof(book*),comparebooksubject);
    }

}




