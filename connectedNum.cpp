/* 
    使用并查集计算连通分量
    Garker-gan
    2020-10-04
 */
#include<iostream>
#include<vector>
using namespace std;

#define max 110
int father[max];
int height[max];
bool visit[max];

void init()
{
    for (int i = 1; i < max; i++)
    {
        height[i] = 0;
        father[i] = i;
        visit[i] = false;
    }
}

int find(int x)
{
    if(x != father[x])
        father[x] = find(father[x]);
    return father[x];
}

void unionRoad(int i,int j)
{
    i = find(i);
    j = find(j);
    if(i != j)
    {
        if(height[i] < height[j])
            father[i] = j;
        else if(height[i] > height[j])
            father[j] = i;
        else
        {
            father[j] = i;
            height[i] ++;
        }
        
    }   

}

int main()
{
    int i,j;
    init();
    while (cin>>i>>j)
    {
        // if(i == 0)
        //     break;
        unionRoad(i,j);
    }
    int sum = 0;
    for (int i = 1; i < max; i++)
    {
        if(i == father[i] && visit[i])
            sum++;
    }
    cout<<sum<<endl;
    
    return 0;
}
