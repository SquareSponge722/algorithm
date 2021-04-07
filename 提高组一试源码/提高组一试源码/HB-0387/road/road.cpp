#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	FILE *fin, *fout;
	fin=fopen("road.in","r");
	fout=fopen("road.out","w");
	int n,i;
	int ch[n];
	for(n=1;n<=100000;n++)
	for(int di=1;di<=10000;di++)
	fscanf(fin,"%d\n",&n);
	fscanf(fin,"%d",&ch[n]);
	if(di!=0)
	{
		ch[n]=di--;
		if(di==0)
		{
			
		}
	}
	
	
	
	
}
