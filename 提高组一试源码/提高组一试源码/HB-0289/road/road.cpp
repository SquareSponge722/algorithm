#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
int n;
int a=0,x=0;
int d[100005],d1[100005];
int ans=0;
void F(int x){

	for(int i=1;i<=x;i++)d[i]-=1;
	ans++;
}
void X(int x){
	
	for(int i=x;i<=n;i++)d[i]-=1;
	ans++;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
	}

		for(int i=1;i<=n;i++)d1[i]=d[i];
		sort(d1,d1+n);
		for(int i=1;i<=d1[1];i++)F(n);
		cout<<d1[1];
		memset(d1,0,sizeof(d1));
		for(int i=1;i<=n;i++){
			if(d[i]==0)break;
			d1[i]=d[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(d[i]==0){
				sort(d1,d1+i-1);
				for(int j=1;j<=d1[1];j++)F(i-1);
				cout<<d1[1];
			}
		}
		memset(d1,0,sizeof(d1));
		for(int i=n;i>=1;i--)
			for(int j=1;j<=n;j++){
				if(d[i]==0)break;
				d1[j]=d[i];
			}
		for(int i=n;i>=1;i--)
		{
			if(d[i]==0){
				sort(d1+i+1,d1+n);
				for(int x=1;x<=d1[2];x++)X(i+1);
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(d[i]!=0)ans+=d[i];
		}
	cout<<ans;
	return 0;
}
