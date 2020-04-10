#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//������ 1���� 100000������� ����� ���ؼ� ���곻���� ���Ѻ��� ū���� �������� ���ϰ�
//���Ѻ��� ������ �װ��� �״�� ���Ѵ�.
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
            //sum�� M���� ������ min�� �÷����� avg+1��
            min = avg+1;
            answer = avg;
        }
    }
    
    return answer;
}
