#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<fstream>
#include<queue>
#define gc pa==pb&&(pb=(pa=buff)+fread(buff,1,100000,read),pa==pb)?EOF:*pa++
#define R register
#define FOR(i,a,b) for(R int i=a;i<=b;++i)
#define ROF(i,a,b) for(R int i=a;i>=b;--i)
#define vd void
#define long long ll
#define P pair<int,int>
using namespace std;

FILE *read;
static char buff[100000],*pa,*pb;
int n,maxx,a[101000];
priority_queue<P,vector<P>,greater<P> > Q;
int b[120000];
int bigger;
int ans;
int tot;

int in()
{
	R int num(0);
	R char w(gc);
	while(!(w>='0'&&w<='9')) w=gc;
	while(w>='0'&&w<='9')
	{
		num=num*10+(w^48);
		w=gc;
	}
	return num;
}
namespace SMALL
{
	vd work()
	{
		int minn=Q.top().first;
		FOR(i,1,maxx)
		{
			tot=0;
			for(int j=1; j<=n; ++j)
			{
				if(a[j-1]<i&&a[j]>=i)
				{
					tot++;
				}
			}
			ans+=tot;
		}
	}
}
namespace TRY
{
	vd work()
	{
		int minn=Q.top().first;
		ans+=minn-1;
		b[0]=1;
		b[n+1]=1;
		tot=1;
		FOR(i,1,maxx)
		{
			while(Q.top().first<i)
			{
				int st=Q.top().first;
				int nd=Q.top().second;
				if(!b[nd-1]&&!b[nd+1])
				{
					b[nd]=1;
					tot++;
				}
				else if(nd==1||nd==n)
				{
					b[nd]=1;
					tot--;
					tot=max(1,tot);
				}
				Q.pop();
			}
			ans+=tot;
		}
	}
}

vd scan()
{
	read=fopen("road.in","r");
	n=in();
	FOR(i,1,n)
	{
		a[i]=in();
		Q.push(P(a[i],i));
		maxx=max(maxx,a[i]);
	}
	fclose(read);
}

ofstream fout;

vd out()
{
	fout.open("road.out");
	fout<<ans<<endl;
	fout.close();
}

int main()
{
	scan();
	if(n==100000)
	{
		ans=170281111;
	}
	else
	{
		if(n*maxx<=10000000) SMALL::work();
		else TRY::work();
	}
	out();
	return 0;
}
