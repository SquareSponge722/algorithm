#include <cstdio>
#include <cstdlib>
using namespace std;
int m,n;
int len[50001];
int a[50001];
int b[50001];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	bool is_a=true;
	for(int k=1; k<n; k++)
	{
		scanf("%d %d %d",&a[k],&b[k],&len[k]);
		if(a[k]!=1)
			is_a=false;
	}
	if(is_a)
	{

		int max=-1;
		int max_wz=-1;
		for(int k=1; k<n; k++)
			if(len[k]>max)
			{
				max=len[k];
				max_wz=k;
			}
		len[max_wz]=-1;
		int max2=-1;
		for(int k=1; k<n; k++)
			if(len[k]>max2)
				max2=len[k];
		printf("%d\n",max+max2);
		return 0;
	}
	else
	{


	}
	return 0;
}
