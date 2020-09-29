/*  
    建立二叉树并输出其前中后序遍历
    2020.09.29
    Garker-gan
 */

#include<iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(int x):data(x),leftChild(NULL),rightChild(NULL){}
};


// 建立二叉排序树
TreeNode* BSTree_insert(TreeNode* root,int x)
{
    if(root == NULL)
        root = new TreeNode(x);
    else if(x < root->data)
        root->leftChild = BSTree_insert(root->leftChild,x);
    else 
        root->rightChild = BSTree_insert(root->rightChild,x);
    return root;
}

//前序遍历
void PreOrder(TreeNode* root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    PreOrder(root->leftChild);
    PreOrder(root->rightChild);
}

//中序遍历
void InOrder(TreeNode* root)
{
    if(root == NULL)
        return;
    InOrder(root->leftChild);
    cout<<root->data<<" ";
    InOrder(root->rightChild);
}
//后序遍历
void PostOrder(TreeNode* root)
{
    if(root == NULL)
        return;
    PostOrder(root->leftChild);
    PostOrder(root->rightChild);
    cout<<root->data<<" ";
}

int main()
{
    int n;
    cin>>n;
    TreeNode* root = NULL;

    for(int i = 0;i < n;i++)
    {
        int x;
        cin>>x;
        root = BSTree_insert(root,x);
    }

    PreOrder(root);
    cout<<endl;
    InOrder(root);
    cout<<endl;
    PostOrder(root);
    cout<<endl;
    return 0;
}

