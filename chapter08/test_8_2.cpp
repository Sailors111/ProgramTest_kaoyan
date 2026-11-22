#include <iostream>
#include <vector>
#include "test_8_2.hpp"
using namespace std;

/* 8.2 深度优先搜索 */ 

// 北京大学机试题T131 神奇的口袋（难） 
void combination(const vector<int>& items, int start, int target, int& res){
    if(target == 0){
        res++;
        return;
    }else if(target < 0){
        return;
    }else{
        for(int i = start; i < items.size(); i++){
            if(items[i] > target){
                continue;
            }
            combination(items, i + 1, target - items[i], res);
        }
    }
}

void PeKing_131(){
    int n;
    while(cin >> n){
        vector<int> items(n, 0);
        for(int i = 0; i < n; i++){
            cin >> items[i];
        }
        int res = 0;
        combination(items, 0, 40, res);
        cout << res << endl;
    }
}

// 北京大学机试题T157 八皇后（难）
vector<string> vectorToString(vector<vector<int>> res){
    vector<string> temp;
    for(auto & i : res){
        string str = "";
        for(auto & j : i){
            str += char(j + 1 + '0');
        }
        temp.push_back(str);
    }
    return temp;
}

void PeKing_157(){
    int index;
    vector<string> vec = vectorToString(NQueen(8));
    sort(vec.begin(), vec.end());
    while(cin >> index){
        cout << vec[index - 1] << endl;
    }
}
