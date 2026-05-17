#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* 11.1 图的定义与遍历 */

// 图的邻接矩阵表示
struct Graph{
    vector<vector<int>> matrix; // 邻接矩阵
    vector<int> nodes;          // 顶点向量
    int vex_num;                // 顶点数
    int arc_num;                // 边数
    bool graph_type;            // true为有向图，false为无向图

    Graph(int num, bool type){
        vex_num = num;
        arc_num = 0;
        graph_type = type;
        matrix = vector<vector<int>>(num, vector<int>(num, 0));
        nodes = vector<int>(num, 0);
    }

    Graph(bool type, vector<int> items){
        vex_num = items.size();
        arc_num = 0;
        graph_type = type;
        nodes = items;
        matrix = vector<vector<int>>(items.size(), vector<int>(items.size(), 0));
    }

    void addEdge(int x, int y){ // 添加边
        if (x < 0 || y < 0 || x >= vex_num || y >= vex_num){
            return;
        }
        if(graph_type){
            matrix[x][y] = 1;
        }else{
            matrix[x][y] = 1;
            matrix[y][x] = 1;
        }
        arc_num++;
    }

    void addNode(int node){     // 添加顶点
        nodes.push_back(node);
        for(int i = 0; i < vex_num; i++){
            matrix[i].push_back(0);
        }
        matrix.push_back(vector<int>(vex_num + 1, 0));
        vex_num++;
    }

    void print(){               // 打印邻接矩阵
        for(int i = 0; i < vex_num; i++){
            for(int j = 0; j < vex_num; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// 访问顶点
void visit(const Graph& graph, int index){
    cout << graph.nodes[index] << " ";
}

// 深度优先搜索
void dfs(const Graph& graph, vector<bool>& visited, int start){
    visit(graph, start);
    visited[start] = true;
    for(int end = 0; end < graph.vex_num; end++){
        if(graph.matrix[start][end] && !visited[end]){
            dfs(graph, visited, end);
        }
    }
}

void DFS(const Graph& graph){
    vector<bool> visited(graph.vex_num, false);
    for(int i = 0; i < graph.vex_num; i++){
        if(!visited[i]){
            dfs(graph, visited, i);
        }
    }
}

// 广度优先搜索
void bfs(const Graph& graph, vector<bool>& visited, int start){ 
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int index = q.front();
        q.pop();
        visit(graph, index);
        for(int end = 0; end < graph.vex_num; end++){
            if(graph.matrix[index][end] && !visited[end]){
                q.push(end);
                visited[end] = true;
            }
        }
    }
}

void BFS(const Graph& graph){
    vector<bool> visited(graph.vex_num, false);
    for(int i = 0; i < graph.vex_num; i++){
        if(!visited[i]){
            bfs(graph, visited, i);
        }
    }
}

