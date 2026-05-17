#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "test_3_1.hpp"
using namespace std;

/* 3.2 字符串匹配 */    

// 北京航空航天大学机试题T105 字符串匹配
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
        toLower(pattern);
        for (int i = 0; i < n; i++) {
            str = vec[i];
            toLower(str);
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


