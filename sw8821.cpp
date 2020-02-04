#include <iostream> 
#include <string> 
using namespace std;
int main(){
	int T=0;
	cin>>T;
	for(int i = 0; i < T; i++){
		int len=0;
		string num;
		cin>>num;
		string num2;
		len = num.length();
		int len2 = 0; 
		int a = 0;
		int b = 0;
		int flag = 0;
		for(a = 0; a < len; a++){
			num2 += num[a];
			if((a > 0 ) &&(num2.length() != 0)){
				for(b =0; b < num2.length()-1; b++){
					if(num2[b] == num[a]){
						num2.erase(b,1);
					}
				}	
			}
			
		}
		cout<<num2.length()<<endl;
		//cout<<"#"<<i+1<<" "<<fi<<endl;
	}
}
