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
		//���� ū�� ���ϰ� 1 �� �ϰ� ���� ū�� ���ϰ� 1 ���ϰ� �״��� ū �� ���ϰ� 
		//������ �� ���� ��������*2 + N �ϸ� �ּڰ� 
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
