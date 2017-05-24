#include<iostream>
using namespace std;
const int maxSize = 10;
class MGraph
{
    private:
        int vertex[maxSize];
        int arc[maxSize][maxSize];
        int vertexNum,arcNum;
        int visited[maxSize];
    public:
        MGraph(int a[],int n,int e);
        ~MGraph(){}
        void DFSTraverse(int v);
        void BFSTraverse(int v);
};
MGraph::MGraph(int a[],int n,int e)
{
    vertexNum = n;
    arcNum = e;
    int i;
    int j;
    //输入顶点信息存储在一维数组vertex中
    for(i = 0; i < n; i++)
    {
        vertex[i] = a[i];
    }
    //初始化邻接矩阵
    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
        for(j = 0; j < e; j++)
        {
            arc[i][j] = 0;
        }
    }
    for(int k = 0; k < arcNum; k++)
    {
        cin >> i >> j;
        arc[i][j] = 1;
        arc[j][i] = 1;
    }
}
void MGraph::DFSTraverse(int v)
{
    cout << vertex[v] << " ";
    visited[v] = 1;
    for(int j = 0; j < vertexNum; j++)
    {
        if(arc[v][j] == 1 && visited[j] == 0)
        {
            DFSTraverse(j);
        }
    }
}
void MGraph::BFSTraverse(int v)
{
    //定义一个队列
    int q[maxSize];
    int front,rear;
    front = rear = -1;
    rear++;
    //初始化判断数组
    for(int j = 0;j < vertexNum;j++)
    {
        visited[j] = 0;
    }
    cout << vertex[v] << " ";
    visited[v] = 1;
    q[rear] = v;
    while(front!=rear)
    {
        front++;
        v = q[front];
        for(int i = 0; i < vertexNum; i++)
        {
            if(arc[v][i]==1 && visited[i] == 0)
            {
                cout << vertex[i] << " ";
                visited[i] = 1;
                rear++;
                q[rear] = i;
            }
        }
    }
}
int main()
{
    int a[] = {0,1,2,3};
    MGraph mg(a,4,4);
    mg.DFSTraverse(0);
    cout << endl;
    mg.BFSTraverse(0);
    return 0;
}
