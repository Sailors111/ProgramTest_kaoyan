#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

/* 9.4 哈希表 */  

// 清华大学机试题T126 查找学生信息
struct Student{
    string name;
    string gender;
    int age;
    Student() : age(0){}
    Student(string _name, string _gender, int _age){
        name = _name;
        gender = _gender;
        age = _age;
    }
    Student(const Student& other){
        name = other.name;
        gender = other.gender;
        age = other.age;
    }
};

void TsingHua_126(){
    int N, M;
    while(cin >> N){
        unordered_map<string, Student> map;
        string num, name, gender;
        int age;
        for(int i = 0; i < N; i++){
            cin >> num >> name >> gender >> age;
            Student stu(name, gender, age);
            map.insert(pair<string, Student>(num, stu));
        }
        cin >> M;
        for(int i = 0; i < M; i++){
            cin >> num;
            auto it = map.find(num);
            if(it == map.end()){
                cout << "No Answer!" << endl;
                continue;
            }
            Student stu(map[num]);
            cout << num << " " << stu.name << " " << stu.gender << " " << stu.age << endl;
        }
    }
}

// 浙江大学机试题T130 魔咒词典（难）
void ZJU_130(){
    string str;
    unordered_map<string, string> map;
    while(getline(cin, str)){
        if(str == "@END@"){
            break;
        }
        int pos = str.find(']');
        string key = str.substr(0, pos + 1);
        string value = str.substr(pos + 2);
        map.insert(pair<string, string>(key, value));
        map.insert(pair<string, string>(value, key));
    }
    int N;
    scanf("%d\n", &N);  // 需要输入N与回车
    for(int i = 0; i < N; i++){
        getline(cin, str);
        string result = map[str];
        if(result == ""){
            result = "what?";
        } else if(result[0] == '['){
            result = result.substr(1, result.size() - 2);
        }
        cout << result << endl;
    }
}

// 北京大学机试题T139 子串计算 
void Peking_139(){ 
    string str;
    while(cin >> str){
        map<string, int> map;
        int size = str.size();
        for(int i = 0; i < size; i++){
            int bound = size - i;
            for(int len = 1; len <= bound; len++){
                string substr = str.substr(i, len);
                if(map.find(substr) == map.end()){
                    map.insert(pair<string, int>(substr, 1));
                } else {
                    map[substr]++;
                }
            }
        }
        for(auto & pair : map){
            if(pair.second > 1){
                cout << pair.first << " " << pair.second << endl;
            }
        }
    }
}

// 浙江大学机试题T120 统计同成绩同学人数 
void ZJU_120(){
    int N;
    while(cin >> N){
        if(N == 0){
            break;
        }
        unordered_map<int, int> map;
        int score;
        for(int i = 0; i < N; i++){
            cin >> score;
            if(map.find(score) == map.end()){
                map.insert(pair<int, int>(score, 1));
            }else{
                map[score]++;
            }
        }
        cin >> score;
        if(map.find(score) == map.end()){
            cout << 0 << endl;
        }else{
            cout << map[score] << endl;
        }
    }
}

// 浙江大学机试题T124 开门人和关门人 
void ZJU_124(){
    int N;
    while(cin >> N){
        string str, in, out;
        map<string, string> map1, map2;
        for(int i = 0; i < N; i++){
            cin >> str >> in >> out;
            map1.insert(pair<string, string>(in, str));
            map2.insert(pair<string, string>(out, str));
        }
        string first_one = map1.begin()->second;
        string last_one = map2.rbegin()->second;
        cout << first_one << " " << last_one << endl;
    }
}   

// 北京大学机试题T101 谁是你的潜在朋友 
void Peking_101(){
    int N, M;
    while(cin >> N >> M){
        map<int, int> map;
        int favorite;
        for(int i = 0; i < N; i++){
            cin >> favorite;
            map[i] = favorite;
        }
        for(int i = 0; i < N; i++){
            int count = 0, first = i, seconde = map[i];
            for(int j = 0; j < N; j++){
                if(i != j && map[i] == map[j]){
                    count++;
                }
            }
            if(count){
                cout << count << endl;
            }else{
                cout << "BeiJu" << endl;
            }
        }
    }
}
