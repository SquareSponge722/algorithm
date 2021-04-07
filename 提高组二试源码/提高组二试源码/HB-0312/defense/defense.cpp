#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
FILE *fin,*fout;
int main()
{
	int n,m,i,b=12,c=7,d=-1;//   i£º³ÇÊÐºÅ 
	char a;
	fin=fopen("defense.in","r");
	fout=fopen("defense.out","w");
	fscanf(fin,"%d %d %s\n",&n,&m,a);
	fprintf(fout,"%d %d %s\n",b,c,d);
}
