#include <iostream>
using namespace std;

/* 2.2 模拟 */   

/* 2.2.1 图形排版  */

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

// 北京大学机试题T130 Repeater //未完成！
void PeKing_130(){
    // 未完成！
    int N, scale;
    scanf("%d", &N);
    char** ch = new char*[N];
    for(int i = 0; i < N; i++){
        ch[i] = new char[N];
    }
    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%c", &ch[i][j]);
            count++;
        }
    }
    printf("%d\n", count);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%c", ch[i][j]);
        }
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


/* 2.2.2 日期问题 */

int isLeapYear(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); // 是否为闰年
}

int numberOfYear(int year) {
    return isLeapYear(year) ? 366 : 365;   //该年份的总天数
}

// 清华大学机试题T118 今年的第几天？
void TsingHua_118(){
    int year,month,day;
    int date[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while(scanf("%d %d %d",&year, &month, &day)!=EOF){
        int sum = 0;
        if(month == 1) {
            sum = day;
        }
        else if(month == 2){
            sum = 31 + day;
        }
        else{
            for(int i = 0; i < month - 1; i++){
                sum += date[i];
            }
            if(isLeapYear(year) == 1){
                sum++;
            }
            sum += day;
        } 
        printf("%d\n", sum);
    }
}

// 华中科技大学机试题T118 打印日期
void HUS_118(){
    int year, n;
    int date[2][12] = {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    while (scanf("%d %d", &year, &n) != EOF) {
        int sum = 0 ,i = 0;
        int row = isLeapYear(year);
        int month, day;
        while(n > sum){
            sum += date[row][i];
            i++;
        }
        sum -= date[row][i-1];
        month = i;
        day = n - sum;
        printf("%d-",year);
        if(month < 10){
            printf("0");
        }
        printf("%d-", month);
        if(day < 10){
            printf("0");
        }
        printf("%d\n", day);
    }
}

// 北京理工大学机试题T117 日期累加
void BI_117(){
    int date[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    int num;
    int year, month, day, addDate;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d %d %d %d", &year, &month, &day, &addDate);
        int row = isLeapYear(year);
        for (int i = 0; i < month; i++) {
            addDate += date[row][i];
        }
        addDate += day;
        while (addDate > numberOfYear(year)) {
            addDate -= numberOfYear(year);
            year++;
        }
        month = 0;
        row = isLeapYear(year);
        while (addDate > date[row][month]) {
            addDate -= date[row][month];
            month++;
        }
        day = addDate;
        printf("%d-", year);
        if (month < 10) {
            printf("0");
        }
        printf("%d-", month);
        if (day < 10) {
            printf("0");
        }
        printf("%d\n", day);
    }
}

// 上海交通大学机试题T120 日期差值
void SJU_120(){
    int y_m_d01, y_m_d02;

    int date[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    while (scanf("%d\n%d", &y_m_d01, &y_m_d02) != EOF) {
        if (y_m_d01 > y_m_d02) {
            int temp = y_m_d01;
            y_m_d01 = y_m_d02;
            y_m_d02 = y_m_d01;
        }

        int year01 = y_m_d01 / 10000;
        int month01 = (y_m_d01 % 10000) / 100;
        int day01 = y_m_d01 % 100;
        int year02 = y_m_d02 / 10000;
        int month02 = (y_m_d02 % 10000) / 100;
        int day02 = y_m_d02 % 100;

        int total = 0;  //日期差值总天数

        for (int i = year01 + 1; i < year02; i++) {  
            total += numberOfYear(i);
        }
        if (year01 < year02) {
            int all = numberOfYear(year01);
            int n = 0, row = isLeapYear(year01);
            for (int i = 0; i < month01; i++) {
                n += date[row][i];
            }
            n += day01;
            total += all - n + 1;
            row = isLeapYear(year02);
            n = 0;
            for (int i = 0; i < month02; i++) {
                n += date[row][i];
            }
            n += day02;
            total += n;
        }
        if (year01 == year02){
            int row = isLeapYear(year01);
            int n1 = 0, n2 = 0;
            for(int i = 0; i < month01; i++){
                n1 += date[row][i];
            }
            n1 += day01;
            for(int i = 0; i < month02; i++){
                n2 += date[row][i];
            }
            n2 += day02;

            total = n2 - n1 + 1;
        }
        printf("%d\n", total);
    }
}

// 上海交通大学机试题T117 Day Of Week //未完成！
void SJU_117(){
    
}

// 北京理工大学机试题T109 日期类
void BI_109(){
    int date[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int n = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int year,month,day;
        scanf("%d %d %d", &year, &month, &day);
        if(day == date[month]){
            day = 1;
            month++;
        }else{
            day++;
        }
        if(month == 13){
            month = 1;
            year++;
        }
        printf("%d-",year);
        if(month < 10){
            printf("0");
        }
        printf("%d-",month);
        if(day < 10){
            printf("0");
        }
        printf("%d\n",day);
    }
}


/* 2.2.3 其他模拟 */

// 清华大学机试题T124 剩下的树
void TsingHua_124(){
    int L, M;
    scanf("%d %d", &L, &M);
    int* tree = (int*)malloc(sizeof(int)*(L+1));
    for(int i = 0; i < L + 1; i++){
        tree[i] = 1;
    }
    int left, right;
    for(int i = 0; i < M; i++){
        scanf("%d %d", &left, &right);
        for(int j=left; j<=right; j++){
            tree[j] = 0;
        }
    }
    int total = 0;
    for(int i = 0; i < L+1; i++){
        if(tree[i] == 1){
            total++;
        }
    }
    printf("%d\n", total);
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
int _abs(int x){  // 绝对值
    return x >= 0 ? x : -x;
}

double _average(int x, int y){ // 平均值
    double sum = x + y;
    return sum / 2.0;
}

int _max(int x, int y, int z){ // 最大值
    if(x > y && x > z){
        return x;
    }else if(y > x && y > z){
        return y;
    }else {
        return z;
    }
}

void ZJU_104(){
    int P,T,G1,G2,G3,GJ;
    while(scanf("%d %d %d %d %d %d", &P, &T, &G1, &G2, &G3, &GJ) != EOF){
        double score = 0;
        if(_abs(G1 - G2) <= T){
            score = _average(G1, G2);
        }else{
            if(_abs(G3 - G1) <= T && _abs(G3 - G2) <= T){
                score = _max(G1, G2, G3);
            }else if(_abs(G3 - G1) > T && _abs(G3 - G2) > T){
                score = GJ;
            }else{
                if(_abs(G3 - G1) < _abs(G3 - G2)){
                    score = _average(G1, G3);
                }else{
                    score = _average(G2, G3);
                }
            }
        }
        printf("%0.1lf\n", score);
    }
}


