#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;


/* 11.2 并查集 */

const int MAX_SIZE = 100;

// 并查集定义
struct UFSet{
    int parent[MAX_SIZE];   // 父节点
    int size;               // 集合大小
};

// 初始化并查集
void Init(UFSet& set, int n) {
    for (int i = 0; i < n; i++) {
        set.parent[i] = i;  // 初始化父节点为自身
    }
    set.size = n;
}

// 查找根节点
int Find(UFSet& set, int x) {
    if (set.parent[x] != x) {   // 递归寻找根节点
        set.parent[x] = Find(set, set.parent[x]);
    }
    return set.parent[x];
}

// 合并两个集合
void Union(UFSet& set, int x, int y) {
    int x_root = Find(set, x);
    int y_root = Find(set, y);
    if (x_root != y_root) {     // 不同集合
        set.parent[x_root] = y_root;
        set.size--;
    }
}
