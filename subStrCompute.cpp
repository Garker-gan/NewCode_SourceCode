/* 
    利用map散列表解决字串个数计算的问题
    2020.09.30
    Garker-gan
 */
#include<iostream>
#include<map>
using namespace std;

map<string,int>subStr;

int main()
{
    string str;
    cin >> str;  
    //将主串的所有子串保存在map散列表中。
    for(int i = 0;i <= str.size();i++)
    {
        for (int j = 0; j < i; j++)
        {
            string key = str.substr(j,i-j);
            subStr[key]++;
        }
    }
    map<string,int>::iterator it;
    for(it = subStr.begin();it != subStr.end();it++)
    {
        if(it->second > 1)
            cout << it->first<<" "<<it->second<<endl; 
    }
    return 0;
}

