#include <iostream>
#include <string>
#include <stack>
using namespace std;

// N进制数加法，N为1~10的整数
string add_N(string x, string y, int N) {    
    int len1 = x.size(), len2 = y.size();
    // 补0对齐
    while (len1 < len2) {
        x = "0" + x;
        len1++;
    }
    while (len2 < len1) {
        y = "0" + y;
        len2++;
    }
    // 进位加法
    string res = "";
    int len = x.size(), carry = 0;
    for (int i = len - 1; i >= 0; i--) {
        int sum = x[i] - '0' + y[i] - '0' + carry;
        carry = sum / N;
        res = char(sum % N + '0') + res;
    }
    if (carry > 0) {
        res = "1" + res;
    }
    return res;
}

//十进制数乘以N，N是1~10之间的整数
string multiple(string num, int N) {
    string res = "";
    int carry = 0;  
    for (int i = num.size() - 1; i >= 0; i--) {
        int product = (num[i] - '0') * N + carry;
        carry = product / 10;        
        res = char(product % 10 + '0') + res;  
    }
    if (carry > 0) {
        res = char(carry + '0') + res;
    }
    return res;
}

// 十进制数除以N，N为1~9之间的整数
string divide(string num, int N){
    string res = "";
    int carry = 0;
    // 模拟除法
    for(int i = 0; i < num.size(); i++){
        int sum = num[i] - '0' + carry * 10;
        carry = sum % N;
        res += char(sum / N + '0');
    }
    // 去除前导0
    int end = 0;
    while(end < res.size() && res[end] == '0'){
        end++;
    }
    if(end == res.size()){
        return "0";
    }
    res = res.substr(end);
    return res;
}

// 十进制数取模N，N为1~9之间的整数
char mod(string num, int N) {
    int res = 0;
    for (int i = 0; i < num.size(); i++) {
        res = (res * 10 + (num[i] - '0')) % N;
    }
    return char(res + '0');
}


// 十进制转N进制，N为1~9的整数
string TenToN(string num, int N) { 
    string res = "";
    while (num != "0") {
        res = mod(num, N) + res;
        num = divide(num, N);
    }
    return res;
}

// N进制转十进制，N为1~9的整数
string NToTen(string num, int N) { 
    string res = "0";
    for (int i = 0; i < num.size(); i++) {
        res = multiple(res, N);
        res = add_N(res, to_string(num[i] - '0'), 10);
    }
    return res;
}


// 字符转数字
int CharToInt(char ch){
    int res = 0;
    if('0' <= ch && ch <= '9'){
        res = ch - '0';
    }else if('a' <= ch && ch <= 'z'){
        res = ch - 'a' + 10;
    }else if('A' <= ch && ch <= 'Z'){
        res = ch - 'A' + 10;
    }
    return res;
}

// 数字转字符
char IntToChar(int num){
    char res = ' ';
    if(num < 10){
        res = num + '0';
    }else{
        res = num - 10 + 'a';
    }
    return res;
}

// M进制转N进制
string MToN(string num, int M, int N){
    string res = "";
    unsigned long long temp = 0;
    for(int i = 0; i < num.size(); i++){
        temp = CharToInt(num[i]) + temp * M;
    }
    while(temp != 0){
        res = IntToChar(temp % N) + res;
        temp /= N;
    }
    if(res.empty()){
        res = "0";
    }
    return res;
}

