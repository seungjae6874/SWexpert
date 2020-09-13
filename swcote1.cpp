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
	int dw=0;//막힌방향갯수 
	int real = 0;//가능 방향갯수 
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
	//cout<<'전선 가능 방향 '<<real<<endl; 
	return real;
}
int mindis(int(*m)[12],int x, int y, int n,int s){
	//x,y는 가장 최소의 방향수 갖는 좌표 s는 방향수 
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
	//전선 위치인덱스 찾아내기 
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
		//우선 테두리에 있는 1은 계산 x
		//우선 테두리가 아닌 1인 친구들의 위치를 모두 체크
		// 그리고 나서 자신의 동서남북에서 가장 테두리랑 가까운 거리를 체크
		// 가장 거리가 가까운 순서대로 먼저 그 라인을 모두 1로 바꾼다.
		// 계속 최신화된 배열에서 가까운 순으로 전선을 이으면 될듯?
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
			//내부 코어 갯수 = core 
			for(int a = 1 ; a < N-1; a++){
				for(int b= 1; b < N-1; b++){
				
					if(m[a][b]==1){
						cout<<"좌표 "<<a<<" "<<b<<" "<<dis(m,a,b,N)<<endl;
					//테두리가 아니면가장 테두리라 거리 가까운놈 찾기	
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
			cout<<"추가 전선 거리 "<<mindis(m,minx,miny,N,min)<<endl;
			//min의 좌표는 temp에서 제거
			for(int a = 0; a < core1; a++){
				if(min == temp[a][0]){
					//for(int b= a; b < core1; b++){
					//	temp[b][0] = 
					//}
					m[temp[a][1]][temp[a][2]] = 2;
				}
			}
			//배열도 갱신 완료
			//이제 다시 반복하면  
			countcore++;
		}
		
		
	}
}
