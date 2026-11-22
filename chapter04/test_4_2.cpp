#include <iostream>
#include <string>
#include <stack>
#include "test_4_2.hpp"
using namespace std;

/* 4.2 栈与队列 */      

// 上海交通大学机试题T118 Zero-complexity Transposition
void SJU_118(){
    int n;
    while(cin >> n){
        stack<int> st;
        int num;
        for(int i = 0; i < n; i++){
            cin >> num;
            st.push(num);
        }
        while(!st.empty()){
            int top = st.top();
            st.pop();
            cout << top << " ";
        }
        cout << endl;
    }
}

// 浙江大学机试题T113 简单计算器
void ZJU_113(){
    string str;
    while(getline(cin, str)){
        if(str == "0"){
            break;
        }else{
            double result = calculateExpression(str);
            printf("%0.2lf\n", result);
        }
    }
}

// 吉林大学机试题T180 堆栈的使用
void JLU_180(){
    int n;
    while (cin >> n) {
        stack<int> st;
        for (int i = 0; i < n; i++) {
            char ch;
            cin >> ch;
            if (ch == 'P') {
                int num;
                cin >> num;
                st.push(num);
            } else if (ch == 'O') {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (ch == 'A') {
                if (!st.empty()) {
                    int top = st.top();
                    cout << top << endl;
                } else {
                    cout << "E" << endl;
                }
            } else {
                continue;
            }
        }
    }
}

// 上海交通大学机试题T111 计算表达式
void SJU_111(){
    string str;
    while(getline(cin, str)){
        double result = calculateExpression(str);
        cout << result << endl;
    }
}

