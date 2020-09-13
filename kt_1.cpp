#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int itoa(int num){
	int a[5] = {0,};
	int cnt = 0;
	int answer = 0;
	while(num > 0){
		a[cnt] = num%10;
		num/=10;
		cnt++;
	}
	for(int j = 0; j < 5; j++){
		if(a[j] == 8){
			answer++;
		}
	}
	return answer;
}

int main(){
	int ans=0;
	for(int i = 1; i < 20; i++){
		ans+=itoa(i);
		
	}	
	cout<<ans<<endl;
}
