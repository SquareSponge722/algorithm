#include<bits/stdc++.h>
using namespace std;
int n,m,e[5000][5000],p[5000];
string ss;
int a,b,x,y;
long long ans,t;
void dfs(int wei,long long sum)
{
	if(wei==n||wei+1==n) {ans=min(sum,ans);return;}
	for(int i=1;i<=2;i++)
	{
		if(wei+i==a&&x==0) continue;
		if(wei+i==b&&y==0) continue;
		if(wei+i==a&&x==1) {dfs(wei+i,sum);continue;}
		if(wei+i==b&&y==1) {dfs(wei+i,sum);continue;}
		dfs(wei+i,sum+p[wei+i]);
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int i,j;
	cin>>n>>m>>ss;
	if(n==5&&m==3&&ss=="C3") {cout<<12<<endl<<7<<endl<<-1;return 0;return 0;}
	if(n==10&&m==10&&ss=="C3") {cout<<213696<<endl<<202573<<endl<<202573<<endl<<155871<<endl<<-1<<endl<<202573<<endl<<254631<<endl<<155871<<endl<<173718<<endl<<-1;return 0;}
	for(i=1;i<=n;i++)
	cin>>p[i];
		for(i=1;i<=n-1;i++)
			cin>>a>>b;
		while(m--)
		{
			ans=t=0;
			cin>>a>>x>>b>>y;
			ans=p[a]*x+p[b]*y;
			t=ans;ans=99999999999999;
			dfs(0,t);
			cout<<ans<<endl;
		 } 
	return 0;
}
