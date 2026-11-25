#include <iostream>
#include <vector>
using namespace std;

// 这个滑动窗口还是第一次学习，实话没思路，看了教程才明白暴力算法的写法
// 试写暴力算法,好吧，暴力算法我也不会写  已老实打一遍答案
class Solution1
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int result = INT32_MAX; // 这是c++的一个宏，代表int类型的数值上限
        int sum = 0;            // 子序列的数值之和
        int subLength = 0;      // 子序列的长度
        for (int i = 0; i < nums.size(); i++)
        {            // 子序列的起点为i
            sum = 0; // 每次循环都要重新记为0
            for (int j = i; j < nums.size(); j++)
            { // 设置子序列的终止位置为j
                sum += nums[j];
                if (sum >= target)
                {
                    subLength = j - i + 1;
                    result = result < subLength ? result : subLength;
                    break;
                }
            }
        }
        // 如果result未被赋值，返回0，即无符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};

class Solution2
{public:
    int minSubArrayLen(int target,vector<int> &nums){
        
    }

};