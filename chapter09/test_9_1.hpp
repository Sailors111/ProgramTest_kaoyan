#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstdint>
using namespace std;

/* 9.1 二叉树 */

// 二叉树结构体定义
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 访问节点
void visit(TreeNode* node){
    cout << node->val << " ";
}

// 中序遍历
void inorder(TreeNode* root){
    if(root == nullptr) {
        return;
    }
    inorder(root->left);
    visit(root);
    inorder(root->right);
}

// 前序遍历
void preorder(TreeNode* root){
    if(root == nullptr) {
        return;
    }
    visit(root);
    preorder(root->left);
    preorder(root->right);
}

// 后序遍历
void postorder(TreeNode* root){
    if(root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    visit(root);
}

// 层序遍历
void levelorder(TreeNode* root){
    if(root == nullptr) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        visit(node);
        if(node->left != nullptr) {
            q.push(node->left);
        }
        if(node->right != nullptr) {
            q.push(node->right);
        }
    }
}


// 利用中序遍历序列与前序遍历序列构造树
TreeNode* buildTree_pre(string inorder, string preorder){
    if(preorder.size() == 0){
        return nullptr;
    }
    char ch = preorder[0];
    // 确定根节点
    TreeNode* root = new TreeNode(ch);
    int pos = inorder.find(ch);
    if(pos == string::npos){
        return nullptr;
    }
    // 确定左子树和右子树的大小
    string leftInorder = inorder.substr(0, pos), rightInorder = inorder.substr(pos + 1);
    int left_size = leftInorder.size(), right_size = rightInorder.size();
    string leftPreorder = preorder.substr(1, left_size), rightPreorder = preorder.substr(pos + 1, right_size);
    // 构造左子树
    root->left = buildTree_pre(leftInorder, leftPreorder);
    // 构造右子树
    root->right = buildTree_pre(rightInorder, rightPreorder);
    return root;
}

// 利用中序遍历序列与后序遍历序列构造树
TreeNode* buildTree_post(string inorder, string postorder){
    if(postorder.size() == 0){
        return nullptr;
    }
    char ch = postorder[postorder.size() - 1];
    // 确定根节点
    TreeNode* root = new TreeNode(ch);
    int pos = inorder.find(ch);
    if(pos == string::npos){
        return nullptr;
    }
    // 确定左子树和右子树的大小
    string leftInorder = inorder.substr(0, pos), rightInorder = inorder.substr(pos + 1);
    int left_size = leftInorder.size(), right_size = rightInorder.size();
    string leftPostorder = postorder.substr(0, left_size), rightPostorder = postorder.substr(pos, right_size);
    // 构造左子树
    root->left = buildTree_post(leftInorder, leftPostorder);
    // 构造右子树
    root->right = buildTree_post(rightInorder, rightPostorder);
    return root;
}


// 计算节点数量
int countNodes(TreeNode* root) {
    if(root == nullptr){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 计算叶子节点的数量
int countLeafNodes(TreeNode* root) {
    if(root == nullptr){
        return 0;
    }else if(root->left == nullptr && root->right == nullptr){
        return 1;
    }else{
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }
}

// 计算单度节点的数量
int countOneDegreeNodes(TreeNode* root) {
    if(root == nullptr){
        return 0;
    }else if((root->left == nullptr && root->right != nullptr) || (root->left != nullptr && root->right == nullptr)){
        return 1 + countOneDegreeNodes(root->left) + countOneDegreeNodes(root->right);
    }else{
        return countOneDegreeNodes(root->left) + countOneDegreeNodes(root->right);
    }
}

// 计算两度节点的数量
int countTwoDegreeNodes(TreeNode* root) {
    if(root == nullptr){
        return 0;
    }else if(root->left != nullptr && root->right != nullptr){
        return 1 + countTwoDegreeNodes(root->left) + countTwoDegreeNodes(root->right);
    }else{
        return countTwoDegreeNodes(root->left) + countTwoDegreeNodes(root->right);
    }
}

// 计算某一层的节点数量（根节点在第一层）
int countNodesAtLevel(TreeNode* root, int level){
    if(root == nullptr || level < 1){
        return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    int res = 1;
    while(!q.empty() && level > 0){
        int size = q.size();
        for(int i = 0; i < size; i++){
            TreeNode* node = q.front();
            if(node->left != nullptr){
                q.push(node->left);
            }
            if(node->right != nullptr){
                q.push(node->right);
            }
            q.pop();
        }
        level--;
        res = size;
    }
    if(level > 0){
        return 0;
    }
    return res;
}


// 计算二叉树的高度
int height(TreeNode* root){
    if(root == nullptr){
        return 0;
    }else if(root->left == nullptr && root->right == nullptr){
        return 1;
    }else{
        return max(height(root->left), height(root->right)) + 1;
    }
}

// 计算二叉树的宽度
int width(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    int res = 0;
    while(!q.empty()){
        int size = q.size();
        if(size > res){
            res = size;
        }
        for(int i = 0; i < size; i++){
            TreeNode* node = q.front();
            if(node->left != nullptr){
                q.push(node->left);
            }
            if(node->right != nullptr){
                q.push(node->right);
            }
            q.pop();
        }
    }
    return res;
}


// 完全二叉树判断
bool isCompleteTree(TreeNode* root){
    if(root == nullptr){
        return true;
    }
    queue<TreeNode*> q;
    q.push(root);
    bool flag = false;
    while(!q.empty()){
        TreeNode* node = q.front();
        if(node != nullptr && flag){
            return false;
        }
        if(node == nullptr){
            flag = true;
            q.pop();
            continue;
        }
        q.push(node->left);
        q.push(node->right);
        q.pop();
    }
    return true;
}

// 满二叉树判断
bool isFullTree(TreeNode* root){
    if(root == nullptr){
        return true;
    }
    queue<TreeNode*> q;
    q.push(root);
    int nodeNum = 1;
    while(!q.empty()){
        int size = q.size();
        if(size != nodeNum){
            return false;
        }
        for(int i = 0; i < size; i++){
            TreeNode* node = q.front();
            if(node->left != nullptr){
                q.push(node->left);
            }
            if(node->right != nullptr){
                q.push(node->right);
            }
            q.pop();
        }
        nodeNum = 2 * nodeNum;
    }
    return true;
}

// 二叉搜索树判断
bool isBSTNode(TreeNode* root, int& pre_val){
    if(root == nullptr){
        return true;
    }
    bool l = isBSTNode(root->left, pre_val);
    if(l == false){
        return false;
    }
    if(root->val <= pre_val){
        return false;
    }
    pre_val = root->val;
    bool r = isBSTNode(root->right, pre_val);
    if(r == false){
        return false;
    }
    return true;
}

bool isValidBST(TreeNode* root){
    if(root == nullptr){
        return true;
    }
    int pre_val = INT32_MIN;
    return isBSTNode(root, pre_val);
}

// 平衡二叉树判断
int isBalanced(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    int lh = isBalanced(root->left);
    if(lh == -1){
        return -1;
    }
    int rh = isBalanced(root->right);
    if(rh == -1){
        return -1;
    }
    if(abs(lh - rh) > 1){
        return -1;
    }
    return max(lh, rh) + 1;
}

bool isBalancedTree(TreeNode* root){
    return isBalanced(root) != -1;
}


// 二叉树的路径长度：根到每个节点的路径长度（边数）之和
int pathLength(TreeNode* root, int depth = 0){
    if(root == nullptr){
        return 0;
    }
    return depth + pathLength(root->left, depth + 1) + pathLength(root->right, depth + 1);
}

// 二叉树的带权路径长度：WPL，所有叶子节点的[权值×路径长度]之和
int weightedPathLength(TreeNode* root, int depth = 0){
    if(root == nullptr){
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr){
        return depth * root->val;
    }
    return weightedPathLength(root->left, depth + 1) + weightedPathLength(root->right, depth + 1);
}

