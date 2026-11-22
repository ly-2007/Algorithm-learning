#include<iostream>
#include<vector>
using namespace std;

//左闭右闭区间
int msolution(){
    int n,target;
    cin>>n>>target;
    int left = 0;
    int right = n-1;
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    //实现查找代码
    while(left<=right){
        int middle = left+(right-left)/2;
        if(nums[middle]>target){
            right = middle-1;
        }else if(nums[middle]<target){
            left = middle+1;
        }else{
            return middle;
        }
    }
    return -1;
}
//以上为自己写的并询问ai改正后的内容,以下为教程内容

class Solution{
    public:
    int search(vector<int>& nums,int target){
        int left = 0;
        int right = nums.size() - 1;
        while(left<=right){
            int middle = left + (right-left)/2;
            if(nums[middle]>target){
                right = middle-1;
            }else if(nums[middle]<target){
                left = middle +1;
            }else{
                return middle;
            }
        }
        //未找到
        return -1;
    }
};


//左闭右开区间
class Solution2{
    public:
    int search(vector<int>& nums,int target){
        int left = 0;
        int right = nums.size();
        while(left < right){
            int middle = left + (right-left)/2;
            if(nums[middle]>target){
                right = middle;
            }else if(nums[middle]<target){
                left = middle+1;
            }else{
                return middle;
            }
        }
        //未找到
        return -1;
    }
};

//找完之后,若是没找到target,那么left即是target应该插入的位置。
/*重要：区间的定义就是不变量，那么在循环中坚持根据查找区间的定义来做边界处理，就是循环不变量规则。*/