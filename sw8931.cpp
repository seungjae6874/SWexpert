#include<iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i =0; i<T; i++)
	{
		int K=0; 
		cin>>K;
		int cnt=0;//가장 최근 입금액의 포인터
		int zero=0;//0이 몇번 나오는지 카운트 
		int m;//현재 입금하는 돈 
		int sum=0; //돈의 합을 저장하는 통장
		int *lastm = new int[K];// 돈의 기록들을 담는 통장		 
		for(int j = 0; j < K; j++)
		{
			cin>>m;
			lastm[cnt] = m;
			cnt++;
			cout<<"Money : "<<m<<endl;
			if(m==0){
				int p = 2;
				if(lastm[cnt-p] == 0){
					while(lastm[p] != 0){
						p++;
						cout<<p<<endl;
					}
					sum -= lastm[p];	
				}
				else{
					sum -= lastm[cnt-2];
				}
				
					 
			}
			else{
				sum += m;
			}
			cout<<"Sum : "<<sum<<endl;
		}
		
		
	}
}
