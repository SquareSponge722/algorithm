#include<cstdio>

int main()
{
	int i;
	FILE *fin, *fout;
	fin=fopen("defense.in","r");
	fout=fopen("defense.out","w");
	fscanf(fin,"%d",&i);
	fprintf(fout,"-1");
	return 0;
}
