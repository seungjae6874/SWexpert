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
		int N,K;
		cin >>N >>K;
		int *a = new int[N];
		int *b = new int[N];
		for(int i =0; i < N; i++){
			cin>>a[i];
		}
		for(int j = 0; j< N; j++){
			cin>>b[j];
		}
		int *c = new int[K];
		//A �� B�迭�� ���� �ϰ��� , K�Ͽ� ���缭 �ڸ���.
		sort(a,a+N);
		sort(b,b+N);
		int *b2 = new int[K];
		sort(b,b+K,desc);
		for(int c = 0; c<K; c++){
			cout<<b[c];
		}
		//�� �Ŀ� B�迭�� ��������, A�迭�� ������������ ����
		//C �迭�� ���� �� �� �ε����� ���Ѵ�.
		for(int k=0; k< K; k++){
			c[k] = a[k]+b[k];
		}
		cout<<a[K-1]<<" "<<b[K-1]<<endl;
		sort(c,c+K);
		Answer = c[K-1];
		//���� �ּҰ��� ����. 
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
