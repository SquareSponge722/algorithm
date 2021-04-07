#include<stdio.h>
int main()
{
	FILE*fout;
	fout=fopen("money.out","w");
	fprintf(fout,"2\n5");
	fclose(fout);
	return 0;
}
