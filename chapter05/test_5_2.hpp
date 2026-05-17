#include <iostream>
using namespace std;


/* 6.2 最大公约数与最小公倍数 */

/*
    最大公约数定理：
        a, b的最大公约数，等于其中较小的数与两数相除余数的最大公约数。
        a = b × q + r (0≤r<b)
        gcd(a,b) = gcd(b,r) = gcd(b,a mod b)
        当余数r=0时，直接可得 gcd(a,b) = b
    
    最小公倍数定理：
        a, b的最小公倍数，等于两数的乘积除以它们的最大公约数。
        lcm(a,b) = a × b / gcd(a,b)
*/ 

// 最大公约数
int gcd(int a, int b){      
    if(b == 0){             // 辗转相除法
        return a;
    }else{
        return gcd(b, a % b);
    }
}

// 最小公倍数
int lcm(int a, int b){      
    return a / gcd(a, b) * b;  
}


