from asyncio import constants


class Solution:
    def minCostClimbingStairs(self , cost: list) -> int:
        # write code here
        # dp array:  dp[i] = minCost i
        # dp transition: dp[n] = min(dp[n-1]+cost[n-1], dp[n-2]+cost[n-2])
        # dp initial: dp[2] = min(dp[0]+cost[0], dp[1]+cost[1])
        # loop 
        # print dp
        dp = []
        dp.append(0)
        dp.append(0) # 可以从0 1 开始往爬

        for i in range(2, len(cost)+1):
            dp.append(min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]))
        
        return dp[len(cost)]

    def uniquePaths(self, m: int, n: int) -> int:
        # write here code  
        # dp matrix dp[m][n]: start to grad[m][n] cost
        # dp[i][j] = dp[i-1][m] + dp[i][m-1]
        # dp[0][0] = 0
        # loop m:0 n:0-n  这与机器人的走向有关 -> 只能向右 和 向下
        # --------------------------- #
        # dp = [[0 for i in range(n)] for j in range(m)] 
        # for i in range(m):
        #     for j in range(n):
        #         if i-1 < 0:
        #             dp[i-1][j] = 0
        #         if j-1 < 0:
        #             dp[i][j-1] = 0
        #         dp[i][j] = dp[i][j-1] + dp[i-1][j]
        #         if j == 0 and i == 0:
        #             dp[i][j] = 1 
        # --------------------------- #
        # 改进 上面版本
        dp = [[1 for i in range(n)] for j in range(m)] 
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i][j-1] + dp[i-1][j]
        return dp[m-1][n-1]
                

if __name__ == "__main__":
    solution = Solution()
    print(solution.minCostClimbingStairs([2, 5, 20]))
    print(solution.uniquePaths(3, 7)) 




