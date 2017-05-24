#include<iostream>
using namespace std;
struct Node{
	int data;
	Node * next;
};
class LinkList{
	private :
		Node * first;
	public :
		LinkList();
		LinkList(int n);
		~LinkList();
		int Length();
		void PrintList();
		void Insert(int i,int data);
		int Get(int i);
		int Locate(int data);
		void Delete(int i);
};
LinkList::LinkList(){
	first = new Node;
	first->next = NULL;
}
LinkList::LinkList(int n){
	first = new Node;
	Node *p,*r;
	r = first;
	//r始终指向最后一个元素
	for(int i = 0;i < n;i++){
		p = new Node;
		p->data = i+1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	cout<<"LinkList was Created!"<<endl;
}
LinkList::~LinkList(){
	while(first!=NULL){
		Node *p = new Node;
		p = first;
		first = first->next;
		delete p;
	}
}
void LinkList::PrintList(){
	Node *p = first->next;
	while(p!=NULL){
		cout<<p->data<<endl;
		p = p->next;
	}
}
int LinkList::Length(){
	int count = 0;
	Node *p = first->next;
	while(p!=NULL){
		count++;
		p = p->next;
	}
	return count;
}
int LinkList::Get(int i){
	Node *p;
	int count = 0;
	p = first;
	while(p!=NULL && count<i){
		p = p->next;
		count++;
	}
	if(p == NULL){
		throw invalid_argument("位置异常");
	}else{
		return p->data;
	}
}
int LinkList::Locate(int data){
	Node *p;
	p = first;
	int count = 0;
	while(p!=NULL && p->data!=data){
		p = p->next;
		count++;
	}
	if(p == NULL){
		throw invalid_argument("Exception");
	}else{
		return count;
	}
}
void LinkList::Insert(int i , int data){
	Node *p;
	Node *s;
	int count = 0;
	p = first;
	while(p!=NULL && count < i-1){
		p = p->next;
		count++;
	}
	if(p == NULL)
		throw invalid_argument("EXCEPTION");
	else{	
		s = new Node;
		s->data = data;
		s->next = p->next;
		p->next = s;
	}
}
void LinkList::Delete(int i){
	//先找到第i个节点
	Node *p,*r;
	p = first;
	int count = 0;
	while(p!=NULL && count<i-1){
		p = p->next;
		count++;
	}
	if(p == NULL)
		throw invalid_argument("Exception");
	else{
		r = p->next;
		p->next = r->next;;
		delete r;
	}
}	
int main(){

	int x;
	int i;
	cout<<"input a number:"<<endl;
	cin>>x;

	LinkList list(x);
	list.PrintList();
	cout<<"The length of the LinkList is :"<<list.Length()<<endl;
	try{
		cout<<"输入你想查找的值的位置:";
		cin>>i;
		cout<<"该位置的值为: "<<list.Get(i)<<endl;
		cout<<"请输入你想查找的值,返回它的位置:";
		cin>>x;
		cout<<list.Locate(x)<<endl;
		cout<<"请输入你想插入的数的位置和数值："<<endl;
		cout<<"i = ";
		cin>>i;
		cout<<"x = ";
		cin>>x;
		list.Insert(i,x);
		list.PrintList();
		cout<<"输入你要删除的结点的位置：";
		cin>>i;
		list.Delete(i);
		cout<<"已删除"<<endl;
		list.PrintList();
	}catch(const invalid_argument& e){
		cout<<"No Pointer Exception"<<endl;	
	}
	return 0;
}

