#include <iostream>
#include <string>
#include "test_5_7.hpp"
using namespace std;


/* 6.7 高精度整数 */  // 进度：4/4

// 华中科技大学机试题T105 a + b √
void HUS_105(){
    BigInteger a, b;
    while(cin >> a >> b){
        cout << a + b << endl;
    }
}

// 清华大学机试题T123 N的阶乘（难）
void TsingHua_123(){
    int N;
    while(cin >> N){
        BigInteger result(1);
        for(int i = 1; i <= N; i++){
            result = result * BigInteger(i);
        }
        cout << result << endl;
    }
}

// 哈尔滨工业大学机试题T167 数字阶梯求和（难）
void HaGongDa_167(){
    int a, n;
    while(cin >> a >> n){
        BigInteger result(0), x(a);
        for(int i = 0; i < n; i++){
            result = result + x;
            x = x * BigInteger(10) + BigInteger(a);
        }
        cout << result << endl;
    }
}

// 北京大学机试题T111 大整数的因子（难）
void PeKing_111(){
    string str;
    while (getline(cin, str)) {
        if (str == "-1") {
            break;
        }
        BigInteger c(str);
        bool flag = false;
        int k = 2;
        while (k <= 9) {
            if (c % BigInteger(k) == BigInteger(0)) {
                cout << k;
                flag = true;
                break;
            }
            k++;
        }
        k++;
        while (k <= 9) {
            if (c % BigInteger(k) == BigInteger(0)) {
                cout << " " << k;
            }
            k++;
        }
        if (!flag) {
            cout << "none";
        }
        cout << endl;
    }
}


