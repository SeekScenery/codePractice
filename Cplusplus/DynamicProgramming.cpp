#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // write code here
        vector<int> dp(cost.size(), 0);
        for(int i=2; i<=cost.size(); i++)
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        
        return dp[cost.size()];
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i=1; i < m; i++)
            for(int j=1; j<n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[m-1][n-1];
    }
    int uniquePathsV2(int m, int n)
    {
        // 递归版
        if(m==1 || n==1)
            return 1;
        return uniquePathsV2(m-1, n) + uniquePathsV2(m, n-1);
    }

    int LCS(string s1, string s2)
    {
        // 构建 dp 矩阵 dp[i][j] 表示 s1 0-i  s2 0-j 最长公共子序列
        // 转移方程 dp[i][j] = dp[i-1][j-1] + 1  or dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        for(int i=1; i<=s1.size(); i++)
        {
            for(int j=1; j<=s2.size();  j++)
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]); 
        }

        return dp[s1.size()][s2.size()];
    }

    int longestCommonSubsequence(string s1, string s2)
    {
        // 用一维数组
        vector<int> dp(s2.size()+1, 0);
        for(int i=0; i<s1.size(); i++)
        {
            for(int j=s2.size(); j>0; j--)
                if(s1[i] == s2[j-1])
                    dp[j] = 1 + dp[j-1];
                else
                    dp[j] = max(dp[j], dp[j-1]);
        }
        return dp[s2.size()];
    }
     
};

int main()
{
    Solution solution;
    vector<int> test_nums = {2, 5, 20};
    // int result = solution.minCostClimbingStairs(test_nums);
    // cout << solution.uniquePaths(3, 7) << endl;
    vector<int> test_resize(4, 5);
    vector<vector<vector<int>>> img(3, vector<vector<int>>(640, vector<int>(640, 3)));
    test_resize.resize(8, 2);
    // for(auto elem: test_resize)
    //     cout << elem << endl;
    // cout << img.size() << endl;
    cout << solution.longestCommonSubsequence("1A2C3D4B56", "B1D23A456A") << endl;
    return 0;
}