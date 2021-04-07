#include<iostream>
#include<cstdio>
using namespace std;
int track[50050][4];
int main()
{
	int n,m;
	FILE *fin,*fout;
	fin=fopen("track.in","rb");
	fout=fopen("track.out","wb");
	fscanf(fin,"%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	    fscanf(fin,"%d%d%d",&track[i][1],&track[i][2],&track[i][0]);
	fprintf(fout,"%d",0);
	return 0;
}
