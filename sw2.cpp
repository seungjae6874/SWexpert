/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <algorithm>

using namespace std;

int Answer;
bool desc(int a, int b){
	return a > b;
}
int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		int n,K;
		cin >>n >>K;
		int *a = new int[n];
		int *b = new int[n];
		int aflag=0;
		int bflag= 0;
		for(int i =0; i < n; i++){
			cin>>a[i];
			if(a[i] == K){
				aflag = 1;
			}
		}
		for(int j = 0; j< n; j++){
			cin>>b[j];
			if(b[j] == K){
				bflag = 1;
			}
		}
		//n이 짝수이면 total은 홀수이고
		//k가 팩 내에 있으면 답은 total-1/2 +1/total-1/2
		//k가 팩에 없으면 total/3*2 / total/3
		//n이 홀수 total은 짝수
		// 반반
		int an1,an2;
		int total = 0; 
		if(n %2 == 0){
			total = (n+1)*(n+1);
			int half = (total-1)/2;
			if((aflag == 0) && (bflag == 0)){
				an1 = (total/3)*2;
				an2 = (total/3);
			}
			else{
				an1 = half+1;
				an2 = half;
			}
		}
		else{
			total = (n+1)*(n+1);
			an1 = total/2;
			an2 = total/2;
		}
		
		
		
		//가장 최소값이 정답. 
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << an1<<" "<<an2 << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
