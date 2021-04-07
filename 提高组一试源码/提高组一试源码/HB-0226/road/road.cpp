#include <cstdio>
#include <cstdlib>
using namespace std;
int n;
const int N=20000000;
int d[N];
long long cc;
bool flag[N];
int sum;
int zero_;
int min_zero;
void init_()
{
	scanf("%d",&n);
	sum=n;	
	for (int i=0;i<n;i++)
	{
		scanf("%d",&d[i]);
		if(!d[i])
			sum--,flag[i]=false;
		else
			flag[i]=true;
	}
}
void do_slx()
{
	while(sum>0)
	{
		for (int i=0;i<n;i++)
		{
			if(flag[i]==false)
				continue;
			if((!d[i]&& !d[i+1]) || (!d[i-1]&&!d[i])|| !d[i])
				continue;
						
			if(d[i])
				d[i]--;
			if((!d[i] && !d[i+1]))
			{
				cc++;
				sum--;
				flag[i]=false;
				break;
			}
			else 
			{
				if(!d[i]&&flag[i])
					sum--;
				if(!d[i+1])
					cc++;
			}
		}
	}
	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init_();
	do_slx();
	printf("%d",cc);
	return 0;
	
}
