class Solution:
    def intersection(self, num1: list, num2: list) -> list:
        # python set 是支持 &交集 和 |并集
        return list((set(num1) & set(num2)))

    def isHappy(self, num: int) -> bool:
        sum_set = set()
        while num!=1:
            sum = 0
            while num > 0:
                sum += (num % 10) * (num % 10)
                num = num // 10
            num = sum
            if sum in sum_set:
                return False
            else:
                sum_set.add(sum)
        return True
    
    def twoSum(self, nums: list, target: int) -> list:
        records = dict()
        for i, num in enumerate(nums):
            temp = target - num
            if temp in records:
                return [records[temp], i]
            else:
                records[num] = i
    
    def fourSumCount(self, nums1: list, nums2: list, nums3: list, nums4: list) -> int:
        # 分组计算 1 2 统计两数组相加的 的情况 3 4 统计数组 相加等于零的情况
        # 记录总的元组数
        count = 0
        records = dict()
        for i in nums1:
            for j in nums2:
                # 在dict 中先要有key 才能 有+=
                if i+j in records:
                    records[i+j] += 1
                else:
                    records[i+j] = 1
        for i in nums3:
            for j in nums4:
                temp = 0 - (i + j)
                if temp in records:
                    count += records[temp]
        return count

if __name__ == "__main__":
    solution = Solution()
    result = solution.intersection([3, 4, 2, 1, 2], [3, 3, 2, 1])
    print(result)
    print(solution.isHappy(19))
    print(solution.fourSumCount([0], [0], [0], [0]))
