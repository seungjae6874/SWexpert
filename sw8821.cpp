#include <iostream> 
#include <string.h> 
using namespace std;
int main(){
	int T=0;
	cin>>T;
	for(int i = 0; i < T; i++){
		int len=0;
		char num[10000];
		cin>>num;
		char check2[] = {'0','1','2','3','4','5','6','7','8','9'}; 
		int check[10] = {0,};//문자열에서 각 수가 몇번 나왔는지 담는 배열
		 
		for(int i = 0; i<10; i++){
			for(int a = 0; num[a] != '\0'; a++){
				if(num[a] == check2[i]){
					check[i]++;
				}
			}
		}
		int cnt = 0;
		for(int a =0; a<10; a++){
			if(check[a] %2 == 1){
				cnt++;
			}
			
		}
		cout<<"#"<<i+1<<" "<<cnt<<endl;
	}
}
