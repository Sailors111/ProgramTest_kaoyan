#include <iostream>
using namespace std;


/* 2.2 模拟 */

/* 2.2.2 日期问题 */

// 获取某年某月的天数
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
    int wd = ((now - base) % 7 + 7) % 7;
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


