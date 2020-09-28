#include<iostream>
#include<string>
using namespace std;

//创建结点
struct TreeNode
{
    char data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(char c):data(c),leftChild(NULL),rightChild(NULL){}
};

//根据二叉树的前序和中序序列，推导出后序序列
TreeNode* order_predict(string preOrder,string inOrder)
{   
    if(preOrder.size() == 0)
        return NULL;
    if(preOrder.size() != inOrder.size())
        return NULL;
    char r = preOrder[0]; //找到根节点
    TreeNode* root = new TreeNode(r);
    int position = inOrder.find(r); //在中序序列中找到根节点
    root->leftChild = order_predict(preOrder.substr(1,position),inOrder.substr(0,position));            //中序左子树从0到position不能理解???
    root->rightChild = order_predict(preOrder.substr(position+1,preOrder.length()),inOrder.substr(position+1,inOrder.length()));
    return root;
}

//后序递归遍历
void postOrder(TreeNode* root)
{
    if(root == NULL)
        return;
    postOrder(root->leftChild);
    postOrder(root->rightChild);
    cout<<root->data;
}

int main()
{
    string preOrder,inOrder;
    cin>>preOrder;
    cin>>inOrder;
    TreeNode* root = order_predict(preOrder,inOrder);
    postOrder(root);
    return 0;
}