#include<iostream>
#include<queue>
#include<functional>
using namespace std;

//通过建立小根堆来最快速的寻找到序列中最小的两个数
priority_queue<int,vector<int>,greater<int>>Q;      //使用优先队列建立小根堆

int main()
{
    int n,x;        //结点相关
    int a,b,ans = 0;      //建立叶子结点相关
    cin>>n;
    while(Q.empty() == false)   Q.pop();        //如堆不为空，则置空
    for (int i = 0; i < n; i++)         //将结点放入小根堆中
    {
        cin>>x;
        Q.push(x);      
    }
    while (Q.size() > 1)
    {
        //依次取出一根堆中最小的两个数
        a = Q.top();
        Q.pop();
        b = Q.top();
        Q.pop();
        ans += a + b;
        Q.push(a + b);
    }
    cout << ans;
    return 0;
}

