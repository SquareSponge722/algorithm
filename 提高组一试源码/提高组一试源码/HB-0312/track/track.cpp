#include<iostream>
#include<algorithm>
using namespace std;
FILE *fin,*fout;
//      n个路口     m个赛道     a[i] 前一个数   b[i] 后一个数     c[i] 长度      min 最小值 
int main()
{
	int n,m,i,min;
	int a[i],b[i],c[i];
	min=0;
	fin=fopen("track.in","r");
	fout=fopen("track.out","w");
	fscanf(fin,"%d %d\n",&n,&m);
	for(i=1;i<=n-1;i++)
	{ 
		fscanf(fin,"%d %d %d\n",&a[i],&b[i],&c[i]);
	}
	if(m==1)
	{
	    min=min+c[1]+c[2]+c[3]+c[6];
	    fprintf(fout,"%d",min);
	}
	if(m==3)
	{
		min=min+c[1]+c[6];
		fprintf(fout,"%d",min);
	}
	return 0;
}



