#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
using namespace std;


// 表达式求值
int priority(char ch){
    if(ch == '#'){
        return 0;
    }else if(ch == '$'){
        return 1;
    }else if(ch == '+' || ch == '-'){
        return 2;
    }else{
        return 4;
    }
}

double calculate(double x, double y, char op){
    double res;
    if (op == '+') {
        res = x + y;
    } else if (op == '-') {
        res = x - y;
    } else if (op == '*') {
        res = x * y;
    } else if (op == '/') {
        res = x / y;
    }
    return res;
}

double getNumber(string str, int& index){
    double number = 0;
    while(isdigit(str[index])){
        number = number * 10 + str[index] - '0';
        index++;
    }
    return number;
}

double calculateExpression(string str){
    int index = 0;
    stack<char> opStack;
    stack<double> numStack;
    str += "$";
    opStack.push('#');
    while(index < str.size()){
        if(str[index] == ' '){
            index++;
        }else if(isdigit(str[index])){
            numStack.push(getNumber(str, index));
        }else{
            if(priority(opStack.top()) < priority(str[index])){
                opStack.push(str[index]);
                index++;
            }else{
                double y = numStack.top();
                numStack.pop();
                double x = numStack.top();
                numStack.pop();
                numStack.push(calculate(x, y, opStack.top()));
                opStack.pop();
            }
        }
    }
    return numStack.top();
}

void demo1(){
    string str;
    while(getline(cin, str)){
        if(str == "0"){
            break;
        }else{
            double result = calculateExpression(str);
            printf("%0.2lf\n", result);
        }
    }
}




// 字符串操作
void string_test01(){
    // 字符串遍历
    string str;
    cin >> str;

    for(int i = 0; i < str.size(); i++){ // 普通遍历
        cout << str[i] << " ";
    }
    cout << endl;

    for(string::iterator it = str.begin(); it != str.end(); it++){ // 迭代器遍历
        cout << *it << " ";
    }
    cout << endl;

    for(auto & it : str){
        cout << it << " ";
    }
    cout << endl;
}

void string_test02(){
    string str, S, T;
    cin >> str >> S >> T;

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
    
    // 字符串查找find(str, pos)
    int pos = str.find(S), len = S.size();
    if(pos != string::npos){
        cout << str.find(S) << endl; // 从str[0]开始查找字符串S，找到返回第一个字符串的下标，找不到返回string::npos
        cout << str.find(S, pos) << endl; // 从str[pos]开始查找字符串S，找到返回第一个字符串的下标，找不到返回string::npos
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


// 浮点数加法
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

void demo2(){
    string S, T;
    while(cin >> S >> T){
        // InitProcess(S, T);
        // cout << S << endl;
        // cout << T << endl;
        string res = FloatAdd(S, T);
        cout << res << endl;
    }
    
}


// vector
void vector_test(){
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

    for(auto & it : vec){
        cout << it << " ";
    }
    cout << endl;

    // 插入
    vec = vector<int>();
    for(int i = 0; i < n; i++){
        vec.push_back(i);   // 在末尾插入元素
    }
    vec.insert(vec.end(), n); // 在vec.end()后插入元素

    // 查找最值
    if(!vec.empty()){
        int max_val = *max_element(vec.begin(), vec.end()); // 最大值
        int min_val = *min_element(vec.begin(), vec.end()); // 最小值
    }

    // 删除
    vec.pop_back(); // 删除末尾元素
    vec.erase(vec.begin()); // 删除vec.begin()的元素
    vec.erase(vec.begin(), vec.begin() + n); // 删除[vec.begin(), vec.begin() + n)区间内的元素

    // 清空
    vec.clear();

    // 预分配内存
    vec.reserve(n);  // 预分配长度为n的内存，提升性能
}

// queue
void queue_test(){
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

// stack
void stack_test(){
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

// sort
bool compare(int x, int y){
    return x > y;
}

void sort_test(){
    int len;
    cin >> len;

    int* arr = new int[len];
    for(int i = 0; i < len; i++){
        arr[i] = len - i;
    }

    sort(arr, arr + len);  // 正序排序
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    sort(arr, arr + len, compare); // 逆序排序
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> vec;
    for(int i = 0; i < len; i++){
        vec.push_back(len - i);
    }

    sort(vec.begin(), vec.end()); // 正序排序
    for(auto & it : vec){
        cout << it << " ";
    }
    cout << endl;
    sort(vec.begin(), vec.end(), compare); // 逆序排序
    for(auto & it : vec){
        cout << it << " ";
    }
    cout << endl;
}

// find
void find_test(){
    int len, val;
    cin >> len >> val;

    vector<int> vec;
    for(int i = 0; i < len; i++){
        vec.push_back(len - i);
    }
    
    if(!vec.empty()){
        auto it = find(vec.begin(), vec.end(), val);
        if(it != vec.end()){
            cout << *it << endl;
        }
    }
}


// 十进制数
long long reverse(long long num){   // 取反序数
    long long res = 0;
    while(num != 0){
        res = res * 10 + num % 10;
        num /= 10;
    }
    return res;
}

vector<int> getDigit(long long num){  // 取十进制数各个位
    vector<int> vec;
    while(num != 0){
        vec.push_back(num % 10);
        num /= 10;
    }
    reverse(vec.begin(), vec.end());
    return vec;
}

void demo3(){
    long long num;
    cin >> num;

    long long res = reverse(num);
    cout << res << endl;

    vector<int> digit = getDigit(num);
    for(auto & it : digit){
        cout << it << " ";
    }
    cout << endl;
}

// 进制转换
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

string MToN(string str, int M, int N){  // M进制转N进制
    long long temp = 0; // 十进制中间数
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

void demo4(){
    string str;
    int M, N;
    while(cin >> str >> M >> N){
        cout << MToN(str, M, N) << endl;
    }
}

void demo5(){
    string x = "1000", y = "1011";
    cout << add_N(x, y, 2) << endl;
}


// 求质因数
vector<pair<long long, int>> getPrimeFactor(long long num){  // 求所有质因数及其指数
    vector<pair<long long, int>> res;
    for(long long i = 2; i * i <= num; i++){
        if(num % i == 0){
            int count = 0;
            while(num % i == 0){
                num /= i;
                count++;
            }
            res.emplace_back(i, count);
        }
    }
    if(num > 1){  // 剩余的n为质数
        res.emplace_back(num, 1);
    }
    return res;
}

void demo6(){
    long long n;
    while(cin >> n){
        vector<pair<long long, int>> vec = getPrimeFactor(n);
        long long product = 1;
        for(auto it : vec){
            cout << "factor=" << it.first << " index=" << it.second << endl;
            for(int i = 0; i < it.second; i++){
                product *= it.first;
            }
        }
        cout << "result=" << product << endl;
    }
}

// 求约数
vector<long long> getDivisor(long long num){     // 求所有约数
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

void demo7(){
    long long n;
    while(cin >> n){
        cout << n << ": ";
        vector<long long> vec = getDivisor(n);
        for(auto it : vec){
            cout << it << " ";
        }
        cout << endl;
    }
}


// 矩阵

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
        out << endl;
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

void demo8(){
    Matrix A(2, 2), B(2, 2);
    long long arr[2][2] = {
        {1, 2}, 
        {2, 1}
    };
    for(int i = 0; i < A.row; i++){
        for(int j = 0; j < B.column; j++){
            A.matrix[i][j] = arr[i][j];
            B.matrix[i][j] = arr[i][j];
        }
    }
    cout << A + B;
    cout << A - B;
    cout << A * B;
    cout << matrixQuickPow(A, 10);
}

// 高精度整数
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


void demo9(){
    BigInteger a("173"), b("19");
    cout << a << " " << b << endl;
    BigInteger q = a / b,  r = a % b, p = q * b + r;
    cout << q << endl;
    cout << r << endl;
    cout << p << endl;
}

void demo10(){
    for(int i = 0; i <= 20; i++){
        cout << "2^" << i << "=" << QuickPow(BigInteger(2), i) << endl;
    }
}


// 日期问题

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
    int wd = (now - base) % 7;
    if(wd < 0){
        wd += 7;
    }
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


void demo11(){
    cout << getWeek(2101, 1, 2) << endl;
}


// BFS
string swap(string str, int i, int j) {
    string res = str;
    char temp = res[i];
    res[i] = res[j];
    res[j] = temp;
    return res;
}

int MayaCode(string str) {
    queue<string> q;
    q.push(str);
    int count = 0;
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            string temp = q.front();
            q.pop();
            if(temp.find("2012") != string::npos){
                return count;
            }
            for(int j = 1; j < temp.size(); j++){
                q.push(swap(temp, j - 1, j));
            }
        }
        count++;
    }
    return -1;
}

void demo12(){
    string str = "012120";
    cout << MayaCode(str) << endl;
}


/* DFS */

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

void demo13(){
    vector<int> vec = {0, 1, 2, 3};
    vector<vector<int>> res = subset(vec);
    for(auto & it_i : res){
        for(auto & it_j : it_i){
            cout << it_j << " ";
        }
        cout << endl;
    }
}

void demo14(){
    vector<int> vec;
    int target = 40;
    for(int i = 0; i < target / 2; i++){
        vec.push_back(i + 1);
    }
    vector<vector<int>> res = combination(vec, target);
    for(auto & it_i : res){
        for(auto & it_j : it_i){
            cout << it_j << " ";
        }
        cout << endl;
    }
}


// 迷宫路径问题模板
vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs_maze(const vector<vector<int>>& maze, vector<pair<int, int>>& path, vector<vector<bool>>& visited, int x, int y, int end_x, int end_y, vector<vector<pair<int, int>>>& res){
    int row_len = maze.size(), col_len = maze[0].size();
    if(x < 0 || x >= row_len || y < 0 || y >= col_len || visited[x][y] || maze[x][y]){
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

void demo15(){
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };
    vector<vector<pair<int, int>>> paths = maze_path(maze, 0, 0, 4, 0);
    for(auto & path : paths){
        for(auto & point : path){
            cout << "(" << point.first << "," << point.second << ")" << " ";
        }
        cout << endl;
    }
}


// N皇后问题模板
void dfs_NQueen(int N, int row, vector<int>& path, vector<bool>& col_used, vector<bool>& diag1, vector<bool>& diag2, vector<vector<int>>& res) {
    if (row == N) {
        res.push_back(path);
        return;
    }
    for (int col = 0; col < N; col++) {
        int d1 = row - col + N - 1;
        int d2 = row + col;
        if (col_used[col] || diag1[d1] || diag2[d2]) {
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

vector<vector<int>> NQueen(int N) {
    vector<int> path;
    vector<vector<int>> res;
    vector<bool> col_used(N, false), diag1(2 * N - 1, false), diag2(2 * N - 1, false);
    dfs_NQueen(N, 0, path, col_used, diag1, diag2, res);
    return res;
}

vector<string> vectorToString(vector<vector<int>> res){
    vector<string> temp;
    for(auto & i : res){
        string str = "";
        for(auto & j : i){
            str += char(j + 1 + '0');
        }
        temp.push_back(str);
    }
    return temp;
}

void demo16(){
    int index;
    vector<string> vec = vectorToString(NQueen(8));
    sort(vec.begin(), vec.end());
    while(cin >> index){
        cout << vec[index - 1] << endl;
    }
}

void demo17(){
    int index;
    vector<string> vec = vectorToString(NQueen(8));
    sort(vec.begin(), vec.end());
    while(cin >> index){
        cout << vec[index - 1] << endl;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(j == int(vec[index][i] - 1 - '0')){
                    cout << "1" << " ";
                }else{
                    cout << "0" << " ";
                }
            }
            cout << endl;
        }
    }
}


// 迷宫最短路径问题
struct Node{
    int x;
    int y;
    int step;
};

int bfs_maze(const vector<vector<int>>& maze, int start_x, int start_y, int end_x, int end_y, vector<pair<int, int>>& path){
    int row_len = maze.size(), col_len = maze[0].size();
    vector<vector<bool>> visited(row_len, vector<bool>(col_len, false));

    vector<vector<pair<int, int>>> parent(row_len, vector<pair<int, int>>(col_len, {-1, -1})); // 保存路径上的点的前驱结点

    queue<Node> q;
    q.push({start_x, start_y, 0});
    visited[start_x][start_y] = true;
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

void demo18(){
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {1, 1, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 1, 1, 1, 0, 1, 1},
        {0, 1, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 0, 0}
    };
    vector<pair<int, int>> path;
    int end_x = maze.size() - 1, end_y = maze[0].size() - 1;
    int shortest_len = bfs_maze(maze, 0, 0, end_x, end_y, path);
    for(auto & point : path){
        cout << "(" << point.first << "," << point.second << ")" << "->";
    }
    cout << endl << shortest_len << endl;
}

// 优先队列
void demo19(){
    priority_queue<int> pq;
    // 判空与长度
    cout << pq.empty() << " " << pq.size() << endl;
    // 添加
    for(int i = 0; i < 10; i++){
        pq.push(i);
    }
    // 删除
    pq.pop(); // 删除优先级最高的元素
    // 访问
    cout << pq.top() << endl;  // 取优先级最高的元素
}

void demo20(){
    int value = 0;
    scanf("value=%d", &value); // 要求输入为value=x，才能成功赋值
    printf("value=%d\n", value); // 输出value=x，x为输入的整数
    double d = 0.222222;
    printf("%0.2lf", d); // 保留小数点后2位
}

void demo21(){ 
    unordered_map<string, int> map; // 键常用int/string/char
    // 直接赋值
    map["hello"] = 1;   // 没有该键则插入
    // 插入
    map.insert(pair<string, int>("world", 2));  
    // 访问
    cout << map["hello"] << endl; // 按键访问
    // 遍历
    for(auto & pair : map){ // 键值对遍历
        cout << pair.first << ":" << pair.second << endl;
    }
    // 删除
    map.erase("hello"); // 按键删除
    // 查找
    unordered_map<string, int>::iterator it = map.find("world");
    if(it != map.end()){ // 查找失败时返回map.end()
        cout << it->first << ":" << it->second << endl;
    }
    // 清空
    map.clear();
}

void demo22(){
    map<string, int> map;
    // 插入
    map.insert(pair<string, int>("hello", 1));
    map.insert(pair<string, int>("world", 2));
    // 访问
    for(auto & pair : map){ // 键值对遍历
        cout << pair.first << ":" << pair.second << endl;
    }
    // 查找
    auto it = map.find("world");
    if(it != map.end()){ // 删除失败时返回map.end()
        cout << it->first << ":" << it->second << endl;
    }
    // 获取迭代器
    auto first = map.begin(); // 返回键值对的第一个元素
    auto last = map.rbegin(); // 返回键值对最后一个元素
    // 删除
    map.erase("hello");
    // 清空
    map.clear();
}

void demo23(){ 
    unordered_set<string> set; 
    // 插入
    set.insert("hello");
    set.insert("world");
    // 查找
    if(set.find("hello") != set.end()){ // 查找失败时返回set.end()
        cout << "hello" << endl;
    }
    if(set.count("world")){ // 查找失败时返回0
        cout << "world" << endl;
    }
    // 删除
    set.erase("hello");
    // 清空
    set.clear();
}

void demo24(){ 
    int n;
    while (cin >> n) {
        vector<int> items;
        for (int num = 3; num < n; num += 2) {
            items.push_back(num);
        }
        int left = 0, right = items.size() - 1;
        while (left < right) {
            if (items[left] + items[right] == n) {
                cout << items[left] << " " << items[right] << endl;
                left++;
                right--;
            } else if (items[left] + items[right] < n) {
                left++;
            } else {
                right--;
            }
        }
    }
}


void demo25(){
    int n;
    char ch = '*';
    while (cin >> n >> ch) {
        int len = 2 * n - 1;
        vector<vector<char>> graph(len, vector<char>(len, ' '));
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


vector<string> split(const string& str){
    vector<string> res;
    int start = 0;
    for(int end = 0; end < str.size(); end++){
        if(str[end] == ' '){
            res.push_back(str.substr(start, end - start));
            while(end < str.size() && str[end] == ' '){
                end++;
            }
            start = end;
        }
    }
    if(start < str.size()){
        res.push_back(str.substr(start));
    }
    return res;
}


void demo26(){
    string str;
    while(getline(cin, str)){
        vector<string> items = split(str);
        int left = 0, right = items.size() - 1;
        while(left < right){
            string temp = items[left];
            items[left] = items[right];
            items[right] = temp;
            left++;
            right--;
            cout << items[left] << " " << items[right] << " " << endl;
        }
        for(auto & item : items){
            cout << item << " ";
        }
        cout << endl;
    }
}


struct LNode{
    int value;
    struct LNode* next;
};

LNode* insert(LNode*& p, int val){
    if(p == nullptr){
        p = new LNode();
        p->value = val;
        p->next = p;
    }else{
        auto* q = new LNode();
        q->value = val;
        q->next = p->next;
        p->next = q;
        p = q;
    }
    return p;
}

LNode* remove(LNode*& p){
    auto* q = p->next;
    if(q != nullptr && q != p && q->next != p){
        p->next = q->next;
    }
    return q;
}

void demo27(){
    LNode* head = nullptr;
    auto* p = head;
    insert(p, 1);
    insert(p, 2);
    insert(p, 3);
    head = p->next;
    for(auto* q = head; q->next != head; q = q->next){
        cout << q->value << " ";
    }
}

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


void demo28(){
    char ch;
    while(cin >> ch){
        cout << getStrByChar(ch) << endl;
    }
}


void demo29(){ 
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



struct Graph{
    vector<vector<int>> matrix; // 邻接矩阵
    vector<int> nodes;          // 顶点向量
    int vex_num;                // 顶点数
    int arc_num;                // 边数
    bool graph_type;            // true为有向图，false为无向图

    Graph(int num, bool type){
        vex_num = num;
        arc_num = 0;
        graph_type = type;
        matrix = vector<vector<int>>(num, vector<int>(num, 0));
        nodes = vector<int>(num, 0);
    }

    Graph(bool type, vector<int> items){
        vex_num = items.size();
        arc_num = 0;
        graph_type = type;
        nodes = items;
        matrix = vector<vector<int>>(items.size(), vector<int>(items.size(), 0));
    }

    void addEdge(int x, int y){ // 添加边
        if(graph_type){
            matrix[x][y] = 1;
        }else{
            matrix[x][y] = 1;
            matrix[y][x] = 1;
        }
    }

    void addNode(int node){     // 添加顶点
        nodes[node] = node;
        for(int i = 0; i < vex_num; i++){
            matrix[i].push_back(0);
        }
        matrix.push_back(vector<int>(vex_num, 0));
        vex_num++;
    }

    void print(){               // 打印邻接矩阵
        for(int i = 0; i < vex_num; i++){
            for(int j = 0; j < vex_num; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};


void visit(const Graph& graph, int index){
    cout << graph.nodes[index] << " ";
}

// 深度优先搜索
void dfs(const Graph& graph, vector<bool>& visited, int start){
    visit(graph, start);
    visited[start] = true;
    for(int i = 0; i < graph.vex_num; i++){
        if(graph.matrix[start][i] && !visited[i]){
            dfs(graph, visited, i);
        }
    }
}

void DFS(const Graph& graph){
    vector<bool> visited(graph.vex_num, false);
    for(int i = 0; i < graph.vex_num; i++){
        if(!visited[i]){
            dfs(graph, visited, i);
        }
    }
}

// 广度优先搜索
void bfs(const Graph& graph, vector<bool>& visited, int start){ 
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int index = q.front();
        q.pop();
        if(!visited[index]){
            visit(graph, index);
            visited[index] = true;
            for(int i = 0; i < graph.vex_num; i++){
                if(graph.matrix[index][i] && !visited[i]){
                    q.push(i);
                }
            }
        }
    }
}

void BFS(const Graph& graph){
    vector<bool> visited(graph.vex_num, false);
    for(int i = 0; i < graph.vex_num; i++){
        if(!visited[i]){
            bfs(graph, visited, i);
        }
    }
}

void demo30(){
    vector<int> items = {1, 2, 3, 4, 5};
    Graph graph(true, items);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.print();
    DFS(graph);
    cout << endl;
    BFS(graph);
    cout << endl;
}


int main(){
    demo30();
    return 0;
}


