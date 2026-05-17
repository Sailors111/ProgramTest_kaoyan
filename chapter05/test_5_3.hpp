#include <iostream>
using namespace std;

/* 5.3 质数 */

/* 
    质数判定定理：若一个数n不能被[2, sqrt(n)]内的任何质数整除，则n为质数。 
*/

// 判断是否为质数
bool isPrime(long long num) {    
    if(num == 2) {     // 2为质数
        return true;
    } else if(num < 2 || num % 2 == 0) {     // 小于2的数和不是2的偶数都不是质数
        return false;
    } else {
        for(long long i = 3; i * i <= num; i += 2){  // 从3开始，只判断奇数
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
}
