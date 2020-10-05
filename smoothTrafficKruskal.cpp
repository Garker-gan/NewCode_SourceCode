/* 
    使用并查集和克鲁斯卡尔算法计算最小生成树
    Garker-gan
    2020-10-05
 */
#include<iostream>
#include<algorithm>
using namespace std;

#define max 101

struct Edge
{
    int from;
    int to;
    int len;
    bool operator< (const Edge &s)const{
        return len<s.len;
    }
}edge[max*max];

//并查集相关信息
int father[max];
int height[max];

void init(int n)
{
    for(int i = 1;i <= n;i++)
    {
        father[i] = i;
        height[i] = 0;
    }
}

int find(int x)
{
    if(x != father[x])
        father[x] = find(father[x]);
    return father[x];
}

void unionSet(int x,int y)
{
    x = find(x);
    y = find(y);
    if(x != y)
    {
        if(height[x] < height[y])
            father[x] = y;
        else if(height[x] > height[y])
            father[y] = x;
        else
        {
            father[y] = x;
            height[x]++;
        }
    }
}


int main()
{
    int n;
    while (scanf("%d",&n) != EOF)
    {
        if(n == 0)  break;
        int line = n*(n-1)/2;
        init(n);
        for (int i = 1; i <= line; i++)
        {
            cin>>edge[i].from>>edge[i].to>>edge[i].len;
        }
        sort(edge,edge+line);  //将结构体数组按照权值从小到大排序
        int sum = 0;
        for(int j = 1;j <= line;j++)
        {
            int f,t;
            f = find(edge[j].from);
            t = find(edge[j].to);
            if(f != t)
            {
                unionSet(t,j);
                sum += edge[j].len;
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}
