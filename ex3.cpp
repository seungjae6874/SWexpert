#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i = 0; i< T; i++)
	{
		double sum=0;
		double avg = 0;
		int number[10] = {0,};
	
		for(int a = 0; a<10; a++)
		{
			cin>>number[a];	
		}
		sort(number,number+10);
		
		for(int j = 1;j<9; j++)
		{
			//cout<<number[j]<<" ";
			sum += number[j];
		}
		avg = round(sum/8.0);
		
		cout<<"#"<<i+1<<" "<<avg;
	}
	return 0;
}
