#include <iostream>
#include <vector>
using namespace std;
// 其实根本算不上solution,写错了
// 盲目的缩短左半边（一刀切）
class Solution1
{
    int totalFruit(vector<int> &fruits)
    {
        int kind1 = fruits[0];
        int kind2 = fruits[1]; // 分别用来记录水果种类，kind1永远设为靠前的
        int maxnum = 0;        // 先初始化成最小的，方便比较
        int head = 0;
        int sum_1 = 1; // 第一个是默认的
        int sum_2 = 0;
        for (int tail = 0; tail < fruits.size(); tail++)
        {

            if (fruits[tail] == kind1)
            {
                sum_1++;
            }
            else if (fruits[tail] == kind2)
            {
                sum_2++;
            }
            else if (kind1 == kind2)
            { // 虽不是现有种类，但还有一个篮子空的
                sum_1 += sum_2;
                sum_2 = 1;
                kind2 = fruits[tail];
            }
            else
            {                                                                 // 来了新的种类
                maxnum = maxnum > (sum_1 + sum_2) ? maxnum : (sum_1 + sum_2); // 开始清算
                head += sum_1;
                sum_1 = sum_2;
                sum_2 = 1; // 新的那个
            }

            if (tail == fruits.size() - 1)
            {
                maxnum = maxnum > (sum_1 + sum_2) ? maxnum : (sum_1 + sum_2);
            } // 打个补丁：外一到尾上了
        }
    }
};
//在b站上看到的一种好方法
class Solution2{
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 0;
        //下标代表水果种类，值代表该水果在窗口内的数量
        vector<int> cnt(n,0);
        int diff = 0;//记录当前窗口内不同水果的种类数量

        //j是左指针，i是右指针
        for(int i=0,j=0;i<n;++i){
            //1.进窗口：右指针的水果加入
            cnt[fruits[i]]++;
            //如果该水果数量由0->1，说明多了一种水果
            if(cnt[fruits[i]]==1) diff++;

            //判断与出窗口：当种类数超过2时，左指针不断向右收缩
            while(diff > 2){
                cnt[fruits[j]] --; //移出左指针的水果，数量-1
                //该水果数量减到0时，该水果已经彻底离开，种类数--；
                if(cnt[fruits] == 0){
                    diff--;
                }
                j += 1;//左指针右移
            }
            //更新答案：此时窗口【j,i】必定合法
            ans = ans>(i-j+1)? ans:(i-j+1);
        }
        return ans;
    }
};
int main()
{

    return 0;
}