#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

/* 北京理工大学复试上机题 */   

// 北京理工大学机试题T1 表达式求值 未完成！
void BIT_1(){ 

}

// 北京理工大学机试题T2 等腰梯形
void BIT_2(){
    int h;
    while(cin >> h){
        int bottom = h + 2 * (h - 1);
        int gap = h - 1;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < gap - i; j++){
                cout << " ";
            }
            for(int j = 0; j < h + 2 * i; j++){
                cout << "*";
            }
            for(int j = 0; j < gap - i; j++){
                cout << " ";
            }
            cout << endl;
        }
    }
}

// 北京理工大学机试题T3 字符大小写交替
string getStrByChar(char ch){
    string res = "";
    if('A' <= ch && ch <= 'Z'){
        ch = ch - 'A' + 'a';
    }
    for(char c = 'a'; c <= ch; c++){
        if((c - 'a') % 2 == 0){
            res += c - 'a' + 'A';
        }else{
            res += c;
        }
    }
    int len = res.size();
    for(int i = len - 2; i >= 0; i--){
        res += res[i];
    }
    return res;
}

void BIT_3(){
    char ch;
    while(cin >> ch){
        cout << getStrByChar(ch) << endl;
    }    
}

// 北京理工大学机试题T100 分段函数
double func(int x){
    double res = 0;
    if(0 <= x && x < 2){
        res = -x + 2.5;
    }else if(2 <= x && x < 4){
        res = 2.0 - 1.5 * (x - 3) * (x - 3);
    }else if(4 <= x && x < 6){
        res = x / 2.0 - 1.5;
    }
    return res;
}

void BIT_100(){
    int m, x;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> x;
        double res = func(x);
        printf("y=%0.1lf\n", res);
    }
}

// 北京理工大学机试题T101 整数和
void BIT_101(){
    int m, N;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> N;
        int res = 0;
        if(N > 0){
            for(int k = N; k <= 2 * N; k++){
                res += k;
            }
        }else{
            for(int k = 2 * N; k <= N; k++){
                res += k;
            }
        }
        cout << res << endl;
    }    
}

// 北京理工大学机试题T102 围圈报数 未完成！
void BIT_102(){

}

// 北京理工大学机试题T103 阶乘
void BIT_103(){
    int m, n;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> n;
        long long res = 1;
        for(int k = 1; k <= n; k++){
            res *= k;
        }
        cout << res << endl;
    }
}

// 北京理工大学机试题T104 球的计算
void BIT_104(){
    int m, x0, y0, z0, x1, y1, z1;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1;
        int sum = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0) + (z1 - z0) * (z1 - z0);
        double r = sqrt(sum);
        const double PI = 3.1415926;
        double vul = 4 * PI * r * r * r / 3.0;
        printf("%0.2lf %0.2lf\n", r, vul);
    }    
}

// 北京理工大学机试题T105 学生查询
struct Student{
    string name;
    string gender;
    int age;
};

void BIT_105(){
    int m, n;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> n;
        map<int, Student> map;
        int num, age;
        string name, gender;
        for(int k = 0; k < n; k++){
            cin >> num >> name >> gender >> age;
            map.insert(pair<int, Student>(num, {name, gender, age}));
        }
        cin >> num;
        Student stu = map[num];
        cout << num << " " << stu.name << " " << stu.gender << " " << stu.age << endl;
    }
}

// 北京理工大学机试题T106 计算天数
const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(int y){
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int getDayOfYear(int y){
    return isLeapYear(y) ? 366 : 365;
}

int getDayOfMonth(int y, int m){
    if(isLeapYear(y) && m == 2){
        return 29;
    }
    return days[m];
}

long long dateToDay(int y, int m, int d){
    long long res = 0;
    for(int i = 1; i < y; i++){
        res += getDayOfYear(i);
    }
    for(int i = 1; i < m; i++){
        res += getDayOfMonth(y, i);
    }
    res += d;
    return res;
}

void BIT_106(){ 
    int T, y, m, d;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> y >> m >> d;
        long long start = dateToDay(y, 1, 1);
        long long end = dateToDay(y, m, d);
        int res = end - start + 1;
        cout << res << endl;
    }
}

// 北京理工大学机试题T107 重载运算符
struct Angle{
    int angle;
    Angle(int a) : angle(a){}
    Angle operator=(const Angle& other){
        this->angle = other.angle;
        return *this;
    }
    friend double operator-(const Angle& A, const Angle& B){
        int sub = A.angle - B.angle;
        double res = sub * 3.1415926 / 180;
        return sin(res);
    }
};

void BIT_107(){
    int m, angle;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> angle;
        Angle A(angle);
        cin >> angle;
        Angle B(angle);
        double res = A - B;
        printf("%0.2lf\n", res);
    }
}

// 北京理工大学机试题T108 多项式的值
void BIT_108(){
    int m, n, x;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> n;
        vector<int> items(n + 1, 0);
        for(int k = 0; k < n + 1; k++){
            cin >> items[k];
        }
        long long res = 0;
        cin >> x;
        int product = 1;
        for(int k = 0; k < n + 1; k++){
            res += items[k] * product;
            product *= x;
        }
        cout << res << endl;
    }
}

// 北京理工大学机试题T110 复数
struct Complexity{
    int a;
    int b;
    Complexity() : a(0), b(0) {}
    Complexity(int x, int y) : a(x), b(y) {}
    friend Complexity operator+(const Complexity& x, const Complexity& y){
        Complexity res;
        res.a = x.a + y.a;
        res.b = x.b + y.b;
        return res;
    } 
    friend ostream& operator<<(ostream& out, const Complexity& x){
        if(x.a == 0 && x.b == 0){
            out << 0;
            return out;
        }
        if(x.a != 0){
            out << x.a;
        }
        if(x.b > 0){
            out << "+" << x.b << "i";
        }else if(x.b < 0){
            out << x.b << "i";
        }
        return out;
    }
};

void BIT_110(){
    int m, x, y;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        Complexity A(x, y);
        cin >> x >> y;
        Complexity B(x, y);
        cout << A + B << endl;
    }
}

// 北京理工大学机试题T111 判断数字位置
void BIT_111(){ 
    int m;
    string str;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> str;
        int end = 0, len = str.size();
        while(end < len){
            if(isdigit(str[end])){
                cout << end + 1 << " ";
            }
            end++;
        }
        cout << endl;
    }
}

// 北京理工大学机试题T112 整型存储
void BIT_112(){
    string str;
    int count = 0;
    while (cin >> str) {
        if (str == "0" || count > 9) {
            break;
        }
        cout << str << " ";
        int left = 0, right = str.size() - 1;
        while (left < right) {
            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;
            left++;
            right--;
        }
        int end = 0;
        while (end < str.size()) {
            if (str[end] != '0') {
                break;
            }
            end++;
        }
        str = str.substr(end);
        cout << str << endl;
        count++;
    }
}

// 北京理工大学机试题T113 三角形相加
struct CTriangle {
    int x;
    int y;
    CTriangle(int _x, int _y) {
        x = _x;
        y = _y;
    }
    friend CTriangle operator+(const CTriangle& A, const CTriangle& B) {
        CTriangle res(0, 0);
        res.x = A.x + B.x;
        res.y = A.y + B.y;
        return res;
    }
    CTriangle operator=(const CTriangle& other) {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }
    friend ostream& operator<<(ostream& out, const CTriangle& A) {
        out << "A(0," << A.x << "),B(0,0),C(" << A.y << ",0)";
        return out;
    }
};

void BIT_113(){
    int m, n;
    CTriangle res(0, 0);
    cin >> m >> n;
    while (m != 0) {
        CTriangle A(m, n);
        res = res + A;
        cin >> m >> n;
    }
    if (m == 0 || n == 0) {
        cout << res << endl;
    }
}

// 北京理工大学机试题T114 弹地小球
void BIT_114(){ 
    int m, n;
    double H;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> H >> n;
        double sum = H;
        for(int k = 0; k < n; k++){
            sum += H;
            H = H / 2;
        }
        sum -= 2 * H;
        printf("%0.2lf\n", sum);
    }
}

// 北京理工大学机试题T115 点的距离
struct CPoint{
    int x;
    int y;
    CPoint(int _x, int _y) : x(_x), y(_y){}
    double operator-(const CPoint& other){
        int sub_x = x - other.x, sub_y = y - other.y;
        double sum = sub_x * sub_x + sub_y * sub_y;
        double res = sqrt(sum);
        return res;
    }
};

void BIT_115(){
    int m, x, y;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        CPoint A(x, y);
        cin >> x >> y;
        CPoint B(x, y);
        double res = A - B;
        printf("%0.2lf\n", res);
    }
}

// 北京理工大学机试题T116 直角三角形
void BIT_116(){
    int m, x1, y1, x2, y2, x3, y3;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int p_x = x1 - x2, q_x = x2 - x3, r_x = x3 - x1;
        int p_y = y1 - y2, q_y = y2 - y3, r_y = y3 - y1;
        int a = p_x * p_x + p_y * p_y;
        int b = q_x * q_x + q_y * q_y;
        int c = r_x * r_x + r_y * r_y;
        if(a + b == c || a + c == b || b + c == a){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
        double res = sqrt(a) + sqrt(b) + sqrt(c);
        printf("%0.2lf\n", res);
    }
}

// 北京理工大学机试题T118 编排字符串
void BIT_117(){
    int m;
    vector<string> items;
    cin >> m;
    string str;
    for(int i = 0; i < m; i++){
        cin >> str;
        items.insert(items.begin(), str);
        for(int k = 0; k < items.size(); k++){
            if(k > 3){
                break;
            }
            cout << k + 1 << "=" << items[k] << " ";
        }
        cout << endl;
    }
}

// 北京理工大学机试题T119 分组统计 未完成！
void BIT_119(){
    
}

// 北京理工大学机试题T120 单词识别
void lowerCase(string& str){
    int end = 0, len = str.size();
    while(end < len){
        if('A' <= str[end] && str[end] <= 'Z'){
            str[end] = str[end] - 'A' + 'a';
        }
        end++;
    }
}

vector<string> split(const string& str){
    int start = 0, len = str.size();
    vector<string> res;
    for(int end = 0; end < len; end++){
        if(str[end] == ' ' || str[end] == '.'){
            res.push_back(str.substr(start, end - start));
            while(end < len && (str[end] == ' ' || str[end] == '.')){
                end++;
            }
            start = end;
        }
    }
    if(start < len){
        res.push_back(str.substr(start));
    }
    return res;
}

void BIT_120(){
    string str;
    while(getline(cin, str)){
        lowerCase(str);
        vector<string> items = split(str);
        map<string, int> map;
        for(auto & item : items){
            if(map.find(item) == map.end()){
                map.insert(pair<string, int>(item, 1));
            }else{
                map[item]++;
            }
        }
        for(auto & pair : map){
            cout << pair.first << ":" << pair.second << endl;
        }
    }
}

// 北京理工大学机试题T121 加法等式
void BIT_121(){
    for(int a = 0; a <= 9; a++){
        for(int b = 0; b <= 9; b++){
            for(int c = 0; c <= 9; c++){
                int x = 100 * a + 10 * b + c;
                int y = 100 * b + 11 * c;
                if(x + y == 532){
                    cout << a << " " << b << " " << c << endl;
                }
            }
        }
    }
}

// 北京理工大学机试题T122 完数与盈数
int getSum(int num){
    int res = 0;
    for(int i = 1; i < num; i++){
        if(num % i == 0){
            res += i;
        }
    }
    return res;
}

void BIT_122(){
    vector<int> E_nums, G_nums;
    G_nums.push_back(2);
    for(int i = 2; i <= 60; i++){
        int sum = getSum(i);
        if(sum == i){
            E_nums.push_back(i);
        }else if(sum > i){
            G_nums.push_back(i);
        }
    }
    cout << "E: ";
    for(auto & it : E_nums){
        cout << it << " ";
    }
    cout << "G: ";
    for(auto & it : G_nums){
        cout << it << " ";
    }
    cout << endl;
}

// 北京理工大学机试题T123 反序相等
void BIT_123(){ 
    for(int N = 1000; N <= 9999; N++){
        int res = 0, x = N;
        while(x != 0){
            res = res * 10 + x % 10;
            x /= 10;
        }
        if(N * 9 == res){
            cout << N << endl;
        }
    }
}

// 北京理工大学机试题T124 邮票
void dfs_subset(const vector<int>& items, vector<int>& path, int start, vector<vector<int>>& res){
    res.push_back(path);
    for(int i = start; i < items.size(); i++){
        path.push_back(items[i]);
        dfs_subset(items, path, i + 1, res);
        path.pop_back();
    }
}

int calculateSum(const vector<int>& items){
    if(items.empty()){
        return 0;
    }
    int sum = 0;
    for(auto & it : items){
        sum += it;
    }
    return sum;
}

void BIT_124(){
    vector<int> items;
    for(int i = 0; i < 5; i++){
        items.push_back(8);
    }
    for(int i = 0; i < 4; i++){
        items.push_back(10);
    }
    for(int i = 0; i < 6; i++){
        items.push_back(18);
    }
    vector<int> path;
    vector<vector<int>> res;
    dfs_subset(items, path, 0, res);
    vector<int> count(189, 0);
    for(auto it : res){
        int sum = calculateSum(it);
        count[sum]++;
    }
    int result = 0;
    for(int i = 1; i < 189; i++){
        if(count[i] != 0){
            result++;
        }
    }
    cout << result << endl;
}

// 北京理工大学机试题T125 对称平方数
void BIT_125(){
    for(int n = 1; n < 256; n++){
        long long res = n * n;
        string str = to_string(res);
        int left = 0, right = str.size() - 1;
        bool flag = true;
        while(left < right){
            if(str[left] != str[right]){
                flag = false;
                break;
            }
            left++;
            right--;
        }
        if(flag){
            cout << n << endl;
        }
    }
}
