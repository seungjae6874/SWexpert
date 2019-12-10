#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i = 0; i < T; i++)
	{
		int N,K;
		int cnt = 0;
		cin>>N>>K;
		string stu[N];
		string grade[10] = {"A+","A0","A-","B+","B0","B-","C+","C0","C-","D0"};
		int mid[N];
		int fin[N];
		int hw[N];
		double sum[N];
		for(int a = 0; a< N; a++)
		{
			cin>>mid[a]>>fin[a]>>hw[a];
			sum[a] = 0.35*mid[a]+0.45*fin[a]+0.2*hw[a];
					
		}
		sort(sum,sum+N);
		for(int a = 0; a< N; a++)
		{
			cout<<sum[a]<<endl;
		}
		for(int b= 0; b< N; b++)
		{
			if(((b+1) % (N/10))== 0)
			{
				stu[b] = grade[10-cnt];
				cnt++;
			}
			else{
				stu[b] = grade[cnt];
			}
		}
	
		cout<<"#"<<i<<" "<<stu[K-1];
	}
	return 0;
}
