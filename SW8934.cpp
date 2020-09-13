#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

string check(int a, int b, int c, int size){
	
	if((a-b) >=2 || (a-b) <= -2) return "NO";
	if((a-c) >=2 || (a-c) <= -2) return "NO";
	if((c-b) >=2 || (c-b) <= -2) return "NO";
	
	return "YES";
}
int main(){
	int TC;
	cin>>TC;
	for(int i = 0; i<TC; i++){
		string S;
		string answer;
		cin>>S;
		int len = S.length();
		int cnt[3]={0,};
		//먼저 길이 홀수이면
		for(int a = 0; a < len; a++){
			if(S[a] == 'a') cnt[0]++;
			else if(S[a] == 'b') cnt[1]++;
			else if(S[a] == 'c') cnt[2]++;
		}
		
		answer = check(cnt[0], cnt[1], cnt[2],len);
		//일단 팰린드롬 
		//배열 인덱스를 돌면서 '나'를 기준으로 양옆
		cout<<"#"<<i+1<<" "<<answer<<endl;
	}
}
