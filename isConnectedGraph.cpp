/* 
    使用并查集判断无向图的连通问题(与畅通工程解答相同)
    Garker-gan
    2020-10-03
 */
#include<iostream>
#include<cstdio>
using namespace std;

int father[1000];
int height[1000];

void init(int n)
{
    for (int i = 0; i < n; i++)
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


void unionTree(int x,int y)
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
            height[x]++;
            father[y] = x;
        }
    }

}


int main()
{
    int n,m;
    while (scanf("%d",&n) != EOF)
    {
        if(n == 0)
            break;
        scanf("%d",&m);
        init(n);
        for (int i = 0; i < m; i++)
        {
            int x,y;
            cin>>x>>y;
            unionTree(x,y);
        }
        int ans = -1;
        for (int i = 0; i <  n; i++)
        {
            if(i == father[i])
                ans++;
        }
        if(ans == 0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;        
        
    }
    
    return 0;
}
