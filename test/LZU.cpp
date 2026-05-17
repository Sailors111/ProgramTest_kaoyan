#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

/* 兰州大学复试上机题 */    // 进度：4/4


// 兰州大学机试题T1 哈夫曼树
struct HTNode{
    int weight;
    struct HTNode* left;
    struct HTNode* right;
    HTNode() : weight(0), left(nullptr), right(nullptr){}
    HTNode(int w, HTNode* l, HTNode* r){
        weight = w;
        left = l;
        right = r;
    }
    HTNode(HTNode* l, HTNode* r){
        weight = l->weight + r->weight;
        left = l;
        right = r;
    }
};

struct HTree_ptr{
    bool operator()(HTNode* x, HTNode* y){
        return x->weight > y->weight;
    }
};

HTNode* createHTree(const vector<int>& items){
    priority_queue<HTNode*, vector<HTNode*>, HTree_ptr> pq;
    for(int i = 0; i < items.size(); i++){
        auto* node = new HTNode(items[i], nullptr, nullptr);
        pq.push(node);
    }
    while(pq.size() != 1){
        auto* node1 = pq.top();
        pq.pop();
        auto* node2 = pq.top();
        pq.pop();
        auto* node = new HTNode(node1, node2);
        pq.push(node);
    }
    auto* root = pq.top();
    pq.pop();
    return root;
}

int calculateWPL(HTNode* root, int h){
    if(root == nullptr){
        return 0;
    }else if(root->left == nullptr && root->right == nullptr){
        return h * root->weight;
    }else{
        return calculateWPL(root->left, h + 1) + calculateWPL(root->right, h + 1);
    }
}

void LZU_1(){
    int n;
    while(cin >> n){
        vector<int> items(n, 0);
        for(int i = 0; i < n; i++){
            cin >> items[i];
        }
        HTNode* root = createHTree(items);
        int res = calculateWPL(root, 0);
        cout << res << endl;
    }
}


// 兰州大学机试题T2 句子正序
vector<string> split(const string& str){
    vector<string> res;
    int start = 0;
    for(int end = 0; end < str.size(); end++){
        if(str[end] == ' '){
            res.push_back(str.substr(start, end - start));
            while(end < str.size() && str[end] == ' '){
                end++;
            }
            start = end;
        }
    }
    if(start < str.size()){
        res.push_back(str.substr(start));
    }
    return res;
}

void LZU_2(){ 
    string str;
    while(getline(cin, str)){
        vector<string> items = split(str);
        int left = 0, right = items.size() - 1;
        while(left < right){
            string temp = items[left];
            items[left] = items[right];
            items[right] = temp;
            left++;
            right--;
        }
        for(auto & item : items){
            cout << item << " ";
        }
        cout << endl;
    }
}


// 兰州大学机试题T3 求三角形的面积

// 海伦公式：p = (a + b + c) / 2, S = sqrt(p * (p - a) * (p - b) * (p - c))，a、b、c为边长
// 坐标法：A(x1, y1), B(x2, y2)、C(x3, y3), S = abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;

void LZU_3(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int _abs = abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
        double area = double(_abs) / 2.0;
        printf("%0.2lf\n", area);
    }
}


// 兰州大学机试题T4 最大序列和
void LZU_4(){ 
    int n;
    while(cin >> n){
        vector<long long> items(n, 0);
        for(int i = 0; i < n; i++){
            cin >> items[i];
        }
        vector<long long> dp(n, 0);
        dp[0] = items[0];
        long long res = dp[0];
        for(int i = 1; i < items.size(); i++){
            dp[i] = max(items[i], dp[i - 1] + items[i]);
            res = max(dp[i], res);
        }
        cout << res << endl;
    }
}


