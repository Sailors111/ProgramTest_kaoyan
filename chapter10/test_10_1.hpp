#include <iostream>
#include <vector>
using namespace std;

/* 10.1 递推求解 */    

// 爬楼梯问题：dp[n] = dp[n-1] + dp[n-2], dp[0] = 1, dp[1] = 2; dp[i]表示第i个台阶的方案数
int climb_stairs(int n) {
    if (n <= 1) {
        return 1;
    }
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// 爬楼梯问题进阶版：dp[n] = dp[n-1] + dp[n-2] + dp[n-3], dp[0] = 1, dp[1] = 1, dp[2] = 2; dp[i]表示第i个台阶的方案数
int climb_stairs_plus(int n) { 
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}


// 最大子数组和：dp[i] = max(nums[i], dp[i-1] + nums[i]); dp[i]表示以第i个元素结尾的最大子数组和。
int maxSubArray(const vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    int res = dp[0];
    for(int i = 1; i < n; i++){
        dp[i] = max(nums[i], dp[i-1] + nums[i]);
        res = max(res, dp[i]);
    }
    return res;
}

// 最小子数组和：dp[i] = min(nums[i], dp[i-1] + nums[i]); dp[i]表示以第i个元素结尾的最小子数组和。
int minSubArray(const vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    int res = dp[0];
    for(int i = 1; i < n; i++){
        dp[i] = min(nums[i], dp[i-1] + nums[i]);
        res = min(res, dp[i]);
    }
    return res;
}
