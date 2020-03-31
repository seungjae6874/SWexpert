#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(),citations.end(),greater<int>());
    vector<int> count;
    int answer = 0;
    for(int i =0; i<citations.size(); i++){
        cout<<citations[i];
        if(citations[i]<=answer)break;
        answer++;
    }
    return answer;
}
