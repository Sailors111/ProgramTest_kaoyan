#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/* 5.1 向量 */    

// 清华大学机试题T119 完数VS盈数
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
    for(auto it = E_nums.begin(); it != E_nums.end(); it++){
        cout << " " << *it ;
    }
    cout << endl;
    cout << "G:";
    for(auto it = G_nums.begin(); it != G_nums.end(); it++){
        cout << " " << *it ;
    }
    cout << endl;
}

/* 5.3 栈 */      

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
int priority(char ch){     // 判断操作符的优先级
    if(ch == '#'){
        return 0;
    }else if(ch == '$'){
        return 1;
    }else if(ch == '+' || ch == '-'){
        return 2;
    }else{
        return 4;
    }
}

double calculate(double x, double y, char op){    // 操作数计算
    double res;
    if (op == '+') {
        res = x + y;
    } else if (op == '-') {
        res = x - y;
    } else if (op == '*') {
        res = x * y;
    } else if (op == '/') {
        res = x / y;
    }
    return res;
}

double getNumber(string str, int& index){   // 从字符串中读数字
    double number = 0;
    while(isdigit(str[index])){   // isdigit函数用于判断字符是不是数字
        number = number * 10 + str[index] - '0';
        index++;
    }
    return number;
}

double calculateExpression(string str){    //  表达式求值
    int index = 0;
    stack<char> opStack;
    stack<double> numStack;
    str += "$";
    opStack.push('#');
    while(index < str.size()){
        if(str[index] == ' '){
            index++;
        }else if(isdigit(str[index])){
            numStack.push(getNumber(str, index));
        }else{
            if(priority(opStack.top()) < priority(str[index])){
                opStack.push(str[index]);
                index++;
            }else{
                double y = numStack.top();
                numStack.pop();
                double x = numStack.top();
                numStack.pop();
                numStack.push(calculate(x, y, opStack.top()));
                opStack.pop();
            }
        }
    }
    return numStack.top();
}

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



