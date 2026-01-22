#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 4.3 字符串匹配 */    

// KMP算法实现
int* get_next(string str){
    int i = 0, j = -1, len = str.size();
    int* next = new int[len];
    next[0] = -1;
    while(i < len){
        if(j == -1 || str[i] == str[j]){
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    return next;
}

int KMP(string S, string T){
    int len_S = S.size(), len_T = T.size();
    int i = 0, j = 0;
    int* next = get_next(T);
    while(i < len_S && j < len_T){
        if(j == -1 || S[i] == T[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if(j == len_T) {
        return i - j;
    } else {
        return -1;
    }
}


// 北京航空航天大学机试题T105 字符串匹配
void translation(string &str){     // 将字符串中的大写字母转为小写字母
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

void BUA_105(){
    int n;
    while (cin >> n) {
        vector<string> vec;
        string str, pattern;
        for (int i = 0; i < n; i++) {
            cin >> str;
            vec.push_back(str);
        }
        cin >> pattern;
        translation(pattern);
        for (int i = 0; i < n; i++) {
            str = vec[i];
            translation(str);
            int a = 0, b = 0;
            while(a < str.size() && b < pattern.size()) {
                if(str[a] == pattern[b]) {
                    a++;
                    b++;
                } else if(pattern[b] == '[') {
                    int pos = pattern.find(str[a], b); // 从pattern[b]开始查找str[a]，返回下标pos
                    if(pos != string::npos) {    // 在pattern中[]内的字符中有str[a]
                        b = pattern.find(']', pos) + 1;
                        a++;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
            if(a == str.size() && b == pattern.size()){
                cout << i + 1 << " " << vec[i] << endl;
            }
        }
    }
}

// 上海交通大学机试题T100 String Matching
void SJU_100(){
    string test, pattern;
    while(cin >> test >> pattern){
        int shift = 0, count = 0;
        while(shift <= test.size() - pattern.size()){
            int i = shift, j = 0;
            while(i < test.size() && j < pattern.size()){
                if(test[i] == pattern[j]) {
                    i++;
                    j++;
                } else {
                    break;
                }
            }
            if(j == pattern.size()){
                count++;
            }
            shift++;
        }
        cout << count << endl;
    }
}

