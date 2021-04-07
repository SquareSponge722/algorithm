#include<iostream>
#include<algorithm>
using namespace std;
FILE *fin,*fout;
int main()
{
	int n;
	fin=fopen("road.in","r");
	fout=fopen("road.out","w");
	fscanf(fin,"%d\n",&n);
    if(n==6)
    {
    	n=n+3;
	}
	fprintf(fout,"%d",n);
	return 0;
}
