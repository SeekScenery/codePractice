# test = list(map(int, input().split()))
# test3 = [int(i) for i in input().split()]
# test2 = list(map(int, input().split()))
# print(test)
# print(test3)
# print(test2) 
# list_ = [2, 4, 1, 4, 2]

# for i in range(1, len(list_)):
#     print(list_[i])

    # for i in range(len(nums)):
    #     for j in range(i+1, len(nums)-1):
    #         if nums[i] < nums[j]:
    #             for k in range(j+1, len(nums)):
    #                 if nums[j] > nums[k]:
    #                     count += 1

def solution(nums: list, len_1) -> int:
    if len(nums) < 3:
        return 0
    count = 0
    # 先遍历高塔
    for i in range(1, len_1-1):
        count_left = 0
        count_right = 0
        for j in range(0, i):
            if nums[i] > nums[j]:
                count_left += 1
        for j in range(i+1, len_1):
            if nums[i] > nums[j]:
                count_right += 1
        count += count_left * count_right
            
    return count
            

count = list(map(int, input().split()))[0]
nums = list(map(int, input().split()))
count = len(nums)
result = solution(nums, count)
print(result)