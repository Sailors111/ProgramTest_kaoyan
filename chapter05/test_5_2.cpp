#include <iostream>
#include <algorithm>
#include "test_5_2.hpp"
using namespace std;

/* 5.2 最大公约数与最小公倍数 */  

// 哈尔滨工业大学机试题T161 最大公约数 
void HaGongDa_161(){
    int a, b;
    while(cin >> a >> b){
        cout << gcd(a, b) << endl;
    }
}

// 北京大学机试题T107 最简真分数 
void PeKing_107(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }else{
            int* arr = new int[n];
            for(int i = 0; i < n; i++){
                cin >> arr[i];
            }
            sort(arr, arr + n);
            int count = 0;
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    if(gcd(arr[i], arr[j]) == 1){
                        count++;
                    }
                }
            }
            cout << count << endl;
        }
    }
}


