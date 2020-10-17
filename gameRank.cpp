/* 
        拓扑排序解决比赛排名问题
         Gaker-gan
         2020-10-17
 */
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<functional>
using namespace std;

#define max 501
vector<int>graph[max];
int inDegree[max];

void gameRank(int n)
{
    //这里使用优先队列不适用向量的原因是：在存在多条入读为0的情况，优先使用编号小的点.
    priority_queue<int,vector<int>,greater<int>>node;
    for (int i = 1; i <= n; i++)
    {
        if(inDegree[i] == 0)
            node.push(i);
    }
    //count用于最后一个编号输出换行
    int count = 0;
    while (!node.empty())
    {
        int u = node.top();
        node.pop();
        if(count == n-1)
        {
            cout<<u<<endl;
        }
        else
        {
            cout<<u<<" ";
            count++;
        }
        
        for(int i = 0;i < graph[u].size();i++)
        {
            int v = graph[u][i];
            inDegree[v]--;
            if(inDegree[v] == 0)
                node.push(v);
        }
    }
}

int main()
{
    int n,m;
    while (cin>>n>>m)
    {
        memset(graph,0,sizeof(graph));
        memset(inDegree,0,sizeof(inDegree));
        if(n == 0 && m == 0)    break;
        while (m--)
        {
            int from,to;
            cin>>from>>to;
            graph[from].push_back(to);
            inDegree[to]++;
        }
        cout<<"Finish"<<endl;
        gameRank(n);
    }

}
