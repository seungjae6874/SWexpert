#include <string>
#include <vector>
#include <iostream>
using namespace std;
int answer = 0;
bool visit[201];
void dfs(int idx,vector<vector<int>> &computers){
    visit[idx] = true;
    for(int i =0; i<computers.size(); i++){
        if(!visit[i] && computers[idx][i]==1){
            //�湮�������� false�� computers�� 1�̸� ��Ʈ��ũ ã����
            dfs(i,computers);
        }
    }
}
    

int solution(int n, vector<vector<int>> computers) {
    int answer=0;
    for(int j = 0; j<computers.size(); j++){
        if(!visit[j]){//j,j�� ���� ���ؾ� �ϹǷ�
            answer++;
          dfs(j,computers);
        }
    }
    return answer;
}
