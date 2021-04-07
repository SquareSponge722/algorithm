#include<stdio.h>
int main()
{
	FILE *fin,*fout;
	fin=fopen("track.in","r");
	fout=fopen("track.out","w");
	int i,j,k,a[1001][4],x,r,s;
	fscanf(fin,"%d",&s);
	for(i=1;i<=s;i++)
	{
		fscanf(fin,"%d %d %d",a[i][1],a[i][2],a[i][3]);
	}
	for(i=1;i<=3;i++)
	{
		for(j=i+1;j<=s;j++)
		{
		   if(a[i][3]<a[j][3])
		   {
		   	r=a[i][3];
		   	a[i][3]=a[j][3];
		   	a[j][3]=r;
		   }
		}
	}
	x=a[1][3]+a[2][3]+a[3][3];
	fprintf(fout,"%d",x);
	fclose(fin);
	fclose(fout);
	return 0;
}
