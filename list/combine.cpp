#include<iostream>
#include"LinkList.cpp"
using namespace std;
//使用三个指针即可
LinkList Combine(LinkList l1,LinkList l2){
    LinkList l3;
    Node *p,*q,*r;
    p = l1.GetFirst()->next;
    q = l2.GetFirst()->next;
    r = l3.GetFirst();
    while(p && q){
        if(p->data < q->data){
            r->next = p;
            r = p;
            p = p->next;
        }else if(p->data > q->data){
            r->next = q;
            r = q;
            q = q->next;
        }else{
            r->next = p;
            r = p;
            p = p->next;
            q = q->next;
        }
    }
    if(q){
        while(q){
            r->next = q;
            r = q;
            q = q->next;
        }
    }else{
        while(p){
            r->next = p;
            r = p;
            p = p->next;
        }
     }
        return l3;
}

int main(){
    cout << "初始化LA" << endl;
    LinkList l1(10);
    l1.PrintList();
    cout << "初始化LB" << endl;
    LinkList l2(10.0);
    l2.PrintList();
    cout << "生成合并链表LC" <<endl;
    LinkList l3;
    l3 = Combine(l1,l2);
    l3.PrintList();
    
    return 0;
}

