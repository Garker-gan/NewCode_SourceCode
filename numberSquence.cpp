/* 
    使用KMP算法做数字串匹配(含暴力匹配)
    Garker-gan
    2020-10-19
 */
#include<iostream>
using namespace std;

#define MAX 1000000
#define max 10000

int NextTable[max];
int Text[MAX];
int Pattern[max];


//遍历模式串获取next数组,数组从1开始存储
void getNextTable(int m)
{
    int j = 0;
    NextTable[j] = -1;
    int i = NextTable[j];
    while (j < m)
    {
         if(i == -1||Pattern[i] == Pattern[j])       //寻找最长公共前缀和后缀
        {
            i++;
            j++;
            NextTable[j] = i;
        }
        else
        {
            i = NextTable[i];
        }
    }
}

//暴力匹配
int NaiveMatch(string pattern,string text)    //n文本串长度 ,m模式串长度
{
    int M = pattern.length();
    int N = text.length();
    for (int i = 0; i < N-M+1; i++)
    {
        int j;
        for (j = 0; j < M; j++)
        {
            if(pattern[j] != text[i+j])     //出现不同的就结束，从头开始
                break;
        }
        if(j == M-1)    return i;       //全部匹配结束
    }
    return -1;  //没有匹配到
}

int KMP(int n,int m)
{
    getNextTable(m);    //获取NEXT数组 
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        //相同则同时后移
        if(Pattern[j] == Text[i])
        {
            i++;
            j++;
        }
        else
        {
            j = NextTable[j];
        }
    }
    if(j == m)
        return i-j+1;
    else return -1;
}


int main()
{
    int caseNum;
    cin>>caseNum;
    while (caseNum--)
    {
        int n,m;
        cin>>n>>m;
        for (int i = 0; i < n; i++)
        {
            cin>>Text[i];
        }
        for (int j = 0; j < m; j++)
        {
            cin>>Pattern[j];
        }
        cout<<KMP(n,m)<<endl;
    }
    

    return 0;
}

