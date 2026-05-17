#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


/* 6.4 分解质因数 */

/*
    埃氏质数筛法
*/
void InitPrime(vector<int>& prime, bool*& isPrime, int MAX){   // 筛选质数
    // 找出[2, MAX)之间的所有质数保存在prime中
    isPrime = new bool[MAX];
    for(int i = 0; i < MAX; i++){
        isPrime[i] = true;          // 假定所有数均为质数
    }
    isPrime[0] = false;     // 0与1不是质数
    isPrime[1] = false;
    for(int i = 2; i < MAX; i++){   // 外层循环：遍历[2, MAX)的所有数
        if(!isPrime[i]){
            continue;
        }
        prime.push_back(i);
        for(int j = i * i; j < MAX; j += i){  // 内层循环：筛除当前质数的所有倍数（非质数）
            isPrime[j] = false;
        }
    }
}


/*
    分解约数：
    遍历[0, sqrt(num)]，若num % d == 0，则num % (num / d) == 0，即 d 和 num / d 都为约数，
    若d * d == num，则只保留一个约数d
*/

// 求约数的个数
int numOfDivisor(long long num){      
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

// 求所有约数
vector<long long> getDivisor(long long num){     
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


/*
    分解质因数：
    a == pow(p1, e1) × pow(p2, e2) × ... × pow(pm, em)，其中pi为质因数，ei为pi的指数
*/

// 求质因数的个数
int numOfPrimeFactor(long long num){       
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

// 求所有质因数及其指数
vector<pair<long long, int>> getPrimeFactor(long long num){  
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


/*
    勒让德公式(Legendre's Formula)：
    
    求n!中质数p的最大幂次k：
        k = Legendre(n, p) = n / p + n / pow(p, 2) + n / pow(p, 3) + ...... 直到pow(p, k) > n

    求n!中任意数a的最大幂次k：
        k = min(ki / ei)，1<=i<=m，ki = Legendre(n, pi)，pi为a的质因数，ei为对应指数。
*/
long long Legendre(long long n, long long p) {  // 求n!中质数p的最大幂次k
    long long num = 0;
    while (n > 0) {
        n = n / p; 
        num += n;
    }
    return num;
}

long long maxPowerOfAInFactN(long long n, long long a) {  // 求n!中任意数a的最大幂次k
    long long res = 1e18; 
    for (long long i = 2; i * i <= a; i++) {
        if (a % i == 0) { // a为合数，求a的质因数i
            long long index = 0;
            while (a % i == 0) { // 统计i的指数
                a = a / i;
                index++;
            }
            res = min(res, Legendre(n, i) / index);
            // k = min(ki / ei)，1<=i<=m，ki = Legendre(n, pi)
        }
    }
    if (a > 1) {   // a为质数
        res = min(res, Legendre(n, a));
    }
    return res;
}


