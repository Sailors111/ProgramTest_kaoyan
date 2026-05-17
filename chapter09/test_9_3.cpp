#include <iostream>
#include <queue>
#include "test_9_3.hpp"
using namespace std;

/* 9.3 优先队列 */  

/* 9.3.1 顺序问题 */

// 北京邮电大学机试题T108 复数集合 
struct Complexity {
    int x;
    int y;
    Complexity(int _x, int _y) : x(_x), y(_y) {}
    long long getMod() const {
        return x * x + y * y;
    }
    bool operator<(const Complexity& other) const {
        if (getMod() == other.getMod()) {
            return y > other.y;
        }
        return getMod() < other.getMod();
    }
};

void BUP_108(){
    int n;
    string str;
    while (cin >> n) {
        priority_queue<Complexity> pq;
        for (int i = 0; i < n; i++) {
            cin >> str;
            if (str == "Pop") {
                if (pq.empty()) {
                    cout << "empty" << endl;
                } else {
                    Complexity top = pq.top();
                    pq.pop();
                    cout << top.x << "+i" << top.y << endl;
                    cout << "SIZE = " << pq.size() << endl;
                }
            } else if (str == "Insert") {
                int x, y;
                scanf("%d+i%d", &x, &y);
                Complexity new_node(x, y);
                pq.push(new_node);
                cout << "SIZE = " << pq.size() << endl;
            }
        }
    }
}

// 北京邮电大学机试题T103 查找第K小的数 
struct Compare_Int{
    bool operator()(const int x, const int y){
        return x > y;
    }
};

void BUP_103(){
    int n;
    while(cin >> n){
        priority_queue<int, vector<int>, Compare_Int> pq;
        int val, count = 0;
        for(int i = 0; i < n; i++){
            cin >> val;
            pq.push(val);
        }
        cin >> count;
        int top = pq.top();
        for(int i = 1; i < count; i++){
            while(top == pq.top()){
                pq.pop();
            }
            top = pq.top();
            pq.pop();
        }
        cout << top << endl;
    }
}

/* 9.3.2 哈夫曼树 */

// 北京邮电大学机试题T101 哈夫曼树 
void BUP_101(){
    int n;
    while (cin >> n) {
        vector<int> weight(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> weight[i];
        }
        HTNode* root = createHTree(weight);
        int result = calculateWPL(root, 0);
        cout << result << endl;
    }
}

// 吉林大学机试题T179 搬水果 
void JLU_179(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        vector<int> weight(n, 0);
        int val;
        for(int i = 0; i < n; i++){
            cin >> weight[i];
        }
        HTNode* root = createHTree(weight);
        int result = calculateWPL(root, 0);
        cout << result << endl;
    }
}

