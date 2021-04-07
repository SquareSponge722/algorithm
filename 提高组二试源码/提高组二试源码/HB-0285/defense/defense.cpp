#include<stdio.h>
int n,m,a,b,x,y,i,j,k,fy[10001]={10001},fypm[10001]={-1},tp,zje,min[10001],u,v,csq,cs2,cs3,bj[10001]={0},bjzs=0,lt[10001][10001]={0};
char sj[3];
FILE *fin,*fout;
int zbj1()
{
	for(i=1;i<=n-1;i++)
	{
		if(lt[x][i]==1)
		{
			bj[i]=1;
			zje=zje+fy[i];
			bjzs++;
		}
	}	
}
int zbj2()
{
	for(j=1;j<=n-1;j++)
	{
		if(lt[i][j])
	}
}
int main()
{
	fin=fopen("defense.in","r");
	fout=fopen("defense.out","w");
	fscanf(fin,"%d %d %s",&m,&n,sj);
	for(i=1;i<=n;i++) 
	{
		if(fy[fypm[i]]<fy[fypm[i-1]])
		{
			tp=fypm[i];
			fypm[i]=fypm[i-1];
			fypm[i-1]=tp;
		}
		fscanf(fin,"%d",fy[i]);
		fypm[i]=i;
	}
	for(i=1;i<=n-1;i++)
	{
		fscanf(fin,"%d %d",&u,&v);
		lt[u][v]=1;
		lt[v][u]=1;
	}
	for(i=1;i<=m;i++)
	{
		zje=0;
		fscanf(fin,"%d %d %d %d",&a,&x,&b,&y);
		if((lt[a][b]==1)&&(x==0)&&(y==0)) {min[i]=-1;}
		 else
		 {
		 	bj[a]=x;
		 	bj[b]=y;
		 	while(bjzs!=n)
		 	{
		 		if(y==1) zje=zje+fy[b];
				if(x==0)
				{
			        zbj1();
			        for(i=1;i<=n;i++)
	                {
		              if(bj[i]==1)
		              {
			             zbj2();
		              }
	                }
				}
				else 
				{
					zje=zje+fy[a];
				}
			}
		 }
	}
	for(i=1;i<=m;i++)
	{
		fprintf(fout,"%d",min[i]);
	}
	return 0;
}
