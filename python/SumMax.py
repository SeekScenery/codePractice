"""
给定一个整数数组[a1,a2,.....aN] ，N个数,  现在从里面选择若干数使得他们的和最大，
同时满足相邻两数不能同时被选， a1和aN首尾两个也认为是相邻的。 
"""

def solution(nums: list):
    sum = nums[0] 
    for i in range(len(nums)):
        if(sum > nums[i]):
            sum += nums[i]
        else:
            sum = nums[i]
    

            


    
    