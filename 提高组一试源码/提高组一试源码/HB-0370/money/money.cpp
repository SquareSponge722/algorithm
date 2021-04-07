#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[110],b[10],t=0;
bool flag;
void check(int x,int k)
{
	if(k>t)return;
	if(x%b[k]==0)
	{
		flag=true;
		return;
	}
	for(int i=1;i*b[k]<=x;i++)
	{
		check(x-i*b[k],k+1);
		if(flag)return;
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)
	{
		t=0;
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		if(n==2)
			t=(a[2]%a[1]==0)?1:2;
		else
		{
			for(int i=1;i<=n;i++)
			{
				flag=false;
				check(a[i],1);
				if(!flag)
					b[++t]=a[i];
			}
		}
		printf("%d\n",t);
	}
	return 0;
}