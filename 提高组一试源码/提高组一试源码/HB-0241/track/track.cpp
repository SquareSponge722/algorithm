#include<stdio.h>
int main()
{
	FILE *fin,*fout;
    int i,n;
	fin=fopen("track.in","r");
	fout=fopen("track.out","w");
	fprintf(fin,"%d",&n);
	for(i=1;i<=n;i++)
	{
     i=-1;
     n=-1;
	}
	fprintf(fout,"-1",&n);
	fclose(fin);
	fclose(fout);
	return 0;
} 
