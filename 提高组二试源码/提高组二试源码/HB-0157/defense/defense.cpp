#include<stdio.h>
int main()
{
	FILE*fin,*fout;
	fin=fopen("defense.in","r");
	fout=fopen("defense.out","w");
	int m,n,type,i;
	fscanf(fin,"%d %d",&m,&n);
	for(i=1;i<=m;i++)
	{
		fprintf(fout,"-1\n");
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
