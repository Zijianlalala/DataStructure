#include<iostream>
using namespace std;
struct Node
{
    char data;
    Node *lChild;
    Node *rChild;
};
class BiTree
{
    private:
        Node *root;
        int number;
        Node *Create(Node *bt);
        void Release(Node *bt);
        void PreOrder(Node *bt);
        void InOrder(Node *bt);
        void PostOrder(Node *bt);
        void NumPlus(Node *bt);
    public:
        BiTree(){root = Create(root);number = 0;}
        ~BiTree(){Release(root);}
        void PreOrder(){PreOrder(root);}
        void InOrder(){InOrder(root);}
        void PostOrder(){PostOrder(root);}
        void LevelOrder();
        int GetNum(){NumPlus(root);return number;}
};
Node *BiTree::Create(Node *bt)
{
    char ch;
    cout << "输入一个节点，‘#’为空" << endl;
    cin >> ch;
    if(ch == '#')
    {
        bt = NULL;
    }
    else
    {
        bt = new Node;
        bt->data = ch;
        bt->lChild = Create(bt->lChild);
        bt->rChild = Create(bt->rChild);
    }
    return bt;
}
void BiTree::Release(Node *bt)
{   
    if(bt != NULL)
    {
        Release(bt->lChild);
        Release(bt->rChild);
        delete bt;
    }
}
void BiTree::PreOrder(Node *bt)
{
    if(bt ==  NULL)
    {
        return;
    }
    else
    {
        cout << bt->data << " ";
        PreOrder(bt->lChild);
        PreOrder(bt->rChild);
    }
}
void BiTree::InOrder(Node *bt)
{
    if(bt == NULL)
    {
        return;
    }
    else
    {
        InOrder(bt->lChild);
        cout << bt->data << " ";
        InOrder(bt->rChild);
    }
}
void BiTree::PostOrder(Node *bt)
{
    if(bt == NULL)
    {
        return;
    }else
    {
        PostOrder(bt->lChild);
        PostOrder(bt->rChild);
        cout << bt->data << " ";
    }
}
void BiTree::LevelOrder()
{
   Node queue[10];
   int front,rear;
   front = rear = -1;
   rear++;
   queue[rear]  = root;
   while(front != )
   
}
void BiTree::NumPlus(Node *bt)
{
    if(bt == NULL){
        return;
    }
    else{
        number++;
        NumPlus(bt->lChild);
        NumPlus(bt->rChild);
    }
}
int main()
{
    BiTree bt;
    cout << "PreOrder :";
    bt.PreOrder();
    cout << endl;   
    cout << "InOrder :";
    bt.InOrder();
    cout << endl;
    cout << "PostOrder :";
    bt.PostOrder();
    cout << endl;
    cout << "LevelOrder :";
    bt.LevelOrder();
    cout << endl;
    cout << "There are " << bt.GetNum() << " Nodes." << endl;
    return 0;
}
