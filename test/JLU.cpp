#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

/* 吉林大学复试上机题 */    // 进度：7/8


// 吉林大学机试题T172 字符串的反码
void JLU_172(){
    string str;
    while(cin >> str){
        int index = 0;
        while(index < str.size()){
            if('a' <= str[index] && str[index] <= 'z'){
                int x = str[index] - 'a';
                str[index] = char('z' - x);
            }else if('A' <= str[index] && str[index] <= 'Z'){
                int x = str[index] - 'A';
                str[index] = char('Z' - x);
            }
            index++;
        }
        cout << str << endl;
    }
}


// 吉林大学机试题T173 三角形的边
void JLU_173(){
    int a, b, c;
    while(cin >> a >> b >> c){
        if(a == 0 || b == 0 || c == 0){
            break;
        }
        vector<int> vec;
        vec.push_back(a);
        vec.push_back(b);
        vec.push_back(c);
        sort(vec.begin(), vec.end());
        int min = vec[0], mid = vec[1], max = vec[2];
        int res = min + mid - max;
        cout << res << endl;
    }
}


// 吉林大学机试题T174 怪异的洗牌
void shift(vector<int>& items, int shift){
    vector<int> temp = vector<int>(items.begin(), items.end());
    int len = temp.size();
    items = vector<int>(len, 0);
    for(int i = shift; i < len; i++){
        items[i - shift] = temp[i];
    }
    for(int i = 0; i < shift; i++){
        items[len - shift + i] = temp[i];
    }
}

void flip(vector<int>& items){
    int left = 0, right = items.size();
    int mid = (right - left) / 2 + left;
    right = mid - 1;
    while(left < right){
        int temp = items[left];
        items[left] = items[right];
        items[right] = temp;
        left++;
        right--;
    }
}

void JLU_174(){ 
    int n, k;
    while(cin >> n >> k){
        if(n == 0 || k == 0){
            break;
        }
        vector<int> items;
        for(int i = 0; i < n; i++){
            items.push_back(i + 1);
        }
        int s;
        for(int i = 0; i < k; i++){
            cin >> s;
            shift(items, s);
            flip(items);
        }
        for(auto & item : items){
            cout << item << " ";
        }
        cout << endl;
    }
}


// 吉林大学机试题T175 连通图
void dfs(vector<vector<int>> matrix, vector<bool>& visited, int n, int start){
    visited[start] = true;
    for(int end = 0; end < n; end++){
        if(!visited[end] && matrix[start][end] == 1){
            dfs(matrix, visited, n, end);
        }
    }
}

void JLU_175(){
    int n, m, x, y;
    while(cin >> n >> m){
        if(n == 0 || m == 0){
            break;
        }
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            matrix[x-1][y-1] = 1;
            matrix[y-1][x-1] = 1;
        }
        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(matrix, visited, n, i);
                count++;
            }
        }
        if(count == 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}


// 吉林大学机试题T176 排列与二进制 未完成！
void JLU_176(){

}


// 吉林大学机试题T177 平方因子
void JLU_177(){
    int num;
    while(cin >> num){
        if(num == 0){
            break;
        }
        int i;
        for(i = 2; i * i <= num; i++){
            if(num % (i * i) == 0){
                break;
            }
        }
        if(i * i > num){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
}


// 吉林大学机试题T178 数字之和
void JLU_178(){
    int num;
    while(cin >> num){
        long long res1 = 0, res2 = 0;
        long long x = num;
        while(x != 0){
            res1 += x % 10;
            x /= 10;
        }
        x = num * num;
        while(x != 0){
            res2 += x % 10;
            x /= 10;
        }
        cout << res1 << " " << res2 << endl;
    }
}



