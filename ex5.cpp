#include<iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=0; i<T; i++)
	{
		int h,m,h2,m2;
		cin>>h>>m>>h2>>m2;
		int sumh,summ;
		sumh = h+h2;
		summ = m+m2;
		if(summ > 60)
		{
			summ -= 60;
			sumh += 1;
		}
		if(sumh > 12)
		{
			sumh-= 12;
		}
		cout<<"#"<<i+1<<" "<<sumh<<" "<<summ<<endl;
	}
	return 0;
}
