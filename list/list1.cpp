#include<iostream>
using namespace std;
struct weapon {
	int atk;
	int price;
	struct weapon * next;
};
int main(){
	struct weapon a,b,c,*head;
	a.atk = 100;
	a.price = 100;
	b.atk = 200;
	b.price = 200;
	c.atk = 300;
	c.price = 300;
	head = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	struct weapon *p;
	p = head;
	while(p!=NULL){
		cout<<p->atk<<","<<p->price<<endl;
		p = p->next;
	}
	return 0;
}
