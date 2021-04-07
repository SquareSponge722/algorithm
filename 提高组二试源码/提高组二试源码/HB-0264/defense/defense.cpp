#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn=5000+100;
const int inf=99999999;
int n,m,cnt,ans;
char a[100];
int v[maxn]={0},book[maxn]={0},flag[maxn]={0},in[maxn]={0},ll[maxn]={0},head[maxn]={0};
struct node
{
	int next,to;
}edge[maxn]={0};
int x,y,p,q;
void add(int a,int b)
{
	edge[++cnt].next=head[a];
	edge[cnt].to=b;
	head[a]=cnt;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d %s",&n,&m,&a);
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
		int b,c;
	for(int i=1;i<=n-1;i++) scanf("%d%d",&b,&c),add(b,c),add(c,b),in[c]++,in[b]++;
	for(int i=1;i<=m;i++)
	{
		int flagg=0;
		scanf("%d%d%d%d",&x,&y,&p,&q);
		if(y==1&&q==1) if(x==p+1||y==p-1) flagg=1;
		if(y==1) book[x]=1,flag[x-1]=1,flag[x-2]=1,flag[x]=1,ans+=v[x-1],flag[x+1]=1,flag[x+2]=1,flag[x]=1,ans+=v[x+1],ll[x+1]++,ll[x-1]++;
		if(q==1) book[p]=1,flag[p-1]=1,flag[p-2]=1,flag[p]=1,ans+=v[p-1],flag[p+1]=1,flag[p+2]=1,flag[p]=1,ans+=v[p+1],ll[p+1]++,ll[p-1]++;
		if(y==0) flag[x-1]=1,flag[x+1]=1,flag[x]=1,ans+=v[x],ll[x]++;
		if(q==0) flag[p-1]=1,flag[p+1]=1,flag[p]=1,ans+=v[p],ll[p]++;
		for(int i=1;i<=n;i++)
		{
			if(ll[i]>1) ans-=(ll[i]-1)*v[x],ll[i]=1;
			if(i>=3&&ll[i]==1&&ll[i]==1&&ll[i-1]==1&&ll[i-2]==1) ans-=v[i-2],ll[i-2]=0;
			if(flag[i]==0&&book[i]!=1) flag[i]=flag[i+1]=flag[i-1]=1,ll[i]=1,ans+=v[i];
		}
		for(int i=1;i<=n;i++) if(flag[i]==0) flagg=1;
		if(flagg==1) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}