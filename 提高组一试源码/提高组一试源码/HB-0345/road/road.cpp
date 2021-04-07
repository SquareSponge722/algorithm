#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,a[200050],tot,c[200050],ans,maxn=-1;
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
namespace task1
{
	int dfs(int f,int l,int p)
	{
		if(f>l) return 0;
		int minn=100000000,ans=0,last=100000000;
		for(int i=f;i<=l;i++) 
		{
		    if(minn>a[i])
		    {
		    	minn=a[i];
		    	last=i;
			}
		}
		ans+=minn-p;
		ans+=dfs(f,last-1,minn);
		for(int i=f;i<=l;i++)
		{
			if(a[i]==minn)
			{
			    ans+=dfs(last+1,i-1,minn);
			    last=i;
			}
		}
		ans+=dfs(last+1,l,minn);
		return ans;
	}
	void work()
	{
		cout<<dfs(1,n,0)<<endl;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	long long i;
	for(i=1;i<=n;i++) a[i]=read(),maxn=max(maxn,a[i]);
	task1::work();
	return 0;
}
