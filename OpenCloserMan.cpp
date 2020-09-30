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


/* 
本程序的重点就是讲时间序列的字符串转换成数字，从而可以进行大小比较来判断时间早晚
  str-08:59:30
 num-[01234567]
 */


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

