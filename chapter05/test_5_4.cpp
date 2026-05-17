#include <iostream>
#include "test_5_4.hpp"
using namespace std;


/* 6.4 分解质因数 */   // 进度：3/3

// 清华大学机试题T106 质因数的个数 √
void TsingHua_106(){
    long long num;
    while(cin >> num){
        int count = numOfPrimeFactor(num);
        cout << count << endl;
    }
}

// 清华大学机试题T102 约数的个数 √
void TsingHua_102(){
    int N;
    while(cin >> N){
        long long* arr = new long long[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        for(int i = 0; i < N; i++){
            int count = numOfDivisor(arr[i]);
            cout << count << endl;
        }
    }
}

// 上海交通大学机试题T114 整除问题（难）
void SJU_114(){
    long long n, a; 
    while (cin >> n >> a) { 
        if (a < 2) {
            cout << 0 << endl;
        }else{
            cout << maxPowerOfAInFactN(n, a) << endl;
        }
    }
}



