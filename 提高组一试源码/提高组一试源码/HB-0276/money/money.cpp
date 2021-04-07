#include<iostream>
#include<cstdio>
using namespace std;
int a[1001];
int main()
{
	FILE*fin,*fout;
	fin=fopen("money.in","rb");
	fout=fopen("money.out","wb");
	int t,n,m;
	fscanf(fin,"%d",&t);
	for(int i=1;i<=t;i++)
	{
		fscanf(fin,"%d",&n);
		for(int j=0;j<n;j++)
		fscanf(fin,"%d",&a[j]);
		for(int k=0;k<n;k++)
		{
			if(a[k]%2!=0)
			m=n;
			else
			m=n/2;
		}
		
	    fprintf(fout,"%d\t",m);
	}
	return 0;
}
