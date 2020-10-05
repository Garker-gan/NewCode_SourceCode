/* 
    使用并查集和克鲁斯卡尔算法计算最小生成树(新增已建路径减少成本)
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
    int state;
    // 首先根据状态排序，然后根据权值大小排序
    bool operator< (const Edge &e)const{
        if(e.state != state)
        {
            return state>e.state;
        }
        else
        {
            return len<e.len;
        }
        
    }
}edge[max*(max-1)/2];

int father[max];
int height[max];

int init(int n)
{
    for(int i = 1;i <= n;i++)
    {
        height[i] = 0;
        father[i] = i;
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
        else if(height[y] > height[x])
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
        init(n);
        int line = n*(n-1)/2;
        for (int i = 1; i <= line; i++)
        {
            cin>>edge[i].from>>edge[i].to>>edge[i].len>>edge[i].state;
        }
        sort(edge+1,edge+1+line);
        int sum = 0;        //权值之和
        for(int j = 1;j <= line;j++)
        {
            int f = find(edge[j].from);
            int t = find(edge[j].to);
            if(f != t)
            {
                if(edge[j].state == 1)
                {
                    unionSet(f,t);
                }
                else
                {
                    unionSet(f,t);
                    sum += edge[j].len;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
