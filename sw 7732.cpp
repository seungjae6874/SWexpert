#include<iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=0; i<T; i++)
	{
		int time,hour,second;//����ð� 
		int time1, hour1,second1;//��ӽð� 
		int time2 = 0;
		int hour2 = 0;
		char term;
		int second2= 0;;//�����ð� 
		cin>>time>>term>>hour>>term>>second;
		cin>>time1>>term>>hour1>>term>>second1;
		//����ð����� ��ӽð��� ������ ��ӽð��� �� ���� ����
		if(second > second1) //��ӽð��� �� ������� ��ӽð��� ������ 
		{
			second1 = second1+60;
			second2 = second1-second;
			if(hour > hour1) //��ӽð��� ���� �� ������� 
			{
				hour1 = hour1+59;
				hour2 = hour1-hour;
				if(time > time1) //�ʰ� ��ӽð��� �� ���� ���
				{
					time1 = time1+23;
					time2 = time1-time;
					
				 } 
				 else{
				 	time2 = time1-time;
				 }
				 
				
			}
			else {//��ӽð��� �ô� ���� �� ���� ū��� 
				if(time > time1) //��� �ʰ� �� ������ 
				{
					
					time1 = time1+24;
					if(hour1 == 0)
					{
						hour1 +=59;
						time1 -=1;
					}
					hour2 = hour1 - hour;
					time2 = time1-time;
					
				}
				else{
					if(hour1 == 0)
					{
						hour1 +=59;
						time1 -=1;
					}
					hour2 = hour1- hour;
					time2 = time1-time;
				}
				
			}
		}
		//��ӽð��� ����ð����� ū��� 
		else{
			second2 = second1 - second;
			if(hour > hour1) //��ӽð��� ���� �� ������� 
			{
				hour1 += 60;
				hour2 = hour1-hour;
				if(time > time1)
				{
					time1 += 23;
					time2 = time1-time;
				}
				else{
					time2 = time1-time;
					
				}
				
				
			}
			else{ //��ӽð��� ���� �� ū ��� �׳� ���� �� 
				hour2 = hour1-hour;
				if(time > time1)
				{
					time1 +=24;
					time2 = time1-time;
					
				}
				else{
					time2 = time1-time;
				}
	
				
			}
		} 
		if(10>time2)
		{
			if(10>hour2)
			{
				if(10>second2)
				{	
				cout<<"#"<<i+1<<" "<<"0"<<time2<<":0"<<hour2<<":0"<<second2<<endl; 
				}
				else{//�ʴ� �ƴѰ�� 
					cout<<"#"<<i+1<<" "<<"0"<<time2<<":0"<<hour2<<":"<<second2<<endl;
				} 
				 	
			}
			else{ //���� 10�̻��� ��� 
				if(10>second2)
				{
					cout<<"#"<<i+1<<" "<<"0"<<time2<<":"<<hour2<<":0"<<second2<<endl; 
				}	
				else{
					cout<<"#"<<i+1<<" "<<"0"<<time2<<":"<<hour2<<":"<<second2<<endl; 
					
				}
			} 
			
			//cout<<"#"<<i+1<<" "<<"0"<<time2<<":"<<hour2<<":"<<second2<<endl;
			
		}
		else{ //���� �ð��� 10 �̻��϶� 
			if(10>hour2)
			{
				if(10>second2)
				{	
				cout<<"#"<<i+1<<" "<<time2<<":0"<<hour2<<":0"<<second2<<endl; 
				}
				else{//�ʴ� �ƴѰ�� 
					cout<<"#"<<i+1<<" "<<time2<<":0"<<hour2<<":"<<second2<<endl;
				} 
				 	
			}
			else{ //���� 10�̻��� ��� 
				if(10>second2)
				{
					cout<<"#"<<i+1<<" "<<time2<<":"<<hour2<<":0"<<second2<<endl; 
				}	
				else{
					cout<<"#"<<i+1<<" "<<time2<<":"<<hour2<<":"<<second2<<endl; 
					
				}
			} 
		}
	}
	return 0;
}
