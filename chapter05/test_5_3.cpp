#include <iostream>
#include "test_5_3.hpp"
using namespace std;

/* 5.3 质数 */  

// 哈尔滨工业大学机试题T163 素数判定 
void HaGongDa_163(){
    int n;
    while(cin >> n){
        if(isPrime(n)){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}

// 北京航空航天大学机试题T102 素数 
void BUA_102(){
    int n;
    while(cin >> n){
        for(int i = 2; i < n; i++){
            if(isPrime(i) && i % 10 == 1){
                cout << i << " ";
            }
        }
        cout << endl;
    }
}

// 上海交通大学机试题T119 Prime Number 
void SJU_119(){
    int k;
    while(cin >> k){
        int x = 2, count = 0;
        while(count < k){
            if(isPrime(x)){
                count++;
            }
            x++;
        }
        cout << x - 1 << endl;
    }
}
