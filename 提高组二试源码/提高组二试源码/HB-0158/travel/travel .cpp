#include<cstdio>
#include<iostream>
using namespace std;
int d[5001][5001],dp[5001];
int main()
{
FILE *fin,*fout;
fin=fopen("travel.in","rb");
fout=fopen("travel.out","wb");
int n,m,v,u,po=1,fro=1,x=0;
fscanf(fin,"%d%d",&n,&m);
for(int i=1;i<=m;i++)
    {
	fscanf(fin,"%d%d",&v,&u);
    d[v][u]=1;
    d[u][v]=1;
    }
    fprintf(fout,"%d ",po);
while(po<=n)
    {
	dp[po]=5001;
	for(int i=2;i<=n;i++)
    if(d[po][i])
        {
        dp[po]=min(dp[po],min(dp[fro],i));
        x=1;
		}
	if(x)
	dp[fro]=5001;
	else
	{
	dp[po]=dp[fro];
	dp[fro]=5001;
	}
	d[po][dp[po]]=0;
    for(int j=2;j<=n;j++)
        {
		if(d[j][po])
		d[j][po]=0;
	    }
	if(dp[po]<=n)
    fprintf(fout,"%d ",dp[po]);
    fro=po;
    po=dp[po];
    dp[fro]=5001;
    for(int x=2;x<=n;x++)
    if(d[fro][x])
        {
        dp[fro]=min(dp[fro],x);
        }
    x=0;
    }
return 0;
}
