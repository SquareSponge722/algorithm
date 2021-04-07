#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 200001
#define M 20005
using namespace std;
int n,m,line[M][M],flag[N],ans;
char type[3];
struct node
{
	int x;
	int y;
	int cost;
}a[N];
int q1[N/2],q2[N/2],p1[N/2],p2[N/2],q3[N/2];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",type);
	memset(line,0,sizeof(line));
	memset(flag,-1,sizeof(flag));
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i].cost);
	for(int i=1;i<n;i++)
	{
		cin>>a[i].x>>a[i].y;
		line[a[i].x][a[i].y]=1;
		line[a[i].y][a[i].x]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int aa,xx,bb,yy;
		cin>>aa>>xx>>bb>>yy;
		if(xx==0&&yy==0&&line[aa][bb]==1)cout<<-1<<endl;
		if(xx==0&&yy==0&&line[aa][bb]==0)
		{
			int num=0,numm=0;
			flag[aa]=0;flag[bb]=0;
			for(int j=1;j<=n;j++)
			if(line[aa][j]==1)
			{
				num++;
				q1[num]=a[j].cost;
				flag[j]=1;
			}
			sort(q1+1,q1+1+num);
			for(int k=1;k<=n;k++)
			if(flag[k]==-1)
			{
				numm++;
				p1[numm]=a[k].cost;
			}
			sort(p1+1,p1+1+numm);
			ans+=(q1[1]+p1[1]);
			for(int ii=1;ii<=n;ii++)
			{
				if(a[ii].cost==q1[1])flag[ii]=1;
				else
				flag[ii]=-1;
			}
			cout<<ans<<endl;
			ans=0;
		}
		if(xx==1&&yy==1)
		{
			int num=0;
			ans+=(a[aa].cost+a[bb].cost);
			flag[aa]=1;flag[bb]=1;
			for(int j=1;j<=n;j++)
			{
				if(line[aa][j]==1||line[bb][j]==1)flag[j]=0;
				if(flag[j]==-1)
				{
					num++;
					q2[num]=a[j].cost;
				}
			}
			sort(q2+1,q2+1+num);
			ans+=q2[1];
			cout<<ans<<endl;
			ans=0;
		}
		if(xx==1&&yy==0)
		{
			int num=0,numm=0;
			flag[aa]=1;flag[bb]=0;
			ans+=a[aa].cost;
			for(int j=1;j<=n;j++)
			{
				if(line[bb][j]==1)
				ans+=a[j].cost;
			}
			sort(p2+1,p2+1+num);
			ans+=p2[1];
			for(int i=1;i<=n;i++)
			{
				if(a[i].cost==p2[1])flag[i]=1;
				if(flag[i]==-1)
				{
					numm++;
					q3[i]=a[i].cost;
				}
			}
			sort(q3+1,q3+1+numm);
			ans+=q3[1];
			cout<<ans<<endl;
			ans=0;
		}
	}
	return 0;
}
