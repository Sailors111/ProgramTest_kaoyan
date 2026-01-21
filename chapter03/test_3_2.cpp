#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/* 3.2 查找 */   

// 哈尔滨工业大学机试题T158 找x
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

// 北京邮电大学机试题T111 查找
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

// 北京邮电大学机试题T110 找最小数
struct Data{
    int x;
    int y;
};

void BUP_110(){
    int n;
    const int _INT_MAX = 0x7fffffff;
    while(scanf("%d", &n) != EOF){
        Data* arr = new Data[n];
        for(int i = 0; i < n; i++){
            scanf("%d%d", &arr[i].x, &arr[i].y);
        }
        int min_index, min_x = _INT_MAX, min_y = _INT_MAX;
        for(int i = 0; i < n; i++){
            if(arr[i].x < min_x){
                min_index = i;
                min_x = arr[i].x;
                min_y = arr[i].y;
            }else if(arr[i].x == min_x){
                if(arr[i].y < min_y){
                    min_index = i;
                    min_x = arr[i].x;
                    min_y = arr[i].y;
                }
            }
        }
        printf("%d %d\n", arr[min_index].x, arr[min_index].y);
    }
}

// 北京大学机试题T126 打印极值点下标
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

// 华中科技大学机试题T124 找位置
void HUS_124(){
    string str;
    while (cin >> str) {
        bool visited[128];
        for (int i = 0; i < 128; i++) {
            visited[i] = false;
        }
        int len = str.size();
        for (int i = 0; i < len; i++) {
            char ch = str[i];
            bool flag = false;
            for (int j = i + 1; j < len; j++) {
                if (ch == str[j]) {
                    flag = true;
                    break;
                }
            }
            if (flag && !visited[ch]) {
                visited[ch] = true;
                cout << ch << ":" << i;
                for (int j = i + 1; j < len; j++) {
                    if (ch == str[j]) {
                        cout << "," << ch << ":" << j;
                    }
                }
                cout << endl;
            }
        }
    }
}



