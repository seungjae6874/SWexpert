#include <string>
#include <vector>

using namespace std;

//DFS문제는 스택과 재귀 두가지방법이 있고,index포인터로 이동해주면서 끝까지 순회하면 된다...
//dfs 재귀함수를 만들자
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
