#include<bits/stdc++.h>
using namespace std;
int t,a[110],n,c[25010],cnt=0;
bool b[25010];
void read(int& x)
{
	char c=getchar();
	x=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	read(t);
	b[1]=0;
	for(int i=2;i<=25000;i++)
	{
		if(!b[i])a[cnt++]=i;
		for(int j=0;j<cnt&&i*a[j]<=n;j++)
		{
			b[i*a[j]]=1;
			if(i%a[j]==0)break;
		}
	}
	while(t--)
	{
		read(n);
		bool ok=0,jud=1;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			read(a[i]);
			if(a[i]==1)
			{
				ok=1;
				printf("1\n");
				break;
			}
			if(!b[a[i]])jud=0;
		}
		if(jud)printf("%d\n",n);
		if(ok)continue;
		if(n==2)
		{
			printf("2\n");
		}
	}
	return 0;
}
