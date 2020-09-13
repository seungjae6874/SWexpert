#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
using namespace std;

string check(int a, int b, int c, int size){
	
	if((a-b) >=2 || (a-b) <= -2) return "NO";
	if((a-c) >=2 || (a-c) <= -2) return "NO";
	if((c-b) >=2 || (c-b) <= -2) return "NO";
	
	return "YES";
}
int main(){
	int TC;
	cin>>TC;
	for(int i = 0; i<TC; i++){
		int N,K;
		cin>>N>>K;
		//n개 다이아의 각각 크기를 입력
		int *size = new int[N];
		for(int a=0; a<N; a++){
			cin>>size[a];// 각 다이아의 크기를 저장 
		}
		//배열 크기순 정렬
		int mine[N]= {1,};
		for(int i = 0; i < N; i++){
			mine[i] = 1;
		}
		//1  3  4 7 9 k는 3이면
		//1, 3, 4가능, 1,3,4,7 가능 4, 7, 9 가능
		//1 2 6 7 8 k는 3이면
		//1 2가능, 6,7,8 가능 총 5 
		// 1) 각 배열에 알맞은 최대 보석 갯수를 담고
		// 2) 가장 큰수부터 정렬
		// 3) 뒤에서부텉 수를 더해되 N보다 커지면 stop 
		
		//나랑 k 이하 차이나는 보석을 내 인덱스 배열에 담고
		//내 인덱스 배열 내에서 하나라도 서로 차이가 
		//1 4 6 이면 -> 나와 다른 것들의 크기 차가 | k |보다 작으면 배열로 저장
		for(int c = 0; c<N-1; c++){
			for(int d = c+1; d<N; d++){
				if(d != c){ //나 자신을 제외하고 
					if(abs(size[d]-size[c]) <= K){
						//차이가 K이하이면 담아라
						mine[c]++; 
					}
				}
			}
		}
		//cout<<"hi"<<endl;
		for(int i = 0; i < N; i++){
			//cout<<mine[i]<<endl;
		}
		//정렬 후에 최대값 출력
		sort(mine,mine+N);
		int answer = 0;
		for(int a = N-1; a>=0; a-- ){
			answer+=mine[a];
			if(answer > N){
				answer -= mine[a];
				break;
			}
		}
		cout<<"#"<<i+1<<" "<<answer<<endl;
	}
}
