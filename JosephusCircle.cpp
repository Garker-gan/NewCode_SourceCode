#include<iostream>
#include<queue>
using namespace std;

queue<int>children;

//队首元素进队再出队 来模拟 循环队列
class JosephusCircle
{
public:
    void josephusCircle(int n,int p,int m)
    {    
        //n个小朋友入队
        for(int i = 1;i <= n;i++)
            children.push(i);
        //将编号p的小朋友放在队首
        for (int i = 1; i < p; i++)
        {
            children.push(i);
            children.pop();
        }
        
        while (!children.empty())
        {
            for(int i = 1;i < m;i++)
            {
                children.push(children.front());
                children.pop();
            }
            cout<<children.front()<<" ";
            children.pop();
        }
    }
};

int main()
{
    JosephusCircle jose;
    jose.josephusCircle(8,3,4);
    return 0;
}