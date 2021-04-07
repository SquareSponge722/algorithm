#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
long long n,m;
long long read(){
	long long s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
struct ao{
	long long t,next,go;
}a[400050];
long long head[200050],tot;
void add(long long st,long long t){
	long long i=head[st],last;
	while(a[i].t<t&&i) last=i,i=a[i].next;
	if(i==head[st])
	a[++tot].next=head[st],a[tot].t=t,head[st]=tot;
	else
	a[++tot].next=i,a[tot].t=t,a[last].next=tot;
	a[tot].go=1;
}
namespace task1
{
	long long fw[200050];
	void dfs(long long pos)
	{
		fw[pos]=1;
		long long i,to;
		for(i=head[pos];i;i=a[i].next)
		{
			to=a[i].t;
			if(fw[to]) continue;
			cout<<to<<' ';
			dfs(to);
		}
	}
	void work()
	{
		cout<<1<<' ';
		dfs(1);
	}
}
namespace task2
{
	long long ans[200050],flag,pd,deep;
	long long fw[200050];
	void dfs(long long pos)
	{
		deep++;
		fw[pos]=1;
		long long i,to;
		for(i=head[pos];i;i=a[i].next)
		{
			to=a[i].t;
			if(fw[to]||a[i].go==0) continue;
			
			if(flag) ans[deep]=to;
			else if(to>ans[deep])
			{
				pd=1;
				return;
			}
			else if(to<ans[deep])
			{
				flag=1;
				ans[deep]=to;
			}
			dfs(to);
			if(pd) return;
		}
	}
	void work()
	{
		for(long long i=1;i<=n;i++) ans[i]=10000000000000;
		for(long long i=0;i<=n-2;i++)
		{
			a[i*2+1].go=a[i*2+2].go=0;
			flag=pd=0;
			deep=1;
			dfs(1);
			a[i*2+1].go=a[i*2+2].go=1;
			for(long long j=1;j<=n;j++) fw[j]=0;
		}
		ans[1]=1;
		for(long long i=1;i<=n;i++) cout<<ans[i]<<" ";
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	long long i,x,y;
	for(i=1;i<=m;i++)
	{
		x=read();y=read();
		add(x,y),add(y,x);
	}
	if(n==m)
	task2::work();
	else task1::work();
	return 0;
}
