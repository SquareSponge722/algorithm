#include <cstdio>
#include <cstdlib>
using namespace std;
int d[100010];
int n;
int ans;
void work(int l,int r)
{
	int len=r-l+1;
	int min=10001;
	for(int k=0;k<len;k++)
		if(d[l+k]<min)
			min=d[l+k];
	for(int k=0;k<len;k++)
		d[l+k]-=min;
	ans+=min;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int k=1;k<=n;k++)
		scanf("%d",&d[k]);
	for(;;)
	{
		bool flag=true;
		for(int k=1;k<=n;k++)
			if(d[k]!=0)
				flag=false;
		if(flag)
			break;
		for(int k=1;k<=n;k++)
		{
			while(k<=n && d[k]==0)
				k++;
			if(k>n)
				break;
			int first=k;
			while(k<=n && d[k]!=0)
				k++;
			int last=--k;
			work(first,last);
		}
	}
	printf("%d\n",ans);
	return 0;
}
