#include <iostream>
#include <string>
#include <vector>
using namespace std;


/* 4.2 字符串处理 */  


// 字符串替换
void replaceAll(string& str, const string& S, const string& T){ // 将str中所有的S替换为T
    if(S.empty()){
        return;
    }
    size_t pos = 0;
    while((pos = str.find(S, pos)) != string::npos){
        str.replace(pos, S.size(), T);
        pos += T.size();
    }
}


// 字符串分割
vector<string> split(string str, char ch) { // 将str按ch为界分割
    vector<string> vec;
    int start = 0, len = str.size();
    for (int end = 0; end < len; end++) {
        if (str[end] == ch) {
            vec.push_back(str.substr(start, end - start));
            while (end < len && str[end] == ch) {
                end++;
            }
            start = end;
        }
    }
    if (start < len) {
        vec.push_back(str.substr(start));
    }
    return vec;
}


// 浮点数加法
void InitProcess(string& S, string& T) {
    int pos01 = S.find('.'), pos02 = T.find('.');
    while (pos01 < pos02) {
        S = '0' + S;
        pos01++;
    }
    while (pos02 < pos01) {
        T = '0' + T;
        pos02++;
    }
    int len01 = S.size(), len02 = T.size();
    while (len01 < len02) {
        S = S + '0';
        len01++;
    }
    while (len02 < len01) {
        T = T + '0';
        len02++;
    }
}

string FloatAdd(string S, string T) {
    InitProcess(S, T);
    int carry = 0;
    int len = S.size();
    string res = "";
    for (int i = len - 1; i >= 0; i--) {
        if (S[i] == '.') {
            res = '.' + res;
            continue;
        } else {
            int sum = S[i] - '0' + T[i] - '0' + carry;
            carry = sum / 10;
            res = char(sum % 10 + '0') + res;
        }
    }
    if (carry > 0) {
        res = '1' + res;
    }
    // 把字符串首部的所有0去掉
    int end;
    for (end = 0; end < res.size(); end++) {
        if (res[end] != '0') {
            break;
        }
    }
    res.erase(0, end);
    if (res[0] == '.') {
        res = '0' + res;
    }
    // 把字符串尾部的所有0去掉
    for (end = res.size() - 1; end >= 0; end--) {
        if (res[end] != '0') {
            break;
        }
    }
    res.erase(end + 1, res.size() - end - 1);
    if (res[res.size() - 1] == '.') {
        res = res + '0';
    }
    return res;
}


// 字符串大小写
void toLower(string& str){     // 将字符串中的大写字母转为小写字母
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

void toUpper(string& str){     // 将字符串中的小写字母转为大写字母
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 'a' + 'A';
        }
    }
}


