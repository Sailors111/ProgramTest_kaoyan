#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* 9.3 优先队列 */

// 哈夫曼树定义
struct HTNode {
    int weight;
    struct HTNode* left;
    struct HTNode* right;
    HTNode() : weight(0), left(nullptr), right(nullptr) {}
    HTNode(int w, HTNode* l, HTNode* r) {
        weight = w;
        left = l;
        right = r;
    }
    HTNode(HTNode* l, HTNode* r) {
        weight = l->weight + r->weight;
        left = l;
        right = r;
    }
};

// 优先级队列比较函数
struct Compare_HT_ptr {
    bool operator()(const HTNode* h1, const HTNode* h2) {
        return h1->weight > h2->weight;
    }
};

// 创建哈夫曼树
HTNode* createHTree(const vector<int>& weight) {
    priority_queue<HTNode*, vector<HTNode*>, Compare_HT_ptr> pq;
    for (int w : weight) {
        auto* h = new HTNode(w, nullptr, nullptr);
        pq.push(h);
    }
    while (pq.size() != 1) {
        HTNode* h1 = pq.top();
        pq.pop();
        HTNode* h2 = pq.top();
        pq.pop();
        auto* new_h = new HTNode(h1, h2);
        pq.push(new_h);
    }
    HTNode* root = pq.top();
    pq.pop();
    return root;
}

// 计算哈夫曼树编码的权值和
int calculateWPL(HTNode* root, int h) {
    if (root == nullptr) {
        return 0;
    } else if (root->left == nullptr && root->right == nullptr) {
        return h * root->weight;
    } else {
        return calculateWPL(root->left, h + 1) + calculateWPL(root->right, h + 1);
    }
}


