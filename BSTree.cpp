/* 二叉排序树的建立
    2020.09.29 
    Garker-gan  */
#include<iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(int x):data(x),leftChild(NULL),rightChild(NULL){}
};

TreeNode* BSTree_insert(TreeNode* root,int x,int father)
{
    if(root == NULL)        //结点为空则创建结点
    {
        root = new TreeNode(x);
        cout<<"father node is :"<<father<<endl;
    }
    else if(x < root->data)     //小于结点值则插在左子树上
    {
        root->leftChild = BSTree_insert(root->leftChild,x,root->data);
    }
    else                //大于结点值则插在右子树上
    {
        root->rightChild = BSTree_insert(root->rightChild,x,root->data);
    }
    return root;
}

int main()
{
    int n;
    cin>>n;
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        root = BSTree_insert(root,x,-1);
    }
    
    return 0;
}
