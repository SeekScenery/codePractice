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

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // 层次遍历
        // write code here
        // 使用队列deque 先进先出 记录下一轮要遍历的数组
        deque<TreeNode *> next_node;
        vector<vector<int>> result;
        vector<int> record_layer;
        // 使用两个变量记录 当前层 和 下一层的数o量
        int count_current = 1;
        if (root == nullptr)
            return result;

        next_node.push_back(root);
        while (!next_node.empty())
        {
            TreeNode *temp = next_node.back();
            next_node.pop_back();
            if (temp->left != nullptr)
                next_node.push_front(temp->left);
            if (temp->right != nullptr)
                next_node.push_front(temp->right);
            record_layer.push_back(temp->val);
            count_current--;
            if (count_current == 0)
            {
                result.push_back(record_layer);
                record_layer.clear();
                count_current = next_node.size();
            }
        }
        return result;
    }

    vector<vector<int>> leveOrderV2(TreeNode* root)
    {
        // 层次遍历 用二重循环实现
        deque<TreeNode*> nextNode;
        vector<vector<int>> result;
        if(root == nullptr)
            return result;
        vector<int> recordLayer;
        nextNode.push_front(root);
        int nextNodeNum = 1;
        while(!nextNode.empty())
        {
            recordLayer.clear();
            nextNodeNum = nextNode.size();
            for(int i = 0; i < nextNodeNum; i++)
            {
                TreeNode* temp = nextNode.back();
                nextNode.pop_back();
                if(temp->left != nullptr)
                    nextNode.push_front(temp->left);
                if(temp->right != nullptr)
                    nextNode.push_front(temp->right);
                recordLayer.push_back(temp->val);
            }
            result.push_back(recordLayer);
        }
        return result;
    }
    
    vector<vector<int>> Print(TreeNode* root)
    {
        // 按之字形来打印二叉树  用两个stack来解: currentStack  nextStack
        // currentStack 从左往右出栈 nextStack从左往右入栈 这里需要先遍历左节点 增加if 判断
        // currentStack 从右往左出栈 nextStack从右往左入栈 这里需要先遍历右节点  
         stack<TreeNode*> stack1;
        stack<TreeNode*> stack2;
        stack<TreeNode*> *traPointer;
        stack<TreeNode*> *recordPointer;
        vector<vector<int>> result;
        vector<int>  recordLayer;
        bool directFlag = true;
 
        if (root == nullptr)
            return result;
 
        stack1.push(root);
        while (!stack1.empty() || !stack2.empty()) {
            if (stack1.empty()) {
                traPointer = &stack2;
                recordPointer = &stack1;
            } else {
                traPointer = &stack1;
                recordPointer = &stack2;
            }
            int nodeNum = traPointer->size();
            for (int i = 0; i < nodeNum; i++) {
                TreeNode* temp = traPointer->top();
                traPointer->pop();
                recordLayer.push_back(temp->val);
                if (directFlag == true) {
                    if (temp->left != nullptr)
                        recordPointer->push(temp->left);
                    if (temp->right != nullptr)
                        recordPointer->push(temp->right);
                } else {
                    if (temp->right != nullptr)
                        recordPointer->push(temp->right);
                    if (temp->left != nullptr)
                        recordPointer->push(temp->left);
                }
            }
            directFlag = !directFlag;
            result.push_back(recordLayer);
            recordLayer.clear();
        }
 
        return result;

    }

    vector<vector<int>> PrintV2(TreeNode* root)
    {
        // 打印之字形 在层次遍历的基础上 修改 vector 的插入顺序
        // 层次遍历 用二重循环实现
        queue<TreeNode*> nextNode;
        vector<vector<int>> result;
        if(root == nullptr)
            return result;
        vector<int> recordLayer;
        nextNode.push(root);
        int nextNodeNum;
        bool orderFlag = true;
        while(!nextNode.empty())
        {
            recordLayer.clear();
            nextNodeNum = nextNode.size();
            for(int i = 0; i < nextNodeNum; i++)
            {
                TreeNode* temp = nextNode.front();
                nextNode.pop();
                if(temp->left != nullptr)
                    nextNode.push(temp->left);
                if(temp->right != nullptr)
                    nextNode.push(temp->right);
                recordLayer.push_back(temp->val);
                // if(orderFlag)
                //     recordLayer.push_back(temp->val);
                // else
                //     recordLayer.insert(recordLayer.begin(), temp->val);
            }
            if(!orderFlag)
                reverse(recordLayer.begin(), recordLayer.end()); // 反转元素
            orderFlag = !orderFlag;
            result.push_back(recordLayer);
        }
        return result;
    }
    
    TreeNode* buildTree(vector<int>& treeValue)
    {
        TreeNode* root = nullptr;
        if(treeValue.empty())
            return root;
        root = new TreeNode(treeValue[0]);
        cout << treeValue[0];
        queue<TreeNode*> nextNodes;
        nextNodes.push(root);
        // 层次遍历 
        int nodeNum;
        int valPosition = 1;
        // 循环终止条件
        while(valPosition < treeValue.size())
        {
            nodeNum = nextNodes.size();
            cout << endl;
            for(int i=0; i<nodeNum; i++)
            {
                TreeNode* temp = nextNodes.back();
                nextNodes.pop();
                int leftValue = treeValue[valPosition++];
                if(leftValue != -1)
                {
                    cout << leftValue << " ";
                    TreeNode* newNode = new TreeNode(leftValue);
                    temp->left = newNode;
                    nextNodes.push(newNode);
                }
                int rightValue = treeValue[valPosition++];
                if(rightValue != -1)
                {
                    cout << rightValue << " ";
                    TreeNode* newNode = new TreeNode(rightValue);
                    temp->right = newNode;
                    nextNodes.push(newNode);
                }

            }
            
        }
        return root;
    }


    int maxDePth(struct TreeNode* root)
    {
        int maxD = 0;
        int currentDepth = 0;
        DFS(root, maxD, currentDepth);
        return maxD;
    }

    void DFS(TreeNode* root, int &maxD, int& currentDepth)
    {
        if(root == nullptr)
            return;
        currentDepth += 1;
        if(maxD < currentDepth)
            maxD = currentDepth;
        DFS(root->left, maxD, currentDepth);
        DFS(root->right, maxD, currentDepth);
        currentDepth -= 1;
    }

    void destroyTree(TreeNode* root)
    {
        // 清除构建的二叉树 后续遍历
        if(root == nullptr)
            return;
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }

    void midTraversal(TreeNode* root)
    {
        // 清除构建的二叉树 后续遍历
        if(root == nullptr)
            return;
        cout << root->val << endl;
        midTraversal(root->left);
        midTraversal(root->right);
    }

};

int main()
{
    // vector<int> treeVec = {1, 2, 3, -1, -1, 4, 5};
    // Solution solution;
    // TreeNode* root = solution.buildTree(treeVec);
    // solution.midTraversal(root);
    // vector<vector<int>> result = solution.Print(root);
    // solution.destroyTree(root);
    int num, leftB, rightB;
    cin >> num >> leftB >> rightB;
    vector<int> nums;
    for(int i=0; i < num; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end());
    // sort(nums.rbegin(), nums.rend());

     
    while(true)
    {

    }
    return 0;
}