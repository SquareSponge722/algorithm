#include<iostream>
#include<cstdio>
using namespace std;
int a[1001];
int b[1001];
int l[1001];
int main()
{
	FILE*fin,*fout;
	fin=fopen("track.in","rb");
	fout=fopen("track.out","wb");
	int n,m,x;
	fscanf(fin,"%d%d",&n,&m);
	for(int i=1;i<n;i++)
	fscanf(fin,"%d%d%d",&a[i],&b[i],&l[i]);
	if(m>=n)
	x=l[m]+l[n]+l[m-n];
	else
	x=l[m]+l[n]+l[n-m];
	fprintf(fout,"%d",x);
	return 0;
}
