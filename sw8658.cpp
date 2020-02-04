#include <iostream>
#include <algorithm>
using namespace std;
int fun(int x){
	int sum =0;
	while(x !=0){
		sum += x % 10; 
		x /= 10;
	}
	return sum;
}
int main(){
	int T;
	cin>>T;
	for(int i = 0; i< T; i++){
		int *num = new int[10];
		int *sum = new int[10];
		for(int i = 0; i < 10; i++){
			cin>>num[i];
			sum[i] = fun(num[i]);	
		}
		int min = *min_element(sum,sum+10);
		int max = *max_element(sum,sum+10);
		
		cout<<"#"<<i+1<<" "<<max<<" "<<min<<endl;
	}
	return 0;
}
