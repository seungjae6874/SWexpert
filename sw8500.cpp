#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int T=0;
	cin>>T;
	for(int i =0; i<T; i++)
	{
		int count = 0;
		int sum =0;
		int N;
		int A[100000] = {0,};
		cin>>N;
		for(int j=0; j<N; j++)
		{
			int k;
			cin>>k;
			A[j] = k;
		}
		sort(A,A+N);
		for(int a = N-1; a >= 0; a--)
		{
			if(a == N-1)
			{
				sum += 2*A[a];	
			}
			else
			{
				sum += A[a];
			}
		}
		sum += N;
		cout<<"#"<<i+1<<" "<<sum<<endl;	
	}
	return 0;
}
