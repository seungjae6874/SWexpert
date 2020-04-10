#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(),greater<int>());
    int num = atoi(numbers.c_str());
    long long *p = new long long[num +3];//p배열은 해당수가 에라토스네스 체 즉 n은 
    //sqrt(n)보다 작은 수들로 나눠지지 않으면 그 수는 소수이다.의 boolean 배열이다.
    for(int i = 2; i < sqrt(num); i++){
        if(!p[i]){
            for(int j = i*i; j<=num; j+=i){
                p[j] = 1;
            }
        }
    }
    for(int i = 2 ; i <= num; i++){
        if(p[i]==0)//소수임을 찾았을때
        {
            int val = i; //val에 i를 저장
            int j;
            char temp[8],orit[8];
            numbers.copy(temp,sizeof temp -1);//numbers를 copy
            temp[numbers.size()] = '\0';
            for(j=0; j < 8; j++)//소수 val 을 문자열로 바꾼다.
            {
                orit[j] = (val%10) +'0';
                val /= 10;
                if(val == 0)
                {
                    break; 
    //소수인 문자열의 갯수가 j와 동일하도록 break를 걸어 j가 9가 됨을 방지
                }
            }
            int count =-1; //중복숫자 011과 11이 같음을 방지
            for(int x = 0; x <= j; x++){
                for(int y = 0; y < numbers.size(); y++){
                    if(orit[x]==temp[y]){//소수 문자열이 numbers에 존재한다면
                        temp[y]=-1; //중복방지
                        count++;
                        break;
                    }
                }
            }
            if(count==j){
                //소수인 문자열이 numbers에 포함되어 있으면 answer갯수를 증가.
                answer++;
            }
        }
        
    };
    delete[] p;
    return answer;
}
