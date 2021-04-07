#include<bits/stdc++.h>
using namespace std;
bool d[10001][10001];
int n,hi,jmax,step=0;
int tn(int p,int h)
{
	for(int i=p;i<=n;i++)
	if(d[i][h])
	return i;
	return 0;
}
int fn(int p,int h)
{
	for(int i=p;i<=n;i++)
	if(!d[i][h])
	return i;
	return 0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&hi);
		jmax=max(jmax,hi);
		for(int j=1;j<=hi;j++)
		d[i][j]=1;
	}
	int st=1,op;
	for(int j=1;j<=jmax;j++)
	{
		if(fn(1,j)==0)
		{
			step++;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(d[i][j])
			d[i][j]-=1;
			else if((!d[i][j])&&((i!=1)&&(i!=n)))
			step++;
		}
	}
	cout<<step;
	return 0;
}
