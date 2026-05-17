#include <iostream>
#include <vector>
#include <cmath>
#include "test_10_2.hpp"
using namespace std;

/* 10.2 背包问题 */     

// 北京大学机试题T137 点菜问题 
void PeKing_137(){
    int C, N;
    while(cin >> C >> N){
        vector<int> values(N, 0), prices(N, 0);
        for(int i = 0; i < N; i++){
            cin >> prices[i] >> values[i];
        }
        int max_value = zero_one_bag_max(prices, values, C);
        cout << max_value << endl;
    }
}

// 北京大学机试题T146 采药 
void PeKing_146(){ 
    int T, M;
    while(cin >> T >> M){
        vector<int> times(M, 0), values(M, 0);
        for(int i = 0; i < M; i++){
            cin >> times[i] >> values[i];
        }
        int max_value = zero_one_bag_max(times, values, T);
        cout << max_value << endl;
    }
}

// 清华大学机试题T113 最小邮票数 

// 方法一：动态规划
void TsingHua_113_1(){
    int M, N;
    while(cin >> M){
        cin >> N;
        vector<int> items(N, 0);
        for(int i = 0; i < N; i++){
            cin >> items[i];
        }
        vector<int> dp(M + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < items.size(); i++){
            for(int j = M; j >= items[i]; j--){
                if(dp[j - items[i]] != INT_MAX){
                    dp[j] = min(dp[j] , dp[j - items[i]] + 1);
                }
            }
        }
        if(dp[M] == INT_MAX){
            cout << 0 << endl;
        }else{
            cout << dp[M] << endl;
        }
    }
}

// 方法二：DFS
void dfs(const vector<int>& items, int& path, int start, int target, int& res){
    if(target == 0){
        res = min(path, res);
        return;
    }else if(target < 0){
        return;
    }else{
        for(int i = start; i < items.size(); i++){
            if(items[i] > target){
                return;
            }
            path++;
            dfs(items, path, i + 1, target - items[i], res);
            path--;
        }
    }
}

void TsingHua_113_2(){ 
    int M, N;
    while(cin >> M){
        cin >> N;
        vector<int> items(N, 0);
        for(int i = 0; i < N; i++){
            cin >> items[i];
        }
        int res = INT_MAX, path = 0;
        dfs(items, path, 0, M, res);
        if(res == INT_MAX){
            cout << 0 << endl;
        }else{
            cout << res << endl;
        }
    }
}
