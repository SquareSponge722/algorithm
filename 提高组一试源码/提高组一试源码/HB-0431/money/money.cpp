#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int t;
int n,a[25001],m,b[25001];
int main()
{
	FILE *fin,*fout;
	fin=fopen("money.in","r");
	fout=fopen("money.out","w");
	fscanf(fin,"%d",&t);
	for(int w=1;w<=t;w++)
	{
		fscanf(fin,"%d",&n);
		for(int i=1;i<=n;i++)
		fscanf(fin,"%d",&a[i]);
		int k=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			if(a[i]%a[j]!=0)
			k++;
			if(k==n-1)
			ans++;
		}
		fprintf(fout,"%d\n",ans);
	}
	return 0;
}
