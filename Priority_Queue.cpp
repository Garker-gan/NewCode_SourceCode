/* 
    使用优先队列实现输出队列出最大的复数
    2020.09.29
    Garker-gan
 */
#include<iostream>
#include<queue>
#include<string>
using namespace std;


//建立一个复数结构体
struct Complex
{
    int real;
    int imag;   //虚部：imaginary part
    Complex(int a ,int b):real(a),imag(b){}
    //优先队列按照复数从大到小排列
    bool operator< (Complex c) const{
        return real*real + imag*imag < c.real*c.real+c.imag*c.imag;
    }
};

//创建一个优先队列
priority_queue<Complex>PriorityQueue;

int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin>>str;
        if(str == "Pop")
        {
            if(PriorityQueue.empty())
                cout<<"empty"<<endl;
            else
            {
                Complex c = PriorityQueue.top();
                PriorityQueue.pop();
                cout<<c.real<<"+"<<c.imag<<"i"<<endl;
                cout<<"Size="<<PriorityQueue.size()<<endl;
            }
        }
        else
        {
            int a,b;
            scanf("%d+i%d",&a,&b);
            PriorityQueue.push(Complex(a,b));
            cout<<PriorityQueue.size()<<endl;
            cout<<PriorityQueue.top().real<<" "<<PriorityQueue.top().imag<<endl;
        }  
    }
    
    return 0;
}


