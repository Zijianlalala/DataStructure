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
        LinkList(double n);
        void PrintList();
        void Insert(int x);
        Node* GetFirst();
        
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
LinkList::LinkList(double n){
    first = new Node;
    Node *p,*r;
    r = first;
    for(double i = 1.0;i<n;i+=2){
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
    if(!p)
        cout << "The LinkList is NULL." << endl;
    while(p){
        cout << p->data << endl;
        p = p->next;
    }
}
Node* LinkList::GetFirst(){
    return first;
}
