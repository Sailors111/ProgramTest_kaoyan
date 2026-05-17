#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
#include "test_1_2.hpp"
using namespace std;

/* 1.2 模拟 */   

/* 1.2.1 图形排版  */

// 清华大学机试题T201 输出梯形 
void TsingHua_201(){
    int h;
    scanf("%d",&h);
    for(int i = 0; i < h; i++){
        int x = 2 * h - 2 - i * 2;
        while(x != 0){
            printf(" ");
            x--;
        }
        x = h + i * 2;
        while(x != 0){
            printf("*");
            x--;
        }
        printf("\n");
    }
}

// 浙江大学机试题T131 Hello World for U 
void ZJU_131(){
    char str[80];
    while(scanf("%s", &str)!=EOF){
        int total_len = strlen(str);
        int left_right_len = total_len / 3;
        int bottom_len = total_len - 2 * left_right_len;
        if(left_right_len == bottom_len){
            left_right_len--;
            bottom_len += 2;
        }
        int gap = bottom_len - 2;
        int i = 0, j = total_len - 1, k = gap;
        while(i != j){
            if(left_right_len > 0) {
                k = gap;
                printf("%c", str[i]);
                while(k > 0){
                    printf(" ");
                    k--;
                }
                printf("%c\n", str[j]);
                i++;
                j--;
                left_right_len--;
            } else {
                printf("%c", str[i]);
                i++;
            }
        }
        printf("%c\n",str[j]);
    }
}


/* 1.2.2 日期问题 */

// 清华大学机试题T118 今年的第几天？
void TsingHua_118(){
    int y, m, d;
    while(cin >> y >> m >> d){
        int res = 0;
        for(int i = 1; i < m; i++){
            res += getDaysOfMonth(y, i);
        }
        res += d;
        cout << res << endl;
    }
}

// 华中科技大学机试题T118 打印日期 
void HUS_118(){
    int y, n;
    while(cin >> y >> n){
        int m = 1, d;
        while(n > getDaysOfMonth(y, m)){
            n -= getDaysOfMonth(y, m);
            m++;
        }
        d = n;
        printDate(y, m, d);
    }
}

// 北京理工大学机试题T117 日期累加 
void BIT_117(){
    int count, y, m, d, num;
    cin >> count;
    while(count > 0){
        cin >> y >> m >> d >> num;
        long long days = dateToDays(y, m, d) + num;
        daysToDate(days, y, m, d);
        printDate(y, m, d);
        count--;
    }
}

// 上海交通大学机试题T120 日期差值 
void SJU_120(){
    string x, y;
    while (cin >> x >> y) {
        int y1 = stoi(x.substr(0, 4)), m1 = stoi(x.substr(4, 2)), d1 = stoi(x.substr(6,2));
        int y2 = stoi(y.substr(0, 4)), m2 = stoi(y.substr(4, 2)), d2 = stoi(y.substr(6,2));
        long long res = diffDays(y1, m1, d1, y2, m2, d2);
        cout << res + 1 << endl;
    }
}

// 上海交通大学机试题T117 Day Of Week 
void SJU_117(){
    unordered_map<string, int> map = {
        {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4}, {"May", 5}, {"June", 6}, {"July", 7}, {"August", 8}, {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}
    };
    vector<string> Week = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    int y, m, d;
    string month;
    while(cin >> d >> month >> y){
        m = map[month];
        int wd = getWeek(y, m, d);
        cout << Week[wd] << endl;
    }
}

// 北京理工大学机试题T109 日期类 
void BIT_109(){
    int count, y, m, d;
    cin >> count;
    while(count > 0){
        cin >> y >> m >> d;
        long long days = dateToDays(y, m, d) + 1;
        daysToDate(days, y, m, d);
        printDate(y, m, d);
        count--;
    }
}


/* 1.2.3 其他模拟 */

// 清华大学机试题T124 剩下的树 
void TsingHua_124(){
    int L, M;
    while(cin >> L >> M){
        bool* tree = new bool[L + 1];
        for(int i = 0; i < L + 1; i++){
            tree[i] = true;
        }
        int left, right, count = 0;
        for(int i = 0; i < M; i++){
            cin >> left >> right;
            for(int j = left; j <= right; j++){
                if(tree[j] == true){
                    tree[j] = false;
                    count++;
                }
            }
        }
        cout << L + 1 - count << endl;
    }
}

// 清华大学机试题T105 手机键盘 
void TsingHua_105(){
    int keyboard[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
    char str[100];
    while (scanf("%s", &str) != EOF) {
        int time = 0;
        int i = 0;
        while(str[i] != '\0'){
            time += keyboard[str[i]-'a'];
            if(i != 0 && str[i] - str[i-1] == keyboard[str[i] - 'a'] - keyboard[str[i-1] - 'a']){
                time += 2;
            }
            i++;
        }
        printf("%d\n", time);
    }
}

// 浙江大学机试题T116 XXX定律 
void ZJU_116(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(n == 0){
            break;
        }
        int total = 0;
        while(n != 1){
            if(n % 2 == 1){
                n = 3 * n + 1;
            } 
            n = n / 2;
            total++;
        }
        printf("%d\n", total);
    }
}

// 浙江大学机试题T104 Grading 
double average(int x, int y){
    return double(x + y) / 2;
}

double max_in_three(int x, int y, int z){
    return double(max(max(x, y), z));
}

void ZJU_104(){
    int P, T, G1, G2, G3, GJ;
    while(cin >> P >> T >> G1 >> G2 >> G3 >> GJ){
        double score = 0;
        if(abs(G1 - G2) <= T){
            score = average(G1, G2);
        }else if(abs(G1 - G3) <= T && abs(G2 - G3) <= T){
            score = max_in_three(G1, G2, G3);
        }else if(abs(G1 - G3) <= T || abs(G2 - G3) <= T){
            score = abs(G1 - G3) < abs(G2 - G3) ? average(G1, G3) : average(G2, G3);
        }else{
            score = GJ;
        }
        printf("%0.1lf\n", score);
    }
}
