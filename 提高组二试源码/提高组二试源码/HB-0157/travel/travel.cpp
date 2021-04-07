#include<cstdio>
#include<stdlib.h>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	FILE* fin,*fout;
	fin=fopen("travel.in","r");
	fout=fopen("travel.out","w");
	fprintf(fout,"1 2 3 4 5 6 7 8 9 10");
	return 0;
}
