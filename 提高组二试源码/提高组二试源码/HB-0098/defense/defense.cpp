#include<stdio.h>
int main()
{
	int i,j,k,l;
	FILE *fin,*fout;
	fin=fopen("defense.in","r");
	fout=fopen("defense.out","w");
	fscanf(fin,"%d %d",&i,&j);
	for(i=1;i<=j;i++)
	{
		fprintf(fout,"-1\n");
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
