#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dis(int(*m)[12],int x,int y,int n){
	int cnt = 0;
	int dx=0;
	int dy=0;
	int dz=0;
	int dw=0;//�������ⰹ�� 
	int real = 0;//���� ���ⰹ�� 
	for(int i = 0; i<x; i++){
		if(m[i][y] != 0){
			dx++;
		}
	}
	if(dx == 0){
		real++;	
	}
	for(int i = x+1; i<n; i++){
		if(m[i][y] != 0){
			dy++;
		}
	}
	if(dy==0){
		real++;	
	}
	for(int j = 0;j<y;j++){
		if(m[x][j] !=0){
			dz++;
		}
	}
	if(dz==0){
		real++;	
	}
	for(int j = y+1; j<n;j++){
		if(m[x][j] != 0){
			dw++;
		}
	}
	if(dw==0){
		real++;	
	}
	//cout<<'���� ���� ���� '<<real<<endl; 
	return real;
}
int mindis(int(*m)[12],int x, int y, int n,int s){
	//x,y�� ���� �ּ��� ����� ���� ��ǥ s�� ����� 
	vector<int> min;
	int dx=0;
	int dy=0;
	int dw=0;
	int dz=0;
	for(int a = 0; a < x; a++){
		if(m[a][y]==0){
			dx++;
		}
	}
	if(dx == x){
		min.push_back(dx);
	}
	for(int a = x+1; a < n; a++){
		if(m[a][y]==0){
			dy++;
		}
	}
	if(dy == n-x-1){
		min.push_back(dy);
	}
	for(int a = 0; a < y; a++){
		if(m[x][a]==0){
			dw++;
		}
	}
	if(dw == y){
		min.push_back(dw);
	}
	for(int a = y+1; a < n; a++){
		if(m[x][a]==0){
			dz++;
		}
	}
	if(dz == n-y-1){
		min.push_back(dz);
	}
	sort(min.begin(),min.end());
	int start=0;
	int end= 0; 
	//���� ��ġ�ε��� ã�Ƴ��� 
	if(min[0] == dx){
		for(int a = 0; a < x; a++){
			m[a][y] = -1;
		}
	}
	if(min[0] == dy){
		for(int a = x+1; a < n; a++){
			m[a][y] = -1;
		}
	}
	if(min[0] == dw){
		for(int a = 0; a < y; a++){
			m[x][a] = -1;
		}
	}
	if(min[0] == dz){
		for(int a = y+1; a < n; a++){
			m[x][a] = -1;
		}
	}
	return min[0];
}
int main(){
	int T;
	cin>>T;
	for(int i=0; i < T; i++){
		int N;
		cin>>N;
		int m[12][12] = {-1,};
		for(int a =0; a<N; a++){
			for(int b = 0; b<N; b++){
				cin>>m[a][b];
			}
		}
		//�켱 �׵θ��� �ִ� 1�� ��� x
		//�켱 �׵θ��� �ƴ� 1�� ģ������ ��ġ�� ��� üũ
		// �׸��� ���� �ڽ��� �������Ͽ��� ���� �׵θ��� ����� �Ÿ��� üũ
		// ���� �Ÿ��� ����� ������� ���� �� ������ ��� 1�� �ٲ۴�.
		// ��� �ֽ�ȭ�� �迭���� ����� ������ ������ ������ �ɵ�?
		int core=0;
		for(int i=1 ; i < N-1; i++){
			for(int j =1 ; j <N-1; j++){
				if(m[i][j]==1){
					core++;	
				}
			}
		}
		int countcore = 0;
		while(countcore != core){
			int core1=0;
			for(int i=1 ; i < N-1; i++){
				for(int j =1 ; j <N-1; j++){
					if(m[i][j]==1){
						core1++;	
					}
				}
			}
			int temp[core1][3]={N,};
			int cnt = 0;
			//���� �ھ� ���� = core 
			for(int a = 1 ; a < N-1; a++){
				for(int b= 1; b < N-1; b++){
				
					if(m[a][b]==1){
						cout<<"��ǥ "<<a<<" "<<b<<" "<<dis(m,a,b,N)<<endl;
					//�׵θ��� �ƴϸ鰡�� �׵θ��� �Ÿ� ������ ã��	
						temp[cnt][0] = dis(m,a,b,N);
						temp[cnt][1] = a;
						temp[cnt][2] = b;
						cnt++;
					
					}
				}
			}
		
			int min = temp[0][0];
			int minx = temp[0][1];
			int miny = temp[0][2];
			for(int a = 0 ; a < core1; a++){
				//cout<<temp[a][1]<<" "<<temp[a][2]<<endl;
				if(min >= temp[a][0]){
					min = temp[a][0];
					minx= temp[a][1];
					miny = temp[a][2];
				}
			}
			cout<<min<<" "<<minx<<" "<<miny<<endl;
			cout<<"�߰� ���� �Ÿ� "<<mindis(m,minx,miny,N,min)<<endl;
			//min�� ��ǥ�� temp���� ����
			for(int a = 0; a < core1; a++){
				if(min == temp[a][0]){
					//for(int b= a; b < core1; b++){
					//	temp[b][0] = 
					//}
					m[temp[a][1]][temp[a][2]] = 2;
				}
			}
			//�迭�� ���� �Ϸ�
			//���� �ٽ� �ݺ��ϸ�  
			countcore++;
		}
		
		
	}
}
