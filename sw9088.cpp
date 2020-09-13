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
		//n�� ���̾��� ���� ũ�⸦ �Է�
		int *size = new int[N];
		for(int a=0; a<N; a++){
			cin>>size[a];// �� ���̾��� ũ�⸦ ���� 
		}
		//�迭 ũ��� ����
		int mine[N]= {1,};
		for(int i = 0; i < N; i++){
			mine[i] = 1;
		}
		//1  3  4 7 9 k�� 3�̸�
		//1, 3, 4����, 1,3,4,7 ���� 4, 7, 9 ����
		//1 2 6 7 8 k�� 3�̸�
		//1 2����, 6,7,8 ���� �� 5 
		// 1) �� �迭�� �˸��� �ִ� ���� ������ ���
		// 2) ���� ū������ ����
		// 3) �ڿ����ζ� ���� ���ص� N���� Ŀ���� stop 
		
		//���� k ���� ���̳��� ������ �� �ε��� �迭�� ���
		//�� �ε��� �迭 ������ �ϳ��� ���� ���̰� 
		//1 4 6 �̸� -> ���� �ٸ� �͵��� ũ�� ���� | k |���� ������ �迭�� ����
		for(int c = 0; c<N-1; c++){
			for(int d = c+1; d<N; d++){
				if(d != c){ //�� �ڽ��� �����ϰ� 
					if(abs(size[d]-size[c]) <= K){
						//���̰� K�����̸� ��ƶ�
						mine[c]++; 
					}
				}
			}
		}
		//cout<<"hi"<<endl;
		for(int i = 0; i < N; i++){
			//cout<<mine[i]<<endl;
		}
		//���� �Ŀ� �ִ밪 ���
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
