#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int T;
	cin>>T;
	for(int i =0; i< T; i++){
		int n;
		cin>>n;
		int *coin = new int[n];
		unsigned long long count = 0;		
		for(int a = 0; a< n; a++){
			coin[a] = a+1;
		}
		do{
			int *coin2 = new int[n];
			int *fb = new int[n]; //앞 뒤를 저장하는 배열 
			for(int b = 0; b<n; b++){
				coin2[b] = coin[b];
				fb[b] = 0;
				
			}
			for(int c = 0; c < n-1; c++){
				for(int d = c+1; d < n; d++){
					if(coin2[c] < coin2[d]){
						if(fb[d] == 1){
							fb[d] = 0;
						}
						else if(fb[d] == 0)
						{
							fb[d] = 1;
						}
					}
				}
			}
			for(int k = 0; k < n; k++){
				if(fb[k] == 1){
					count++;
				}	
			}
		}while(next_permutation(coin, coin+n));
		unsigned long long ans = count%1000000007;
		cout<<"#"<<i+1<<" "<<ans<<endl;
	}
	return 0;
}
