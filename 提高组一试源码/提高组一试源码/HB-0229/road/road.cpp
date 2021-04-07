#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
int d[100010],ans=0;
void deep(int s,int l)
{
	int min=100001,k=0;
	for(int i=s;i<=l;i++)
	if(d[i]<min) {min=d[i];k=i;};
	ans+=min;
	for(int i=s;i<=l;i++)
	d[i]-=min;
	if(s!=k) deep(s,k-1);
	if(l!=k) deep(k+1,l);
}
int main()
{
   	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
     int n;
	 scanf("%d",&n);
	 for(int i=1;i<=n;i++)
	 scanf("%d",&d[i]);
	 deep(1,n);
	printf("%d",ans);	
	return 0;
}
