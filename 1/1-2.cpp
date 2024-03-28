#include<iostream>
#include<string>
using namespace std;
typedef struct Link 
{
    char a;
    struct Link* next;
    struct Link* front;
}Linknode;

void InitLink(Linknode*&h){//初始化循环双链表
    h=new Linknode;
    h->next=h;
    h->front=h;
}
void print(Linknode*&h){//输出双链表
    Linknode *p=h->next;
    while(p!=h)
    {
        cout<<p->a<<" ";
        p=p->next;
    }
    cout<<endl;
    return;
}
void InsertLink(Linknode*&h,char ch){//用尾插法插入
    Linknode *t = new Linknode;  
    t->a = ch;  
    t->next = h;  
    t->front = h->front;  
    h->front->next = t; // 将前一个节点的next指向新节点  
    h->front = t; // 更新头节点的前指针  
    return ;
}
int getlenth(Linknode*&h){//输出双链表h长度
    if (h->next==h)return 0;
    int lenth=0;
    Linknode *p=h->next;
    while(p!=h)
    {
        lenth++;
        p=p->next;
    }
    return lenth;
}
int ifempty(Linknode*&h){//判断双链表h是否为空
    
    if (h->next==h)return 1;
    return 0;
}
int ifSymmetry(Linknode*&h){//判断双链表h是否对称
    Linknode *p=h->next;
    Linknode*r=h->front;
    while(p!=r&&p->next!=r)//分别是奇数偶数终止的情况
    {
        if(p->a!=r->a)return 0;
        p=p->next;
        r=r->front;
    }
    return 1;
}
int main(){
    Linknode*A;
    string str;
    cin>>str;//以学号的字符串作为输入(不用string的话直接用char数组是一样的，用int类型输入的话+'0'即可)
    InitLink(A);//初始化双链表
    for(char i:str){InsertLink(A,i);}
    print(A);//输出

    Linknode*B;
    InitLink(B);
    str="abc";
    //依次插入’a’,’b’,’c’ ,并每次插入后输出双链表内容、长度、是否为空。 
    for(auto i:str){
    InsertLink(B,i);
    print(B);
    cout<<"lenth:"<<getlenth(B)<<"\tifempty:"<<ifempty(B)<<"\n";}

    Linknode*C;//新建一个空链表并判断其是否为空。 
    InitLink(C);
    cout<<"lenth:"<<getlenth(C)<<"\tifempty:"<<ifempty(C)<<"\n";

    //以 “12321” ， “123321”， “12312” 三个字符串初始化双链表并判断其是否对称
    for (int i = 0; i < 3; i++)
    {
        cin>>str;
        Linknode*C;
        InitLink(C);
        for(auto i:str){InsertLink(C,i);}
        cout<<ifSymmetry(C)<<"\n";
    }
    
    
    return 0;
}