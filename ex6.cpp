#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i = 0; i<T; i++)
	{
		
		int money[8] = {0,0,0,0,0,0,0,0};
		int N; //돈
		int big; // 오만원
		big = 50000;
		int man = 10000;// 만원
	
		int three = 5000;
		int four;
		four = 1000;
		int five = 500;
		int six = 100;
		int seven = 50;
		int eight = 10;
		
		cin>>N;
		
			int mod;
			int rest;
		
			if(N >= big)
			{
				while(N>=0)
				{
					N = N-big;
					money[0]++;
					
				}
				N += big;
				money[0]--;
			//	cout<<N<<endl;
			}	
				
			if((N >= man) && (N<big))
			{
				
				while(N>=0)
				{
					N -= man;
					money[1]++;
				}
				N += man;
			//	cout<<N<<endl;
				money[1]--;
			}	
				
			if((N >= three)&&(N<man))
			{
				cout<<1<<endl;
				while(N>=0)
				{
					N -= three;
					money[2]++;
				}
				N += three;
			//	cout<<N<<endl;
				money[2]--;
				
			}
			if((N >= four) && (N<three))
			{ 
				while(N>=0)
				{
					N -= four;
				money[3]++;
			}	
			N += four;
			//	cout<<N<<endl;
			money[3]--;
			}
			
			if((five <= N) && (N<four))
			{
				while(N>=0)
				{
					N -= five;
				money[4]++;
					
				}
				N += five;
				//cout<<N<<endl;
				money[4]--;
				
			}
			if((six <= N) && (N<five))
			{
				while(N>=0)
				{
					N -= six;
					money[5]++;	
				}
				N += six;	
				//cout<<N<<endl;
				money[5]--;
				
			}	
			if((seven <= N) && (N<six)){
			
				while(N>=0)
				{
					N -= seven;
					money[6]++;
					
				}
				N += seven;
			//	cout<<N<<endl;
				money[6]--;
			}
			if((eight <= N) && (N<seven)){
			
				while(N>=0)
				{
					N -= eight;
					money[7]++;
					
				}
				N += eight;
				//cout<<N<<endl;
				money[7]--;
				
			}
		cout<<"#"<<i+1<<endl;
		for(int a = 0; a<8; a++)
		{
			cout<<money[a]<<" ";
		}
			//cout<<N<<" "<<endl;
			
		
	
	}
		
	
	return 0;
}
