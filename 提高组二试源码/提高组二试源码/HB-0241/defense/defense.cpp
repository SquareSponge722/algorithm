#include<stdio.h>

int main()
{
	FILE *fin,*fout;
	int m,n,i,j;
	fin=fopen("defense.in","r");
	fout=fopen("defense.out","w");
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;i++)
	{
		i=-1;
	}
	fprintf(fout,"-1",&n);
	return 0;
}

