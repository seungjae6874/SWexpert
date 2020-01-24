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
		
		for(int a = 0;  num[a] != '\0'; a++){
			len++;
		}
		//cout<<len<<endl;;
		char num2[len];
		for(int l = 0; l<len; l++){
			num2[l] = '\0';
		}
		int flag =0;
		int index = 0;
		for(int i = 0; i < len; i++){
			for(int j = 0; j<len;j++){
				if(num2[j] == num[i]){
					num2[j] = '\0';		
				}
				else{
					index++;
				}
			}
			if(index == len){
				num2[flag++] = num[i];
				index = 0;
			}
					
		}
		int final = 0;
		for(int f = 0; f<len; f++){
			if(num2[f] != '\0'){
			//	cout<<num2[f]<<endl;
				final++;	
			}
		}
		cout<<"#"<<i+1<<" "<<final<<endl;
	}
}
