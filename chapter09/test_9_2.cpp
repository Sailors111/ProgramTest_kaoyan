#include <iostream>
#include "test_9_2.hpp"
using namespace std;

/* 9.2 二叉排序树 */   

// 华中科技大学机试题T103 二叉排序树1 
void HUS_103(){
    int N;
    while(cin >> N){
        int val;
        BST* root = nullptr;
        for(int i = 0; i < N; i++) {
            cin >> val;
            BST* node = BST_insert(root, nullptr, val);
            if(node->parent == nullptr) {
                cout << -1 << endl;
            } else {
                cout << node->parent->val << endl;
            }
        }
    }
}

// 华中科技大学机试题T119 二叉排序树2 
void HUS_119(){
    int N;
    while(cin >> N){
        int val;
        BST* root = nullptr;
        for(int i = 0; i < N; i++){
            cin >> val;
            BST_insert(root, nullptr, val);
        }
        preorder(root);
        cout << endl;
        inorder(root);
        cout << endl;
        postorder(root);
        cout << endl;
    }
}

// 浙江大学机试题T108 二叉搜素树 
void ZJU_108(){
    int N;
    while (cin >> N) {
        if(N == 0){
            break;
        }
        BST* root1 = nullptr;
        string str1, str2;
        cin >> str1;
        for (auto ch : str1) {
            int val = ch - '0';
            BST_insert(root1, nullptr, val);
        }
        for (int i = 0; i < N; i++) {
            BST* root2 = nullptr;
            cin >> str2;
            for (auto ch : str2) {
                int val = ch - '0';
                BST_insert(root2, nullptr, val);
            }
            bool flag = isSameBST(root1, root2);
            if(flag){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
}
