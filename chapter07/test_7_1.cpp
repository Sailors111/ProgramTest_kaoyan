#include <iostream>
#include <vector>
#include <algorithm>
#include "test_7_1.hpp"
using namespace std;


/* 8.1 递归 */     // 进度：2/2

// 清华大学机试题T116 n的阶乘 √
void TsingHua_116(){
    int num;
    while(cin >> num){
        cout << Factorial(num) << endl;
    }
}

// 北京大学机试题T115 全排列（难） √
void PeKing_115(){
    string str;
    while(cin >> str){
        vector<string> res = permute(str);
        for(auto & it : res){
            cout << it << endl;
        }
    }
}


