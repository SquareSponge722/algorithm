#include <bits/stdc++.h>
using namespace std;

const int maxn=5e4+100;
struct stu
{
	int to,next,dis;	
}road[maxn*2]; int first[maxn],cnt=0;
int n,m,maxx,pos,ans;
int book[maxn],len[maxn];

void addedge(int x,int y,int z)
{
	road[++cnt].to=y;
	road[cnt].dis=z;
	road[cnt].next=first[x];
	first[x]=cnt;	
}

void dfs(int now,int dist)
{
	book[now]=1;
	if(dist>maxx) { maxx=dist,pos=now; }
	for(int i=first[now];i;i=road[i].next)
	{
		int to=road[i].to;
		if(book[to]) continue;
		book[to]=1;
		dfs(to,dist+road[i].dis);	
	}
}

bool check(int mid)
{
	int nowans=0,cnt1=0;
	for(int i=1;i<=n-1;i++)
	{
		nowans+=len[i];
		if(nowans>=mid)
		{
			nowans=0;
			cnt1++;
		}
		if(cnt1>=m) return 1;	
	}
	return 0;	
}

bool cmp1(int t1,int t2)
{
	return t1>t2;	
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	bool flag1=1,flag2=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x!=1) flag1=0;
		if(y!=x+1) flag2=0;
		len[i]=z;
		addedge(x,y,z);addedge(y,x,z);	
	}
if(m==1)
{
	memset(book,0,sizeof(book));
	maxx=0;
	dfs(1,0);
	maxx=0;
	memset(book,0,sizeof(book));
	dfs(pos,0);
	printf("%d\n",maxx);	
}
else
{
	if(flag1)
	{
		sort(len+1,len+n,cmp1);
		if(m==n-1)
		{
			printf("%d\n",len[n-1]);	
		}
		else
		{
			printf("%d\n",min(len[m-1],len[m]+len[m+1]));
		}
	}
	else
	{
			int l=0,r=(n-1)*10000;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				int kk=check(mid);
				if(kk) { ans=mid;l=mid+1; }
				else r=mid-1;
			}
			printf("%d\n",ans);
	}
}
	return 0;	
}
