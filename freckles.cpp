/* 
    并查集加库鲁斯卡尔算法解决雀斑连线最短问题
    Garker-gan
    2020-10-06
 */
#include<iostream>
#include<cstdio>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

#define max 100

//存放顶点信息的结构体数组
struct Vertex
{
    int id;
    float x;
    float y;
}vertex[max];

//保存每条边及其对应的顶点信息
struct Freckles
{
    Vertex ver1;
    Vertex ver2;   
    float len;
    Freckles(Vertex v1,Vertex v2):ver1(v1),ver2(v2),len(sqrt(pow(v1.x-v2.x,2)+pow(v1.y-v2.y,2))){}        
};
vector<Freckles>freckles;       //向量存放边的结构体
bool cmp(Freckles f1,Freckles f2)
{
    return f1.len<f2.len;
}

int father[max];
int height[max];

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        father[i] = i;
        height[i] = 0;
    }
}

//并查集相关
int find(int x)
{
    if(x != father[x])
        father[x] = find(father[x]);
    return father[x];
}

//合并并查集
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
    cin>>n;
    int count = 0;
    init(n);
    for(int i = 0;i < n;i++)
    {
        cin>>vertex[i].x>>vertex[i].y;
        vertex[i].id = count++;
    }
    //遍历所有点之间的边
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            Freckles f =  Freckles(vertex[i],vertex[j]);
            freckles.push_back(f);
        }
    }
    sort(freckles.begin(),freckles.end(),cmp);
    float sum = 0;
    for (int i = 0; i < freckles.size(); i++)
    {
        int x,y;
        x = find(freckles[i].ver1.id);
        y = find(freckles[i].ver2.id);
        if(x != y)
        {
            unionSet(x,y);
            sum += freckles[i].len;
        }
    }
    printf("%.2f",sum);
    return 0;
}
