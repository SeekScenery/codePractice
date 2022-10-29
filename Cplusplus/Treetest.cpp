#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

bool solution(TreeNode *root)
{
    if(!root)
        return true;
    return compareTwoTree(root->left, root->right);
}

bool compareTwoTree(TreeNode* tree1, TreeNode* tree2)
{
    if(tree1 == nullptr && tree2 == nullptr)
        return true;
    if(tree1 != nullptr && tree2 == nullptr)
        return false;
    if(tree1 == nullptr && tree2 != nullptr)
        return false;
    bool flag = false;
    if(tree1->val == tree2->val)
    {
       flag = compareTwoTree(tree1->left, tree2->right); 
       if (flag)
            flag = compareTwoTree(tree1->right, tree2->left); 
    }
    else
        return false;
    
    return flag; 
}