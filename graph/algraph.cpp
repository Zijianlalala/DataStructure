#include<iostream>
using namespace std;
struct ArcNode//定义边表结点
{
    int adjvex;
    ArcNode *next;
};
struct VertexNode//定义顶点表结点
{
    int vertex;
    ArcNode *firstEdge;
};
const int MaxSize = 10;
class ALGraph
{
    private:
        VertexNode adjList[MaxSize];//存放顶点表的数组
        int vertexNum,arcNum;
        int visited[MaxSize];
        void clear();
    public:
        ALGraph(int a[],int n,int e);
        void DFSTraverse(int v);
        void BFSTraverse(int v);
};
void ALGraph::clear()
{
    for(int i = 0;i < vertexNum;i++)
    {
        visited[vertexNum] = 0;
    }
}
ALGraph::ALGraph(int a[],int n,int e)
{
    vertexNum = n;
    arcNum = e;
    int l1,l2;
    clear();//visited[]清零
    for(int i = 0;i < n;i++)
    {
        adjList[i].vertex = a[i];
        adjList[i].firstEdge = NULL;
    }
    ArcNode *s;
    for(int k = 0;k < e;k++)
    {
        cout << "输入一条边" << endl;
        cin >> l1 >> l2;
        s = new ArcNode;
        s->adjvex = l2;
        s->next = adjList[l1].firstEdge;
        adjList[l1].firstEdge = s;
    }
}
void ALGraph::DFSTraverse(int v)
{   
    cout << adjList[v].vertex << " ";
    visited[v] = 1;
    ArcNode *p = adjList[v].firstEdge;
    while(p!=NULL)
    {
      if(visited[p->adjvex]==0)
      {
        DFSTraverse(p->adjvex);
      }
      p = p->next;
    }
}
void ALGraph::BFSTraverse(int v)
{
    clear();//visited[]清零
    int q[MaxSize];
    int front,rear;
    front = rear = -1;
    cout << adjList[v].vertex;
    q[++rear] = v;
    ArcNode *p;
    int j;
    while(front!=rear)
    {   
        v = q[++front];
        p = adjList[v].firstEdge;
        while(p!=NULL)
        {
            j = p->adjvex;
            if(visited[j] == 0)
            {
                cout << adjList[j].vertex << " ";
                visited[j] = 1;
                q[++rear] = j;
            }
            p = p->next;
        }
    }
}
int main()
{
    int a[] = {0,1,2,3};
    ALGraph g(a,4,4);
    g.DFSTraverse(0);
 //   g.BFSTraverse(0);
    return 0;
}
