#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
string removespace(string str){
	int m = str.length();
	int i =0;
	while(i<m){
		if(str[i] == ' '){
			str.erase(i,1);
		}
		i++;
	}
	return str;
}
int main(){
	int T;//한줄씩 단어를 입력 받고, 15*5의 행렬에 한 행씩 넣는다 
	string a;
	cin>>T;
	int len[5] = {0};
	int index = 0;
	int j;
	int g,h;
	for(int i = 0; i < T; i++){
		int e[5];
		string r,r2,r3,r4,r5;	
		int ca=0;
		int maxe;
		char b[5][index];
		int l=0;	
		for(j= 0; j< 5; j++){
			cin>>a;					
			index = a.length();
			e[j] = index;
			maxe = e[j];
			if(j >=1){
				if(e[j] >= e[j-1]){
					maxe = e[j];
				}
					
			}
			for(int i =0; i < index; i++){
				b[j][i] = a[i];
						
			}
			while(l<e[l])
			{
				r += b[j][l];
			}
			while(l <e[l+1])
			{
				r2 += b[j][l+1];
			}
			while(l < e[l+2]){
				r3 += b[j][l+2];	
			}
			while(l < e[l+3]){
				r4 += b[j][l+3];	
			}
			while(l < e[l+4]){
				r5 += b[j][l+4];	
			}
							
		}
		cout<<r<<r2<<r3<<r4<<r5;
		sort(e,e+5);
		int len;
		int q1 = e[0];
		int q2 = e[1];
		int q3 = e[2];
		int q4 = e[3];
		int q5 = e[4];
		

		cout<<"#"<<T<<" ";
		cout<<endl;
				
	}
	
	return 0;
	
}
