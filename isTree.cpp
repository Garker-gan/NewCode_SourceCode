/* 
    使用并查集来判断是否为树
    树和图判断的区别是：树的根节点入读为0，出度>1.其余结点入读为1.
    Garker-gan
    2020-10-03
 */
#include<iostream>
using namespace std;

int father[10000];
int height[10000];
int inDegree[10000];
int outDegree[10000];

//初始化所有结点以及树
void init()
{
    for(int i =0 ;i < 10000;i++)
    {
        father[i] = i;
        height[i] = 0;
        inDegree[i] = 0;
        outDegree[i] = 0;
    }
}

//寻找根节点，并可以通过数量判断需要合并的树的个数
int find(int x)
{
    if(x != father[x])
        father[x] = find(father[x]);
    return father[x];
}

//将输入的两个结点合并成一棵数
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

//判断树的依据：树的根节点入读为0，出度>1.其余结点入读为1.
bool isTree(int *inDegree,int *outDegree)
{
    int root = 0;       //统计符合根节点的数量 
    int node = 0;       //统计入读为1的结点个数
    int nullTree = 0;
    for (int i = 0; i < 10000; i++)
    {
        if(inDegree[i] == 0 &&outDegree[i] == 0)    //空树也是一棵树
        {
            nullTree++;
        }
        if(inDegree[i] == 0)
        {
            if(outDegree[i] >= 1)
                root++;
        }
        if(inDegree[i] > 1)
        {
            node++;
        }
    }
    if((root == 1&&node == 0)||nullTree == 10000)
        return true;
    else
        return false;
    
}

int main()
{
    int x,y;
    // int nodeNum = 0;
    int count = 1;
    init();
    while (scanf("%d %d",&x,&y) != EOF)
    {
        if(x == -1&&y == -1)
            break;
        if(x == 0 &&y == 0) 
        {
            if(isTree(inDegree,outDegree))
            {
                cout<<"Case "<<count++<<" is a tree."<<endl;
            }            
            else
            {
                cout<<"Case "<<count++<<" is not a tree."<<endl;
            } 
            init();
            // nodeNum = 0;
        }   
        else
        {
            // nodeNum++;
            outDegree[x]++;
            inDegree[y]++;   
            unionTree(x,y);
        }
           
    }
    

    return 0;
}

