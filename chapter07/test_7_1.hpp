#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 7.1 递归 */  

// N的阶乘
long long Factorial(long long num){
    if(num == 0){
        return 1;
    }else{
        return num * Factorial(num - 1);
    }
}


// 字符串全排列
void dfs_permute(const string& str, string& path, vector<bool>& visited, vector<string>& res){
    if(path.size() == str.size()){
        res.push_back(path);
        return;
    }
    for(int i = 0; i < str.size(); i++){
        if(visited[i]){
            continue;
        }
        visited[i] = true;
        path.insert(path.size(), 1, str[i]);
        dfs_permute(str, path, visited, res);
        path.erase(path.size() - 1, 1);
        visited[i] = false;
    }
}

vector<string> permute(const string& str){
    vector<string> res;
    string path;
    vector<bool> visited(str.size(), false);
    dfs_permute(str, path, visited, res);
    sort(res.begin(), res.end());
    return res;
}

