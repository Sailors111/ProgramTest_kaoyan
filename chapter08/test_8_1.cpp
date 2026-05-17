#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

/* 8.1 宽度优先搜索 */

// 清华大学机试题T111 玛雅人的密码 
string swap(string str, int i, int j) { // 交换字符串中的两个字符str[i]与str[j]
    string res = str;
    char temp = res[i];
    res[i] = res[j];
    res[j] = temp;
    return res;
}

int MayaCode(string str) {
    queue<string> q;
    unordered_set<string> visited;
    // 初始状态入队
    q.push(str);
    visited.insert(str);
    int count = 0;
    // 队列非空
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            // 出队
            string temp = q.front();
            q.pop();
            // 终止条件判断
            if (temp.find("2012") != string::npos) {
                return count;
            }
            // 新状态扩展
            for (int j = 1; j < temp.size(); j++) {
                string new_str = swap(temp, j - 1, j);
                // 判断重复
                if(!visited.count(new_str)){
                    // 新状态入队
                    visited.insert(new_str);
                    q.push(new_str);
                }
            }
        }
        count++;
    }
    return -1;
}

void TsingHua_111(){
    int N;
    string str;
    while (cin >> N >> str) {
        int res = MayaCode(str);
        cout << res << endl;
    }
}
