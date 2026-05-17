#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(pair<int, int> x, pair<int, int> y){
    return x.second < y.second;
}

// 不重叠区间选择（端点不算重叠）
int interval_select(const vector<pair<int, int>>& vec){
    sort(vec.begin(), vec.end(), compare);
    int count = 1;
    int last = vec[0].second;  // 选最早结束的
    for(int i = 1; i < vec.size(); i++){
        if(vec[i].first >= last){
            count++;
            last = vec[i].second;
        }
    }
    return count;
}

// 删除区间（端点算重叠）
int interval_delete(const vector<pair<int, int>>& vec){
    sort(vec.begin(), vec.end(), compare);
    int count = 1;
    int last = vec[0].second;
    for(int i = 1; i < vec.size(); i++){
        if(vec[i].first > last){
            count++;
            last = vec[i].second;
        }
    }
    return vec.size() - count;
}


