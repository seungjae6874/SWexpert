#include <iostream>
using namespace std;
int main(){
	int T=0;
	cin>>T;
	for(int i =0; i<T; i++ ){
		int n=0;
		int m=0;
		cin>>n>>m;
		//�������� �� �ڸ����� ��ݹ迭
		int *park = new int[n];
		//���� �ϰԵǸ� ���� index ���� �迭 
		int rpark[n] = {0,}; 
		for(int a=0; a<n; a++){
			int r=0; 
			cin>>r;
			park[a] = r;
			cout<<a<<"�� ��ġ ���� ���� ����� "<<park[a]<<"�Դϴ�."<<endl; 
		}
		//���� ������ ���� ���Թ迭
		int *weight = new int[m];
		int *carsparkinglot = new int[m];
		for(int b = 0; b<m; b++){
			int w = 0;
			cin>>w;
			weight[b] = w;
			cout<<b<<"�� ������ ���Դ� "<<weight[b]<<"�Դϴ�."<<endl;
		}
		//�� ������� ������� �迭 
		int sum[m] = {0,};
		int count = 0;
		int cnt = 0;//�������� ������� ä���� �ִ� ��ġ������cnt�� �ִ� n-1�̴�.
		int realx=0;
		int wait[m] = {0,};//������ �� á�� �� ����ϴ� �迭 
		int turn = 0;//���� ��ġ������ 
		//���� �Ϸ� ���� ������ ������ 2m��ŭ �Է�
		for(int c = 0; c < 2*m; c++){
			int x=0;
			//x�� �ִ� m�� ũ���̴�. 
			cin>>x;
					
			if(x>0){
				if(x > m){
					cout<<"�߸��� ����ȣ �Դϴ� �ٽ� �Է����ּ��� ";
					cin>>x;
				}
				//����̹Ƿ� �������� 
				//���⼭ �߿��Ѱ� �������� ť ó�� ���� �����̴�. ���� cnt�� n�̸� ����ؾ���
				cout<<x<<"�� �����Դϴ�."<<endl;
				cout<<"�� ������ �� count : "<<count<<endl;
				if(count >= n){//������ ���� 
					cout<<"���� "<<turn<<"������ �̵��մϴ�."<<endl;
					wait[turn++] = x; //���ǿ� �ڵ��� ��ȣ�� ���� 
					
				} 
				else if(count < n){//������ �ڸ� ���� 
					for(int p =0; p<n; p++){
						if(rpark[p] < 1){ //����ִ� �� ���ڸ����� 
							rpark[p] = x; //������ġ�� ��  ��ȣ ����
							count++;
							carsparkinglot[x-1] = p; //���� ������ġ ���� 
							cout<<"���������� �־� "<<p<<" �� ��ġ�� �����մϴ�. count�� "<<count<<endl;
							break;		
						}
					}
					cout<<"���� �� �ݺ��� Ż��cnt�� "<<cnt<<endl;					
					//cnt++;
				}
				 
			}
			else if(x < 0){//���� ������ ������ �ڸ� ����-> ����ϰ�, �ڸ� ����
			//�׸��� ���迭���� �� �տ� �� ���ֱ�
				if(x < -m){
					cout<<"�߸��� ����ȣ �Դϴ�. �ٽ� �Է����ּ��� : ";
					cin>>x;
				}
				cout<<-x<<"�� �����Դϴ�."<<endl; 		
				realx = -x;
				sum[realx-1] = park[carsparkinglot[realx-1]]*weight[realx-1];
				cout<<"��������� "<<sum[realx-1]<<endl;
				cout<<realx<<"�� ������ �����մϴ�."<<carsparkinglot[realx-1]<<"�� ����ĭ�� ������ϴ�."<<endl; 
				//�̰� wait�ϴ� ���� �־�� �ϴ� �� 
				if(wait[0] > 0){
					carsparkinglot[wait[0]-1] = carsparkinglot[realx-1];//���� ���� ���� ������ġ ��ȣ �Ҵ�
					cout<<"������ "<<wait[0]<<"�� ������ "<<carsparkinglot[wait[0]-1]<<" �� ����ĭ���� ���ɴϴ�."<<endl; 
					carsparkinglot[realx-1] = 0;
					for(int i = 1; i< m; i++){
					//���� ��ȣ ������ ��ĭ�� ����ֱ�
						wait[i-1] = wait[i]; 
					}
					turn -= 1;
				}
				else{
					rpark[carsparkinglot[realx-1]] = 0;	
					count--;
					
				}
				//carsparkinglot[wait[0]] = carsparkinglot[realx-1];//���� ���� ���� ������ġ ��ȣ �Ҵ�
				
				//cout<<"������ "<<wait[0]<<"�� ������ "<<carsparkinglot[realx-1]<<" �� ����ĭ���� ���ɴϴ�."<<endl; 
				 
				 
				 
			}
		}
		int total=0;
		for(int s =0; s <m; s++){
			if(sum[s] != 0){
				total += sum[s];
			}
		}
		cout<<"#"<<i+1<<" "<<total<<endl;
	}
}
