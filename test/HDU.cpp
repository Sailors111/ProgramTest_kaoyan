#include <iostream>
#include <vector>
using namespace std;


/* 杭州电子科技大学复试上机题 */    // 进度：3/3


// 杭州电子科技大学机试题T1 上楼梯
void HDU_1(){
    int T, N;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N;
        if(N < 3){
            cout << N << endl;
            continue;
        }else if(N == 3){
            cout << 4 << endl;
            continue;
        }
        vector<int> dp(N + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i = 4; i < N + 1; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3]; 
        }
        cout << dp[N] << endl;
    }
}


// 杭州电子科技大学机试题T2 字符菱形
void HDU_2(){ 
    int n;
    while (cin >> n) {
        int len = 2 * n - 1;
        vector<vector<char>> graph(len, vector<char>(len, ' '));
        char ch = '*';
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < i + 1; k++) {
                graph[i][n - 1 + k] = ch;
                graph[i][n - 1 - k] = ch;
            }
        }
        for (int i = n; i < len; i++) {
            for (int k = 0; k < len - i; k++) {
                graph[i][n - 1 + k] = ch;
                graph[i][n - 1 - k] = ch;
            }
        }
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                cout << graph[i][j];
            }
            cout << endl;
        }
    }
}


// 杭州电子科技大学机试题T3 最大公约数和最小公倍数
long long gcd(long long a, long long b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a % b);
    }
}

long long lcm(long long a, long long b){
    return a / gcd(a, b) * b;
}

void HDU_3(){
    long long n, m;
    while(cin >> n >> m){
        cout << gcd(n, m) << " " << lcm(n, m) <<endl;
    }
}

