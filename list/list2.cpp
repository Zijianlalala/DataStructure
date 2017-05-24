#include<iostream>
using namespace std;

struct SList{
	int data;
	struct SList *next;
};
SList * Create(int);
void  ShowList(SList *);

int main(){
	SList * head;
	int num;
	cout<<"please input the number of total:"<<endl;
	cin>>num;
	head = Create(num);
	ShowList(head);
	return 0;
}
SList * Create(int n){
	SList *h,*p;
	h = new SList;
	h->next = NULL;
	for(int i = 0;i < n;i++){
		p = new SList;
		p->data = i+1;
		p->next = h->next;
		h->next = p;
	}
	return h;
}
void  ShowList(SList *h){
	SList *p;
	p = h->next;
	while(p!=NULL){
		cout<<p->data<<endl;
		p = p->next;
	}
}
