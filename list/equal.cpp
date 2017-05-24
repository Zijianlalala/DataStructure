#include<iostream>
#include"LinkList.cpp"
using namespace std;
bool IsEqual(LinkList l1,LinkList l2){
    Node *p,*q;
    p = l1.GetFirst()->next;
    q = l2.GetFirst()->next;
    while(q && p){
        if(q->data != p->data){
            return  false;
        }
        q = q->next;
        p = p->next;
    }
    if(!p && !q){
        return true;
    }else{
        return false;
    }
}
int main(){
    LinkList l1(10);
    LinkList l2(10.0);
    cout << "l1: " << endl;
    l1.PrintList();
    cout << "l2 :" << endl;
    l2.PrintList();
    cout << "Does l1 equal l2 ? " << IsEqual(l1,l2) <<endl;
    return 0;
}
