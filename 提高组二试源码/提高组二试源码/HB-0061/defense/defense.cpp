#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
const int N=1e5+5,inf=0x3f3f3f3f;
int n,m,a,b,x,y,t[N],flag[N];//0 wei wei
long long ans,sumj,tot,sumo;
bool use[N],fl[N];
char s[3];
vector <int> f[N];
queue <int> q;
inline int read()
{
	int x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		w=-1;
		ch=getchar();	
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*w;
}
void bfs(int x)
{
	tot=0;
	while(!q.empty())
		q.pop();
	q.push(x);
	use[x]=1;
	flag[x]=3;
	tot+=t[x];
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		for(int i=0;i<f[temp].size();i++)
		{
			int xx=f[temp][i];
			if(use[xx])
				continue;
			if(flag[temp]==3)
			{
				if(flag[xx]==1)
					flag[xx]=2;
				else
				{
					if(flag[xx]==3)
					{
						tot=-1;
						return ;
					}
				}
			}	
			if(flag[temp]==2)
			{
				if(flag[xx]==1||fl[xx])
				{
					flag[xx]=3;
					tot+=t[xx];
					fl[xx]=0;
					//printf("%d %d\n",xx,t[xx]);
				}
				else
				{
					if(flag[xx]==2)
					{
						tot=-1;
						return ;
					}
				}
			}
			use[xx]=1;
			q.push(xx);
		}
	}
}
void bfs2(int x)
{
	tot=0;
	while(!q.empty())
		q.pop();
	q.push(x);
	use[x]=1;
	flag[x]=2;
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		for(int i=0;i<f[temp].size();i++)
		{
			int xx=f[temp][i];
			if(use[xx])
				continue;
			if(flag[temp]==3)
			{
				if(flag[xx]==1)
				{
					flag[xx]=2;
				}
				else
				{
					if(flag[xx]==3)
					{
						tot=-1;
						return ;
					}
				}
			}	
			if(flag[temp]==2)
			{
				if(flag[xx]==1)
				{
					flag[xx]=3;
					tot+=t[xx];
				}
				else
				{
					if(flag[xx]==2)
					{
						tot=-1;
						return ;
					}
				}
			}
			use[xx]=1;
			q.push(xx);
		}
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();m=read();scanf("%s",&s);
	for(int i=1;i<=n;i++)
	{
		t[i]=read();
		if(i&1)
			sumj+=t[i];
		else
			sumo+=t[i];
	}
	for(int i=1;i<n;i++)
	{
		x=read();y=read();
		f[x].push_back(y);
		f[y].push_back(x);
	}
	if(s[0]=='A')
	{
		for(int i=1;i<=m;i++)
		{
			a=read();x=read();b=read();y=read();
			int w=a%2,r=b%2;
			if(x==1&&y==0)
			{
				if((w&&r)||(w==0&&r==0))
				{
					ans=-1;
				}
				else
				{
					if(w==1)
						ans=sumj;
					else
						ans=sumo;
				}
			}
			if(x==0&&y==1)
			{
				if((w&&r)||(w==0&&r==0))
				{
					ans=-1;
				}
				else
				{
					if(r==1)
						ans=sumj;
					else
						ans=sumo;
				}
			}
			if(x==1&&y==1)
			{
				
				if((w&&r)||(w==0&&r==0))
				{
					if(w==1)
						ans=sumj;
					if(w==0)
						ans=sumo;
				}
				else
				{
					ans=-1;
				}
				
			}	
			if(x==0&&y==0)
			{
				if((w&&r)||(w==0&&r==0))
				{
					if(w==1)
						ans=sumo;
					if(w==0)
						ans=sumj;
				}
				else
				{
					ans=-1;
				}
			}
			printf("%lld\n",ans);
		}
	}
	if(s[0]=='B'||s[0]=='C')
	{
		if(s[1]=='1')
		{
			for(int i=1;i<=m;i++)
			{
				a=read();x=read();b=read();y=read();
				memset(use,0,sizeof(use));				
				for(int j=1;j<=n;j++)
					flag[j]=1;
				if(y==1)
				{
					fl[b]=1;
					flag[b]=3;
				}
				else
					flag[b]=2;
				bfs(a);
				ans=tot;
				printf("%lld\n",ans);
			}
		}
		if(s[1]=='2')
		{
			for(int i=1;i<=m;i++)
			{
				ans=0;
				memset(use,0,sizeof(use));
				for(int j=1;j<=n;j++)
					flag[j]=1;
				a=read();x=read();b=read();y=read();
				if(x==1&&y==1)
				{
					printf("-1");
				}
				else
				{
					if(x==1&&y==0)
					{
						flag[b]=2;
						bfs(a);
					}
					if(x==0&&y==1)
					{
						flag[a]=2;
						bfs(b);
					}
					if(x==0&&y==0)
					{
						flag[b]=2;
						bfs2(a);
					}
				}
				ans=tot;
				printf("%lld\n",ans);
			}
		}
		if(s[1]=='3')
		{
			for(int i=1;i<=m;i++)
			{
				memset(use,0,sizeof(use));
				for(int j=1;j<=n;j++)
					flag[j]=1;
				a=read();x=read();b=read();y=read();
				if(x==1&&y==1)
				{
					fl[b]=1;
					flag[b]=3;
					bfs(a);
				}
				else
				{
					if(x==1&&y==0)
					{
						flag[b]=2;
						bfs(a);
					}
					if(x==0&&y==1)
					{
						flag[a]=2;
						bfs(b);
					}
					if(x==0&&y==0)
					{
						flag[b]=2;
						bfs2(a);
					}
				}
				ans=tot;
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
/*
5 4 B1
1 2 3 4 5
1 3 
2 5 
1 2
1 4
1 1 4 0
1 1 4 1
1 1 3 1
1 1 3 0
*/


