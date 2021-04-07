#include <bits/stdc++.h>
#define N 100000+100
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct node
{
	int val,id;
}q[N];
bool cmp(node a,node b)
{
	return a.val<b.val||a.val==b.val&&a.id<b.id;
}
int n,a[N],cnt=0,l=0,r=0;
int main() 
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)q[i].val=read(),q[i].id=i,a[i]=q[i].val;
	sort(q+1,q+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(!a[q[i].id])continue;
		l=r=0;
		for(int j=q[i].id+1;j<=n;j++)
		{
			if(a[j]>=a[q[i].id]){r=j;}
			else break;
		}
		if(!r)r=q[i].id;
		for(int j=q[i].id-1;j>=1;j--)
		{
			if(a[j]>=a[q[i].id]){l=j;}
			else break;
		}
		if(!l)l=q[i].id;
		cnt+=a[q[i].id];
		int d=a[q[i].id];
		for(int j=l;j<=r;j++)
		{
			a[j]-=d;
		}
	}
	printf("%d",cnt);
	return 0;
}