#include <iostream>
using namespace std;
int main()
{
	int N,T;
	cin>>T;
	int anw=0;
	int sum[10];
	for(int i =0; i< T; i++)
	{
		cin>>N;
		if(N%2==0)
		{
			sum[i] = -N;
		}
		else{
			sum[i] = N;
		}
		
		anw += sum[i];
		cout<<"#"<<i+1<<" "<< anw<< endl;
		
	}
	
	
	return 0;
}
