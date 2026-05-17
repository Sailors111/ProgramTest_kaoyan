#include <iostream>
#include <vector>
using namespace std;


/* 5.1 向量 */    // 进度：1/1

// 清华大学机试题T119 完数VS盈数 √
int Sum(int x){         // 求一个数的因子之和
    int sum = 0;
    for(int i = 1; i < x; i++){
        if(x % i == 0){
            sum += i;
        }
    }
    return sum;
}

void TsingHua_119(){
    vector<int> E_nums;
    vector<int> G_nums;
    for(int i = 2; i <= 60; i++){
        if(i == Sum(i)){
            E_nums.push_back(i);
        }else if(i < Sum(i)){
            G_nums.push_back(i);
        }
    }
    cout << "E:";
    for(auto & it : E_nums){
        cout << " " << it ;
    }
    cout << endl;
    cout << "G:";
    for(auto & it : G_nums){
        cout << " " << it ;
    }
    cout << endl;
}


