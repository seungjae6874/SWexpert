#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(),greater<int>());
    int num = atoi(numbers.c_str());
    long long *p = new long long[num +3];//p�迭�� �ش���� �����佺�׽� ü �� n�� 
    //sqrt(n)���� ���� ����� �������� ������ �� ���� �Ҽ��̴�.�� boolean �迭�̴�.
    for(int i = 2; i < sqrt(num); i++){
        if(!p[i]){
            for(int j = i*i; j<=num; j+=i){
                p[j] = 1;
            }
        }
    }
    for(int i = 2 ; i <= num; i++){
        if(p[i]==0)//�Ҽ����� ã������
        {
            int val = i; //val�� i�� ����
            int j;
            char temp[8],orit[8];
            numbers.copy(temp,sizeof temp -1);//numbers�� copy
            temp[numbers.size()] = '\0';
            for(j=0; j < 8; j++)//�Ҽ� val �� ���ڿ��� �ٲ۴�.
            {
                orit[j] = (val%10) +'0';
                val /= 10;
                if(val == 0)
                {
                    break; 
    //�Ҽ��� ���ڿ��� ������ j�� �����ϵ��� break�� �ɾ� j�� 9�� ���� ����
                }
            }
            int count =-1; //�ߺ����� 011�� 11�� ������ ����
            for(int x = 0; x <= j; x++){
                for(int y = 0; y < numbers.size(); y++){
                    if(orit[x]==temp[y]){//�Ҽ� ���ڿ��� numbers�� �����Ѵٸ�
                        temp[y]=-1; //�ߺ�����
                        count++;
                        break;
                    }
                }
            }
            if(count==j){
                //�Ҽ��� ���ڿ��� numbers�� ���ԵǾ� ������ answer������ ����.
                answer++;
            }
        }
        
    };
    delete[] p;
    return answer;
}
