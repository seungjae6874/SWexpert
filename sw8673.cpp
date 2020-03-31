#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int T;
	cin>>T;
	for(int i =0; i<T; i++){
		int K;
		cin>>K;
		int len = pow(2,K);
		int *p = new int[len]; //기존 배열
		int len2 = len/2;
		int *w = new int[len2]; 
		int sum = 0; //코딩실력 차이를 합하는 값 
		int windex = 0;
		int cnt = 0; 
		int value = 0; //코딩 실력 차이 값 
		for(int k = 0; k<len; k++){
			cin>>p[k];
		}
		for(int j = 0; j<len; j++){
				if(j %2 == 1){
					value = p[j]- p[j-1];
					if(p[j]> p[j-1]){
						p[j-1] = -1;
					}
					else{
						p[j] = -1;
					}
					cout<<"winner = "<<w[windex-1]<<endl;
					sum += abs(value);
					cout<<sum<<endl;	
				}
				
		}
		cout<<"1단계 끝"<<endl;
		while(len2 > 0){
			cout<<sum<<endl;
			int count = 0;
			int value = 0;
			int len3 = ceil(len2/2);
			if(len3 < 1){
				len3 = 1;
			}
			int *copy = new int[len3];
			for(int a = 0; a< len2; a++){
				if(a%2== 1){
					value = w[a] - w[a-1];
					if(w[a] > w[a-1]){
						copy[count] = w[a];
					}
					else{
						copy[count] = w[a-1];
					}
					count++;
					cout<<"winner = "<<copy[count-1]<<endl;
					sum += abs(value);
					cout<<"sum : "<<sum<<endl;
					
				}
			}
			int *w = new int[len3];
			for(int a = 0; a < len3; a++){
				w[a] = copy[a];
 			}	
			
			len2 /= 2;
		}
			
		cout<<sum<<endl;
	}
}
