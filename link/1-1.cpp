#include<iostream>
#include<string>
using namespace std;
typedef struct Link 
{
    char a;
    struct Link* next;
}Linknode;
void CreateLink(Linknode*&h,string a){
    Linknode *t,*r;
    h=new Linknode;
    r=h;
    for(char i:a)
    {
        t=new Linknode;
        t->a=i;
        t->next=NULL;
        r->next=t;
        r=r->next;
    }
    return;
}
int main(){
    //输入
    string a,b;
    Linknode *A=NULL,*B=NULL;
    cin>>a>>b;//(不用string的话直接用char数组是一样的，用int类型输入的话+'0'即可)
    //创建
    CreateLink(A, a);
    CreateLink(B, b);
    //比较
    Linknode *t1=A,*t2=B->next;
    while (t1->next!=NULL)
    {   
        t1=t1->next;//A的下一个
        if (t1->a==t2->a)t2=t2->next;//在A找到B的开头，准备比较B的下一个
        else t2=B->next;//若不同B回到开头，等待在A找到下一个开头
        if(t2==NULL){cout<<"yes";return 0;}//B被找完了
    }
    cout<<"no";
    return 0;
}