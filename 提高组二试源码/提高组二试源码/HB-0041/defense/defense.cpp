#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
vector<int>q[N];int p[N];
int n,m,fa[N];char cas[20];
long long ans,anns[2];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,&cas);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<n;i++)
	{
		int ju1,ju2;q[ju1].push_back(ju2);q[ju2].push_back(ju1);
	}
	if(cas[1]=='3'&&cas[0]=='A')
	{
		for(int i=1;i<=n;i+=2)anns[1]+=p[i];
		for(int i=2;i<=n;i+=2)anns[2]+=p[i];
		for(int i=1;i<=m;i++)
		{
			int ju1,ju3,ju2,ju4;
			scanf("%d%d%d%d",&ju1,&ju3,&ju2,&ju4);
			if(ju1>ju2)swap(ju1,ju2),swap(ju3,ju4);
			if(ju2==ju1+1&&ju3==ju4&&ju3==0){printf("-1\n");continue;}
			if(ju3!=ju4&&ju1==ju2){printf("-1\n");continue;}			
			if((ju1%2+ju2%2)%2==0)
			{
				if(ju3==ju4)
				{
					if(ju3==1&&ju1%2==0||ju3==0&&ju1%2==1)printf("%lld\n",anns[0]);
					else if(ju3==1&&ju1%2==1||ju3==0&&ju1%2==0)printf("%lld\n",anns[1]);
				}
				else if(ju1!=1)printf("%lld\n",min(p[ju1+1],p[ju1-1])+anns[ju2%2]-p[ju1]);
				else printf("%lld\n",p[ju1+1]+anns[ju2%2]-p[ju1]);
			}
			else if(ju3!=ju4)
			{
				if(ju4==1)printf("%lld\n",anns[ju2%2]);
				else if(ju3==1)printf("%lld\n",anns[ju1%2]);
			}
			else if(ju3==1)
			{
				printf("%lld\n",min(anns[ju2%2]+p[ju1],anns[ju1%2]+p[ju2]));
			}
			else printf("%lld\n",min(anns[(ju1%2+1)%2],anns[(ju2%2+1)%2]));
		}
	}
	return 0;
}
