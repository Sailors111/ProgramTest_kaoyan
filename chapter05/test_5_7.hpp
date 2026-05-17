#include <iostream>
#include <string>
using namespace std;

/* 5.7 高精度整数 */

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

