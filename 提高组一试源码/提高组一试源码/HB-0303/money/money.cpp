#include<cstdlib>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>

const int MAXM = 25000+500;
const int MAXN = 200;

int num[MAXN];
bool D[MAXM];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	int totMoney, x, cnt, totCases;
	
	scanf("%d",&totCases);
	
	while(totCases--)
	{
		memset(D,false,sizeof(D));*D = true;
		memset(num,0,sizeof(num));
		cnt = 0;
		
		scanf("%d",&totMoney);
		for(int i=0;i<totMoney;i++)scanf("%d", num+i);
		std::sort(num,num+totMoney);
		
		for(int i=0;i<totMoney;i++)
		{
			x = num[i];
			if(D[x]) continue;
			else ++cnt;
				
			for(int i=0;i+x<MAXM;i++)
				if(D[i]) D[i+x] = true;
		}
		printf("%d\n",cnt);
	}
	
	return 0;
}