#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#define N 10010
#define M 1000010
using namespace std;
int m,n,f[M],flag[M],p[N],num,b[M],nt[M];
string r;
struct node
{
	int x;
	int y;
}a[N];
bool cmp(node x,node y)
{
	if(x.x==y.x)return x.y>y.y;
	return x.x>y.x;
}
void add(int x,int y)
{
	num++;
	b[num]=y;
	nt[num]=p[x];
	p[x]=num;
}
void star(int x)
{
	int e=p[x];
	r+=x+48;
	flag[x]++;
	f[x]++;
	while(e>0)
	{
		if(flag[b[e]]==0)star(b[e]);
		e=nt[e];
	}
	flag[x]--;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[2*i-1].x>>a[i*2-1].y;
		a[2*i].y=a[2*i-1].x;
		a[2*i].x=a[i*2-1].y;
	}
	sort(a+1,a+n*2+1,cmp);
	//for(int i=1;i<=n*2;i++)cout<<a[i].x<<" "<<a[i].y<<" ";
	for(int i=1;i<=n*2;i++)add(a[i].x,a[i].y);
	star(1);
	int len=r.size();
	for(int i=0;i<len;i++)
	{
		if((f[r[i]-48]==1||r[i+1]>r[i])&&flag[r[i]]==0)
		{
			flag[r[i]]=1;
			cout<<r[i]<<" ";
			continue;
		}
		f[r[i]-48]--;
	}
	return 0;
}
