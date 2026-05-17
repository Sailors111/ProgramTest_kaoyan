#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "test_3_1.hpp"
using namespace std;


/* 4.2 字符串处理 */    //进度：10/10

// 清华大学机试题T117 特殊乘法 √
void TsingHua_117(){
    string str1, str2;
    while(cin >> str1 >> str2){
        int result = 0;
        for(int i = 0; i < str1.size(); i++){
            int x = str1[i] - '0';
            for(int j = 0; j < str2.size(); j++){
                int y = str2[j] - '0';
                result += x * y;
            }
        }
        cout << result << endl;
    }
}

// 北京大学机试题T105 密码翻译 √
void PeKing_105(){
    string str;
    while(getline(cin, str)){
        for(auto & it : str){
            if(it == 'z' || it == 'Z'){
                it -= 'Z' - 'A';
            }else if(('a' <= it && it < 'z') || ('A' <= it && it < 'Z')){
                it++;
            }
        }
        cout << str << endl;
    }
}

// 北京大学机试题T161 简单密码 √
void PeKing_161(){
    string str;
    while(getline(cin, str)){
        if(str == "ENDOFINPUT"){
            break;
        }
        getline(cin, str);
        for(int i = 0; i < str.size(); i++){
            if('A' <= str[i] && str[i] <= 'E'){
                str[i] = str[i] - 'A' + 'V';
            }else if('F' <= str[i] && str[i] <= 'Z'){
                str[i] = str[i] - 'F' + 'A';
            }
        }
        cout << str << endl;
        getline(cin, str);
    }
}

// 浙江大学机试题T111 统计字符 √
void ZJU_111(){
    string S, T;         // S为主串，T为模式串
    while(getline(cin, T)){
        if(T == "#"){
            break;
        }
        getline(cin, S);
        for(char ch : T){
            int pos = 0, count = 0;
            while((pos = S.find(ch, pos)) != string::npos){
                count++;
                pos++;
            }
            cout << ch << " " << count << endl;
        }
    }
}

// 上海交通大学机试题T122 字母统计 √
void SJU_122(){
    string str;
    while(getline(cin, str)){
        int len = str.size();
        int count[26];
        for(int i = 0; i < 26; i++){
            count[i] = 0;
        }
        for(int i = 0; i < len; i++){
            if('A' <= str[i] && str[i] <= 'Z'){
                count[str[i] - 'A']++;
            }
        }
        for(int i = 0; i < 26; i++){
            cout << char('A' + i) << ":" << count[i] << endl;
        }
    }
}

// 北京大学机试题T117 skew数 √
void PeKing_117(){
    string str;
    while(cin >> str){
        long long pow = 2, result = 0;
        for(int i = str.size() - 1; i >= 0; i--){
            result += (str[i] - '0') * (pow - 1);
            pow *= 2;
        }
        cout << result << endl;
    }
}

// 北京大学机试题T118 单词替换 √
void PeKing_118(){
    string str, S, T;
    while(getline(cin, str)){
        cin >> S >> T;
        vector<string> vec = split(str, ' ');
        for(auto & it : vec){
            if(it == S){
                it = T;
            }
        }
        str.clear();
        for(auto & it : vec){
            str += it + " ";
        }
        cout << str << endl;
    }
}

// 北京大学机试题T129 首字母大写 √
void PeKing_129(){
    string str;
    while(getline(cin, str)){
        int start = 0, len = str.size();
        for(int end = 0; end < len; end++){
            if(str[end] == ' ' || str[end] == '\t' || str[end] == '\r' || str[end] == '\n'){
                if(end + 1 < len && 'a' <= str[end + 1] && str[end + 1] <= 'z'){
                    str[end + 1] -= 'a' - 'A';
                }
            }
        }
        if('a' <= str[0] && str[0] <= 'z'){
            str[0] -= 'a' - 'A';
        }
        cout << str << endl;
    }
}

// 北京大学机试题T150 浮点数加法 √
void PeKing_150(){
    string S, T;
    while (cin >> S >> T) {
        string res = FloatAdd(S, T);
        cout << res << endl;
    }
}

// 上海交通大学机试题T124 后缀子串排序 √
void SJU_124(){
    string str;
    while(cin >> str){
        vector<string> vec;
        for(int i = 0; i < str.size(); i++){
            vec.push_back(str.substr(i));
        }
        sort(vec.begin(), vec.end());
        for(auto str : vec){
            cout << str << endl;
        }
    }
}

