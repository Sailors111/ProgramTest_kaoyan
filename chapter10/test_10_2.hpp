#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/* 10.2 背包问题 */

/* 0-1背包问题（每个物品只能选一次）*/

// 0-1背包取最大值
int zero_one_bag_max(const vector<int>& weight, const vector<int>& value, int C) {
    vector<int> dp(C + 1, 0); 
    dp[0] = 0;
    for (int i = 0; i < weight.size(); i++) {
        for (int j = C; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[C];
}

// 0-1背包取最小值
int zero_one_bag_min(const vector<int>& weight, const vector<int>& value, int C){
    vector<int> dp(C + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < weight.size(); i++){
        for(int j = C; j >= weight[i]; j--){
            if(dp[j - weight[i]] != INT_MAX){   // 防止越界
                dp[j] = min(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
    }
    return dp[C];
}


/* 完全背包问题（每个物品可以选多次）*/

// 完全背包取最大值
int complete_bag_max(const vector<int>& weight, const vector<int>& value, int C) {
    vector<int> dp(C + 1, 0);  
    dp[0] = 0;
    for (int i = 0; i < weight.size(); i++) {
        for (int j = weight[i]; j <= C; j++) { 
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }   
    }
    return dp[C];
}

// 完全背包取最小值
int complete_bag_min(const vector<int>& weight, const vector<int>& value, int C){
    vector<int> dp(C + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < weight.size(); i++){
        for(int j = weight[i]; j <= C; j++){
            if(dp[j - weight[i]] != INT_MAX){   // 防止越界
                dp[j] = min(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
    }
    return dp[C];
}
