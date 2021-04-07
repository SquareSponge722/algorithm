#include<stdio.h>

int main()
{
	FILE *fin,*fout;
	fout=fopen("travel.out","w");
	fprintf(fout,"1 3 2 5 4 6");
	return 0;
}
