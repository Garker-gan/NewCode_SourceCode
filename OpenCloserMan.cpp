/* 
    利用map散列表解决机房查找开门关门登记最早和最晚时间的问题
    2020.09.30
    Garker-gan
 */
#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string,string>inTime;
map<string,string>outTime;

int main()
{
    int n;
    cin>>n;
    string name,startTime,endTime;
    int sTime,eTime;
    for(int i = 0;i < n;i++)
    {
        cin>>name>>startTime>>endTime;
        inTime[startTime] = name;
        outTime[endTime] = name;
    }
    cout<<inTime.begin()->second<<" "<<outTime.rbegin()->second<<endl;
    return 0;
}

