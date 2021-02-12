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
        cout<<"请输入名称"<<endl;
        cin>>name;
        cout<<"请输入数量"<<endl;
        cin>>number;
        cout<<"请输入价格"<<endl;
        cin>>price;
        cout<<"请输入科目"<<endl;
        cin>>subject;
        cout<<"请输入作者"<<endl;
        cin>>author;
        cout<<"请输入出版社"<<endl;
        cin>>publishingHouse;
        cout<<"请输入备注"<<endl;
        cin>>comments;
        book *newbook = new book(name, number, price, subject, author, publishingHouse, comments);
        booksArray[size]=newbook;
        this->size++;
        isFileEmpty=false;

    }
}
void coursebooks::printBooks() {
    cout<<"共有"<<size<<"本书"<<endl;
        for(int i=0;i<this->size;i++){
            cout<<"序号:"<<i<<" "<<*booksArray[i]<<endl;
        }

}
void coursebooks::save() {
    if(isFileEmpty){
        cout<<"无法保存空的数据！"<<endl;
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
        cout << "未找到文件" << endl;
        this->isFileEmpty = true;
        f.close();
    } else {
        char ch;
        f.get(ch);
        if (f.eof()) {
            this->isFileEmpty = true;
            cout << "文件为空" << endl;
        }
        f.close();
    }
    if (!this->isFileEmpty) {
        f.open(FILEPATH, ios::in);
        cout<<"开始读入文件"<<endl;
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
    cout<<"请输入初始化密码:"<<endl;
    cin>>key;
    if(key!=12345){
        cout<<"密码错误！"<<endl;
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
       cout<<"请输入要修改的书籍序号"<<endl;
       cin>>n;
       if(n>=size){
           cout<<"超出序号范围"<<endl;
           return;
       }
       cout<<"要修改的书籍信息为："<<endl<<*booksArray[n]<<endl;

       delete booksArray[n];
       booksArray[n] = NULL;
    string name;
    int number;
    double price;
    string subject;
    string author;
    string publishingHouse;
    string comments;
    cout<<"请输入名称"<<endl;
    cin>>name;
    cout<<"请输入数量"<<endl;
    cin>>number;
    cout<<"请输入价格"<<endl;
    cin>>price;
    cout<<"请输入科目"<<endl;
    cin>>subject;
    cout<<"请输入作者"<<endl;
    cin>>author;
    cout<<"请输入出版社"<<endl;
    cin>>publishingHouse;
    cout<<"请输入备注"<<endl;
    cin>>comments;
    book *newbook = new book(name, number, price, subject, author, publishingHouse, comments);
    booksArray[n]=newbook;

}

void coursebooks::deletebook() {
       if(isFileEmpty){
           cout<<"书籍为空！"<<endl;
           return;
       }
       int n;
    cout<<"请输入要删除的书籍序号"<<endl;
    cin>>n;
    if(n>=size){
        cout<<"超出序号范围"<<endl;
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
    cout<<"删除完毕"<<endl;

}

void coursebooks::searchallbook() {
          int opt;
          int count=0;
          cout<<"请输入查找的依据，1名称 2专业"<<endl;

          cin>>opt;
          if(opt!=1&&opt!=2){
              cout<<"输入错误！"<<endl;
              return;
          }
          if(opt==1){
              string srchname;
              cout<<"请输入查询的书籍名称"<<endl;
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
        cout<<"请输入查询的书籍专业"<<endl;
        cin>>srchname;
        for(int i=0;i<size;i++){
            if(booksArray[i]->subject==srchname){
                cout<<*booksArray[i]<<endl;
                count++;
            }
        }
    }
    if(count==0)
    cout<<"找不到目标书籍！"<<endl;
    else
        cout<<"共找到了"<<count<<"本书"<<endl;


}

void coursebooks::sort() {
    int opt;
    cout<<"请输入排序的依据，1名称 2出版社"<<endl;
    cin>>opt;
    if(opt!=1&&opt!=2){
        cout<<"输入错误！"<<endl;
        return;
    }
    if(opt==1){
        qsort(&this->booksArray[0],size-1,sizeof(book*),comparebookname);
    }
    else{
        qsort(&this->booksArray[0],size-1,sizeof(book*),comparebooksubject);
    }

}




