#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>
int a[5005],b[5005],u[5005],v[5005],c[5005];
int m,n,i,love;
using namespace std;
void lit(int s)
{
	int j,g = 1,p = 2,h;
	for(i = 1;i <= n;i++)
	{
		c[i] = 1;
		b[i] = 10000;	
	}
	for(j = 1;j <= m;j++)
	{
		if(u[j] == s)
		{
			b[g] = v[j];
		}
		else if(v[j] == s)
		{
			b[g] = u[j];
		}
		else 
		{
			for(i = 1;i <= m;i++)
				for(h = 1;h <= m;h++)
					if(a[i] == h)
						c[h]--;
			for(i = 1;i <= m;i++)
				if(c[i] == 1)
				{
					b[g] = i;	
					break;
				}
		}
		g++;
	}
	sort(b,b + 1 + m);
	a[p] = b[1];
	p++;
	if(p == n)
	{
		for(i = 3;i <= p;i++)
			printf(" %d",a[i]);
	}	
	else lit(a[p]);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i = 1;i <= m;i++)
		scanf("%d%d",&u[i],&v[i]);
	for(i = 1;i <= m;i++)
	{
		if(u[i] == 1)
		{
			a[1] = 1;
			a[i + 1] = v[i];
		}
		else if(v[i] == 1)
		{
			a[1] = 1;
			a[i + 1] = u[i]; 
		}	
	}
	for(i = 1;i <= n;i++)
		if(a[i] == 0)
			a[i] = 10000;
	sort(a + 1,a + n + 1);
	printf("%d %d",a[1],a[2]);
	love=a[2];
	lit(love);	
	return 0;
}
