#include <iostream>
#include <vector>
using namespace std;

/* 7.2 分治 */ 

// Fibonacci数列
long long Fibonacci(long long num){
    if(num == 0 || num == 1){
        return num;
    }else{
        return Fibonacci(num - 1) + Fibonacci(num - 2);
    }
}

// 完全二叉树求节点数
int countNodes(int index, int total_node_num){   // index为节点编号，total_node_num为节点总数
    if(index > total_node_num){
        return 0;
    }else{
        return 1 + countNodes(2 * index, total_node_num) + countNodes(2 * index + 1, total_node_num);
    }
}
