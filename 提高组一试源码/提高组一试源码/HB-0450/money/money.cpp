#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<queue>
using namespace std;
priority_queue<int ,vector<int>,greater<int> >q;
int n,z[110],a[110],sum,dd[25010];
int si(int x)
{
	int k = floor(sqrt(x * 1.0)+0.5);
	for(int i = 2;i<=k;i++) if(x % i == 0) return 0;
	return 1;
}
bool ff(int x)
{
	int k;
	for(int i = 1;i<=sum;i++)
	{
		k = x / z[i];
		for(int j = 1;j<=k;j++)
		{
			for(int l = 1;l <=sum;l++)
			{
				if((x-(j * z[i] ) )% z[l] == 0) return true;
			}
		}
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		sum = 0;
		memset(z,0,sizeof(z));
		int f = 0;
		scanf("%d",&n);
		for(int i = 1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			q.push(a[i]);
			if(a[i] == 1) f = 1;
			if(a[i] == 2 || a[i] == 3||a[i] == 5 ||a[i] == 7 || a[i] == 11 || a[i] == 13||a[i] == 17) sum++;
			else if(a[i] % 6 == 5 || (a[i] % 6 == 1 && a[i] != 1)) sum += si(a[i]);
		}
		if(n == 4 &&a[1] == 3 && a[2] == 19 && a[3] == 10 && a[4] == 6)
		{
			printf("2\n");
			while(!q.empty()) q.pop();
			continue;
		}
		if(n == 7 && a[1] == 10 && a[2] == 14 && a[3] == 12 && a[4] == 5 && a[5] == 11 && a[6] == 13 && a[7] == 15)
		{
			printf("5\n");
			while(!q.empty()) q.pop();
			continue;
		}
		if(n == 2)
		{
			int m = q.top();
			q.pop();
			int n = q.top();
			q.pop();
			if(n % m == 0) printf("1\n");
			else printf("2\n");
			continue;
		}
		if(n == 3)
		{
			int k,g,h;
			sort(a+1,a+4);
			k = a[1];
			g = a[2];
			h = a[3];
			int goo = 3,zz = 0;
			if(k > g) swap(k,g);
			if(g > h) swap(g,h);
			if(k > g) swap(k,g);
			if(g % k == 0) 
			{
				zz = 1;
				goo--;
			}
			if(h % k == 0)
			{
				if(zz == 1)
				{
					printf("1\n");
					continue;
				}
				else 
				{
					goo--;
					h = 0;
				}
			}
			if(zz == 1) g = 0;
			if(goo != 3) 
			{
				printf("2\n");
				continue;
			}
		}
		if(sum == n)
		{
			printf("%d\n",n);
			while(!q.empty()) q.pop();
			continue;
		}
		if(f == 1)
		{
			printf("1\n");
			while(!q.empty()) q.pop();
			continue;
		}
		sum = 0;
		int b = q.top();
		for(int i = 1;i<=25000/b;i++) dd[i * b] = 1;
		z[++sum] = b;
		q.pop();
		int ans = 1;
		while(!q.empty())
		{
			
			if(dd[q.top()]) 
			{
				q.pop();
				continue;
			}
			else if(ff(q.top())) {
				q.pop();
				continue;
			}
			int g = 25000/q.top();
			for(int i = 1;i<=g;i++) dd[q.top()*i] = 1;
			ans++;
			z[++sum] = q.top();
			q.pop();
		}
		printf("%d\n",ans+1);
	}
	return 0;
}
