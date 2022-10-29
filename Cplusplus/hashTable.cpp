#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &num1, vector<int> num2)
    {
        unordered_set<int> result_set;
        unordered_set<int> num_set(num1.begin(), num1.end());

        for (int elem : num2)
        {
            if (num_set.find(elem) != num_set.end())
                result_set.insert(elem);
        }
        return vector<int>(result_set.begin(), result_set.end());
    }

    bool isHappy(int num)
    {
        // 如果进入死循环 如何跳出循环
        int sum = num;
        unordered_set<int> sums;
        sums.insert(sum);

        while (sum != 1)
        {
            // 把数各个位差分出来
            sum = 0;
            int temp;
            while (num > 0)
            {
                temp = num % 10;
                num = num / 10;
                sum += temp * temp;
                // 累计各个位的平方·
            }

            num = sum;
            cout << sum << endl;
            // 判读是否进入死循环 根据sum 集合 判断是否以遍历过
            if (sums.find(sum) != sums.end())
                return false;
            else
                sums.insert(sum);
        }
        return true;
    }

    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            if (map.find(temp) != map.end())
            {
                return vector<int>{map[temp], i};
            }
            map.insert(pair<int, int>(nums[i], i));
        }

        return {};
    }

    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        // 中的四元组数
        int count = 0;
        unordered_map<int, int> records;
        // 遍历前两个数组的 统计相加和
        for (int i = 0; i < nums1.size(); i++)
            for (int j = 0; j < nums1.size(); j++)
                if (records.find(nums1[i] + nums2[j]) != records.end())
                    records[nums1[i] + nums2[j]] += 1;
                else
                    records.insert(pair<int, int>(nums1[i] + nums2[j], 1)); // 插入新key

        for (int elem1 : nums3)
            for (int elem2 : nums4)
            {
                int temp = 0 - (elem1 + elem2);
                if (records.find(temp) != records.end())
                    count += records[temp];
            }

        return count;
    }

    int moreThanHalfNum(vector<int> nums)
    {
        // 用哈希表 O(n) O(n)
        if (nums.size() == 1)
            return nums[0];
        unordered_map<int, int> records;
        int half_len = nums.size() / 2;
        for (int num : nums)
        {
            records[num] += 1;
            if (records[num] > half_len)
                return num;
        }
        return 0;
    }

    int moreThanHalfNumV2(vector<int> nums)
    {
        // 候选法
        if (nums.size() == 1)
            return nums[0];
        int candidate = -1;
        int count = 0;

        for(int elem: nums)
        {
            if (count == 0)  // 重新开始 需要一个新的候选数
            {    
                candidate = elem;
                count++;
            }
            else
            {
                // 计票 和 减票的过程
                if(candidate == elem)
                    count++;
                else 
                    count--;
            }
        }
        // 如果输入 符合要求 则 
        return candidate;
    }

    vector<int> findNumsAppearOnce(vector<int> &nums)
    {
        // 用位运算解题
        // 先将全部数进行异或运算，得出最终结果 与零异或不变
        int tmp = 0;
        for(int num: nums){
            tmp ^= num;
        }

        int mask = lowbit(tmp);

        int a = 0;
        for(int num: nums)
        {
            if((num & mask) == 0)
                a ^= num;
        }

        int b = tmp ^ a;
        // // 找到那个可以充当分组去进行与运算的数
        // // 从最低位开始找起
        // int mask = 1;
        // while((tmp&mask) == 0){
        //     mask <<= 1;
        // }
 
        // // 进行分组，分成两组，转换为两组 求出现一次的数字 去求
        // int a = 0;
        // int b = 0;
        // for(int num:nums){
        //     if((num&mask) == 0){
        //         a ^= num;
        //     }else{
        //         b ^= num;
        //     }
        // }
        // 因为题目要求小的数放前面，所以这一做个判断
        if(a > b){
            int c = a;
            a = b;
            b = c;
        }
        return {a, b};
    }

    vector<int> findNumsAppearOnceV2(vector<int> &nums)
    {
        // 用哈希表解题
        unordered_map<int, int> records;
        vector<int> result;
        // 记录
        for(int elem: nums)
        {
            records[elem] += 1;
            if(records[elem] == 2) 
            {
                records.erase(elem);
            }
        }
        
        for(auto elem: records)
        {
            result.push_back(elem.first);
        }

        if (result[0] > result[1]) 
            swap(result[0], result[1]);

        return result;
    }

    int minNumberDisappeared(vector<int> &nums)
    {
        // 以数组自身建立哈希表
        int len = nums.size();

        for(int i=0; i<len; i++)
        {
            while(0 < nums[i] && nums[i] <= len)
            {
                int temp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = temp;
            }
        }
        for(int i=0; i<len; i++)
        {
            if(nums[i] != i+1)
                return i+1;
        }
    }


    // lowbit操作是求出非负整数x的最后一位1所表示的数值。
    int lowbit(int n)
    {
        return n & -n;
    }

    void printVector(vector<int> &nums)
    {
        for (int elem : nums)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution solution;
    vector<int> num1 = {6, 4, 3, 2};
    vector<int> num2 = {8, 4, 5};
    // solution.intersection(num1, num2);
    // iterator end 是指向最后元素的后一位
    // vector<int>::iterator test_end = num2.end();
    // vector<int>::iterator test_begin = num2.begin();
    // cout << *(test_end - 1) << " " << *test_begin << endl;
    // is happy number 测试
    // cout << solution.isHappy(19) << endl;
    // two sum
    vector<int> result = solution.twoSum(num1, 6);
    solution.moreThanHalfNumV2({1, 2, 3, 2, 2, 2, 5, 4, 2});
    unordered_map<int, int> test_map;
    test_map[1] += 1;
    cout << "====" << test_map[1] << endl;
    test_map.erase(1);
    cout << "====" << test_map.size() << endl;

    vector<int> num3 = {5, 2, 3, 3, 2, 9};
    vector<int> result1 = solution.findNumsAppearOnceV2(num3);


    solution.printVector(result1);

    return 0;
}