#include<iostream>
#include"LinkList.cpp"
using namespace std;
LinkList Intersection(LinkList l1,LinkList l2){
    Node *p,*q,*r,*s,*u;
    p = l1.GetFirst()->next;
    q = l2.GetFirst()->next;
    LinkList l3;
    r = l3.GetFirst();
    while(p && q){
        if(p->data > q->data)
            q = q->next;
        else if(p->data < q->data)
            p = p->next;
        else{
            s = new Node;
            s->data = p->data;
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
    }
    r->next = NULL;
    return l3;
}
int main(){
    LinkList l1(10);
    LinkList l2(10.0);
    LinkList l3;
    l3 = Intersection(l1,l2);
    l3.PrintList();
    return 0;
}
