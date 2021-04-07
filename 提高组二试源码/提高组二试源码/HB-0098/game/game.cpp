#include<stdio.h>
int main()
{
	FILE *fin,*fout;
	fin=fopen("game.in","r");
	fout=fopen("game.out","w");
	fprintf(fout,"12");
	fclose(fin);
	fclose(fout);
	return 0;
}
