#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/* 6.1 进制转换 */   

// 北京邮电大学机试题T100 二进制数
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

// 清华大学机试题T100 进制转换
string mod_2(string str) {    // 取模2
    return to_string((str[str.size() - 1] - '0') % 2);
}

string div_2(string str) {    // 除以2
    if(str.size() <= 1 && stoi(str) <= 1){
        return "0";
    }
    string res = "";
    int index = 0;
    int carry = 0;
    while (index < str.size()) {
        int x = carry * 10 + str[index] - '0';
        carry = x % 2;
        x = x / 2;
        res += to_string(x);
        index++;
    }
    index = 0;
    while (index < res.size() && res[index] == '0') {
        index++;
    }
    res = res.substr(index, res.size() - index);
    return res;
}

string TenToTwo(string str){  // 十进制数转二进制数
    string res = "";
    if (str == "0") {
        res = str;
    } else {
        string x = str;
        stack<char> st;
        while (x != "0") {
            char ch = mod_2(x)[mod_2(x).size() - 1];
            st.push(ch);
            x = div_2(x);
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        int index = 0;
        while (index < res.size() && res[index] == '0') {
            index++;
        }
        res = res.substr(index, res.size() - index);
    }
    return res;
}

void TsingHua_100(){
    string str;
    while (cin >> str) {
        cout << TenToTwo(str) << endl;
    }
}

// 清华大学机试题T125 10进制 VS 2进制
string add_10(string x, string y) {  // 十进制加法
    string res = "";
    int carry = 0;
    int i = x.size() - 1, j = y.size() - 1;
    while (i >= 0 && j >= 0) {
        int sum = carry + x[i] - '0' + y[j] - '0';
        carry = sum / 10;
        res = to_string(sum % 10) + res;
        i--;
        j--;
    }
    while (i >= 0) {
        int sum = carry + x[i] - '0';
        carry = sum / 10;
        res = to_string(sum % 10) + res;
        i--;
    }
    while (j >= 0) {
        int sum = carry + y[j] - '0';
        carry = sum / 10;
        res = to_string(sum % 10) + res;
        j--;
    }
    if (carry > 0) {
        res = "1" + res;
    }
    return res;
}

string TwoToTen(string str) {   // 二进制数转十进制数
    string res = "0";
    int index = 0;
    while (index < str.size()) {
        res = add_10(res, res);
        res = add_10(res, to_string(str[index] - '0'));
        index++;
    }
    return res;
}

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
        string bin_str = TenToTwo(str);
        string bin_res = reverse(bin_str);
        string res = TwoToTen(bin_res);
        cout << res << endl;
    }
}

// 清华大学机试题T129 进制转换2
char IntToChar(int x){     // 数字转字符
    char ch;
    if(x < 10){
        ch = x + '0';
    }else{
        ch = x - 10 + 'a';
    }
    return ch;
}

int CharToInt(char ch){    // 字符转数字
    int x;
    if('0' <= ch && ch <= '9'){
        x = ch - '0';
    }else{
        x = ch - 'A' + 10;
    }
    return x;
}

string MtoN(string str, int M, int N){  // M进制数转N进制数
    long long temp = 0;
    int index = 0;
    while(index < str.size()){
        temp *= M;
        temp += CharToInt(str[index]);
        index++;
    }
    string res = "";
    stack<char> st;
    while(temp != 0){
        st.push(IntToChar(temp % N));
        temp = temp / N;
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}

void TsingHua_129(){
    int M, N;
    while(cin >> M >> N){
        string X;
        cin >> X;
        string res = MtoN(X, M, N);
        cout << res << endl;
    }
}

// 华中科技大学机试题T126 八进制
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

// 浙江大学机试题T119 又一版A+B
string TenToN(unsigned int x, int N){    // 十进制转N进制
    if(x == 0){
        return "0";
    }
    stack<char> st;
    while(x != 0){
        char ch = x % N + '0';
        st.push(ch);
        x = x / N;
    }
    string res = "";
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}

string addAtN(string x, string y, int N) {  // N进制加法
    int carry = 0;
    string res = "";
    int i = x.size() - 1, j = y.size() - 1;
    while (i >= 0 && j >= 0) {
        int sum = carry + x[i] - '0' + y[j] - '0';
        carry = sum / N;
        res = to_string(sum % N) + res;
        i--;
        j--;
    }
    while (i >= 0) {
        int sum = carry + x[i] - '0';
        carry = sum / N;
        res = to_string(sum % N) + res;
        i--;
    }
    while (j >= 0) {
        int sum = carry + y[j] - '0';
        carry = sum / N;
        res = to_string(sum % N) + res;
        j--;
    }
    if(carry > 0){
        res = "1" + res;
    }
    return res;
}

void ZJU_119(){
    unsigned int m, A, B;
    while (cin >> m >> A >> B) {
        if (m == 0) {
            break;
        } else {
            string x = TenToN(A, m), y = TenToN(B, m);
            string res = addAtN(x, y, m);
            cout << res << endl;
        }
    }
}

// 北京大学机试题T151 进制转换2
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

// 北京大学机试题T128 数制转换
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



