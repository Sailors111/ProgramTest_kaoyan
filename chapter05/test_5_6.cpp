#include <iostream>
#include "test_5_6.hpp"
using namespace std;

/* 5.6 矩阵与矩阵快速幂 */   

// 哈尔滨工业大学机试题T171 计算两个矩阵的乘积 
void HaGongDa_171(){
    Matrix A(2, 3), B(3, 2);
    cin >> A;
    cin >> B;
    Matrix C = A * B;
    cout << C;
}

// 北京邮电大学T104 矩阵幂 
void BUP_104(){
    int n, k;
    while(cin >> n >> k){
        Matrix A(n, n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> A.matrix[i][j];
            }
        }
        Matrix result = matrixQuickPow(A, k);
        cout << result;
    }
}

// 浙江大学机试题T137 A + B for Matrices 
void ZJU_137(){
    int M, N;
    while (cin >> M >> N) {
        if (M == 0) {
            break;
        }
        Matrix A(M, N), B(M, N);
        cin >> A;
        cin >> B;
        Matrix C = A + B;
        int row = C.row, col = C.col;
        int count = 0;
        for (int i = 0; i < row; i++) {
            bool flag = true;
            for (int j = 0; j < col; j++) {
                if (C.matrix[i][j] != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                count++;
            }
        }
        for (int j = 0; j < col; j++) {
            bool flag = true;
            for (int i = 0; i < row; i++) {
                if (C.matrix[i][j] != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                count++;
            }
        }
        cout << count << endl;
    }
}

// 清华大学机试题T120 递推数列 
void TsingHua_120(){
    // 动态规划法
    long long a0, a1, p, q, k;
    while(cin >> a0 >> a1 >> p >> q >> k){
        vector<long long> dp(k + 1, 0);
        dp[0] = a0;
        dp[1] = a1;
        int mod = 10000;
        for(int i = 2; i < k + 1; i++){
            dp[i] = ((p * dp[i-1]) % mod + (q * dp[i-2]) % mod) % mod;
        }
        cout << dp[k] << endl;
    }
}

