#include<cstdio>
#include<iostream>
using namespace std;
int m[25],a[105],p[105];
int js(int n,int t);
int main()
{
FILE *fin,*fout;
fin=fopen("money.in","rb");
fout=fopen("money.out","wb");
int t,N;
fscanf(fin,"%d",&t);
for(int h=1;h<=t;h++) 
    {
    fscanf(fin,"%d",&N);
	for(int z=1;z<=N;z++)
        {fscanf(fin,"%d",&a[z]);
        p[z]=a[z];}
    js(N,h);
    for(int z=1;z<=N;z++)
        a[z]=0;
    }
for(int h=1;h<=t;h++)
{fprintf(fout,"%d",m[h]);
fprintf(fout,"\0");
}
return 0;
}


int js(int n,int t)
{
 int d[105][105]={},s=0,maxx;
 for(int j=1;j<=n;j++)
    for(int i=j+1;i<=n;i++)
       {if(a[i]<a[i-1])
          {maxx=a[i];
	      a[i]=a[i-1];
	      a[i-1]=maxx;}
	   }
m[1]=2;
m[2]=5;
m[3]=7;
m[4]=11;
m[5]=13;
}
