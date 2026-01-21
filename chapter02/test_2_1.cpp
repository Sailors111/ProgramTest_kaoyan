#include <iostream>
using namespace std;

/* 2.1 枚举 */   // 进度：6/6

// 清华大学机试题T144 abc
void TsingHua_144(){
    for(int a=0; a<=9; a++){
        for(int b=0; b<=9; b++){
            for(int c=0; c<=9; c++){
                if(100*a+110*b+12*c == 532){
                    printf("%d %d %d\n",a,b,c);
                }
            }
        }
    }
}

// 清华大学机试题T130 反序数
void TsingHua_130(){
    for(int N=1000; N<=9999; N++){
        int reverse = 0, x = N;
        while(x != 0){
            reverse *= 10;
            reverse += x % 10;
            x = x / 10;
        }
        if(reverse == N*9){
            printf("%d\n",N);
        }
    }
}

// 清华大学机试题T131 对称平方数1
void TsingHua_131(){
    for(int i=0; i<=256; i++){
        int N = i*i;
        int reverse = 0;
        while(N != 0){
            reverse *= 10;
            reverse += N % 10;
            N = N / 10;
        }
        if(reverse == i*i){
            printf("%d\n", i);
        }
    }
}

// 北京大学机试题T122 与7无关的数
void PeKing_122(){
    int sum = 0;
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n ; i++){
        int x = i;
        bool flag = false;
        if(x % 7 == 0){
            flag = true;
        }
        while(x != 0) {
            int num = x % 10;
            x = x / 10;
            if(num == 7) {
                flag = true;
            }
        }
        if(!flag){
            sum += i*i;
        }
    }
    printf("%d\n", sum);
}

// 哈尔滨工业大学机试题T156 百鸡问题
void HaGongDa_156(){
    double n;
    scanf("%lf", &n);
    for(int x = 0; x <= 100; x++){
        for(int y = 0; y <= 100 - x; y++){
            int z = 100-x-y;
            double sum = double(5*x + 3*y) + double(z)/3;
            if(sum <= n){
                printf("x=%d,y=%d,z=%d\n",x,y,z);
            }
        }
    }
}

// 上海交通大学机试题T104 Old Bill
void SJU_104(){
    int N, X, Y, Z;
    int max = 0, first = 0, last = 0;
    scanf("%d",&N);
    scanf("%d %d %d",&X,&Y,&Z);
    for(int i = 1; i <= 9 ;i++){
        for(int j = 0; j <= 9; j++){
            int price = i*10000 + X*1000 + Y*100 + Z*10 + j;
            if(price % N == 0){
                max = price / N;
                first = i;
                last = j;
            }
        }
    }
    if(max == 0){
        printf("%d\n", max);
    }else{
        printf("%d %d %d\n", first, last, max);
    }
}



