#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	FILE *fin, *fout;
	fin=fopen("money.in","r");
	fout=fopen("money.out","w");
	int m[1],n[1],a,b;
	for(a=1;a<=20;a++)
	for(b=1;b<=100000;b++)
	
	
	n[1]=a;
	m[1]=b;
	fprintf(fout,"%d\n",n[1]);
	fprintf(fout,"%d",m[1]);
	return 0;
}
