#include <cstdio>
#include <cstring>
using namespace std;

int test;
int n;
int money[25005];
int num;
int temp;

void dfs(int start,int end)
{
	if(money[start]==0)
	return;
	temp=money[start];
	for(int i=1;i<=n;i++)
	{
		if(money[i]==0)
		continue;
		if(money[i]==money[start])
		continue;
		if(money[i]%temp==0)
		{
			money[start]=money[i]/money[start];
			num--;
			money[i]=0;
			dfs(start,end);
		}
	}
}


int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&test);
	for(int i=1;i<=test;i++)
	{
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&money[j]);
		}
		num=n;
		for(int i=1;i<=n;i++){
		dfs(i,n);
	}
		printf("%d\n",num);
	}
    
	return 0;
}


