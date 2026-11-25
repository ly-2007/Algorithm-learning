#include<iostream>
#include<vector>
using namespace std;


//也算是自己摸索出来了
/*过程
1.想尝试先平方，再sort，发现时间复杂度超了
2.用vector的push_back，后来发现顺序错了，且nums[tail]与nums[head]全部写成tail/head
3.改push_back为insert，发现时间上不理想
4.想到直接下标插入
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 我想设计：一个头一个尾指针，都平方后比较谁更大，然后放在新的vector容器的末尾re.push_back()
        int sz = nums.size();
        vector<int> re(sz);
        int index = sz - 1;
        int head = 0, tail = sz - 1;
        while (head < sz && tail >= 0 && head <= tail) {
            if (nums[head] * nums[head] >= nums[tail] * nums[tail]) {
                re[index--] = nums[head] * nums[head];
                head++;
            } else {
                re[index--] = nums[tail] * nums[tail];
                tail--;
            }
        }
        return re;
    }
};
/*以及,代码随想录教程真不赖，提到"打败多少人的指标不要看"我就觉得有意思了，于是按照所说的重新提交一次，时间果然从打败"49.97"到"100"
好的，原来真的是个不准确的玩具啊..."
附上原文："这里还是说一下，大家不必太在意leetcode上执行用时，打败多少多少用户，这个就是一个玩具，非常不准确。

做题的时候自己能分析出来时间复杂度就可以了，至于leetcode上执行用时，大概看一下就行，只要达到最优的时间复杂度就可以了，

一样的代码多提交几次可能就击败百分之百了.....
""*/