#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m,p[100001],j,i;
	int u[100001],v[100001];
	int a,x[100001],b,y[100001];
	string type;
	int win[100001][100001];
	cin>>n>>m;
	cin>>type;
	for(i=1;i<=n;i++)
	cin>>p[i];
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	win[i][j]=0;
	for(i=1;i<n;i++)
	{
	cin>>u[i]>>v[i];
	win[u[i]][v[i]]=1;
    }
	for(j=1;j<=n;j++)
	{
		cin>>a>>x[a];
		cin>>b>>y[b];
		if((win[a][b]==1||win[b][a]==1)&&(x[a]==1||y[b]==1))
		  {
		  if(x[a]==1&&y[b]==1) cout<<p[a]+p[b]<<endl;
		  if(x[a]==1&&y[b]==0) cout<<p[a]<<endl;
		  if(x[a]==0&&y[b]==1) cout<<p[b]<<endl;
	      }
	    if((win[a][b]==1||win[b][a]==1)&&(x[a]==0&&y[b]==0)) cout<<"-1"<<endl;break;
    }
	return 0;
}
