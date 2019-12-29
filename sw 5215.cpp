#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i =0; i<T; i++)
	{
		int N,L;
		cin>>N>>L;
		int T[N];
		int K[N];
		int sum[N][2];
		for(int j = 0; j<N; j++)
		{
			cin>>T[j]>>K[j];
			sum[j][1] = K[j];
			
		}
		for(int j = 0; j<N-1;j++)
		{
			for(int k = j+1; k<N; k++)
			{
				if(sum[k][0] > sum[j][0])
				{
					int temp;
					temp = sum[k][0];
					sum[k][0] = sum[j][0];
					sum[j][0] = temp;
					
				}
				
			}
		}
		for(int a = 0; a<N; a++)
		{
			cout<<sum[a][0]<<endl;
		}
	}
	return 0;
}
