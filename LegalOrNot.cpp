/* 
        拓扑排序判断图是否有环
         Gaker-gan
         2020-10-17
 */
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define max 500

vector<int>graph[max];
int inDegree[max];

bool isRing(int n)
{
    vector<int>node;
    //将入度为0的点保存在向量中
    for (int i = 0; i < n; i++)
    {
        if(inDegree[i] == 0)
            node.push_back(i);
    }

    int count = 0;
    while (!node.empty())
    {
        count++;
        //找到入度为0的点并移出
        int u = node.front();
        node.pop_back();
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            inDegree[v]--;
            if(inDegree[v] == 0)
            {
                node.push_back(v);
            }
        }
    }
    // cout<<count<<endl;
    return count == n;
}

int main()
{
    int n,m;
    inDegree[max] = {0};
    memset(graph,0,sizeof(graph));
    memset(inDegree,0,sizeof(inDegree));
    while (cin>>n>>m)
    {
        if(m == 0 && n == 0)    break;
        while (m--)
        {
            int from,to;
            cin>>from>>to; 
            graph[from].push_back(to);
            inDegree[to]++;
        }
        if(isRing(n))
        {
            cout<<"YES"<<endl;
            cout<<isRing(n)<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
            cout<<isRing(n)<<endl;
        }   
    }   
}

