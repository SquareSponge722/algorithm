#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	FILE*fin,*fout;
	fin=fopen("game.in","rb");
	fout=fopen("game.out","wb");
	int n,m,ans;
	fscanf(fin,"%d%d",&n,&m);
	ans=m*n*3;
	fprintf(fout,"%d",ans);
	return 0;
}
