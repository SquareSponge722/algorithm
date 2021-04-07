#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define ll long long 
#define lson 2*p
#define rson 2*p+1
using namespace std;
const int N=1e4+110;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,a[N],minn=(1<<30),c[N],tot,ans,Case;
int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}
int sum;
bool flag[25010];
bool two_point(int k)
{
	int l=1,r=tot;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(c[mid]<=k)return 1;
		else r=mid-1;
	}
	return 0;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	Case=read();
	while(Case--)
	{
		memset(flag,0,sizeof(flag));
		n=read();tot=0;ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		if(n==1){printf("1\n");continue;}
		if(n==2)
		{
			int GCD=gcd(a[1],a[2]);
			if(GCD!=1)printf("1\n");
			else printf("2\n");
			continue;
		}
		for(int i=1;i<=n;i++)
		 	for(int j=i+1;j<=n;j++)
		 	{
		 		int GCD=gcd(a[i],a[j]);
		 		if(GCD==a[i])flag[a[j]]=1;
		 		else if(GCD==a[j])flag[a[i]]=1;
		 		else c[++tot]=a[i]*a[j]-a[i]-a[j];
			}
		sort(c+1,c+1+tot);
		for(int i=1;i<=n;i++)
		if(!flag[a[i]])
		{
		   if(two_point(a[i]))flag[a[i]]=1;
			
		}
		for(int i=1;i<=n;i++)if(!flag[a[i]])ans++;
		printf("%d\n",ans);
	}
	

  	return 0;	
}
