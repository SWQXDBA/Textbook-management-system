#include "heads.h"

int main() {
    int operation=-1;
    coursebooks *bks1 = new coursebooks();
    cout<<"##########�̲Ĺ���ϵͳ#########"<<endl;
    cout<<"########## by ysc #########"<<endl;
    cout<<"#####���ֶ����治���Զ����棡#####"<<endl;
    cout<<"#####���ֶ����治���Զ����棡#####"<<endl;
    cout<<"#####���ֶ����治���Զ����棡#####"<<endl;
while(true){

    cout<<"1��ʼ��,2��ʾ,3���,4ɾ��,5�༭\n"
          "6��ѯ,7����,8����,0�˳�\n"<<endl;

    cin>>operation;
    if(operation<0||operation>8){
        cout<<"�����������������"<<endl;
    }
    switch(operation){
        case ��ʼ��:bks1->clear();break;
        case ��ʾ:bks1->printBooks();break;
        case ���:bks1->addbook();break;
        case ɾ��:bks1->deletebook();break;
        case �༭:bks1->Editbook();break;
        case ��ѯ:bks1->searchallbook();break;
        case ����:bks1->sort();break;
        case ����:bks1->save();break;
        case �˳�:return 0;break;
    }

}



    return 0;
}
//1 1 1 1 1 1 1
//2 2 2 2 2 2 2
//3 3 3 3 3 3 3
//a 1 1 1 1 1 1
//c 1 1 1 1 1 1
//d 1 1 1 1 1 1
