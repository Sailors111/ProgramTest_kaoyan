#include <iostream>
#include "test_5_5.hpp"
using namespace std;

/* 5.5 快速幂 */ 

// 清华大学机试题T115 求root(N, k)（难） 
void TsingHua_115(){
    long long x, y;
    int k;
    while(cin >> x >> y >> k){
        cout << root(x, y, k) << endl;
    }
}
