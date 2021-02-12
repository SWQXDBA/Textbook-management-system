#include "heads.h"

int main() {
    int operation=-1;
    coursebooks *bks1 = new coursebooks();
    cout<<"##########教材管理系统#########"<<endl;
    cout<<"########## by ysc #########"<<endl;
    cout<<"#####不手动保存不会自动保存！#####"<<endl;
    cout<<"#####不手动保存不会自动保存！#####"<<endl;
    cout<<"#####不手动保存不会自动保存！#####"<<endl;
while(true){

    cout<<"1初始化,2显示,3添加,4删除,5编辑\n"
          "6查询,7排序,8保存,0退出\n"<<endl;

    cin>>operation;
    if(operation<0||operation>8){
        cout<<"输入错误！请重新输入"<<endl;
    }
    switch(operation){
        case 初始化:bks1->clear();break;
        case 显示:bks1->printBooks();break;
        case 添加:bks1->addbook();break;
        case 删除:bks1->deletebook();break;
        case 编辑:bks1->Editbook();break;
        case 查询:bks1->searchallbook();break;
        case 排序:bks1->sort();break;
        case 保存:bks1->save();break;
        case 退出:return 0;break;
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
