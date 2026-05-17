#include <iostream>
#include <queue>
#include "test_9_1.hpp"
using namespace std;


/* 10.1 二叉树 */   // 进度：2/2


// 清华大学机试题T110 二叉树遍历 √
void preorder_insert(TreeNode*& root, string str, int& i){
    if(i == str.size()){
        return;
    }
    if(str[i] == '#'){
        i++;
        root = nullptr;
        return;
    }
    root = new TreeNode(str[i]);
    i++;
    preorder_insert(root->left, str, i);
    preorder_insert(root->right, str, i);
}

void TsingHua_110(){
    string str;
    while(cin >> str){
        TreeNode* root = new TreeNode();
        int pos = 0;
        preorder_insert(root, str, pos);
        inorder(root);
        cout << endl;
    }
}


// 华中科技大学机试题T108 二叉树遍历（难）√
void visit_(TreeNode* root) {
    cout << root->val;
}

void postorder_(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postorder_(root->left);
    postorder_(root->right);
    visit_(root);
}

void HUS_108(){ 
    string preorder_str, inorder_str;
    while (cin >> preorder_str >> inorder_str) {
        TreeNode* root = buildTree_pre(inorder_str, preorder_str);
        postorder_(root);
        cout << endl;
    }
}
