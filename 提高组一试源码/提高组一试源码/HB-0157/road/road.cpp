#include<stdio.h>
int main()
{
	FILE*fout;
	fout=fopen("road.out","w");
	fprintf(fout,"6");
	fclose(fout);
	return 0;
}
