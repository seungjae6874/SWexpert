#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i = 0; i <T; i++)
	{
		int x1,y1,x2,y2;
		int cnt,cnt2,cnt3;
		cnt = 0;
		cnt2 = 0;
		cnt3 = 0;
		cin>>x1>>y1>>x2>>y2;
		int h,w;
		int bigy,bigx,smally,smallx;
		int x3,y3,x4,y4; //x3는 왼쪽 위점, x4는 오른쪽 아래점 
		if(y1 > y2)
		{
			bigy = y1;
			smally = y2;
			h = y1 - y2;
			y3 = y1;
			y4 = y2;
		}
		else if(y2 >= y1){
			bigy = y2;
			smally = y1;
			h = y2 - y1;
			y3 = y2;
			y4 = y1;
		}
		if(x1 > x2)
		{
			bigx = x1;
			smallx = x2;
			w = x1-x2;
			x3 = x2;
			x4 = x1;
		}
		else if(x2 >= x1){
			bigx = x2;
			smallx = x1;
			w = x2-x1;
			x3 = x1;
			x4 = x2;
			
		}
		int N;
		cin>>N;
		for(int j = 0; j<N; j++)
		{
			int x, y;
			cin>>x>>y;
			if((bigx > x)&&(x > smallx)&&(bigy > y)&&(y>smally)){
				cnt3++;
			}
			else if((x < smallx) || (x > bigx)||
			((x>= smallx)&&(bigx >= x))&&((smally > y) ||(y>bigy)))
			{
				cnt++;
			}
			else {
				cnt2++;
			}
			
		}
			cout<<"#"<<i+1<<" "<<cnt3<<" "<<cnt2<<" "<<cnt<<endl;

	}
	return 0;
}
