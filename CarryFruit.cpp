/* 
    用哈夫曼数解决搬水果最小代价问题
    2020.09.29
    Garker-gan
 */
#include<iostream>
#include<queue>
#include<functional>
using namespace std;

//借助优先队列进行哈夫曼树的构造
int main()
{
    priority_queue<int,vector<int>,greater<int>>Q;
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        int x;
        cin>>x;
        Q.push(x);
    }
    int a,b;
    int ans = 0;
    while (Q.size() > 1)
    {
        a = Q.top();
        Q.pop();
        b = Q.top();
        Q.pop();
        ans += a + b;
        Q.push(a+b);
    }
    cout<<ans<<endl;
}

