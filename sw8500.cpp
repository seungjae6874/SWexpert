#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i =0; i<T; i++)
	{
		int sum =0;
		int N;
		int *A = new int[N];
		cin>>N;
		for(int j=0; j<N; j++)
		{
			int k;
			cin>>k;
			A[j] = k;
		}
		sort(A,A+N);
		//가장 큰값 더하고 1 더 하고 가장 큰값 더하고 1 더하고 그다음 큰 값 더하고 
		//마지막 값 제외 나머지값*2 + N 하면 최솟값 
		for(int a = N-1; a >= 0; a--)
		{
			if(a != A[N-1])
			{
				sum += 2*A[a];	
			}
			else if( a == A[N-1])
			{
				sum += A[a];
			}
			sum += N;
			
		}
		cout<<"#"<<i+1<<" "<<sum<<endl;
		sum = 0;
	}
	return 0;
}
