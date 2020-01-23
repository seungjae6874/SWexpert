#include <iostream>
using namespace std;
int main(){
	int T=0;
	cin>>T;
	for(int i =0; i<T; i++ ){
		int n=0;
		int m=0;
		cin>>n>>m;
		//주차장의 각 자리마다 요금배열
		int *park = new int[n];
		//주차 하게되면 주차 index 저장 배열 
		int rpark[n] = {0,}; 
		for(int a=0; a<n; a++){
			int r=0; 
			cin>>r;
			park[a] = r;
			cout<<a<<"번 위치 단위 주차 요금은 "<<park[a]<<"입니다."<<endl; 
		}
		//오늘 들어오는 차의 무게배열
		int *weight = new int[m];
		int *carsparkinglot = new int[m];
		for(int b = 0; b<m; b++){
			int w = 0;
			cin>>w;
			weight[b] = w;
			cout<<b<<"번 차량의 무게는 "<<weight[b]<<"입니다."<<endl;
		}
		//총 주차요금 계산저장 배열 
		int sum[m] = {0,};
		int count = 0;
		int cnt = 0;//주차장의 현재까지 채워져 있는 위치포인터cnt는 최대 n-1이다.
		int realx=0;
		int wait[m] = {0,};//주차장 꽉 찼을 때 대기하는 배열 
		int turn = 0;//대기실 위치포인터 
		//이제 하루 동안 들어오고 나가는 2m만큼 입력
		for(int c = 0; c < 2*m; c++){
			int x=0;
			//x는 최대 m의 크기이다. 
			cin>>x;
					
			if(x>0){
				if(x > m){
					cout<<"잘못된 차번호 입니다 다시 입력해주세요 ";
					cin>>x;
				}
				//양수이므로 주차들어옴 
				//여기서 중요한건 주차장은 큐 처럼 선입 선출이다. 따라서 cnt가 n이면 대기해야함
				cout<<x<<"번 차량입니다."<<endl;
				cout<<"차 들어오기 전 count : "<<count<<endl;
				if(count >= n){//주차장 꽉참 
					cout<<"대기실 "<<turn<<"번으로 이동합니다."<<endl;
					wait[turn++] = x; //대기실에 자동차 번호를 저장 
					
				} 
				else if(count < n){//주차장 자리 있음 
					for(int p =0; p<n; p++){
						if(rpark[p] < 1){ //비어있는 맨 앞자리부터 
							rpark[p] = x; //주차위치에 차  번호 저장
							count++;
							carsparkinglot[x-1] = p; //차에 주차위치 저장 
							cout<<"주차공간이 있어 "<<p<<" 번 위치에 주차합니다. count는 "<<count<<endl;
							break;		
						}
					}
					cout<<"주차 후 반복문 탈출cnt는 "<<cnt<<endl;					
					//cnt++;
				}
				 
			}
			else if(x < 0){//차가 주차장 나가서 자리 생김-> 계산하고, 자리 비우기
			//그리고 대기배열에서 맨 앞에 차 뺴주기
				if(x < -m){
					cout<<"잘못된 차번호 입니다. 다시 입력해주세요 : ";
					cin>>x;
				}
				cout<<-x<<"번 차량입니다."<<endl; 		
				realx = -x;
				sum[realx-1] = park[carsparkinglot[realx-1]]*weight[realx-1];
				cout<<"주차요금은 "<<sum[realx-1]<<endl;
				cout<<realx<<"번 차량이 출차합니다."<<carsparkinglot[realx-1]<<"번 주차칸이 비어집니다."<<endl; 
				//이건 wait하는 차가 있어야 하는 것 
				if(wait[0] > 0){
					carsparkinglot[wait[0]-1] = carsparkinglot[realx-1];//새로 들어온 차에 주차위치 번호 할당
					cout<<"대기실의 "<<wait[0]<<"번 차량이 "<<carsparkinglot[wait[0]-1]<<" 번 주차칸으로 들어옵니다."<<endl; 
					carsparkinglot[realx-1] = 0;
					for(int i = 1; i< m; i++){
					//대기실 번호 앞으로 한칸씩 당겨주기
						wait[i-1] = wait[i]; 
					}
					turn -= 1;
				}
				else{
					rpark[carsparkinglot[realx-1]] = 0;	
					count--;
					
				}
				//carsparkinglot[wait[0]] = carsparkinglot[realx-1];//새로 들어온 차에 주차위치 번호 할당
				
				//cout<<"대기실의 "<<wait[0]<<"번 차량이 "<<carsparkinglot[realx-1]<<" 번 주차칸으로 들어옵니다."<<endl; 
				 
				 
				 
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
