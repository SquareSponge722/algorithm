#include<iostream>
#include<cstdio>
using namespace std;
int d[100005],number1=0,number2=0,maxn=0,minn=0,ans=0;
int main()
{
	FILE *fin,*fout;
	fin=fopen("road.in","rb");
	fout=fopen("road.out","wb");
	int n;
	fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++)
    {
    	fscanf(fin,"%d",&d[i]);
	}
	for(int m=1;m<=n;m++)
	{
		if(d[m]>maxn)
		{
			maxn=d[m];
		}
	}
	for(int j=1;j<=maxn;j++)
	{
				for(int k=1;k<=n;k++)
		{
if(d[k]==0)
{
number1++;
number2++;
}
		}
		if(d[1]==0)number1--;
		if(d[n]==0)number1--;
		int s=1;
		for(int m=1;m<=n;m++)
		{
			if(d[m]!=0)d[s]=d[m];
			if(d[m]==0)
			{
			s--;
		}
			s++;
		}
		n=n-number2;
		for(int k=1;k<=n;k++)
		{
			if(d[k]<minn)
			{
				minn=d[k];
			}
		}
				for(int k=1;k<=n;k++)
		{
	d[k]=d[k]-minn;
		}
		ans=ans+minn*(number1+1);
	}
	fprintf(fout,"%d",ans);
	return 0;
}
