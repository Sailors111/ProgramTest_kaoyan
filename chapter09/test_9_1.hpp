#include <iostream>
#include <string>
#include <queue>
using namespace std;


/* 9.1 二叉树 */

struct TreeNode {
    char val;
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


