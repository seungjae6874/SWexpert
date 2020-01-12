#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for (int i = 0; i< T; i++)
	{
		string ans;
		cin>>ans;
		int len;
		int num=1;
		len = ans.length();
		char *a = new char[len];
		for(int i = 0; i<len; i++)
		{
			a[i] = ans.at(i);
			
		}
		for(int i = 0; i<len; i++)
		{
			if((i == 0) || (i == len-1))
			{
				if(i==0)
				{
					if(a[i] == a[i+1])
					{
						num *=1;
					}
					else{
						num*=2;
					}
				}
				else if(i== len-1)
				{
					if(a[i] == a[i-1])
					{
						num *= 1;
					}
					else{
						num *=2;
					}	
				}
				
			}
			else{
				if((a[i]== a[i-1]) &&(a[i] != a[i+1]))
				{
					num *=2;
					
				}
				else if((a[i]==a[i+1])&&(a[i] != a[i-1]))
				{
				
					num *=2;
					
				}
				else if((a[i]!=a[i-1])&&(a[i] != a[i+1]))
				{
					num *=3;	
				}
				else if((a[i]==a[i-1])&&(a[i] == a[i+1]))
				{
					num *=1;
				}
			}
		}
		cout<<"#"<<i+1<<" "<<num<<endl;
		
	}
	return 0;
}
