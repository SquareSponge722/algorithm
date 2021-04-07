#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int d[10005],a[10005],b[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.ans","w",stdout);
	int i,n,head,num=0,j,lit;
	scanf("%d",&n);
	for(i = 1;i <= n;i++)
		scanf("%d",&d[i]);
	for(i = 1;i <= n;i++)
		a[i] = d[i];			
	sort(a,a + 1 + n);		
	for(i = 1;i <= n;i++)		
		d[i] -= a[1];
	num += a[1];			
	for(i = 1;i <= n;i++)
		a[i]=d[i];	 
	for(i=1;i<=n;i++)
	{
	if(d[1]!=0&&d[n]!=0)
	{
	for(i = 1;i <= n;i++)		
		if(d[i] == 0)
		{
				lit = i;
			sort(a,a + i);
			sort(a + i,a + n + 1);
		}	
	for(i=1;i<=n;i++)			
		if(a[i]!=0)
		{
			head=i;
			break;
		}
	for(i = head;d[i] != 0;i++)		
		d[i] -= a[head];
	for(i = n;d[i] != 0;i--)		
		d[i] -= a[lit + 1];
		num += a[head];
		num += a[lit+1];
	for(i = 1;d[i] != 0;i++)		
		a[i]=d[i];
	for(i=1;i<=n;i++)
		num+=d[i];
	}
	else for(i=1;i<=n;i++)
			d[i]=d[i+1];
	}
		printf("%d",num);
	return 0;
}
