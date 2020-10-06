/* 
    克鲁斯卡尔解决丛林道路最小维护成本问题 
    Garker-gan
    2020-10-06
 */
#include<iostream>
#include<algorithm>
using namespace std;

#define max 26

struct jungleRoads
{
    int from;
    int to;
    int len;
    bool operator< (const jungleRoads &j) const{
        return len<j.len;
    }
}road[max*max];

int father[max];
int height[max];

void init(int count)
{
    for (int i = 0; i < count; i++)
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

int kruskal(jungleRoads *road,int count)
{
    int sum = 0;
    int from,to;    
    for (int i = 0; i <count ; i++)
    {
        from = find(road[i].from);
        to = find(road[i].to);
        // cout<<road[i].from<<" "<<road[i].to<<endl;
        // cout<<from<<" "<<to<<endl;
        if(from != to)
        {
            // cout<<"go "<<i<<endl;
            unionSet(from,to);
            sum += road[i].len;
        }
    }
    return sum;
}


int main()
{
    int n;
    while(cin>>n)
    {
        if(n == 0)  break;
        int count = 0;
        for (int i = 0; i < n-1; i++)
        {
            int edge_num,l;
            char f,t;
            cin>>f;
            cin>>edge_num;
            for (int j = 0; j < edge_num; j++)
            {
                cin>>t>>l;
                road[count].from = f - 'A';
                road[count].to = t - 'A';
                road[count].len = l;
                count++;
            }
        }
        init(count);
        sort(road,road+count);
        // for (int i = 0; i < count; i++)
        // {
        //     cout<<road[i].from<<" "<<road[i].to<<" "<<road[i].len<<" "<<endl;
        // }
        
        cout<<kruskal(road,count)<<endl;
        
    }
    return 0;
}
