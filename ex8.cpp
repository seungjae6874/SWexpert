#include <iostream>
#include <string>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=0; i<T; i++)
	{
		char first[10];
		char second[10];
		int lenf=0;
		int lens =0;
		int firstB=0;
		int secondB=0;
		int cnt = 0;
		int cnt11 = 0;
		int cnt2 = 0;
		int cnt22 = 0;
		char no[20] = "CEFGHIJKLMNSTUVWXYZ";
		char no2[10] = "ADOPQR";
	
		int diff = 0;
		cin>>first>>second;
		for(int k=0; first[k] != NULL; k++)
		{
			lenf++;
			if(first[k] =='B')
			{
				firstB++;
			}
		}
		for(int k=0; second[k] != NULL; k++)
		{
			lens++;
			if(second[k] =='B')
			{
				secondB++;
			}
		}
		for(int a=0; first[a] != NULL; a++)
		{
			for(int b=0; second[b] != NULL; b++)
			{
				if((firstB == secondB) && (secondB != 0)) //�Ѵ� B�� ���� 
				{
					for(int c = 0; no[c] != NULL; c++)
					{
						if(first[a] == no[c])
						{
							cnt++;
						}
						if(second[b] == no[c])
						{
							cnt2++;
						}
						//cnt�� cnt2�� ������ no�� �ִ� ���ĺ� ���� ���� 
					}
					for(int d=0; no2[d] != NULL;d++)
					{
						if(first[a] == no2[d])
						{
							cnt11 += 10;
						}
						if(second[b] == no2[d])
						{
							cnt22 += 10;
						}
						//cnt11�� cnt22�� ������ no2�� �ִ� ���ĺ� ���� ���� 
					}
					
				}
				else if((firstB==0) && (secondB ==0)) //�Ѵ� B �Ȱ��� 
				{
					//�Ѵ� B�� �ȵ�� �մ� ���
					 for(int c = 0; no[c] != NULL; c++)
					{
						if(first[a] == no[c])
						{
							cnt++;
						}
						if(second[b] == no[c])
						{
							cnt2++;
						}
						//cnt�� cnt2�� ������ no�� �ִ� ���ĺ� ���� ���� 
					}
					for(int d=0; no2[d] != NULL; d++)
					{
						if(first[a] == no2[d])
						{
							cnt11 += 10;
						}
						if(second[b] == no2[d])
						{
							cnt22 += 10;
						}
						//cnt11�� cnt22�� ������ no2�� �ִ� ���ĺ� ���� ���� 
					}
				}
				else if( firstB != secondB){ //���� �ϳ��� B������ �׳� �ٸ� 
					diff = 1;
				} 
				
			
			}
		}
		if(lenf != lens)
		{
			cout<<"#"<<i+1<<" DIFF"<<endl;
				}		
		else if(lenf == lens)
		{
			if(((cnt > 0) && (cnt2 > 0))||((cnt11 > 0) && (cnt22 > 0)))
			{
				if((cnt==cnt2)&&(cnt11 == cnt22))
				{
					cout<<"#"<<i+1<<" SAME"<<endl;
				}
				else{
					cout<<"#"<<i+1<<" DIFF"<<endl;
				}
			}
			else if( diff == 1){
			cout<<"#"<<i+1<<" DIFF"<<endl;
			}
		}
		
	}	
	return 0;
}
