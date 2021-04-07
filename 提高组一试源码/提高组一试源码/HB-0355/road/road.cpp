#include<cstdio>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<string>
using namespace std;
const int maxn=100001;
int n;
int d[maxn],vis[maxn];
int mina=999999,po,ans,f,f1,f2,l1,f3,si;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d ",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		if(d[i])si=1;
	}	
	if(!si){printf("0\n");return 0;}
	int l=1,r=n;
	while(1)
	{
		f=0;f1=0;f2=0;f3=0;mina=999999;
		for(int i=l;i<=r;i++)
		{
			if(d[i]){f2=1;mina=min(mina,d[i]);}
			else if(!d[i]&&f2) {r=i-1;break;}
			else if(!d[i]&&!f2){f3=1;l1=i+1;}
		}
		if(f3==1)l=l1;
		for(int i=l;i<=r;i++)d[i]-=mina;
		ans+=mina;
		for(int i=l;i<=r;i++)
		{
			if(d[i]){f=1;l=min(i,l);}
			else if(!d[i]&&f){r=i-1;break;}
			if(!d[i]&&!f)continue;
		}
		if(f==0)
		{
			for(int i=1;i<=n;i++)
				if(d[i]){l=i;f1=1;break;}
			if(f1)r=n;
			else break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
