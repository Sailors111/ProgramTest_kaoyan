#include <iostream>
using namespace std;

/* 5.5 快速幂 */

// 快速幂求 pow(x, y)
long long quickPow(long long x, long long y){     // 求pow(x, y)
    long long res = 1;
    while(y != 0){      
        if(y % 2 == 1){     // y为奇数
            res = res * x;
        }
        x = x * x;
        y /= 2;
    }
    return res;
}

// 快速幂求 pow(x, y) % mod
int quickPow_mod(long long x, long long y, int mod){    // 求pow(x, y) % mod
    int res = 1;
    while(y != 0){      
        if(y % 2 == 1){     // y为奇数
            res = res * x % mod;
        }
        x = x * x % mod;
        y /= 2;
    }
    return res;
}

/*
    求x^y的k进制数字根，结果范围为：[1, k - 1]
    核心原理：
        res == x^y mod (k-1)
        root(x^y, k) == (res != 0 ? res : k - 1)
*/
int root(long long x, long long y, int k){
    int res = quickPow_mod(x, y, k - 1);
    return res ? res : k - 1;
}
