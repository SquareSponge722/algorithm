#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,m;
struct ao{
	long long t,v,next;
}a[400050];
long long head[200050],tot;
void add(long long st,long long t,long long v){
	a[++tot].next=head[st],a[tot].t=t,a[tot].v=v,head[st]=tot;
}
namespace task1
{
	long long maxn=-1;
	void inn()
	{
		long long x,y,z;
		for(long long i=1;i<=n-1;i++)
		{
			cin>>x>>y>>z;
			add(x,y,z),add(y,x,z);
		}
	}
	bool fw[200050];
	long long d[200050],ans[200050],f,l;
	long long bfs(long long st)
	{
		f=-1,l=0;
		d[0]=st;
		fw[st]=1;
		long long i,pos=st,to;
		do{
			pos=d[++f];
			for(long long i=head[pos];i;i=a[i].next)
			{
				to=a[i].t;
				if(fw[to]) continue;
				fw[to]=1;
				d[++l]=to;
				ans[l]=ans[f]+a[i].v;
			}
		}while(f<l);
		for(i=1;i<=n;i++) fw[i]=0;
		for(i=0;i<=l;i++) 
		{
		    if(maxn<ans[i])
		    {
		    	maxn=ans[i];
		    	pos=d[i];
			}
		}
		return pos;
	}
	long long findl()
	{
		long long p1,p2;
		p1=bfs(1);
		maxn=0;
		p2=bfs(p1);
		return maxn;
	}
	void work()
	{
		inn();
		cout<<findl()<<endl;
	}
}
namespace task2
{
	long long sum,v[200050],minn=-1;
	void counted()
	{
		for(long long i=1;i<=n-1;i++) sum+=v[i];
	}
	void inn()
	{
		long long i,x,y,z;
		for(i=1;i<=n-1;i++)
		{
			cin>>x>>y>>z;
			if(x>y) x^=y^=x^=y;
			v[x]=z;
		}
	}
	long long s[200050];
	void tab()
	{
		for(long long i=1;i<=n-1;i++) s[i]=s[i-1]+v[i];
	}
	void dfs(long long last,long long num,long long su)
	{
		if(num==m+1)
		{
			minn=max(minn,su);
			return;
		}
		for(long long i=last+1;i<=n-1;i++)
		{
			dfs(i,num+1,min(su,s[i]-s[last]));
		}
	}
	void work()
	{
		inn();
		tab();
		dfs(0,1,100000000);
		cout<<minn<<endl;
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	if(m==1)
	{
	    task1::work();
	    return 0;
	}
	task2::work();    
	return 0;
}
