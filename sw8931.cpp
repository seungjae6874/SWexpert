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
			lastm[cnt] = m;
			cnt++;
			cout<<"Money : "<<m<<endl;
			if(m==0){
				int p = 2;
				if(lastm[cnt-p] == 0){
					while(lastm[p] != 0){
						p++;
						cout<<p<<endl;
					}
					sum -= lastm[p];	
				}
				else{
					sum -= lastm[cnt-2];
				}
				
					 
			}
			else{
				sum += m;
			}
			cout<<"Sum : "<<sum<<endl;
		}
		
		
	}
}
