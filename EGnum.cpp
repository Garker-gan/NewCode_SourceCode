#include<iostream>
#include<vector>
using namespace std;

vector<int>numE;
vector<int>numG;

class NumEG
{
    public:
    // 求所有因子之和
    int sum(int x)
    {
        int sum = 0;
        for (int i = 1; i < x; i++)
        {
            if(x%i == 0)
                sum += i;
        }
        return sum;
    }
};

int main()
{
    NumEG numEG;
    for (int i = 2; i <= 60; i++)
    {
        if(i == numEG.sum(i))
            numE.push_back(i);
        if(i <= numEG.sum(i))
            numG.push_back(i);
    }
    cout<<"E:";
    for(int i = 0;i < numE.size();i++)
    {
        cout<<numE[i]<<" ";
    }
    cout<<endl;
    cout<<"G:";
    for (int i = 0; i < numG.size(); i++)
    {
        cout<<numG[i]<<" ";
    }
    
    return 0;
}