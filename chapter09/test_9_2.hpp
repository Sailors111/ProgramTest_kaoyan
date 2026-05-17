#include <iostream>
#include <string>
#include <queue>
using namespace std;

/* 9.2 二叉排序树 */

// 二叉排序树结构体定义
struct BST{
    int val;
    struct BST* left;   // 左子树
    struct BST* right;  // 右子树
    struct BST* parent; // 父节点
    BST() : val(0), left(nullptr), right(nullptr), parent(nullptr) {}
    BST(int _val, BST* _parent) : val(_val), left(nullptr), right(nullptr), parent(_parent){}
};

// 插入
BST* BST_insert(BST*& root, BST* _parent, int _val){ // 返回的是新建节点或目标节点
    if(root == nullptr){
        root = new BST(_val, _parent);
        return root;
    }
    if(_val == root->val){
        return root;
    }else if(_val < root->val){
        return BST_insert(root->left, root, _val);
    }else{
        return BST_insert(root->right, root, _val);
    }
}

// 访问节点
void visit(BST* node){
    cout << node->val << " ";
}

// 中序遍历
void inorder(BST* root){
    if(root == nullptr){
        return;
    }
    inorder(root->left);
    visit(root);
    inorder(root->right);
}

// 前序遍历
void preorder(BST* root){
    if(root == nullptr){
        return;
    }
    visit(root);
    preorder(root->left);
    preorder(root->right);
}

// 后序遍历
void postorder(BST* root){
    if(root == nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    visit(root);
}

// 层序遍历
void levelorder(BST* root){
    queue<BST*> q;
    q.push(root);
    while(!q.empty()){
        BST* node = q.front();
        q.pop();
        visit(node);
        if(node->left != nullptr){
            q.push(node->left);
        }
        if(node->right != nullptr){
            q.push(node->right);
        }
    }
}

// 判断两棵树是否相同
bool isSameBST(BST* root1, BST* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    } else if ((root1 == nullptr && root2 != nullptr) || (root1 != nullptr && root2 == nullptr)) {
        return false;
    } else {
        if (root1->val != root2->val) {
            return false;
        } else {
            return isSameBST(root1->left, root2->left) && isSameBST(root1->right, root2->right);
        }
    }
}


