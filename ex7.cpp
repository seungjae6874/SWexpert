#include<iostream>
using namespace std;
typedef unsigned long long ull;
int main()
{
	int T;
	cin>>T;
	int N;
	for(int i = 0; i< T; i++)
	{
		
		cin>>N;
		ull L = 1+2*(N-1)*(N-1);
		ull R = 1+2*(N*N-1);
		cout<<"#"<<i+1<<" "<<L<<" "<<R<<endl;
	}
	return 0;
}
