#include<iostream>
#include<map>
#include<cstdio>
#include<string>
using namespace std;

map<string,string>magicDictionary;

int main()
{
    string str;
    while (getline(cin,str))        //将整行保存在str中
    {
        if(str == "@END@")
            break;
        string key,val;
        key = str.substr(0,str.find(']')+1);
        val = str.substr(str.find(']')+2);
        magicDictionary[key] = val;
        magicDictionary.insert(pair<string,string>(val,key));
    }

    int n;
    cin>>n;
    while (n--)
    {
        string s1;
        getline(cin,s1);
        if (magicDictionary[s1] == "")
        {
            cout<<"what?"<<endl;
        }
        else if(s1[0] == '[')
        {
            cout<<magicDictionary[s1.substr(1,s1.size()-2)]<<endl;
        }
        else 
        {
            cout<<magicDictionary[s1]<<endl;
        }
        
    }
    
    
    
    return 0;
}


