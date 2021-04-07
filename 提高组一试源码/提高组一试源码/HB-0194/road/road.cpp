#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a[105];
int road(int b,int c)
{
	int n,k=0,min;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=c;j++)
		{
			a[j]=a[j]-1;
			if(a[j]==0) min=j;break;
		}
		k=k+i;
	}
	if(min>b) road(b,min);
	if(min<n) road(min,c);
	return k;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,k;
	scanf("%d",&n);
	road(1,n);
	printf("%d",k);
	return 0;
	fclose(stdin);fclose(stdout);
}
