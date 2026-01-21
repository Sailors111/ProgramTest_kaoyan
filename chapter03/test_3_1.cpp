#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 3.1 排序 */  


//华中科技大学机试题T106 排序
void HSU_106(){
    int n;
    scanf("%d",&n);
    int* arr = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr,arr + n);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 清华大学机试题T108 成绩排序1
struct Student{
    int number;
    int score;
};

bool compare(Student x,Student y){
    if(x.score == y.score){
        return x.number < y.number;
    }else{
        return x.score < y.score;
    }
}

void TsingHua_108(){
    int N;
    scanf("%d",&N);
    Student* arr = (struct Student*)malloc(N * sizeof(Student));
    for(int i = 0; i < N; i++){
        scanf("%d %d",&arr[i].number, &arr[i].score);
    }
    sort(arr, arr+N,compare);
    for(int i = 0; i < N; i++){
        printf("%d %d\n",arr[i].number, arr[i].score);
    }
    free(arr);
}

// 清华大学机试题T101 成绩排序2
struct User {
    string name;
    int score;
    int order;
};

bool compare_dec_User(User x, User y) {
    if (x.score == y.score) {
        return x.order < y.order;
    } else {
        return x.score > y.score;
    }
}

bool compare_inc_User(User x, User y) {
    if (x.score == y.score) {
        return x.order < y.order;
    } else {
        return x.score < y.score;
    }
}

void TsingHua_101(){
    int N, sort_mode;
    while (scanf("%d%d", &N, &sort_mode) != EOF) {
        User* arr = new User[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].name >> arr[i].score;
            arr[i].order = i;
        }
        if (sort_mode == 0) {
            sort(arr, arr + N, compare_dec_User);
        } else {
            sort(arr, arr + N, compare_inc_User);
        }
        for (int i = 0; i < N; i++) {
            cout << arr[i].name << " " << arr[i].score << endl;
        }
        delete []arr;
    }
}

// 华中科技大学机试题T107 特殊排序
void HSU_107(){
    int N;
    while (scanf("%d", &N) != EOF) {
        vector<int> vec(N);
        for (int i = 0; i < N; i++) {
            cin >> vec[i];
        }
        int len = vec.size();
        int max = *max_element(vec.begin(), vec.end());
        cout << max << endl;
        if (len == 1) {
            cout << -1 << endl;
        } else {
            for (auto it = vec.begin(); it != vec.end(); it++) {
                if (*it == max) {
                    vec.erase(it);
                    break;
                }
            }
            sort(vec.begin(), vec.end());
            for (int& it : vec) {
                cout << it << " ";
            }
            cout << endl;
        }
    }
}

// 北京大学机试题T138 整数奇偶排序
bool compare_inc_int(int x, int y){
    return x < y;
}

bool compare_dec_int(int x, int y){
    return x > y;
}

void PeKing_138(){
    int arr[10];
    while(cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4]>>arr[5]>>arr[6]>>arr[7]>>arr[8]>>arr[9]){
        int odds[10], evens[10];
        int i = 0, j = 0;
        for(int x = 0; x < 10; x++){
            if(arr[x] % 2 == 1){
                odds[i] = arr[x];
                i++;
            }else{
                evens[j] = arr[x];
                j++;
            }
        }
        sort(odds, odds + i, compare_dec_int);
        sort(evens, evens + j, compare_inc_int);
        for(int x1 = 0; x1 < i; x1++){
            cout << odds[x1] << " ";
        }
        for(int x2 = 0; x2 < j; x2++){
            cout << evens[x2] << " ";
        }
        cout << endl;
    }
}

// 北京大学机试题T109 小白鼠排队
struct Mouse{
    int weight;
    string color;
};

bool compare_Mouse(Mouse x, Mouse y){
    return x.weight > y.weight;
}

void PeKing_109(){
    int N;
    while(scanf("%d", &N) != EOF){
        Mouse* arr = new Mouse[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i].weight >> arr[i].color;
        }
        sort(arr, arr + N, compare_Mouse);
        for(int i = 0; i < N; i++){
            cout << arr[i].color << endl;
        }
        delete[] arr;
    }
}

