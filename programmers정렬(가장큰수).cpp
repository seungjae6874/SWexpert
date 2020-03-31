#include <cstring>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(string a,string b){
    return a+b > b+a;
}
string solution(vector<int> numbers) {
    //음... 벡터를 스트링 벡터로 바꾸고 담아서 0번째가 큰 순서대로 정렬해서 더하자
    vector<string> n;
    string answer = "";
    for(auto num: numbers){
        n.push_back(to_string(num));
    }
    sort(n.begin(),n.end(),cmp);
    if(n.at(0) == "0") return "0";
    for( auto num: n){
        answer += num;
    }
    return answer;
}
