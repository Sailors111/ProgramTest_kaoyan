#include <iostream>
#include <string>
#include <stack>
#include "test_5_1.hpp"
using namespace std;


/* 6.1 进制转换 */    // 进度：8/8

// 北京邮电大学机试题T100 二进制数 √
void BUP_100(){
    unsigned int num;
    while(cin >> num){
        unsigned int x = num;
        stack<char> st;
        while(x != 0){
            if(x % 2 == 0){
                st.push('0');
            }else{
                st.push('1');
            }
            x = x / 2;
        }
        string str;
        while(!st.empty() && st.top() == '0'){
            st.pop();
        }
        while(!st.empty()){
            str += st.top();
            st.pop();
        }
        cout << str << endl;
    }
}


// 清华大学机试题T100 进制转换 √
void TsingHua_100(){
    string str;
    while (cin >> str) {
        if(str == "0" || str == "1"){
            cout << str << endl;
            continue;
        }
        cout << TenToN(str, 2) << endl;
    }
}


// 清华大学机试题T125 10进制 VS 2进制 √
string reverse(string str) { // 字符串逆转
    string res = "";
    stack<char> st;
    for (auto& it : str) {
        st.push(it);
    }
    string bin_res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

void TsingHua_125(){
    string str;
    while (cin >> str) {
        if(str == "0" || str == "1"){
            cout << str << endl;
            continue;
        }
        string temp = TenToN(str, 2);
        temp = reverse(temp);
        string res = NToTen(temp, 2);
        cout << res << endl;
    }
}


// 清华大学机试题T129 进制转换2 √
void TsingHua_129(){
    int M, N;
    while(cin >> M >> N){
        string X;
        cin >> X;
        string res = MToN(X, M, N);
        cout << res << endl;
    }
}


// 华中科技大学机试题T126 八进制 √
void HUS_126(){
    int N;
    while(cin >> N){
        stack<char> st;
        while(N != 0){
            int x = N % 8;
            st.push(x + '0');
            N = N / 8;
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        cout << res << endl;
    }
}


// 浙江大学机试题T119 又一版A+B √
void ZJU_119(){
    unsigned int m;
    string A, B;
    while (cin >> m >> A >> B) {
        if (m == 0) {
            break;
        } else {
            string x = TenToN(A, m), y = TenToN(B, m);
            string res = add_N(x, y, m);
            cout << res << endl;
        }
    }
}


// 北京大学机试题T151 进制转换2 √
string SixteenToTen(string str){  // 十六进制转十进制
    unsigned long long num = 0;
    int index = 0;
    while(index < str.size()){
        num *= 16;
        num += CharToInt(str[index]);
        index++;
    }
    string res = to_string(num);
    return res;
}

void PeKing_151(){
    string str;
    while(cin >> str){
        string temp = str.substr(2, str.size() - 2);
        string res = SixteenToTen(temp);
        cout << res << endl;
    }
}


// 北京大学机试题T128 数制转换 √
char _IntToChar(int x){     // 数字转字符
    char ch;
    if(x < 10){
        ch = x + '0';
    }else{
        ch = x - 10 + 'A';
    }
    return ch;
}

int _CharToInt(char ch){    // 字符转数字
    int x;
    if('0' <= ch && ch <= '9'){
        x = ch - '0';
    }else if('A' <= ch && ch <= 'Z'){
        x = ch - 'A' + 10;
    }else{
        x = ch - 'a' + 10;
    }
    return x;
}

string _MtoN(string str, int M, int N){  // M进制数转N进制数
    long long temp = 0;
    int index = 0;
    while(index < str.size()){
        temp *= M;
        temp += _CharToInt(str[index]);
        index++;
    }
    string res = "";
    stack<char> st;
    while(temp != 0){
        st.push(_IntToChar(temp % N));
        temp = temp / N;
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}

void PeKing_128(){
    int a, b;
    string n;
    while (cin >> a >> n >> b) {
        string res = _MtoN(n, a, b);
        cout << res << endl;
    }
}


