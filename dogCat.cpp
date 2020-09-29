#include<iostream>
#include<queue>
using namespace std;

queue<int>animal;
queue<int>dog;
queue<int>cat;

void adopt_animal(int way,int type)
{
    if(way == 1)
    {
        animal.push(type);   
        if(type > 0)
            dog.push(type);
        if(type < 0)
            cat.push(type);    
    }
    if(way == 2)
    {
        if(type == 0)
        {
            cout<<animal.front()<<" ";
            animal.pop();
        }
        if(type == 1)
        {
            cout<<dog.front()<<" ";
            dog.pop();
        }
        if(type == -1)
        {
            cout<<cat.front()<<" ";
            cat.pop();
        }
    }
}


int main()
{
    int n;
    int type,way;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        cin>>way>>type;
        adopt_animal(way,type);
    }

}