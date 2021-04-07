#include<bits/stdc++.h>
#define N 100010
using namespace std;
struct node
{
	int e,l;
} maxn;
int d[N],n,day=0;
void rebuild(int end,int l)
{
	for(int i=end-l+1; i<=end; i++)
		d[i]--;
}
bool check1()
{
	for(int i=1; i<=n; i++)
		if(d[i]==0)
			return false;
	return true;
}
void init()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&d[i]);
	while(check1())
		for(int i=1; i<=n; i++)
			d[i]--,day++;
}
bool check2()
{
	for(int i=1; i<=n; i++)
		if(d[i]!=0)
			return false;
	return true;
}
node get_max()
{
	maxn.l=0;
	for(int i=1; i<=n; i++)
	{
		int l=0,end;
		if(d[i]!=0)
		{
			l++;
			end=i;
		}
		else
		{
			if(l>maxn.l)
			{
				maxn.l=l;
				maxn.e=end;
			}
		}
	}
	return maxn;
}
int main ()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	while(check2())
	{
		rebuild(get_max().e,get_max().l);
		day++;
	}
	printf("%d\n",day-3);
	return 0;
}
