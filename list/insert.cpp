#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
class LinkList{
    private :
        Node *first;
    public :
        LinkList();
        LinkList(int n);
        void PrintList();
        void Insert(int x);
};
LinkList::LinkList(){
    first = new Node;
    first->next = NULL;
}
LinkList::LinkList(int n){
    first = new Node;
    Node *p,*r;
    r = first;
    for(int i = 0; i < n; i+=2){
        p = new Node;
        p->data = i+2;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}
void LinkList::PrintList(){
    Node *p;
    p = first->next;
    while(p){
        cout << p->data << endl;
        p = p->next;
    }
}
//这里使用p->next作为判断条件而不是p的原因是避免了再使用一个指针r指向p的前一个地址
void LinkList::Insert(int x){
    Node *p,*r,*s;
    s = new Node;
    s->data = x;
    p = first;
    while(p->next && p->next->data <= x){
        p = p->next;
    }
        s->next = p->next;
        p->next = s;
}
int main(){
    cout << "The original version:" << endl;
    LinkList list(10);
    list.PrintList();
    cout << "Insert 7 :" << endl;
    list.Insert(7);
    list.PrintList();
    cout << "Insert 20 :" << endl;
    list.Insert(20);
    list.PrintList();
    cout << "Insert 0 :" << endl;
    list.Insert(-1);
    list.PrintList();
}
