#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/* 9.2 深度优先搜索 */

/*
    核心逻辑：选择-递归-回溯
    判断重复：vector<bool> visited / vector<vector<bool>> visited
 */

// 子集问题模板
void dfs_subset(const vector<int>& items, vector<int>& path, int start, vector<vector<int>>& res){
    res.push_back(path);
    for(int i = start; i < items.size(); i++){
        // 选择
        path.push_back(items[i]);
        // 递归
        dfs_subset(items, path, i + 1, res);
        // 回溯
        path.pop_back();
    }
}

vector<vector<int>> subset(const vector<int>& items){
    vector<int> path;
    vector<vector<int>> res;
    dfs_subset(items, path, 0, res);
    return res;
}


// 组合问题模板
void dfs_combination(const vector<int>& items, vector<int>& path, int start, int target, vector<vector<int>>& res){
    // items存放待选择的元素、path存放选择的元素、res保存所有满足元素之和为target的path
    if(target == 0){
        res.push_back(path);
        return;
    }else if(target < 0){
        return;
    }
    for(int i = start; i < items.size(); i++){
        if(items[i] > target){
            continue;
        }
        // 选择
        path.push_back(items[i]);
        // 递归
        dfs_combination(items, path, i + 1, target - items[i], res);
        // 回溯
        path.pop_back();
    }
    // 组合问题为有约束条件的子集问题
}

vector<vector<int>> combination(const vector<int>& items, int target){
    vector<int> path;
    vector<vector<int>> res;
    dfs_combination(items, path, 0, target, res);
    return res;
}


// 全排列问题模板
void dfs_permute(const vector<int>& items, vector<int>& path, vector<bool>& visited, vector<vector<int>>& res){
    if(path.size() == items.size()){
        res.push_back(path);
        return;
    }
    for(int i = 0; i < items.size(); i++){
        if(visited[i]){
            continue;
        }
        // 选择
        visited[i] = true;
        path.push_back(items[i]);
        // 递归
        dfs_permute(items, path, visited, res);
        // 回溯
        path.pop_back();
        visited[i] = false;
    }
}

vector<vector<int>> permute(const vector<int>& items){
    vector<int> path;
    vector<vector<int>> res;
    vector<bool> visited(items.size(), false);
    dfs_permute(items, path, visited, res);
    return res;
}


// N皇后问题模板
void dfs_NQueen(int N, int row, vector<int>& path, vector<bool>& col_used, vector<bool>& diag1, vector<bool>& diag2, vector<vector<int>>& res){
    // row为行数，col_used为列标记数组，diag1为主对角线标记数组，diag2为副对角线标记数组
    if(row == N){
        res.push_back(path);
        return;
    }
    for(int col = 0; col < N; col++){
        int d1 = row - col + N - 1;
        int d2 = row + col;
        if(col_used[col] || diag1[d1] || diag2[d2]){
            continue;
        }
        // 选择
        col_used[col] = true;
        diag1[d1] = true;
        diag2[d2] = true;
        path.push_back(col);
        // 递归
        dfs_NQueen(N, row + 1, path, col_used, diag1, diag2, res);
        // 回溯
        path.pop_back();
        col_used[col] = false;
        diag1[d1] = false;
        diag2[d2] = false;
    }
}

vector<vector<int>> NQueen(int N){
    vector<int> path;
    vector<vector<int>> res;
    // 行数列数为N，主对角线数副对角线数为2 * N - 1
    vector<bool> col_used(N, false), diag1(2 * N - 1, false), diag2(2 * N - 1, false); 
    dfs_NQueen(N, 0, path, col_used, diag1, diag2, res);
    return res;
}


// 迷宫路径问题模板
vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs_maze(const vector<vector<int>>& maze, vector<pair<int, int>>& path, vector<vector<bool>>& visited, int x, int y, int end_x, int end_y, vector<vector<pair<int, int>>>& res){
    int row_len = maze.size(), col_len = maze[0].size();
    if(x < 0 || x >= row_len || y < 0 || y >= col_len || visited[x][y] || maze[x][y] == 1){
        return;
    }
    // 选择
    visited[x][y] = true;
    path.push_back({x, y});
    // 递归
    if(x == end_x && y == end_y) {
        res.push_back(path);
        return;
    } else {
        for(auto & dir : dirs){
            int new_x = x + dir[0], new_y = y + dir[1];
            dfs_maze(maze, path, visited, new_x, new_y, end_x, end_y, res);
        }
    }
    // 回溯
    path.pop_back();
    visited[x][y] = false;
}

vector<vector<pair<int, int>>> maze_path(const vector<vector<int>>& maze, int x, int y, int end_x, int end_y){
    vector<pair<int, int>> path;
    vector<vector<pair<int, int>>> res;
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    dfs_maze(maze, path, visited, x, y, end_x, end_y, res);
    return res;
}


