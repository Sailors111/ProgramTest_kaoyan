#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/* 6.1 简单贪心 */  

// 北京大学机试题T158 鸡兔同笼 
void PeKing_158(){
    int total;
    while(cin >> total){
        int min, max;
        if(total == 0 || total % 2 == 1) {
            min = max = 0;
        } else if(total == 2) {
            min = max = 1;
        } else {
            if(total % 4 == 0) {
                min = total / 4;
            } else {
                min = total / 4 + 1;
            }
            max = total / 2;
        }
        cout << min << " " << max << endl;
    }
}


// 清华大学机试题T103 代理服务器（难）
bool compare(pair<string, int> x, pair<string, int> y){
    return x.second > y.second;
}

void TsingHua_103(){
    int n, m;
    while (cin >> n) {
        // 输入
        vector<string> agents;  // 代理服务
        string str;
        for (int i = 0; i < n; i++) {
            cin >> str;
            agents.push_back(str);
        }
        cin >> m;
        vector<string> service(m);  // 待处理服务
        for (int i = 0; i < m; i++) {
            cin >> service[i];
        }

        // 代理只有一个且待服务序列中存在代理，无解
        if (n == 1 && find(service.begin(), service.end(), agents[0]) != service.end()) {
            cout << -1 << endl;
            continue;
        }

        int count = 0, pos = 0;
        string current_agent;   // 当前代理
        while (pos < m) {
            // 找当前代理
            unordered_map<string, int> last_pos;
            for (auto & agent : agents) {
                int p = pos;
                while (p < m && service[p] != agent) {  // 最远距离定义为该代理在待服务序列中第一个出现的位置
                    p++;
                }
                last_pos[agent] = p;
            }
            vector<pair<string, int>> temp(last_pos.begin(), last_pos.end());
            sort(temp.begin(), temp.end(), compare);
            // 切换代理
            current_agent = temp[0].first;

            // 遍历待处理服务
            int end = pos;
            while (end < m) {
                if (service[end] == current_agent) { // service[end]是当前代理
                    break;
                }
                end++;
            }

            if (end == m) { // 遍历完所有的待处理服务
                break;
            }

            // 切换次数加1
            count++;
            pos = end;
        }
        cout << count << endl;
    }
}



