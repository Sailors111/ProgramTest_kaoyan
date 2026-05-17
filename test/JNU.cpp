#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

/* 暨南大学复试上机题 */ 

// 暨南大学机试题T1 单词逆序-1
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

void JNU_1(){
    string str;
    while(getline(cin, str)){
        vector<string> vec = split(str);
        int i = 0, j = vec.size() - 1;
        while(i < j){
            string temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            i++;
            j--;
        }
        string res = "";
        for(auto it : vec){
            res += it + " ";
        }
        cout << res << endl;
    }
}

// 暨南大学机试题T2 单词逆序-2
bool isWord(char ch) {
    if ('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z') {
        return true;
    }
    return false;
}

void JNU_2(){ 
    string str;
    while (getline(cin, str)) {
        int start = 0, end = 0;
        while (start < str.size() && end < str.size()) {
            while (end < str.size() && isWord(str[end])) {
                end++;
            }
            int i = start, j = end - 1;
            while (i < j) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
                i++;
                j--;
            }
            while (end < str.size() && !isWord(str[end])) {
                end++;
            }
            start = end;
        }
        cout << str << endl;
    }
}

// 暨南大学机试题T3 二分查找
int binary_search(const vector<int>& nums, int target){
    int left = 0, right = nums.size() - 1;
    while(left <= right){
        int mid = (right - left) / 2 + left;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}

void JNU_3(){
    int n, target;
    while(cin >> n >> target){
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        int res = binary_search(nums, target);
        cout << res << endl;
    }
}

// 暨南大学机试题T4 矩阵旋转
void JNU_4(){
    int n, m;
    while(cin >> n >> m){
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> matrix[i][j];
            }
        }
        vector<vector<int>> result(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                result[i][j] = matrix[n - 1 - j][i];
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
}

// 暨南大学机试题T5 爬楼梯
void JNU_5(){
    int n;
    while(cin >> n){
        vector<unsigned long long> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i < n + 1; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        cout << dp[n] << endl;
    }
}

// 暨南大学机试题T6 区间合并1
void JNU_6(){
    int a1, b1, a2, b2;
    while(cin >> a1 >> b1 >> a2 >> b2){
        if(a1 > b2 || a2 > b1){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }        
    }
}

// 暨南大学机试题T7 区间合并2（难）（本题[1, 2]和[2, 3]算重合，[1, 2]和[3, 4]算相邻，均可合并）
struct Round{
    long long left;
    long long right;
    Round() : left(0), right(0){}
    Round(long long l, long long r) : left(l), right(r){}
};

bool compare(Round x, Round y){
    return x.left < y.left;
}

bool merge(Round x, Round y, Round& res){ // 默认x在y左侧
    if(y.left - 1 <= x.right){
        res.left = x.left;
        res.right = max(x.right, y.right);
        return true;
    }
    return false;
}

void JNU_7(){
    int N;
    while(cin >> N){
        vector<Round> vec;
        vector<Round> res;
        long long x, y;
        for(int i = 0; i < N; i++){
            cin >> x >> y;
            Round a(x, y);
            vec.push_back(a);
        }
        sort(vec.begin(), vec.end(), compare);
        stack<Round> st;
        for(int i = vec.size() - 1; i >= 0; i--){
            st.push(vec[i]);
        }
        while(!st.empty()){
            if(st.size() == 1){
                res.push_back(st.top());
                st.pop();
                break;
            }
            Round a = st.top();
            st.pop();
            Round b = st.top();
            st.pop();
            Round c = {0, 0};
            if(merge(a, b, c)){
                st.push(c);
            }else{
                res.push_back(a);
                st.push(b);
            }
        }
        sort(res.begin(), res.end(), compare);
        for(auto round : res){
            cout << round.left << " " << round.right << endl;
        }
    }
}

// 暨南大学机试题T8 数组逆序
void JNU_8(){ 
    int n;
    while(cin >> n){
        vector<int> vec(n, 0);
        for(int i = 0; i < n; i++){
            cin >> vec[i];
        }
        for(int i = n - 1; i >= 0; i--){
            cout << vec[i] << " ";
        }
        cout << endl;
    }
}

// 暨南大学机试题T9 矩阵乘法
void JNU_9(){
    int n;
    while(cin >> n){
        vector<int> vec(n, 0);
        for(int i = 0; i < n; i++){
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        if(vec[0] == 0){
            int count = 0;
            for(int it : vec){
                if(it != 0){
                    break;
                }
                count++;
            }
            for(int i = count; i < vec.size(); i++){
                vec[i - count] = vec[i];
            }
            int len = n - count;
            while(len < vec.size()){
                vec[len++] = 0;
            }
        }
        for(auto it : vec){
            cout << it << " ";
        }
        cout << endl;
    }
}

// 暨南大学机试题T10 完全平方数（难）
void JNU_10(){
    int n;
    while(cin >> n){
        vector<int> nums;
        for(int i = 1; i * i <= n; i++){
            nums.push_back(i * i);
        }
        // 完全背包取最小值问题
        int len = nums.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < len; i++){
            for(int j = nums[i]; j <= n; j++){
                if(dp[j - nums[i]] != INT_MAX){
                    dp[j] = min(dp[j], dp[j - nums[i]] + 1);
                }
            }
        }
        cout << dp[n] << endl;
    }
}

// 暨南大学机试题T11 二元素数组
bool isPrime(int num){
    if(num == 2){
        return true;
    }else if(num % 2 == 0 || num < 2){
        return false;
    }else{
        for(int i = 3; i * i <= num; i += 2){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
}

vector<int> getPrime(int num){
    vector<int> res;
    res.push_back(2);
    for(int i = 3; i < num; i += 2){
        if(isPrime(i)){
            res.push_back(i);
        }
    }
    return res;
}

vector<pair<int, int>> twoSum(const vector<int>& items, int target) {
    vector<pair<int, int>> res;
    int left = 0, right = items.size() - 1;
    while (left <= right) {
        if (items[left] + items[right] == target) {
            res.emplace_back(items[left], items[right]);
            left++;
            right--;
        } else if (items[left] + items[right] < target) {
            left++;
        } else {
            right--;
        }
    }
    return res;
}

void JNU_11(){ 
    int n;
    while (cin >> n) {
        vector<int> items = getPrime(n);
        vector<pair<int, int>> res = twoSum(items, n);
        for(auto & pair : res){
            cout << pair.first << " " << pair.second << endl;
        }
    }
}

// 暨南大学机试题T12 逆序对的数量（难）未完成！
void JNU_12(){ 

}

// 暨南大学机试题T13 删除区间
bool _compare(pair<long long, long long> x, pair<long long, long long> y){
    return x.second < y.second;
}

int JNU_13(){
    int n, a, b;
    while(cin >> n){
        vector<pair<long long, long long>> items;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            items.emplace_back(a, b);
        }
        sort(items.begin(), items.end(), _compare);
        long long last = items[0].second, count = 1;
        for(int i = 1; i < n; i++){
            if(items[i].first > last){
                last = items[i].second;
                count++;
            }
        }
        cout << n - count << endl;
    }
}

// 暨南大学机试题T14 体重排序
struct Person{
    string name;
    double weight;
};

bool compare_p(Person x, Person y){
    if(x.weight == y.weight){
        return x.name < y.name;
    }
    return x.weight < y.weight;
}

void JNU_14(){
    int n;
    while(cin >> n){
        vector<Person> items;
        string name;
        double weight;
        for(int i = 0; i < n; i++){
            cin >> name >> weight;
            items.push_back({name, weight});
        }
        sort(items.begin(), items.end(), compare_p);
        for(auto p : items){
            cout << p.name << " ";
        }
        cout << endl;
    }
}
