#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
inline int read()
{
	register int a(0),p(1);register char ch=getchar();
	while((ch<'0'&&ch>'9')&&ch!='-') ch=getchar();
	ch=='-'?p=-1,ch=getchar():p;
	while(ch>='0'&&ch<='9') a=a*10+ch-48,ch=getchar();
	return a*p;
}
const int N=50100;
int n,m,u,v,w,head[N],cnt=0,pan1=1,pan2=1,maxn=0,jd,all=0,l,r,ans=0,cun[N],book[N],la,temp;
struct EDGE{int nxt,to,val;}e[N];
// struct BJSZ{int u,v,w;}bj[N];
void add(int u,int v,int w){e[++cnt]=(EDGE){head[u],v,w};head[u]=cnt;}
void dfs(int u,int ff,int su)
{
	if(su>maxn) maxn=su,jd=u;
	for(int i=head[u],v=e[i].to;i;i=e[i].nxt,v=e[i].to) if(v!=ff)
		dfs(v,u,su+e[i].val);
}
bool cmp(int x,int y)
{
	return x>y;
}
bool check(int xx)
{
	la=0,temp=0;
	for(int i=1;i<=m;i++)
	{
		temp=0;
		while(temp<xx&&la<n-1)
		{
			++la;
			temp+=cun[la];
		}
		if(temp<xx) return false;
	}
	return true;
}
bool check2(int xx)
{
	temp=m;int i=1,e=0;
	memset(book,0,sizeof(book));
	for(i=1;i<n;i++)
		if(cun[i]>=xx)
		{
			temp--;
			if(temp<=0) return true;
		}
	while(temp--)
	{
		e=0;
		for(int j=n-1;j>i;j--) if(!book[j]&&cun[j]+cun[i]>=xx)
		{
			e=1;
			book[j]=1;
		}
		if(!e) return false;
	}
	return true;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<n;i++)
	{
		u=read(),v=read(),cun[i]=w=read();
		add(u,v,w);add(v,u,w);all+=w;
		// bj[i]=(BJSZ){u,v,w};
		if(v-u!=1) pan2=0;
		if(u!=1) pan1=0;
	}
	if(m==1)
	{
		dfs(1,0,0);maxn=0;
		dfs(jd,0,0);
		printf("%d\n",maxn);
		return 0;
	}
	else if(pan2)
	{
		int mid;
		l=0,r=all;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid)) ans=max(ans,mid),l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",ans);
		return 0;
	}
	else if(pan1)
	{
		int mid;
		l=0,r=all;
		sort(cun+1,cun+n,cmp);
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check2(mid)) ans=max(ans,mid),l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",ans);
		return 0;
	}
	return 0;
}
