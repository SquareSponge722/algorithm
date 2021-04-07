#include<bits/stdc++.h>
using namespace std;
int d[100010];
int main(void){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(d,0,sizeof(d));
	int n;
	cin>>n;
	int l;
	int r=n;
	bool finish=false;
	int mini= 10000;
	int ans=0;
	int p;
	
	for(int i=1;i<=n;i++)
		cin>>d[i];
		
	while(!finish){
		finish=true;
		for(l=1;l<=n;l++)
			if(d[l]!=0){
				finish=false;
				break;
			}
				
		if(!finish){
			for(l=1;l<=n;l++)
				if(d[l]!=0)
					break;
					
			for(r=l;r<=n;r++)
				if(d[r]==0)
					break;
					
				r--;
					
			for(p=l;p<=r;p++)
				if(d[p]<mini)
					mini=d[p];
			ans+=mini;
			for(p=l;p<=r;p++)
				d[p]-=mini;
		}
	}
	cout<<ans;
	
	
	return 0;
	
}
