#include<iostream>
#include"LinkList.cpp"
using namespace std;
bool IsBelong(LinkList l1,LinkList l2){
    Node *p,*q;
    p = l1.GetFirst()->next;
    q = l2.GetFirst()->next;
    //空集是任何集合的子集
    if(!q){
        return true;
    }else{
        while(p){
            while(q && q->data != p->data){   
                q = q->next;
            }
            if(!q){
                return false;
             }else{
                 p = p->next;
              }
        }
    }
    return true;
} 
int main(){
    LinkList l1(10);
    LinkList l2;
    cout << "l2 belongs to l1 ? :" << IsBelong(l1,l2) << endl;
    return 0;
}
