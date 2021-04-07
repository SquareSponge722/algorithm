#include <cstdio>
#include <cmath>
#include <cstdlib>
int n,m,x,y,mmin,mmax,k,tt;
int e[5010][5010],book[5010],book1[5010],book2[5010],dfs1[5010],dfs2[5010];
int s[20010],quan[5010],qbook[5010];
int output[5010],output2[5010];
int x1,x2,y2,yy1,flag;
void dfss1(int t)
{
	for(int i=1;i<=n;i++)
		if(e[t][i]==1&&book1[i]==0)
		{
			dfs1[i]=dfs1[t]+1;
			book1[i]=1;
			dfss1(i);
		}
}
void dfss2(int t)
{
	for(int i=n;i>=1;i--)
		if(e[t][i]==1&&book2[i]==0)
		{
			dfs2[i]=dfs2[t]+1;
			book2[i]=1;
			dfss2(i);
		}
}
void fuck(int t)
{
	for(int i=1;i<=n;i++)
		if(e[t][i]==1&&book[i]==0)
		{
			output[tt]=i;
			tt++;
			book[i]=1;
			fuck(i);
		}
}
void ffuck(int t)
{
	dfss1(t);
	dfss2(t);
	mmax=0;
	mmin=99999999;
	for(int i=1;i<=n;i++)
		if(dfs1[i]!=dfs2[i])
			s[dfs1[i]+dfs2[i]]++;
	for(int i=1;i<=20000;i++)
		if(s[i]>mmax)
			mmax=i;
	for(int i=1;i<=n;i++)
		if(dfs1[i]!=dfs2[i]&&dfs1[i]+dfs2[i]==mmax)
		{
			k++;
			quan[k]=i;
			qbook[i]=1;
		}
	mmax=0;
	for(int i=1;i<=k;i++)
	{
		if(abs(dfs1[quan[i]]-dfs2[quan[i]])>=mmax)
		{
			mmax=abs(dfs1[quan[i]]-dfs2[quan[i]]);
			if(x1==0)
				x1=quan[i];
			if(x1!=0)
				yy1=quan[i];
		}
		if(abs(dfs1[quan[i]]-dfs2[quan[i]])<=mmin)
		{
			if(x2==0)
				x2=quan[i];
			else
				y2=quan[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if((e[i][x1]==1&&e[i][yy1]==1)&&qbook[i]==0)
			k++,quan[k]=i,qbook[i]=1;
		if((e[i][x2]==1&&e[i][y2]==1)&&qbook[i]==0)
			k++,quan[k]=i,qbook[i]=1;
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
			if(e[quan[i]][quan[j]]==1)
			{
				//printf("%d %d\n",quan[i],quan[j]);
				e[quan[i]][quan[j]]=e[quan[j]][quan[i]]=0;
				tt=2;
				for(int ii=1;ii<=n;ii++)
					book[ii]=0;
				book[1]=1;	
				fuck(1);
				e[quan[i]][quan[j]]=e[quan[j]][quan[i]]=1;
				for(int ii=1;ii<=n;ii++)
				{
					if(output[ii]<output2[ii])
					{
						flag=1;
						break;
					}
					if(output[ii]>output2[ii])
					{
						flag=2;
						break;
					}
				}
				if(flag==1)
					for(int ii=1;ii<=n;ii++)
						output2[ii]=output[ii];
			}
	for(int i=1;i<=n;i++)
		printf("%d ",output2[i]);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		e[x][y]=e[y][x]=1;
	}
	for(int i=1;i<=n;i++)
	{
		output[i]=99999999;
		output2[i]=99999999;
	}
	output[1]=1;
	book[1]=1,book1[1]=1,book2[1]=1;
	dfs1[1]=dfs2[1]=0;
	if(m==n-1)
	{
		tt=2;
		fuck(1);
		for(int i=1;i<=n;i++)
			printf("%d ",output[i]);
		return 0;
	}
	if(m==n)
	{
		ffuck(1);
		return 0;
	}
	return 0;
}