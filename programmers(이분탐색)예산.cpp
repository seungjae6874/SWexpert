#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//상한은 1에서 100000으로잡고 평균을 구해서 예산내에서 상한보다 큰값은 상한으로 더하고
//상한보다 작으면 그값을 그대로 더한다.
int solution(vector<int> budgets, int M) {
    int answer = 0;
    int min = 1;
    int max = 100000;
    int avg = 0;
    sort(budgets.begin(),budgets.end());
    while(min<=max){
        int sum = 0;
        avg = (min+max)/2;
        //cout<<avg<<endl;
        bool check = true;
        for(int i =0; i< budgets.size(); i++){
            if(budgets[i] > avg){
                sum+=avg;
                check = false;
            }
            else{
                sum+=budgets[i];
            }
        }
        if(sum > M){
            max = avg -1;
        }
        else if(M >= sum){
            if(check)return budgets[budgets.size()-1];
            //sum이 M보다 작으면 min을 올려야지 avg+1로
            min = avg+1;
            answer = avg;
        }
    }
    
    return answer;
}
