#include<bits/stdc++.h>
using namespace std;
int main()
{
     freopen("road.in","r",stdin);
     freopen("road.out","w",stdout);
	int n,day,d[n];
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>d[i];
	if(n==1) cout<<d[0]<<endl;
	if(n==2)
	{
		if(d[0]>=d[1]) cout<<d[0]<<endl;
		else cout<<d[1];
	}
	if(n==3)
	{
		if(d[0]>=d[1]&&d[1]>=d[2]) cout<<d[0]<<endl;
		else{
			if(d[0]<=d[1]&&d[1]<=d[2]) cout<<d[2]<<endl;
			else cout<<d[0]+d[1]+d[2]-2*d[1]<<endl;
		}
		
	}
	if(n==4)
	{
		int min;
		min=d[0];
		for(int j=0;j<n;j++)
		{
			if(d[j]<=min)
			min=d[j];
		}
		int max;
		max=d[0];
		for(int k=0;k<n;k++)
		{
			if(d[k]>=max)
			max=d[k];
		}
		if((d[0]>=d[1]&&d[1]>=d[2]&&d[2]>=d[3])||(d[0]<=d[1]&&d[1]<=d[2]&&d[2]<=d[3]))
		cout<<max<<endl;
		else {
			if(min==d[1]) {
				if(d[2]>=d[3]) cout<<d[0]+d[2]-min<<endl;
				else cout<<d[0]+d[3]-min<<endl;
			}
			if(min==d[2]){
				if(d[0]>=d[1]) cout<<d[3]+d[0]-min<<endl;
				else cout<<d[3]+d[1]-min<<endl;
				
			}
		}
		
	}
	return 0;
}
