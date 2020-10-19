/* 
    使用KMP算法计算主串中有多少个模式串
    Garker-gan 
    2020-10-19
 */
#include<iostream>
#include<string>

using namespace std;

#define MAX 1000000
#define max 10000

int NEXT[max];
//获取NEXT数组
void getNextTable(string pat)
{
    int m = pat.length();
    int j = 0;
    NEXT[j] = -1;
    int i = NEXT[j];
    while (j < m)
    {
        if(i == -1 || pat[i] == pat[j])
        {
            i++;
            j++;
            NEXT[j] = i;
        }
        else
        {
            i = NEXT[i];
        }
    }
}

int KMP(string text,string pattern)
{
    int n = text.length();
    int m = pattern.length();
    getNextTable(pattern);
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            j = NEXT[j];
        }
        if(j == m)
        {
            j = NEXT[j];
            count++;
        }
    }
    return count;
}


int main()
{
    string pattern,text;
    cin>>pattern;
    cin>>text;
    cout<<KMP(text,pattern)<<endl;
    return 0;
}
