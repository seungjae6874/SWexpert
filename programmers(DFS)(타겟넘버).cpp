#include <string>
#include <vector>

using namespace std;

//DFS������ ���ð� ��� �ΰ�������� �ְ�,index�����ͷ� �̵����ָ鼭 ������ ��ȸ�ϸ� �ȴ�...
//dfs ����Լ��� ������
int answer = 0;
void dfs(vector<int> number,int target, int sum, int idx){
    if(idx >= number.size()){
        if(sum == target){
            answer++;           
        }
         return;
    }
    dfs(number,target,sum+number[idx],idx+1);
    dfs(number,target,sum-number[idx],idx+1);
    
}
int solution(vector<int> numbers, int target) {
    
    dfs(numbers,target,0,0);
    return answer;
}
