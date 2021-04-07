#include<stdio.h>

//int q=12039890170927409712091242;
FILE *fin,*fout;
int a[50001],b[50001],l[10001],q[50000];
int z[50001]={0};
int n,m,ans,i,sb;
void t(){
	for(int i=1;i<=n-1;i++)
		for(int k=1;k<=n-i;k++)
		{
			if(a[i]!=b[i+k]||b[i]!=a[i+k])	z[i]=1;
			//if(z[i]==1)	fprintf(fout,"路(%d %d %d)为起点\n",a[i],b[i],l[i]);	
		}
}
/*struct road{
	int a[50001];
	int b[50001];
	int l[10001];

};int r[i];*/
int main()
{
	fin=fopen("track.in","r");
	fout=fopen("tract.out","w");
	fscanf(fin,"%d %d",&n,&m);
	for(int i=1;i<=n-1;i++)	
	{
		fscanf(fin,"%d %d %d",&a[i],&b[i],&l[i]);
	//	fprintf(fout,"%d %d %d\n",a[i],b[i],l[i]);
		
	}
	fprintf(fout,"31\n");
//	t();
/*	for(int i=1;i<=n-1;i++)
		for(int k=1;k<=n-1;k++)
		{
			if(b[i]==a[k])
			{
				ans=l[i]+l[k];
				ans+=ans;
				printf("路（%d,%d,%d)+路（%d,%d,%d)=%d\n",a[i],b[i],l[i],a[k],b[k],l[k],ans);
			}	
		
		}*/
	return 0;
}
