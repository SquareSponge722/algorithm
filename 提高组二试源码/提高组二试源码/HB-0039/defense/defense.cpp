#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m,x,y,c[100001]={0},sum1,sum2,ans=0,i,j,a,b,t,ji[100001]={0},ou[100001]={0},t1=0,t2=0;
	char s[10];
	scanf("%d %d %s",&n,&m,s);
	for(i=1;i<=n;i++) 
	{
		scanf("%d",&c[i]);
		if(i%2==1) t1+=c[i];
		else t2+=c[i];
		ji[i]=t1,ou[i]=t2;
	}
	for(i=1;i<=n-1;i++) scanf("%d %d",&x,&y);
	
	for(i=1;i<=m;i++)
	{
		ans=0;
		scanf("%d %d %d %d",&a,&x,&b,&y);
		if(a-b==1 || b-a==1) printf("-1\n");else{
			if(a>b){t=a,a=b,b=t,t=x,x=y,y=t;}
		if(x==1)
		{
			sum1=ji[a-1],sum2=ou[a-1];
			ans+=min(sum1,sum2);
		}
		else
		{
			sum1=0,sum2=0;
			if(a-2>=1){sum1=ji[a-2],sum2=ou[a-2];}
			ans+=min(sum1,sum2);
			ans+=c[a-1];
		}
		if(y==1)
		{
			sum1=ji[n]-ji[b+1],sum2=ou[n]-ou[b+1];
			ans+=min(sum1,sum2);
		}
		else
		{
			sum1=0,sum2=0;
			if(b+2<=n){sum1=ji[n]-ji[b+2],sum2=ou[n]-ou[b+2];}
			ans+=min(sum1,sum2);
			ans+=c[b+1];
		}
		if(b+y-2>=1 && b+y-2<=n && a-x+2>=1 && a-x+2<=n){sum1=max(ji[(b+y-2)]-ji[a-x+2],0),sum2=max(ou[(b+y-2)]-ou[a-x+2],0);}
		ans+=min(sum1,sum2);
		if(x==1) ans+=c[a];
			else ans+=c[a+1];
		if(y==1) ans+=c[b];
			else ans+=c[b-1];
		if(b-a==2 && x==1 && y==1) ans-=c[a+1];
		printf("%d\n",ans);
	}
	
	}
	return 0;
}
