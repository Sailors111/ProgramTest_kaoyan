#include <iostream>
#include "test_10_1.hpp"
using namespace std;

/* 10.1 递推求解 */    

// 华中科技大学机试题T121 N阶楼梯上楼问题
void HUS_121(){
    int N;
    while(cin >> N){
        int count = climb_stairs(N);
        cout << count << endl;
    }
}

// 北京大学机试题T120 吃糖果 
void PeKing_120(){ 
    int N;
    while(cin >> N){
        int count = climb_stairs(N);
        cout << count << endl;
    }
}
