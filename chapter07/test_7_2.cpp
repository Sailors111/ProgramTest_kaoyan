#include <iostream>
#include "test_7_2.hpp"
using namespace std;

/* 7.2 分治 */    

// 上海交通大学机试题T105 Fibonacci 
void SJU_105(){
    int num;
    while(cin >> num){
        cout << Fibonacci(num) << endl;
    }
}

// 北京大学机试题T156 二叉树 
void PeKing_156(){
    int m, n;
    while(cin >> m >> n){
        if(m == 0 || n == 0){
            break;
        }else{
            cout << countNodes(m, n) << endl;
        }
    }
}

// 上海交通大学机试题T112 2的幂次方（难）
string TenToTwo(int num) {
    string res = "";
    while (num != 0) {
        res += char(num % 2 + '0');
        num /= 2;
    }
    return res;
}

void pow2(int num) {
    if (num == 0 || num == 2) {
        cout << "2(" << num << ")";
    } else if (num == 1) {
        cout << "2";
    } else {
        string res = TenToTwo(num);
        int index;
        while ((index = res.rfind("1")) != string::npos) {
            if (index > 2) {
                cout << "2(";
                pow2(index);
                cout << ")";
                res[index] = '0';
                if ((index = res.rfind("1")) != string::npos) {
                    cout << "+";
                }
            } else {
                pow2(index);
                res[index] = '0';
                if ((index = res.rfind("1")) != string::npos) {
                    cout << "+";
                }
            }
        }
    }
}

void SJU_112(){
    int num;
    while (cin >> num) {
        if (num == 1) {
            cout << "2(0)";
        } else if (num == 2) {
            cout << "2";
        } else if (num == 0) {
            cout << "0";
        } else {
            pow2(num);
        }
        cout << endl;
    }
}

