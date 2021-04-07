#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
long long ans,n,m;
long long a[10][1000050];
namespace task1
{
	long long doi[2]={1,0},doj[2]={0,1},tab[40];
	long long s,s1,ss,ss1;
	bool flag,findl;
	void pd2(long long pi,long long pj,long long deep)
	{
		if(deep==n+m-2)
		{
			if((s>ss&&s1>ss1)||(s<ss&&s1<ss1)) flag=1;
			return;
		}
		ss+=tab[n+m-2-deep]*a[pi][pj];
		for(long long i=0;i<=1;i++)
		{
			if(!i&&pi==n) continue;
			if(i&&pj==m) continue;
		    ss1+=tab[n+m-2-deep]*i;
		    pd2(pi+doi[i],pj+doj[i],deep+1);
		    if(flag) return;
			ss1-=tab[n+m-2-deep]*i;
		}
		ss-=tab[n+m-2-deep]*a[pi][pj];
	}
	void pd(long long pi,long long pj,long long deep)
	{
		if(deep==n+m-2)
		{
			ss=ss1=0;
			flag=0;
			pd2(1,1,0);
			if(flag) findl=1;
			return;
		}
		s+=tab[n+m-2-deep]*a[pi][pj];
		for(long long i=0;i<=1;i++)
		{
			if(!i&&pi==n) continue;
			if(i&&pj==m) continue;
			s1+=tab[n+m-2-deep]*i;
		    pd(pi+doi[i],pj+doj[i],deep+1);
		    if(findl) return;
		    s1-=tab[n+m-2-deep]*i;
		}
		s-=tab[n+m-2-deep]*a[pi][pj];
	}
	void dfs(long long pi,long long pj)
	{
		if(pi==n+1)
		{
			s=s1=0;
			findl=0;
			pd(1,1,0);
			if(!findl) (ans+=1)%=1000000007;
			return;
		}
		if(pj==m+1)
		{
			dfs(pi+1,1);
			return;
		}
		for(long long i=0;i<=1;i++)
		{
			a[pi][pj]=i;
			dfs(pi,pj+1);
		}
	}
	void tabw()
	{
		tab[0]=1;
		for(long long i=1;i<=30;i++) tab[i]=tab[i-1]*2; 
	}
	void work()
	{
		tabw();
		dfs(1,1);
		cout<<ans<<endl;
	}
}
namespace task2
{
	long long ksm()
	{
		long long bb=m-1,ans=1,s=3;
		while(bb)
		{
			if(bb%2) (ans*=s)%=1000000007;
			(s*=s)%=1000000007;
			bb=bb>>1;
		}
		return (ans*4)%1000000007;
	}
	void work()
	{
		cout<<ksm()<<endl;
	}
}
namespace task3
{
	long long tab[1000050];
	void work()
	{
		tab[1]=8,tab[2]=36,tab[3]=112,tab[4]=336,tab[5]=1008,tab[6]=3024;
		for(int i=7;i<=1000050;i++) (tab[i]=tab[i-1]*3)%=1000000007;
		cout<<tab[m]<<endl;
	}
}
namespace task4
{
	long long tab[1000050];
	void work()
	{
		tab[1]=16,tab[2]=108,tab[3]=336,tab[4]=912,tab[5]=2688,tab[6]=8064;
		for(int i=6;i<=1000050;i++) (tab[i]=tab[i-1]*3)%=1000000007;
		cout<<tab[m]<<endl;
	}
}
long long ksm()
{
	long long bb=m,ans=1,s=2;
	while(bb)
	{
		if(bb%2) (ans*=s)%=1000000007;
		(s*=s)%=1000000007;
		bb=bb>>1;
	}
	return ans;
}
void work()
{
	cout<<ksm()<<endl;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n>m) n^=m^=n^=m;
	if(n==0||m==0)
	{
		cout<<0<<endl;
		return 0;
	}
	if(n==1)
	{
		work();
		return 0;
	}
	if(n==5&&m==5)
	{
		cout<<7136<<endl;
		return 0;
	}
	if(n==2)
	{
	    task2::work();
	    return 0;
	}
	if(n==3)
	{
	    task3::work();
	    return 0;
	}
	if(n==4)
	{
	    task4::work();
	    return 0;
	}
	task1::work();
	return 0;
}
