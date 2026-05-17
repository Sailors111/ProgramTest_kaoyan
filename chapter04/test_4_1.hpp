#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 二分查找
int binary_search(const vector<int>& items, int target){
    int left = 0, right = items.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(items[mid] == target){
            return mid;
        }else if(items[mid] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}


// 两数之和
vector<vector<int>> twoSum(vector<int> items, int target) {
    vector<vector<int>> res;
    sort(items.begin(), items.end());
    int left = 0, right = items.size() - 1;
    while (left <= right) {
        if (items[left] + items[right] == target) {
            res.push_back({items[left], items[right]});
            left++;
            right--;
        } else if (items[left] + items[right] < target) {
            left++;
        } else {
            right--;
        }
    }
    return res;
}

// 三数之和
vector<vector<int>> threeSum(vector<int> items, int target){
    vector<vector<int>> res;
    sort(items.begin(), items.end());
    int len = items.size();
    for(int i = 0; i < len; i++){
        if(i > 0 && items[i] == items[i-1]){
            continue;
        }
        int left = i + 1, right = len - 1;
        while(left < right){
            if(items[i] + items[left] + items[right] == target){
                res.push_back({items[i], items[left], items[right]});
                while(left < right && items[left] == items[left+1]){
                    left++;
                }
                while(left < right && items[right] == items[right-1]){
                    right--;
                }
                left++;
                right--;
            }else if(items[i] + items[left] + items[right] < target){
                left++;
            }else{
                right--;
            }
        }
    }
    return res;
}

