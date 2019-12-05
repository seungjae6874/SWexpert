#include <iostream>

using namespace std;
int main()
{
	int T;
	cin>>T;
	string s;
	for(int i = 0; i< T; i++)
	{
		cin>>s;
		cout << "#" << i + 1 << " ";
		bool status = true;
		for(int j = 0; j< s.length()/2;j++)
		{
			if(s.at(j)!= s.at(s.length()-1-j))
			{	
				cout<<0<<endl;
				status = false;
				break;
			}		
			
		}
		if(status == true)
		{
			cout<<1<<endl;
		}
		
	}
	return 0;
}
