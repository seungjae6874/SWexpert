#include<iostream>
#include<algorithm>
using namespace std;
//입력 받은 수의 길이를 계산하는 함수 
int fun(int y){
	int c=0;
	while(y>0){
		y = y/10;
		c++;
	}
	return c;
}
int main()
{
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int X;
		cin>>X;
		//x를 입력 받고 몇자리 수인지 파악해서 배열에 담고 정렬
		//수가 달라지는 인덱스 발생시 카운트 증가 
		int len = fun(X);
		int cnt = 1;
		int *array = new int[len];
		int index = 0;
		int rest =0;
		for(int i =0; i<len; i++){
			rest = X%10;
			array[index] = rest;
			index++;
			X /= 10;
		}
		sort(array,array+len);
		for(int i = 0; i<len; i++){
			if(i>0 && (array[i] != array[i-1])){
				cnt++;
			}
		}
		cout<<"#"<<i+1<<" "<<cnt<<endl;
	}
}
