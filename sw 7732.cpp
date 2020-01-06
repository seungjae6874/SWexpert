#include<iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=0; i<T; i++)
	{
		int time,hour,second;//현재시간 
		int time1, hour1,second1;//약속시간 
		int time2 = 0;
		int hour2 = 0;
		char term;
		int second2= 0;;//남은시간 
		cin>>time>>term>>hour>>term>>second;
		cin>>time1>>term>>hour1>>term>>second1;
		//현재시간보다 약속시간이 작으면 약속시간은 그 다음 날임
		if(second > second1) //약속시간이 더 작은경우 약속시간은 다음날 
		{
			second1 = second1+60;
			second2 = second1-second;
			if(hour > hour1) //약속시간의 분이 더 작은경우 
			{
				hour1 = hour1+59;
				hour2 = hour1-hour;
				if(time > time1) //초가 약속시간이 더 작은 경우
				{
					time1 = time1+23;
					time2 = time1-time;
					
				 } 
				 else{
				 	time2 = time1-time;
				 }
				 
				
			}
			else {//약속시간이 시는 작은 데 분은 큰경우 
				if(time > time1) //약속 초가 더 작을때 
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
		//약속시간이 현재시간보다 큰경우 
		else{
			second2 = second1 - second;
			if(hour > hour1) //약속시간의 분이 더 작은경우 
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
			else{ //약속시간의 분이 더 큰 경우 그냥 뺴면 됨 
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
				else{//초는 아닌경우 
					cout<<"#"<<i+1<<" "<<"0"<<time2<<":0"<<hour2<<":"<<second2<<endl;
				} 
				 	
			}
			else{ //분은 10이상인 경우 
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
		else{ //남은 시간이 10 이상일때 
			if(10>hour2)
			{
				if(10>second2)
				{	
				cout<<"#"<<i+1<<" "<<time2<<":0"<<hour2<<":0"<<second2<<endl; 
				}
				else{//초는 아닌경우 
					cout<<"#"<<i+1<<" "<<time2<<":0"<<hour2<<":"<<second2<<endl;
				} 
				 	
			}
			else{ //분은 10이상인 경우 
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
