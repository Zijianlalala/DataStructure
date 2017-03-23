#include<iostream>
using namespace std;
//单链表的逆置问题
//单链表的复制
struct Node{
	int data;
	Node *next;
};
class SList{
	private :
		Node *first;
	public :
		SList();
		SList(int n);
		SList(Node *head);
		~SList();
		void PrintList();
		void Reverse();
		Node *Copy();
};
SList::SList(){
	first = new Node;
	first->next = NULL;
}
SList::SList(int n){
	first = new Node;
	Node *p;
	first->next = NULL;
	int count = 0;
	while(count < n){
		p = new Node;
		p->data = count+1;
		p->next = first->next;
		first->next = p;
		count++;
	}
	cout<<"SList was created."<<endl;
}
SList::SList(Node *head){
	this->first = head;
	cout<<"SList was created."<<endl;
}
SList::~SList(){
	Node *p;
	while(first!=NULL){
		p = first;
		first = first->next;
		delete p;	
	}
	cout<<"SList was destroyed."<<endl;

}
void SList::PrintList(){
	Node *p;
	p = first->next;
	while(p != NULL){
		cout<<p->data<<endl;
		p = p->next;
	
	}
}
void SList::Reverse(){
	Node *p,*pre,*r;
	pre = NULL;
	p = first->next;
	while( p!=NULL ){
		r = new Node;
		r = p->next;
		p->next = pre;
		pre = p;
		p = r;
	}
	first->next = pre;
}
Node* SList::Copy(){
	Node *head,*p,*r,*s;
	head = new Node;
	r = head;
	p = first->next;
	while(p){
		s = new Node;
		s->data = p->data;
		r->next = s;
		r = s;
		p = p->next;
	}
	r->next = NULL;
	return head;
}
int main(){
	SList slist(5);
	slist.PrintList();
	cout<<"Now the list was Reversed."<<endl;
	slist.Reverse();
	slist.PrintList();
	Node *head = slist.Copy();
	SList list2(head);
	list2.PrintList();
	return 0;
}
