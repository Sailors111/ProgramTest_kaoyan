#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* 3.2 查找 */   // 进度：5/5

// 哈尔滨工业大学机试题T158 找x √
void HaGongDa_158(){
    int n;
    while(scanf("%d", &n) != EOF){
        int* arr = new int[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        int x, i;
        scanf("%d", &x);
        for(i = 0; i < n; i++){
            if(arr[i] == x){
                printf("%d\n", i);
                break;
            }
        }
        if(i >= n){
            printf("%d\n", -1);
        }
    }
}


// 北京邮电大学机试题T111 查找 √
void BUP_111(){
    int n;
    while(scanf("%d", &n) != EOF){
        int* arr = new int[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        int m;
        scanf("%d", &m);
        int* search = new int[m];
        for(int i = 0; i < m; i++){
            scanf("%d", &search[i]);
        }
        for(int i = 0; i < m; i++){
            bool flag = false;
            for(int j = 0; j < n; j++){
                if(arr[j] == search[i]){
                    flag = true;
                    break;
                }
            }
            if(flag == true){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
}


// 北京邮电大学机试题T110 找最小数 √
struct Data{
    int x;
    int y;
};

bool compare(Data d1, Data d2){
    if(d1.x == d2.x){
        return d1.y < d2.y;
    }
    return d1.x < d2.x;
}

void BUP_110(){
    int n;
    while(cin >> n){
        vector<Data> vec(n, {0, 0});
        for(int i = 0; i < n; i++){
            cin >> vec[i].x >> vec[i].y;
        }
        sort(vec.begin(), vec.end(), compare);
        Data min_data = vec[0];
        cout << min_data.x << " " << min_data.y << endl;
    }
}


// 北京大学机试题T126 打印极值点下标 √
bool is_extramal_max(int arr[], int x, int len) {  // 求极大值
    if(x == 0){
        return arr[x] > arr[x + 1];
    }else if(x == len - 1){
        return arr[x] > arr[x - 1];
    }else {
        return arr[x] > arr[x + 1] && arr[x] > arr[x - 1];
    }
}

bool is_extramal_min(int arr[], int x, int len) {  // 求极小值
    if(x == 0){
        return arr[x] < arr[x + 1];
    }else if(x == len - 1){
        return arr[x] < arr[x - 1];
    }else {
        return arr[x] < arr[x + 1] && arr[x] < arr[x - 1];
    }
}

void PeKing_126(){
    int k;
    while (scanf("%d", &k) != EOF) {
        int* arr = new int[k];
        for (int i = 0; i < k; i++) {
            scanf("%d", &arr[i]);
        }
        int* external = new int[k];
        int len = 0;
        for (int i = 0; i < k; i++) {
            if(is_extramal_max(arr, i, k) || is_extramal_min(arr, i, k)){
                external[len] = i;
                len++;
            }
        }
        for(int i = 0; i < len; i++){
            printf("%d ", external[i]);
        }
        printf("\n");
    }
}


// 华中科技大学机试题T124 找位置 √
void HUS_124(){
    string str;
    while (cin >> str) {
        vector<int> count(256, 0);
        for (char ch : str) {
            count[ch]++;
        }
        int index = 0;
        while(index < str.size()){
            if(count[str[index]] > 1){
                cout << str[index] << ":" << index;
                int k = index + 1;
                while(k < str.size()){
                    if(str[k] == str[index]){
                        cout << "," << str[k] << ":" << k;
                    }
                    k++;
                }
                cout << endl;
                count[str[index]] = 0;
            }
            index++;
        }
    }
}


