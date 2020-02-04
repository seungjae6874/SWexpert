#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	for(int i =0; i<T; i++){
		string word[3];
		char *sum = new char[3];
		for(int i =0; i< 3; i++){
			cin>>word[i];
			char *w = new char[word[i].length()];
			strcpy(w,word[i].c_str());
			cout<<w[0]<<endl;
			sum[i] = toupper(w[0]);
			//cout<<word[i]<<endl;
		}
		cout<<sum<<endl;
	}
}
