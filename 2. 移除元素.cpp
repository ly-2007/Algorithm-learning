#include<iostream>
#include<vector>
using namespace std;

//暴力解法--两个for循环
//时间复杂度---O(n^2)
class Solution1{
    public:
    int removeElement(vector<int>& nums, int val) {
        int sz = nums.size();
        for(int i=0;i<sz;i++){
            if(nums[i]==val){
                for(int j = i;j<sz-1;j++){
                    nums[j] = nums[j+1];
                }
                i--;
//此处注意，因为i之后的元素都往前移了一个单位，故i也要往前一位，否则新的i位元素没有被比较
                sz--;
            }
        }
        return sz;
    }
};

//双指针法（快慢指针法）:通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。
/* 定义双指针
快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组
慢指针：指向更新 新数组下标的位置
*/
//时间复杂度为O(n)
class Solution2{
    public:
        int removeElement(vector<int>& nums, int val) {
            int slowindex = 0;
            int sz = nums.size();
            for(int fastindex = 0; fastindex<sz; fastindex++){
                if(nums[fastindex]!=val){
                    nums[slowindex] = nums[fastindex];
                    slowindex++;
                }
                //如果slowindex指向的是val，那么就不移动，即不++
            }
            return slowindex;
        }
};

int main(){


    return 0;
}
