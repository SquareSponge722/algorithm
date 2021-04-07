#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
bool jud(int a,int b){return a<b;}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int k=0,n=0,i=0,a[101],t=0,j=0,ans=0,s=0,h=0,res=0,b=0;
	bool book[21][25001]={false};
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		scanf("%d",&n);res=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			res=max(res,a[i]);
		}
		sort(a+1,a+n+1,jud);
		ans=0;
		for(i=1;i<=n;i++)
		{
			b=a[i];s=0;
			if(book[k][b]==true) s=1;
			if(s==0)
			{
				for(j=1;j<=(b+1)/2;j++)
				{
					if(book[k][j]==true && book[k][b-j]==true)
					{
						s=1;
						book[k][b]=true;
					}
				}
			}
			if(s==0)
			{
				ans++;
				for(j=b;j<=res;j+=b) 
				{
					book[k][j]=true;
					for(h=1;h<=res;h++)
					{
						if(book[k][h]==true)
						{
							book[k][h+j]=true;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
