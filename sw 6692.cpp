#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i = 0; i<T; i++)
	{
		int N;
		cin>>N;
		float p[N];
		int x[N];
		double sum[N];
		double m=0.000000000;
		for(int j = 0; j<N; j++)
		{
			cin>>p[j]>>x[j];
			sum[j] = p[j]*x[j];
			
		}
		for(int a = 0; a<N;a++)
		{
			m += sum[a];
		}
		cout.setf(ios::fixed);
		cout.precision(6);
		cout<<"#"<<i+1<<" "<<m<<endl;
	}
	return 0;
}
