#include<iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i =0; i<T; i++)
	{
		int K=0; 
		cin>>K;
		int cnt=0;//���� �ֱ� �Աݾ��� ������
		int zero=0;//0�� ��� �������� ī��Ʈ 
		int m;//���� �Ա��ϴ� �� 
		int sum=0; //���� ���� �����ϴ� ����
		int *lastm = new int[K];// ���� ��ϵ��� ��� ����		 
		for(int j = 0; j < K; j++)
		{
			cin>>m;
			//cout<<"Money : "<<m<<endl;
			if(m==0){
				sum -= lastm[--cnt];
				
					 
			}
			else{
				lastm[cnt] = m;
				cnt++;
				sum += m;
			}
			//cout<<"Sum : "<<sum<<endl;
		}
		cout<<"# "<<i+1<<" "<<sum<<endl; 
		
	}
}
