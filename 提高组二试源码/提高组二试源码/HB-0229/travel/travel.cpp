#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<iomanip>
using namespace std;
int m,n,b[5011];
bool a[5011][5011],c[5011];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i,u,v,head=1,tail=1;
	scanf("%d %d",&m,&n);
	b[1]=1;
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		a[u][v]=1;
		a[v][u]=1;
	}
	do
	{
	    for(i=2;i<=n;i++)
	    if(a[b[head]][i]&&!c[i])
	    {
	    	c[i]=1;
	    	tail++;
	    	b[tail]=i;
		}
		sort(b+head+1,b+tail+1);
		head++;
		
    } while(head<n);
    for(i=1;i<n;i++)
    printf("%d ",b[i]);
    printf("%d",b[n]);

	return 0;
	
}
