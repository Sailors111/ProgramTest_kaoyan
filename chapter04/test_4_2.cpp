#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 4.2 字符串处理 */    

// 清华大学机试题T117 特殊乘法
void TsingHua_117(){
    int x, y;
    while (cin >> x >> y) {
        string str_x = to_string(x), str_y = to_string(y);
        int len_x = str_x.size(), len_y = str_y.size();
        int* arr_x = new int[len_x], *arr_y = new int[len_y];
        int i = 0, j = 0;
        for (string::iterator it = str_x.begin(); it != str_x.end(); it++) {
            arr_x[i] = *it - '0';   // 数字字符串转int型
            i++;
        }
        for (string::iterator it = str_y.begin(); it != str_y.end(); it++) {
            arr_y[j] = *it - '0';
            j++;
        }
        int sum = 0;
        for (int i = 0; i < len_x; i++){
            for(int j = 0; j < len_y; j++){
                sum += arr_x[i] * arr_y[j];
            }
        }
        printf("%d\n", sum);
    }
}

// 北京大学机试题T105 密码翻译
void PeKing_105(){
    string str;
    while(cin >> str) {
        for(string::iterator it = str.begin(); it != str.end(); it++){
            if(*it == 'z' || *it == 'Z'){
                (*it) -= 25;
            } else if ((*it) >= 'a' && (*it) < 'z' || (*it) >= 'A' && (*it) < 'Z'){
                (*it)++;
            }
        }
        cout << str << " ";
    }
}

// 北京大学机试题T161 简单密码
void PeKing_161(){
    string str;
    while (getline(cin, str)) {
        if (str == "ENDOFINPUT") {
            break;
        } else {
            getline(cin, str);   // 读入一行字符串
            for (string::iterator it = str.begin(); it != str.end(); it++) {
                if ('A' <= (*it) && (*it) <= 'E') {
                    (*it) += 'V' - 'A';
                } else if ('F' <= (*it) && (*it) <= 'Z') {
                    (*it) -= 'F' - 'A';
                }
            }
            cout << str << endl;
            getline(cin, str);
        }
    }
}

// 浙江大学机试题T111 统计字符
void ZJU_111(){
    string S, T;         // S为主串，T为模式串
    while(getline(cin, T)){
        if(T == "#"){
            break;
        }else{
            getline(cin, S);
            for(string::iterator it_i = T.begin(); it_i != T.end(); it_i++){
                int count = 0;
                for(string::iterator it_j = S.begin(); it_j != S.end(); it_j++){
                    if(*it_i == *it_j){
                        count++;
                    }
                }
                cout << *it_i << " " << count <<endl;
            }
        }
    }
}

// 上海交通大学机试题T122 字母统计
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
            cout << char('A' + i) << ":" <<count[i] << endl;
        }
    }
}

// 北京大学机试题T117 skew数
int _pow(int x, int index){
    int product = 1;
    for(int i = 0; i < index; i++){
        product *= x;
    }
    return product;
}

void PeKing_117(){
    string str;
    while(cin >> str){
        int len = str.size();
        int* skew = new int[len];
        for(int i = 0; i < len; i++){
            skew[i] = str[i] - '0';
        }
        int skew_num = 0;
        for(int i = 0; i < len; i++){
            skew_num += skew[i] * (_pow(2, len - i) - 1);
        }
        cout << skew_num << endl;
    }
}

// 北京大学机试题T118 单词替换
vector<string> StringToVector(string str) {
    vector<string> vec;
    int start = 0, len = str.size();
    for (int end = 0; end < len; end++) {
        if (str[end] == ' ') {
            vec.push_back(str.substr(start, end - start));
            while (end < len && str[end] == ' ') {
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

void PeKing_118(){
    string str;
    while (getline(cin, str)) {
        string S, T;    // S为被替换的字符串，T为替换S的字符串
        getline(cin, S);
        getline(cin, T);
        vector<string> vec = StringToVector(str);
        for (auto& it : vec) {
            if (it == S) {
                it = T;
            }
        }
        str.clear();
        for (auto& it : vec) {
            str += it + " ";
        }
        cout << str << endl;
    }
}

// 北京大学机试题T129 首字母大写
void PeKing_129(){
    string str;
    while(getline(cin, str)){
        int start = 0, len = str.size();
        for(int end = 0; end < len; end++){
            if(str[end] == ' ' || str[end] == '\t' || str[end] == '\r' || str[end] == '\n'){
                if(end + 1 < len && 'a' <= str[end + 1] && str[end + 1] <= 'z'){
                    str[end + 1] -= 32;
                }
            }
        }
        if('a' <= str[0] && str[0] <= 'z'){
            str[0] -= 32;
        }
        cout << str << endl;
    }
}

// 北京大学机试题T150 浮点数加法
int is_carry(int x){    // 判断是否进位
    return x >= 10 ? 1 : 0;
}

int point_pos(string str){      // 获取小数点所在的下标
    int len = str.size();
    for(int end = 0; end < len; end++){
        if(str[end] == '.'){
            return end;
        }
    }
    return -1;
}

struct Result{
    string result_str;
    int carry;
};

Result processFloat(string str1, string str2){   // 处理小数部分
    if(str1.size() > str2.size()){
        string temp = str1;
        str1 = str2;
        str2 = temp;
    }
    int len, len1 = str1.size(), len2 = str2.size();
    Result result = { 
        "", 0 
    };
    if(len1 < len2){
        string substr = str2.substr(len1, len2 - len1);
        result.result_str = substr + result.result_str;
    }
    len = len1;
    for(int i = len - 1; i >= 0; i--){
        int x = str1[i] - '0' + str2[i] - '0' + result.carry;
        int sum = x % 10;
        result.carry = is_carry(x);
        result.result_str = to_string(sum) + result.result_str;
    }
    return result;
}

Result processInt(string str1, string str2, int carry){   // 处理整数部分
    if(str1.size() > str2.size()){
        string temp = str1;
        str1 = str2;
        str2 = temp;
    }
    int len1 = str1.size(), len2 = str2.size();
    Result result = {
        "", carry
    };
    int len = len1;
    for(int i = len - 1; i >= 0; i--){
        int x = str1[i] - '0' + str2[len2 - len1 + i] - '0' + result.carry;
        int sum = x % 10;
        result.carry = is_carry(x);
        result.result_str = to_string(sum) + result.result_str;
    }
    if(len1 < len2){
        len = len2 - len1;
        for(int i = len2 - len1 - 1; i >= 0; i--){
            int x = str2[i] - '0' + result.carry;
            int sum = x % 10;
            result.carry = is_carry(x);
            result.result_str = to_string(sum) + result.result_str;
        }
    }
    if(result.carry){
        result.result_str = "1" + result.result_str;
    }
    return result;
}

void PeKing_150(){
    string str1, str2;
    while(cin >> str1 >> str2){
        int len1 = str1.size(), len2 = str2.size();
        int pos1 = point_pos(str1), pos2 = point_pos(str2);
        string int_str1 = str1.substr(0, pos1), float_str1 = str1.substr(pos1 + 1, len1 - pos1 - 1);
        string int_str2 = str2.substr(0, pos2), float_str2 = str2.substr(pos2 + 1, len2 - pos2 - 1);

        Result result_float = processFloat(float_str1, float_str2);
        Result result_int = processInt(int_str1, int_str2, result_float.carry);

        string result = result_int.result_str + "." + result_float.result_str;
        cout << result << endl;
    }
}

// 上海交通大学机试题T124 后缀子串排序
bool compare(string x, string y){     // 字符串升序比较
    return x < y;
}

void SJU_124(){
    string str;
    while(cin >> str){
        int len = str.size();
        vector<string> vec;
        for(int i = 0; i < len; i++){
            vec.push_back(str.substr(i, len - i));
        }
        sort(vec.begin(), vec.end(), compare);
        for(int i = 0; i < vec.size(); i++){
            cout << vec[i] << endl;
        }
    }
}

