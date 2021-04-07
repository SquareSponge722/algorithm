#include <bits/stdc++.h>
#define N 25666
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int gcd(int x,int y)
{
	if(!y)return x;
	else return gcd(y,x%y);
}
int t,n,a[N],prim[N],num=0;
bool flag[N],suc[N],exist[N];
void getprim(int s)
{
	flag[1]=1;
	for(int i=2;i<=s;i++)
	{
		if(!flag[i])
		{
			prim[++num]=i;
		}
		for(int j=1;j<=num&&i*prim[j]<=s;j++)
		{
			flag[i*prim[j]]=1;
			if(i%prim[j]==0)break;
		}
	}
}
void whether(int z,int note,int ori)
{
	if(z<0)return ;
	if(exist[z]&&z!=ori){suc[a[note]]=1;return ;}
	for(int i=1;i<note;i++)
	{
		whether(z-a[i],note,ori);
		if(suc[a[note]]==1)break;
	}
}
int main() 
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=read();
	getprim(25000);
	for(int k=1;k<=t;k++)
	{
		memset(suc,0,sizeof(suc));
		memset(exist,0,sizeof(exist));
		n=read();
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			exist[a[i]]=1;
			if(!flag[a[i]])cnt++;
		}
		if(cnt==n){printf("%d\n",n);continue;}
		cnt=0;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(gcd(a[i],a[j])==a[i])suc[a[j]]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!suc[a[i]])
			{
				whether(a[i],i,a[i]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!suc[a[i]])cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}