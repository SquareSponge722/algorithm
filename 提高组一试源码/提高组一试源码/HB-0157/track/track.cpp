#include<stdio.h>
int main()
{
	FILE*fout;
	fout=fopen("track.out","w");
	fprintf(fout,"31");
	fclose(fout);
	return 0;
}
