#include <iostream>
#include <string>
#include <stack>
using namespace std;

/* 4.2 栈与队列 */ 

// 栈的应用-括号匹配
bool isMatch(string str){ 
    stack<char> st;
    for(int i = 0; i < str.size(); i++){ 
        // 左括号入栈
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){ 
            st.push(str[i]);
            continue;
        }
        // 右括号判断
        if(str[i] == ')'){ 
            if(st.empty() || st.top() != '('){  
                return false;
            }
            st.pop();
        }
        if(str[i] == ']'){
            if(st.empty() || st.top() != '['){
                return false;
            }
            st.pop();
        }
        if(str[i] == '}'){ 
            if(st.empty() || st.top() != '{'){
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}


// 栈的应用-表达式求值
int priority(char ch){     // 判断操作符的优先级
    if(ch == '#'){
        return 0;
    }else if(ch == '$'){
        return 1;
    }else if(ch == '+' || ch == '-'){
        return 2;
    }else{
        return 3;
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
            if(priority(opStack.top()) < priority(str[index])){ // 栈顶操作符优先级小于当前操作符
                opStack.push(str[index]);   // 将当前操作符入栈
                index++;
            }else{ // 栈顶操作符优先级大于等于当前操作符
                double y = numStack.top();
                numStack.pop();
                double x = numStack.top();
                numStack.pop();
                numStack.push(calculate(x, y, opStack.top())); // 出栈计算结果再入栈
                opStack.pop();
            }
        }
    }
    return numStack.top();
}

