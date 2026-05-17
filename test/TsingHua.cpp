#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

/* 清华大学复试上机题 */

// 清华大学机试题T1 公司
void TsingHua_1(){ 
    int n, m;
    while(cin >> n >> m){
        vector<int> a(n + 1, 0);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        map<int, pair<int, int>> map;
        int x, y;
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            if(map.find(x) == map.end()){
                map.insert(pair<int, pair<int, int>>({x, {a[y], 1}}));
            }else{
                map[x].first += a[y];
                map[x].second++; 
            }
        }
        int count = 0;
        for(auto & pair : map){
            int x = pair.second.second;
            if(a[pair.first] * x < pair.second.first){
                count++;
            }
        }
        cout << count << endl;
    }
}

// 清华大学机试题T14 Prime 
bool isPrime(unsigned int N){
    if(N == 2){
        return true;
    }else if(N % 2 == 0 || N < 2){
        return false;
    }else{
        for(int i = 3; i * i <= N; i += 2){
            if(N % i == 0){
                return false;
            }
        }
        return true;
    }
}

void TsingHua_14(){ 
    unsigned int N;
    while(cin >> N){
        long long res = N;
        queue<long long> q;
        for(int i = 1; i <= 9; i++){
            q.push(N * 10 + i);
        }
        while(!q.empty()){
            long long temp = q.front();
            q.pop();
            if(isPrime(temp)){
                res = temp;
                break;
            }
            for(int i = 0; i <= 9; i++){
                q.push(temp * 10 + i);
            }
        }
        cout << res << endl;
    }
}
