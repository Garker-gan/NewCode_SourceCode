/* 
    使用迪杰斯特拉算法解决道路畅通问题
    Garker-gan
    2020-10-10
 */
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<stdlib.h>
#include<cstring>
using namespace std;

//保存每个点所对应的边（按无向图处理）
struct Edge
{
    int point;   //点信息
    int len;     //起点到该的最短路
    Edge(int p,int l):point(p),len(l){}
};

//保存起点s到该点的最点距离
struct Point
{
    int id;
    int distance;
    Point(int i,int d):id(i),distance(d){}
    bool operator< (const Point &p) const{
        return distance<p.distance;
    }
};

#define max 200
vector<Edge>graph[max];
int dis[max];

void Djistra(int s)
{
    priority_queue<Point>myQueue;
    dis[s] = 0;
    myQueue.push(Point(s,dis[s]));
    while (!myQueue.empty())
    {
        int u = myQueue.top().id;   //最近的点
        myQueue.pop();
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].point;
            int d = graph[u][i].len;
            if(dis[v] > dis[u] + d)
            {
                dis[v] = dis[u] + d;
                myQueue.push(Point(v,dis[v]));;
            }
        }
    }
    return;
}

int main()
{
    int n,m;
    while (cin>>n>>m)
    {
        if(n == 0&&m == 0)  break;
        memset(graph,0,sizeof(graph));
        fill(dis,dis+n,INT_MAX);
        
        int from,to,len;
        for (int i = 0; i < m; i++)
        {
            cin>>from>>to>>len;
            graph[from].push_back(Edge(to,len));
            graph[to].push_back(Edge(from,len));
        }
        
        int s,t;
        cin>>s>>t;
        Djistra(s);
        cout<<endl;
        if(dis[t] == INT_MAX)
            dis[t] = -1;
        cout<<dis[t]<<endl;   
    }

    return 0;
}
