#include<iostream>
 
#define MAX 5
using namespace std;
 
int Arr[MAX];
bool Select[MAX];
int ans= 0;
bool Print(int num)
{
	int sum = 0;
	int num2 = num;
    for (int i = 0; i < MAX; i++)
    {
    	
        if (Select[i] == true)
        {
            
            sum+= Arr[i];
        }
    }
    if(num2 > sum){
    	cout<<sum << endl;
    	ans++;
    	return true;
	}
    
}
 
int DFS(int Idx, int Cnt, int num)
{
	int num2 = num;
	int an=0;
    if (Cnt == 3)
    {
        Print(num2);	

    }
 
    for (int i = Idx; i < MAX; i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;

        DFS(i, Cnt + 1,num2);
        Select[i] = false;
    }
}
 
int main(void)
{
    Arr[0] = 1;
    Arr[1] = 2;
    Arr[2] = 3;
    Arr[3] = 4;
    Arr[4] = 5;
 	int n = 6;
 	int answer = 0;
    DFS(0, 0,n);
	cout<<ans;
}


