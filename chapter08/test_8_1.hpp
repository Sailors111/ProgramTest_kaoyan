#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* 8.1 宽度优先搜索 */

/*
    核心逻辑：队列存状态-出队检查目标-扩展新状态-判重入队
    判断重复：unordered_set<Type> visited / vector<bool> visited / vector<vector<bool>> visited
*/

// 无权图最短路径问题
vector<int> bfs_shortest_path(const vector<vector<int>>& graph, int start){ 
    int num = graph.size();
    vector<int> dist(graph.size(), -1);
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    // 起始点入队
    q.push(start);
    dist[start] = 0;
    visited[start] = true;
    while(!q.empty()){ 
        // 队头出队
        int current = q.front();
        q.pop();
        // 遍历当前节点的相邻节点
        for(int next = 0; next < num; next++){
            if(!visited[next] && graph[current][next] == 1){ // 未访问且存在边
                dist[next] = dist[current] + 1;
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return dist;
}


// 迷宫最短路径问题
struct Node{
    int x;
    int y;
    int step;
};

vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs_maze(const vector<vector<int>>& maze, int sx, int sy, int end_x, int end_y, vector<pair<int, int>>& path){
    int row_len = maze.size(), col_len = maze[0].size();
    queue<Node> q;
    vector<vector<bool>> visited(row_len, vector<bool>(col_len, false));

    vector<vector<pair<int, int>>> parent(row_len, vector<pair<int, int>>(col_len, {-1, -1})); // 保存路径上的点的前驱结点
    
    q.push({sx, sy, 0});
    visited[sx][sy] = true;
    while(!q.empty()){
        Node node = q.front();
        q.pop();

        int cx = node.x, cy = node.y, step = node.step;
        if(cx == end_x && cy == end_y){
            int x = cx, y = cy;
            while(x != -1 && y != -1){
                path.push_back({x, y});
                pair<int, int> p = parent[x][y];
                x = p.first;
                y = p.second;
            }
            reverse(path.begin(), path.end());
            return step;
        }
        
        for(auto & dir : dirs){
            int nx = cx + dir[0], ny = cy + dir[1];
            if(nx >= 0 && nx < row_len && ny >= 0 && ny < col_len && !visited[nx][ny] && maze[nx][ny] == 0){
                visited[nx][ny] = true;
                parent[nx][ny] = {cx, cy};
                q.push({nx, ny, step + 1});
            }
            
        }
    }
    return -1;
}
