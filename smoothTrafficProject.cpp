/* 
    利用并查集解决个村庄之间道路连通最小开销问题（连通图判断问题）
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
    for(int i = 0;i < n;i++)
    {
        father[i] = i;
        height[i] = 0;
    }
}

//寻找根节点
int find(int x)
{
    if (x != father[x])
    {
        father[x] = find(father[x]);
    }  
    return father[x];    
}

//合并不同的子树
void unionTree(int x,int y)
{
    x = find(x);
    y = find(y);
    if(x != y)
    {
        if(father[x] < father[y])       //矮树作为高树的子树
            father[x] = y;
        else if(father[x] > father[y])
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
    int m,n;
    while (scanf("%d",&n)!= EOF)
    {
        init(n);
        if(n == 0)
            break;
        scanf("%d",&m);
        while (m--)
        {
            int x,y;
            cin>>x>>y;
            unionTree(x,y);
        }

        //开销最小的合并方法就是将所有的子树挂在根节点下，即路径压缩技术
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            if(i == father[i])
                ans++;
        }
        cout<<ans<<endl;
    }
    

}