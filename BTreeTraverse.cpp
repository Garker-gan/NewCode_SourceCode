#include<iostream>
#include<cstdio>
#include<string>
using namespace std;


//根据输入的先序遍历字符串，经过中序遍历输出
struct TreeNode
{
    char data;
    TreeNode *leftChild;
    TreeNode *rightChild;
    TreeNode(char c):data(c),leftChild(NULL),rightChild(NULL){}
};


//树的建立
TreeNode* buildTree(int& position,string str)
{
    char c = str[position++];
    if(c == '#')
    {
        return NULL;
    }
    TreeNode* root = new TreeNode(c);
    root -> leftChild = buildTree(position,str);
    root -> rightChild = buildTree(position,str);
    return root;
}

//递归中序遍历
void inOrder(TreeNode* root)
{   
    if(root == NULL)
        return;
    inOrder(root->leftChild);
    cout<<root->data;
    inOrder(root->rightChild);
}

int main()
{
    string str;
    while (cin>>str)
    {
        int position = 0;
        TreeNode* root = buildTree(position,str);
        inOrder(root);
    }
    return 0;
}
