# 考研机试

**本项目所有题目来自牛客计算机考研题库**<a href="https://www.nowcoder.com/kaoyan" target="_blank">https://www.nowcoder.com/kaoyan</a>

## Chapter01 导论


## Chapter02 枚举与模拟
### 2.1 枚举
- 输入输出
```cpp
#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    while(cin >> n){    // 循环输入单个字符串，不含空格、换行符
        cout << n << endl;
    }
    string str;
    while(getline(cin, str)){  // 循环输入一行字符串，包含空格、换行符，需导入<string>库
        cout << str << endl;
    }
}
```

### 2.2 模拟
- 日期问题
```cpp
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 判断闰年
bool isLeapYear(int year){  
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 该月份的总天数
int getDaysOfMonth(int year, int month){    
    if(month == 2 && isLeapYear(year)){
        return 29;
    }
    return days[month];
}

// 该年份的总天数
int getDaysOfYear(int year) {
    return isLeapYear(year) ? 366 : 365;   
}

// 日期转总天数
long long dateToDays(int year, int month, int day){ //y-m-d转1-1-1到y-m-d之间的总天数
    long long res = 0;
    for(int i = 1; i < year; i++){
        res += getDaysOfYear(i);
    }
    for(int i = 1; i < month; i++){
        res += getDaysOfMonth(year, i);
    }
    res += day;
    return res;
}

// 总天数转日期
void daysToDate(long long days, int& year, int& month, int& day){ // 1-1-1到y-m-d之间的总天数转y-m-d
    long long res = 0;
    year = 1;
    while(true){
        int yd = getDaysOfYear(year);
        if(days > yd){
            days -= yd;
            year++;
        }else{
            break;
        }
    }
    month = 1;
    while(true){
        int md = getDaysOfMonth(year, month);
        if(days > md){
            days -= md;
            month++;
        }else{
            break;
        }
    }
    day = days;
}

// 两个日期相差天数
long long diffDays(int y1, int m1, int d1, int y2, int m2, int d2){
    long long days1 = dateToDays(y1, m1, d1);
    long long days2 = dateToDays(y2, m2, d2);
    return abs(days1 - days2);
}

// 求星期几
int getWeek(int year, int month, int day) {
    long long base = dateToDays(2026, 2, 15); // 2026年2月15日为星期日
    long long now = dateToDays(year, month, day);
    int wd = ((now - base) % 7 + 7) % 7;
    return wd;
}

// 打印日期
void printDate(int year, int month, int day){    
    cout << year << "-";
    if(month < 10){
        cout << "0";
    }
    cout << month << "-";
    if(day < 10){
        cout << "0";
    }
    cout << day << endl;
}
```


## Chapter03 排序与查找
### 3.1 排序
- sort函数
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int x, int y){
    return x > y;
}

int main(){
    int len;
    cin >> len;

    int* arr = new int[len];
    for(int i = 0; i < len; i++){
        arr[i] = len - i;
    }
    sort(arr, arr + len);  // 正序排序
    sort(arr, arr + len, compare); // 逆序排序

    vector<int> vec;
    for(int i = 0; i < len; i++){
        vec.push_back(len - i);
    }
    sort(vec.begin(), vec.end()); // 正序排序
    sort(vec.begin(), vec.end(), compare); // 逆序排序
}
```

- reverse函数
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    vector<int> vec;
    for(int i = 0; i < len; i++){
        vec.push_back(len - i);
    }
    reverse(vec.begin(), vec.end()); // 反转数组

    string str;
    cin >> str;
    reverse(str.begin(), str.end()); // 反转字符串
}
```

### 3.2 查找
- max_element函数与min_element函数
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    vector<int> vec;
    for(int i = 0; i < len; i++){
        vec.push_back(len - i);
    }
    if(!vec.empty()){
        int max_val = *max_element(vec.begin(), vec.end()); // 最大值
        int min_val = *min_element(vec.begin(), vec.end()); // 最小值
    }
}
```

- find函数
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int len, val;
    cin >> len >> val;

    vector<int> vec;
    for(int i = 0; i < len; i++){
        vec.push_back(len - i);
    }

    if(!vec.empty()){
        auto it = find(vec.begin(), vec.end(), val); // 查找元素，查找失败返回vec.end()
         if(it != vec.end()){ 
            cout << *it << endl;
        }
    }
}
```



## Chapter04 字符串
### 4.1 字符串
- string
```cpp
#include <iostream>
#include <string>
using namespace std;

int main(){
    string str, S, T;
    cin >> str >> S >> T;

    // 遍历
    for(int i = 0; i < str.size(); i++){ // 普通遍历
        cout << str[i] << " ";
    }
    cout << endl;

    for(string::iterator it = str.begin(); it != str.end(); it++){ // 迭代器遍历
        cout << *it << " ";
    }
    cout << endl;

    for(auto & it : str){ // 智能指针遍历
        cout << it << " ";
    }
    cout << endl;

    // 字符串长度
    cout << str.size() << endl;

    // 字符串判空
    cout << str.empty() << endl;

    // 字符串拼接
    str += S;
    cout << str << endl;

    // 字符串比较
    cout << (S < T) << " ";
    cout << (S > T) << " ";
    cout << (S == T) << " ";
    cout << (S != T) << " ";
    cout << endl;
    
    // 字符串与基本数据类型的转换
    // 字符串 -> 数字
    int num_i = stoi(str);
    long num_l = stol(str);
    double num_d = stod(str);

    // 数字 -> 字符串
    string str = to_string(num);

    // 字符串查找find(str, pos)
    int pos = str.find(S), len = S.size();
    if(pos != string::npos){
        cout << str.find(S) << endl; // 从str[0]开始查找字符串S，找到返回第一个字符串的下标，找不到返回string::npos
        cout << str.find(S, pos) << endl; // 从str[pos]开始查找字符串S，找到返回第一个字符串的下标，找不到返回string::npos
    }
    if(pos != string::npos){
        // rfind(S)：从字符串str的末尾开始反向查找子串S，找到则返回S最后一次出现的起始下标，找不到返回string::npos
        cout << str.rfind(S) << endl; 
        // rfind(S, pos)：从str的pos下标位置开始反向查找子串S，找到则返回S在[0,pos]范围内最后一次出现的起始下标，找不到返回string::npos
        cout << str.rfind(S, pos) << endl; 
    }

    // 取字符串子串substr(pos, len)
    if(pos != string::npos){
        string substr = str.substr(pos, len); // 从str[pos]开始，取长度为len的子串
        cout << substr << endl;
    }
    
    // 字符串替换replace(pos, len, str)
    if(pos != string::npos){
        str.replace(pos, len, T); // 从str[pos]开始，把长度为len的子串替换为T
        cout << str << endl;
    }

    // 删除字符串子串erase(pos, len)
    pos = str.find(T), len = T.size();
    if(pos != string::npos){
        str.erase(pos, len); // 从str[pos]开始，删除长度为len的子串
        cout << str << endl;
    }

    // 字符串清空
    str.clear();
    cout << str << endl;
}
```

### 4.2 字符串处理
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 字符串替换
void replaceAll(string& str, const string& S, const string& T){ // 将str中所有的S替换为T
    if(S.empty()){
        return;
    }
    size_t pos = 0;
    while((pos = str.find(S, pos)) != string::npos){
        str.replace(pos, S.size(), T);
        pos += T.size();
    }
}

// 字符串分割
vector<string> split(string str, char ch) { // 将str按ch为界分割
    vector<string> vec;
    int start = 0, len = str.size();
    for (int end = 0; end < len; end++) {
        if (str[end] == ch) {
            vec.push_back(str.substr(start, end - start));
            while (end < len && str[end] == ch) {
                end++;
            }
            start = end;
        }
    }
    if (start < len) {
        vec.push_back(str.substr(start));
    }
    return vec;
}

// 字符串大小写
void toLower(string& str){     // 将字符串中的大写字母转为小写字母
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

void toUpper(string& str){     // 将字符串中的小写字母转为大写字母
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 'a' + 'A';
        }
    }
}
```


## Chapter05 初级数据结构
### 5.1 向量
- vector
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> vec;
    int n, val;
    cin >> n >> val;

    // 初始化
    vec = {0, 1, 2, 3}; // 直接赋值
    vec = vector<int>(); // 初始化为空向量
    vec = vector<int>(n); // 长度为n，全部初始化为0
    vec = vector<int>(n, val); // 长度为n，全部初始化为val

    // 遍历
    for(int i = 0; i < vec.size(); i++){    // 普通遍历
        cout << vec[i] << " ";
    }
    cout << endl;

    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){ // 迭代器遍历
        cout << *it << " ";
    }
    cout << endl;

    for(auto & it : vec){   // 智能指针遍历
        cout << it << " ";
    }
    cout << endl;

    // 插入
    vec = vector<int>();
    for(int i = 0; i < n; i++){
        vec.push_back(i);   // 在末尾插入元素
    }
    vec.insert(vec.end(), n); // 在vec.end()后插入元素

    // 删除
    vec.pop_back(); // 删除末尾元素
    vec.erase(vec.begin()); // 删除vec.begin()的元素
    vec.erase(vec.begin(), vec.begin() + n); // 删除[vec.begin(), vec.begin() + n)区间内的元素

    // 清空
    vec.clear();

    // 预分配内存
    vec.reserve(n);  // 预分配长度为n的内存，提升性能
}
```

### 5.2 队列
- queue
```cpp
#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q;
    int n;
    cin >> n;

    // 入队
    for(int i = 0; i < n; i++){
        q.push(i);
    }
    
    // 出队
    q.pop();

    // 取队头
    int front = q.front();

    // 取队尾
    int back = q.back();

    // 判队空
    cout << q.empty() << endl;
}
```

### 5.3 栈
- stack
```cpp
#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> st;
    int n;
    cin >> n;

    // 入栈
    for(int i = 0; i < n; i++){
        st.push(i);
    }

    // 出栈
    st.pop();

    // 取栈顶
    int top = st.top();

    // 判栈空
    cout << st.empty() << endl;
}
```


## Chapter06 数学问题
### 6.1 进制转换
- 十进制数
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 取十进制数的反序数
long long reverse(long long num){   
    long long res = 0;
    while(num != 0){
        res = res * 10 + num % 10;
        num /= 10;
    }
    return res;
}

// 取十进制数各个位
vector<int> getDigit(long long num){  
    vector<int> vec;
    while(num != 0){
        vec.push_back(num % 10);
        num /= 10;
    }
    reverse(vec.begin(), vec.end());
    return vec;
}
```

- 进制转换
```cpp
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int CharToInt(char ch){     // 字符转数字
    int x;
    if('0' <= ch && ch <= '9'){
        x = ch - '0';
    }else if('a' <= ch && ch <= 'z'){
        x = ch - 'a' + 10;
    }else{
        x = ch = 'A' + 10;
    }
    return x;
}

char IntToChar(int x){      // 数字转字符
    char ch;
    if(x < 10){
        ch = x + '0';
    }else{
        ch = x - 10 + 'A';
    }
    return ch;
}

// M进制转N进制
string MtoN(string str, int M, int N){  
    unsigned long long temp = 0; // 十进制中间数
    // M进制转十进制
    for(int i = 0; i < str.size(); i++){
        temp = temp * M + CharToInt(str[i]);
    }
    // 十进制转N进制
    string res = "";
    stack<char> st;
    while(temp != 0){
        st.push(IntToChar(temp % N));
        temp = temp / N;
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}
```

- N进制整数加法
```cpp
#include <iostream>
#include <string>
using namespace std;

int CharToInt(char ch){     // 字符转数字
    int x;
    if('0' <= ch && ch <= '9'){
        x = ch - '0';
    }else if('a' <= ch && ch <= 'z'){
        x = ch - 'a' + 10;
    }else{
        x = ch = 'A' + 10;
    }
    return x;
}

char IntToChar(int x){      // 数字转字符
    char ch;
    if(x < 10){
        ch = x + '0';
    }else{
        ch = x - 10 + 'A';
    }
    return ch;
}

string add_N(string x, string y, int N) {  // N进制加法
    int carry = 0;
    string res = "";
    int i = x.size() - 1, j = y.size() - 1;
    while (i >= 0 && j >= 0) {
        int sum = CharToInt(x[i]) + CharToInt(y[j]) + carry;
        carry = sum / N;
        res = IntToChar(sum % N) + res;
        i--;
        j--;
    }
    while (i >= 0) {
        int sum = carry + CharToInt(x[i]);
        carry = sum / N;
        res = IntToChar(sum % N) + res;
        i--;
    }
    while (j >= 0) {
        int sum = carry + CharToInt(y[j]);
        carry = sum / N;
        res = IntToChar(sum % N) + res;
        j--;
    }
    if(carry > 0){
        res = "1" + res;
    }
    return res;
}
```

- 浮点数加法
```cpp
#include <iostream>
#include <string>
using namespace std;

void InitProcess(string& S, string& T) {
    int pos01 = S.find('.'), pos02 = T.find('.');
    while(pos01 < pos02){
        S = '0' + S;
        pos01++;
    }
    while(pos02 < pos01){
        T = '0' + T;
        pos02++;
    }
    int len01 = S.size(), len02 = T.size();
    while(len01 < len02){
        S = S + '0';
        len01++;
    }
    while(len02 < len01){
        T = T + '0';
        len02++;
    }
}

string FloatAdd(string S, string T) {
    InitProcess(S, T);
    int carry = 0;
    int len = S.size();
    string res = "";
    for (int i = len - 1; i >= 0; i--) {
        if (S[i] == '.') {
            res = '.' + res;
            continue;
        } else {
            int sum = S[i] - '0' + T[i] - '0' + carry;
            carry = sum / 10;
            res = char(sum % 10 + '0') + res;
        }
    }
    if (carry > 0) {
        res = '1' + res;
    }
    // 把字符串首部的所有0去掉
    int end;
    for (end = 0; end < res.size(); end++) {
        if (res[end] != '0') {
            break;
        }
    }
    res.erase(0, end);
    if (res[0] == '.') {
        res = '0' + res;
    }
    // 把字符串尾部的所有0去掉
    for (end = res.size() - 1; end >= 0; end--) {
        if (res[end] != '0') {
            break;
        }
    }
    res.erase(end + 1, res.size() - end - 1);
    if (res[res.size() - 1] == '.') {
        res = res + '0';
    }
    return res;
}
```



### 6.2 最大公约数与最小公倍数
- gcd与lcm
```cpp
#include <iostream>
using namespace std;

long long gcd(long long a, long long b){ // 最大公约数
    if(b == 0){
        return a;
    }else{
        return gcd(b, a % b);
    }
}

long long lcm(long long a, long long b){ // 最小公倍数
    return a / gcd(a, b) * b;
}
```

### 6.3 质数
- 判断质数
```cpp
#include <iostream>
using namespace std;

bool isPrime(long long num){ // 判断是否位质数
    if(num == 2){   // 2为质数
        return true;
    }else if(num < 2 || num % 2 == 0){  // 小于2的数与偶数都不是质数
        return false;
    }else{  // 从3开始，遍历奇数
        for(int i = 3; i * i <= num; i += 2){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
}
```

### 6.4 分解质因数
- 分解约数
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numOfDivisor(long long num){    // 求约数的个数
    int count = 0;
    long long i;
    for(i = 1; i * i < num; i++){
        if(num % i == 0){
            count += 2;
        }
    }
    if(i * i == num){
        count++;
    }
    return count;
}

vector<long long> getDivisor(long long num){    // 求所有的约数
    vector<long long> res;
    long long i;
    for(i = 1; i * i < num; i++){
        if(num % i == 0){
            res.push_back(i);
            res.push_back(num / i);
        }
    }
    if(i * i == num){
        res.push_back(i);
    }
    sort(res.begin(), res.end());
    return res;
}
``` 

- 分解质因数
```cpp
#include <iostream>
#include <vector>
using namespace std;

int numOfPrimeFactor(long long num){       // 求质因数的个数
    int count = 0;
    for(long long i = 2; i * i <= num; i++){
        if(num % i == 0){
            while(num % i == 0){
                num /= i;
                count++;
            }
        }
    }
    if(num > 1){    // num为质数
        count++;
    }
    return count;
}

vector<pair<long long, int>> getPrimeFactor(long long num){  // 求所有质因数及其指数
    vector<pair<long long, int>> res;
    for(long long i = 2; i * i <= num; i++){
        if(num % i == 0){
            int index = 0;  // 质因数的指数
            while(num % i == 0){
                num /= i;
                index++;
            }
            res.emplace_back(i, index);
        }
    }
    if(num > 1){  // num为质数
        res.emplace_back(num, 1);
    }
    return res;
}
```

### 6.5 快速幂
- 快速幂求x^y
```cpp
#include <iostream>
using namespace std;

int quickPow(long long x, long long y, int mod){    // 快速幂求 pow(x, y) % mod
    int res = 1;
    while(y != 0){
        if(y % 2 == 1){
            res = res * x % mod;
        }
        x = x * x % mod;
        y /= 2;
    }
    return res;
}
```


### 6.6 矩阵与矩阵快速幂
- 矩阵
```cpp
#include <iostream>
#include <vector>
using namespace std;

// 矩阵结构体
struct Matrix{
    vector<vector<long long>> matrix;
    int row, column;
    
    Matrix(int r, int c) {
        row = r;
        column = c;
        matrix = vector<vector<long long>>(r, vector<long long>(c, 0));
    }

    Matrix& operator=(const Matrix& A){
        if(this == &A){
            return *this;
        }
        row = A.row;
        column = A.column;
        matrix = vector<vector<long long>>(row, vector<long long>(column, 0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                matrix[i][j] = A.matrix[i][j];
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Matrix& A){
        int row = A.row, column = A.column;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                out << A.matrix[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    friend Matrix operator+(const Matrix& A, const Matrix& B){
        if(A.row != B.row || A.column != B.column){
            return Matrix(0, 0);
        }
        int row = A.row, column = A.column;
        Matrix C(row, column);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                C.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
            }
        }
        return C;
    }

    friend Matrix operator-(const Matrix& A, const Matrix& B){
        if(A.row != B.row || A.column != B.column){
            return Matrix(0, 0);
        }
        int row = A.row, column = A.column;
        Matrix C(row, column);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                C.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
            }
        }
        return C;
    }

    friend Matrix operator*(const Matrix& A, const Matrix& B){
        if(A.column != B.row){
            return Matrix(0, 0);
        }
        int row = A.row, column = B.column;
        Matrix C(row, column);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                C.matrix[i][j] = 0;
                for(int k = 0; k < A.column; k++){
                    C.matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
                }
            }
        }
        return C;
    }
};

// 矩阵快速幂
Matrix matrixQuickPow(Matrix A, int n){
    if (A.row != A.column) {
        return Matrix(0, 0);
    }
    int len = A.row;
    Matrix result(len, len);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (i == j) {
                result.matrix[i][j] = 1;
            } else {
                result.matrix[i][j] = 0;
            }
        }
    }
    while (n != 0) {
        if (n % 2 == 1) {
            result = result * A;
        }
        n /= 2;
        A = A * A;
    }
    return result;
}

// 矩阵快速幂取模操作
Matrix matrixMultiply_mod(const Matrix& A, const Matrix& B, int mod) {  // 取模矩阵乘法
    if (A.column != B.row) {
        return Matrix(0, 0);
    }
    int row = A.row, column = B.column;
    Matrix C(row, column);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            C.matrix[i][j] = 0;
            for (int k = 0; k < A.column; k++) {
                C.matrix[i][j] = (C.matrix[i][j] % mod + A.matrix[i][k] % mod * B.matrix[k][j] % mod) % mod;
            }
        }
    }
    return C;
}

Matrix matrixQuickPow_mod(Matrix A, int n, int mod) {  // 取模矩阵快速幂
    if (A.row != A.column) {
        return Matrix(0, 0);
    }
    int len = A.row;
    Matrix result(len, len);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (i == j) {
                result.matrix[i][j] = 1;
            } else {
                result.matrix[i][j] = 0;
            }
        }
    }
    while (n != 0) {
        if (n % 2 == 1) {
            result = matrixMultiply_mod(result, A, mod);
        }
        n /= 2;
        A = matrixMultiply_mod(A, A, mod);
    }
    return result;
}
```


### 6.7 高精度整数
- 高精度整数
```cpp
#include <iostream>
using namespace std;

// 高精度无符号整数
struct BigInteger{
    const static int MAX = 10000;
    int digit[MAX];
    int length;

    // 构造函数
    BigInteger(){
        memset(digit, 0, sizeof(digit));
        length = 0;
    }

    BigInteger(int x){
        memset(digit, 0, sizeof(digit));
        length = 0;
        if(x == 0){
            digit[length++] = x;
        }
        while(x != 0){
            digit[length++] = x % 10;
            x /= 10;
        }
    }

    BigInteger(string str){
        memset(digit, 0, sizeof(digit));
        length = str.size();
        for(int i = 0; i < length; i++){
            digit[i] = str[length - i - 1] - '0';
        }
    }

    BigInteger(const BigInteger& b){
        memset(digit, 0, sizeof(digit));
        length = b.length;
        for(int i = 0; i < length; i++){
            digit[i] = b.digit[i];
        }
    }

    // 赋值
    BigInteger& operator=(int x){
        memset(digit, 0, sizeof(digit));
        length = 0;
        if(x == 0){
            digit[length++] = x;
        }
        while(x != 0){
            digit[length++] = x % 10;
            x /= 10;
        }
        return *this;
    }

    BigInteger& operator=(string str){
        memset(digit, 0, sizeof(digit));
        length = str.size();
        for(int i = 0; i < length; i++){
            digit[i] = str[length - i - 1] - '0';
        }
        return *this;
    }

    BigInteger& operator=(const BigInteger& b){
        memset(digit, 0, sizeof(digit));
        length = b.length;
        for(int i = 0; i < length; i++){
            digit[i] = b.digit[i];
        }
        return *this;
    }

    // 输入输出
    friend istream& operator>>(istream& in, BigInteger& b){
        string str;
        in >> str;
        b = str;
        return in;
    }

    friend ostream& operator<<(ostream& out, const BigInteger& b){
        for(int i = b.length - 1; i >= 0; i--){
            out << b.digit[i];
        }
        return out;
    }

    // 比较
    friend bool operator==(const BigInteger& a, const BigInteger& b){
        if(a.length != b.length){
            return false;
        }
        for(int i = a.length - 1; i >= 0; i--){
            if(a.digit[i] != b.digit[i]){
                return false;
            }
        }
        return true;
    }

    friend bool operator<=(const BigInteger& a, const BigInteger& b){
        if(a.length < b.length){
            return true;
        }else if(a.length > b.length){
            return false;
        }else{
            for(int i = a.length - 1; i >= 0; i--){
                if(a.digit[i] == b.digit[i]){
                    continue;
                }else{
                    return a.digit[i] < b.digit[i];
                }
            }
            return true;
        }
    }

    friend bool operator>=(const BigInteger& a, const BigInteger& b){
        if(a.length > b.length){
            return true;
        }else if(a.length < b.length){
            return false;
        }else{
            for(int i = a.length - 1; i >= 0; i--){
                if(a.digit[i] == b.digit[i]){
                    continue;
                }else{
                    return a.digit[i] > b.digit[i];
                }
            }
            return true;
        }
    }

    friend bool operator!=(const BigInteger& a, const BigInteger& b){
        return !(a == b);
    }

    friend bool operator>(const BigInteger& a, const BigInteger& b){
        return !(a <= b);
    }

    friend bool operator<(const BigInteger& a, const BigInteger& b){
        return !(a >= b);
    }

    // 运算
    friend BigInteger operator+(const BigInteger& x, const BigInteger& y){
        BigInteger result;
        int carry = 0;
        for(int i = 0; i < x.length || i < y.length; i++){
            int current = carry + x.digit[i] + y.digit[i];
            result.digit[result.length++] = current % 10;
            carry = current / 10;
        }
        if(carry != 0){
            result.digit[result.length++] = carry;
        }
        return result;
    }

    friend BigInteger operator-(const BigInteger& x, const BigInteger& y){
        BigInteger result;
        if(x < y){
            return result;
        }
        int carry = 0;
        for(int i = 0; i < x.length; i++){
            int current = x.digit[i] - y.digit[i] - carry;
            if(current < 0){
                current += 10;
                carry = 1;
            }else{
                carry = 0;
            }
            result.digit[result.length++] = current;
        }
        while(result.digit[result.length - 1] == 0 && result.length > 1){  // x == y
            result.length--;
        }
        return result;
    }

    friend BigInteger operator*(const BigInteger& x, const BigInteger& y){
        BigInteger result;  
        result.length = x.length + y.length;
        for (int i = 0; i < x.length; i++) {
            for (int j = 0; j < y.length; j++) {
                result.digit[i + j] += x.digit[i] * y.digit[j];
            }
        }
        for (int i = 0; i < result.length; i++) {
            result.digit[i + 1] += result.digit[i] / 10;  // 高位累加进位值
            result.digit[i] %= 10;                        // 本位保留余数（0-9）
        }
        while (result.digit[result.length - 1] == 0 && result.length > 1) {
            result.length--;
        }
        return result;
    }

    friend BigInteger operator/(const BigInteger& x, const BigInteger& y){
        BigInteger result;
        result.length = x.length;
        BigInteger remainder = 0;
        BigInteger temp = y;
        for (int i = x.length - 1; i >= 0; --i) {
            if (!(remainder.length == 1 && remainder.digit[0] == 0)) {
                for (int j = remainder.length - 1; j >= 0; --j) {
                    remainder.digit[j + 1] = remainder.digit[j];
                }
                remainder.length++;
            }
            remainder.digit[0] = x.digit[i];
            while (temp <= remainder) {
                remainder = remainder - temp;
                result.digit[i]++;
            }
        }
        while (result.digit[result.length - 1] == 0 && result.length > 1) {
            result.length--;
        }
        return result;
    }

    friend BigInteger operator%(const BigInteger& x, const BigInteger& y){
        BigInteger remainder = 0;
        BigInteger temp = y;
        for (int i = x.length - 1; i >= 0; --i) {
            if (!(remainder.length == 1 && remainder.digit[0] == 0)) {
                for (int j = remainder.length - 1; j >= 0; --j) {
                    remainder.digit[j + 1] = remainder.digit[j];
                }
                remainder.length++;
            }
            remainder.digit[0] = x.digit[i];
            while (temp <= remainder) {
                remainder = remainder - temp;
            }
        }
        return remainder;
    }
};

// 高精度无符号整数快速幂
BigInteger QuickPow(BigInteger b, int n){
    BigInteger res(1);
    while(n != 0){
        if(n % 2 == 1){
            res = res * b;
        }
        b = b * b;
        n /= 2;
    }
    return res;
}
```

## Chapter07 贪心


## Chapter08 递归与分治



## Chapter09 搜索
### 9.1 宽度优先搜索
- 通用模板
```cpp
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

// BFS核心框架
int bfs(初始状态) {
    // 1. 队列（存状态+步数）+ 判重（防循环）
    queue<状态类型> q;
    unordered_set<状态类型> visited;

    // 2. 初始状态入队+标记
    q.push(初始状态);
    visited.insert(初始状态);

    // 3. 层序遍历
    while (!q.empty()) {
        auto cur = q.front(); 
        q.pop();

        // 4. 终止条件：到达目标
        if (cur 是目标) {
            return cur.step;
        }

        // 5. 扩展新状态
        for (所有可能的操作) {
            新状态 = 对cur做操作;
            // 合法+未访问 → 入队+标记
            if (新状态合法 && !visited.count(新状态)) {
                visited.insert(新状态);
                q.push(新状态);
            }
        }
    }
    return -1; // 无解
}
```

- 迷宫最短路径问题
```cpp
#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int x;
    int y;
    int step;
};

vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs_maze(const vector<vector<int>>& maze, int sx, int sy, int end_x, int end_y, vector<pair<int, int>>& path){
    int row_len = maze.size(), col_len = maze[0].size();
    queue<Node> q;
    vector<vector<bool>> visited(row_len, vector<bool>(col_len, false));

    vector<vector<pair<int, int>>> parent(row_len, vector<pair<int, int>>(col_len, {-1, -1})); // 保存路径上的点的前驱结点
    
    q.push({sx, sy, 0});
    visited[sx][sy] = true;
    while(!q.empty()){
        Node node = q.front();
        q.pop();

        int cx = node.x, cy = node.y, step = node.step;
        if(cx == end_x && cy == end_y){
            int x = cx, y = cy;
            while(x != -1 && y != -1){
                path.push_back({x, y});
                pair<int, int> p = parent[x][y];
                x = p.first;
                y = p.second;
            }
            reverse(path.begin(), path.end());
            return step;
        }
        
        for(auto & dir : dirs){
            int nx = cx + dir[0], ny = cy + dir[1];
            if(nx >= 0 && nx < row_len && ny >= 0 && ny < col_len && !visited[nx][ny] && maze[nx][ny] == 0){
                visited[nx][ny] = true;
                parent[nx][ny] = {cx, cy};
                q.push({nx, ny, step + 1});
            }
            
        }
    }
    return -1;
}
```

### 9.2 深度优先搜索
- 子集问题
```cpp
#include <iostream>
#include <vector>
using namespace std;

// 子集问题模板
void dfs_subset(const vector<int>& items, vector<int>& path, int start, vector<vector<int>>& res){
    res.push_back(path);
    for(int i = start; i < items.size(); i++){
        // 选择
        path.push_back(items[i]);
        // 递归
        dfs_subset(items, path, i + 1, res);
        // 回溯
        path.pop_back();
    }
}

vector<vector<int>> subset(const vector<int>& items){
    vector<int> path;
    vector<vector<int>> res;
    dfs_subset(items, path, 0, res);
    return res;
}
```

- 组合问题
```cpp
#include <iostream>
#include <vector>
using namespace std;

// 组合问题模板
void dfs_combination(const vector<int>& items, vector<int>& path, int start, int target, vector<vector<int>>& res){
    // items存放待选择的元素、path存放选择的元素、res保存所有满足元素之和为target的path
    if(target == 0){
        res.push_back(path);
        return;
    }else if(target < 0){
        return;
    }
    for(int i = start; i < items.size(); i++){
        if(items[i] > target){
            continue;
        }
        // 选择
        path.push_back(items[i]);
        // 递归
        dfs_combination(items, path, i + 1, target - items[i], res);
        // 回溯
        path.pop_back();
    }
    // 组合问题为有约数条件的子集问题
}

vector<vector<int>> combination(const vector<int>& items, int target){
    vector<int> path;
    vector<vector<int>> res;
    dfs_combination(items, path, 0, target, res);
    return res;
}
```

- 全排列问题
```cpp
#include <iostream>
#include <vector>
using namespace std;

// 全排列问题模板
void dfs_permute(const vector<int>& items, vector<int>& path, vector<bool>& visited, vector<vector<int>>& res){
    if(path.size() == items.size()){
        res.push_back(path);
        return;
    }
    for(int i = 0; i < items.size(); i++){
        if(visited[i]){
            continue;
        }
        // 选择
        visited[i] = true;
        path.push_back(items[i]);
        // 递归
        dfs_permute(items, path, visited, res);
        // 回溯
        path.pop_back();
        visited[i] = false;
    }
}

vector<vector<int>> permute(const vector<int>& items){
    vector<int> path;
    vector<vector<int>> res;
    vector<bool> visited(items.size(), false);
    dfs_permute(items, path, visited, res);
    return res;
}
```

- 迷宫路径问题
```cpp
#include <iostream>
#include <vector>
using namespace std;

// 迷宫路径问题模板
vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs_maze(const vector<vector<int>>& maze, vector<pair<int, int>>& path, vector<vector<bool>>& visited, int x, int y, int end_x, int end_y, vector<vector<pair<int, int>>>& res){
    int row_len = maze.size(), col_len = maze[0].size();
    if(x < 0 || x >= row_len || y < 0 || y >= col_len || visited[x][y] || maze[x][y] == 1){
        return;
    }
    // 选择
    visited[x][y] = true;
    path.push_back({x, y});
    // 递归
    if(x == end_x && y == end_y) {
        res.push_back(path);
        return;
    } else {
        for(auto & dir : dirs){
            int new_x = x + dir[0], new_y = y + dir[1];
            dfs_maze(maze, path, visited, new_x, new_y, end_x, end_y, res);
        }
    }
    // 回溯
    path.pop_back();
    visited[x][y] = false;
}

vector<vector<pair<int, int>>> maze_path(const vector<vector<int>>& maze, int x, int y, int end_x, int end_y){
    vector<pair<int, int>> path;
    vector<vector<pair<int, int>>> res;
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    dfs_maze(maze, path, visited, x, y, end_x, end_y, res);
    return res;
}
```

- N皇后问题
```cpp
#include <iostream>
#include <vector>
using namespace std;

// N皇后问题模板
void dfs_NQueen(int N, int row, vector<int>& path, vector<bool>& col_used, vector<bool>& diag1, vector<bool>& diag2, vector<vector<int>>& res){
    // row为行数，col_used为列标记数组，diag1为主对角线标记数组，diag2为副对角线标记数组
    if(row == N){
        res.push_back(path);
        return;
    }
    for(int col = 0; col < N; col++){
        int d1 = row - col + N - 1;
        int d2 = row + col;
        if(col_used[col] || diag1[d1] || diag2[d2]){
            continue;
        }
        // 选择
        col_used[col] = true;
        diag1[d1] = true;
        diag2[d2] = true;
        path.push_back(col);
        // 递归
        dfs_NQueen(N, row + 1, path, col_used, diag1, diag2, res);
        // 回溯
        path.pop_back();
        col_used[col] = false;
        diag1[d1] = false;
        diag2[d2] = false;
    }
}

vector<vector<int>> NQueen(int N){
    vector<int> path;
    vector<vector<int>> res;
    // 行数列数为N，主对角线数副对角线数为2 * N - 1
    vector<bool> col_used(N, false), diag1(2 * N - 1, false), diag2(2 * N - 1, false); 
    dfs_NQueen(N, 0, path, col_used, diag1, diag2, res);
    return res;
}
```



## Chapter10 高级数据结构
### 10.1 二叉树



### 10.2 二叉搜索树



### 10.3 优先队列
- priority_queue



### 10.4 哈希表
- unordered_set



- unordered_map


## Chapter11 图论


## Chapter12 动态规划



"# ProgramTest_kaoyan" 
