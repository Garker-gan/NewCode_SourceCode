//     使用树的思想直系亲属关系(困难)
//     Garker-gan
//     2020-10-04
#include<iostream>
#include<string>
// #include<vector>
using namespace std;

int familyTree[26][2];

void init()
{
    for(int i = 0;i < 26;i++)
    {
        for(int j = 0;j < 2;j++)
        {
            familyTree[i][j] = -1;
        }
    }
}

int findFamily(int from,int to,int depth)
{
    int ret;
    if(from == to)
        return depth;
    if(familyTree[from][0] != -1)
    {
        ret = findFamily(familyTree[from][0],to,depth+1);
        if(ret != -1)
            return ret;
    }
    if(familyTree[from][1] != -1)
    {
        ret = findFamily(familyTree[from][1],to,depth+1);
        if(ret != -1)
            return ret;
    }
    return -1;
}

void upShow(int x)
{
    if(x == 1)
        cout<<"parent"<<endl;
    if(x == 2)
        cout<<"grandparent"<<endl;
    if(x >= 3)
    {
        x -= 2;
        for(int i = 0;i < x;i++)
        {
            cout<<"great-";
        }
        cout<<"grandparent"<<endl;
    }
}


void downShow(int x)
{
    if(x == 1)
        cout<<"child"<<endl;
    if(x == 2)
        cout<<"grandchild"<<endl;
    if(x >= 3)
    {
        x -= 2;
        for(int i = 0;i < x;i++)
        {
            cout<<"great-";
        }
        cout<<"grandchild"<<endl;
    }
}


int main()
{
    int n,m;
    cin>>n>>m;
    string str;
    init();
    while (n--)
    {
        cin>>str;
        if(str[1] != '-')
            familyTree[str[0]-'A'][0] = str[1]-'A';
        if(str[2] != '-')
            familyTree[str[0]-'A'][1] = str[2]-'A';
    }
    
    int ret;
    while (m--)
    {
        string findStr;
        cin>>findStr;
        int from,to,depth;
        from = findStr[0] - 'A';
        to = findStr[1] - 'A';
        ret = findFamily(from,to,0);
        if(ret == -1)        //如果向下没找到，则交换顺序再找一遍
        {
            ret = findFamily(to,from,0);
            if(ret == -1)
                cout<<"-"<<endl;    //仍未找到，则没有关系
            else
                upShow(ret);
        }
        else
            downShow(ret);
    }
    return 0;
}




// /*错误解法 
//     使用并查集,树,链表查找直系亲属关系(困难)
//     Garker-gan
//     2020-10-03
//  */
// #include<iostream>
// #include<string>
// using namespace std;

// struct TreeNode
// {
//     char data;
//     TreeNode* leftChild;
//     TreeNode* rightChild;
//     TreeNode(char c):data(c),leftChild(NULL),rightChild(NULL){}
// };

// // 将多个字符串合并成一个字符串,得到一个先序遍历序列的字符串
// string emergeString(string s1,string s2)
// {
//     for(int i = s1.size()-1;i >= 0;i--)
//     {
//         if(s2[0] == s1[i])
//         {
//             cout<<"find successfully!"<<endl;
//             s1.erase(i,1);
//             s1.insert(i,s2);
//             break;
//         }
//     }
//     return s1;
// }

// //构建二叉树（族谱）
// TreeNode* creatTree(string str)
// {
//     char child,leftParent,rightParent;
//     child = str[0];
//     leftParent = str[1];
//     rightParent = str[2];
//     TreeNode* root = new TreeNode(child);
//     root->leftChild = new TreeNode(leftParent);
//     root->rightChild = new TreeNode(rightParent);
//     return root;
// }

// //合并树
// TreeNode* emergeTree(TreeNode* root,TreeNode* preRoot)
// {
//     if(root == NULL)
//         return NULL;
//     root = root->rightChild;
//     if(root->leftChild->data == preRoot->data)
//     {
//         root->leftChild->leftChild = new TreeNode(preRoot->leftChild->data);
//         root->leftChild->rightChild = new TreeNode(preRoot->rightChild->data);
//     }
//     else if(root->rightChild->data == preRoot->data)
//     {
//         root->rightChild->leftChild = new TreeNode(preRoot->leftChild->data);
//         root->rightChild->rightChild = new TreeNode(preRoot->rightChild->data);
//     }
//     return root;
// }

// bool findNode(char c,TreeNode* root)
// {
//     if(root == NULL)
//         return false;
//     if(c == root->data)
//     {
//         return true;    
//     }
//     else
//     {
//         findNode(c,root->leftChild);
//         findNode(c,root->rightChild);
//     } 
// }

// bool findRelationship(char a,char b,TreeNode* root)
// {
//     if(root == NULL)
//         return false;
//     if(root->data != a&&root->data != b)
//     {
//         findRelationship(a,b,root->leftChild);
//     }
//     if(root->data == a)
//     {
//         if(findNode(b,root))
//             return true;
//         else 
//             return false;
//     }
//     if(root->data == b)
//     {
//         if(findNode(a,root))
//             return true;
//         else 
//             return false;
//     }
// }

// void pre_oreder(TreeNode* root)
// {
//     if(root == NULL)
//         return;
//     cout<<root->data;
//     pre_oreder(root->leftChild);
//     pre_oreder(root->rightChild);
// }

// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     string str,s1;
//     //建立族谱
//     for(int i = 0;i < n;i++)
//     {
//         cin>>str;
//         if(i ==0)
//             s1 = str;
//         else
//             s1 = emergeString(s1,str);
//     }

//     // string findStr;
//     // for (int i = 0; i < m; i++)
//     // {
//     //     cin>>findStr;
//     //     char a,b;
//     //     if ((str[1] - str[0])>0)
//     //     {
//     //         a = findStr[0];
//     //         b = findStr[1];
//     //     }
//     //     else
//     //     {
//     //         a = findStr[1];
//     //         b = findStr[0];
//     //     }
        
//     //     if(findRelationship(a,b,root))
//     //         cout<<"1"<<endl;
//     //     else
//     //         cout<<"0"<<endl;
        
//     // }
//     return 0;
// }

