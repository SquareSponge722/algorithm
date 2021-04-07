#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;
const int maxn=200;
const int maxm=25000+100;
int n,maxcoin,top,ans;
int coin[maxn]={0},book[maxm]={0};
long long sum[maxn*2]={0};
int max(int a,int b){if(a>b) return a; else return b;}
int oo(int a){if(a>0) return a; else return -a; }
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(coin,0,sizeof(coin));
		memset(book,0,sizeof(book));
		memset(sum,0,sizeof(sum));
		scanf("%d",&n);
		ans=n;
		top=0;
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&coin[i]);
			maxcoin=max(maxcoin,coin[i]);
		}
		sort(coin+1,coin+1+n);
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+coin[i];
		top=n;
		for(int i=1;i<=n;i++)
		{
			sum[++top]=coin[i];
			int op=coin[i]*2;
			while(op<=maxcoin)
			{
				sum[++top]=op;
				book[op]++;
				op+=coin[i];
			}
		}
		sort(sum+1,sum+1+top);
		for(int i=1;i<=top;i++)
		{
			for(int j=1;j<=top;j++)
			{
				if(sum[i]+sum[j]<=maxcoin)
				book[sum[i]+sum[j]]++;
				else break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(book[coin[i]]!=0)
			{
				ans--;
				continue;
			}
			/*for(int j=1;j<=top;j++)
			{
				if(book[oo(sum[j]-coin[i])]!=0&&oo(sum[j]-coin[i])!=0)
				{
					ans--;
					break;
				}
			}*/
			//else printf("%d ",coin[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
54
74 36 49 81 57 76 93 50 45 69 75 83 59 98 70 80 54 37 92 84 91 58 11 16 96 94 38 55 97 73 46 72 47 51 44 89 90 31 100 99 39 82 65 87 41 79 86 34 95 63 52 12 88 53

*/