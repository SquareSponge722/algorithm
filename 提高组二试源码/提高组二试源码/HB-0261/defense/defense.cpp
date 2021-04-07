#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
int a[10010],c[10110][100],d[10010][100],book[10010];
char b[10];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,money=0,k=0,m;
	scanf("%d%d %s",&n,&m,b);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<n;++i) scanf("%d%d",&c[i][1],&c[i][2]);
	for(int i=1;i<=m;++i) scanf("%d%d%d%d",&d[i][1],&d[i][2],&d[i][3],&d[i][4]);
	for(int i=1;i<=m;++i)
	{
		if(d[i][2]>0) book[d[i][1]]++,money+=a[d[i][1]];
		else book[d[i][1]]--;
		if(d[i][4]>0) book[d[i][3]]++,money+=a[d[i][3]];
		else book[d[i][3]]--;
		for(int p=1;p<n;++p)
		{
			if(book[c[p][1]]<0&&book[c[p][2]]<0)
			{
				printf("-1");
				printf("\n");
				k++;
				break;
			}
			else
			{
				if(book[c[p][1]]!=1&&book[c[p][2]]!=1)
				{
					if(book[c[p][1]]<0)
					{
						book[c[p][2]]++;
						money+=a[c[p][2]];
					}
					else if(book[c[p][2]]<0) 
					{
						book[c[p][1]]++;
						money+=a[c[p][1]];
					}
					else if(book[c[p][1]]==0&&book[c[p][2]]==0)
					{
						if(a[c[p][1]]>a[c[p][2]])
						{
							book[c[p][2]]++;
							money+=a[c[p][2]];
						}
						else
						{
							book[c[p][1]]++;
							money+=a[c[p][1]];
						}
					}
				}
			}
		}
		if(k==0) printf("%d\n",money);
		for(int i=1;i<=n;++i) book[i]=0;
		money=0;
		k=0;
	}
	return 0;
}
