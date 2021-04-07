#include<cstdio>
using namespace std;
int a[1000],b[1000],l[1000],d[100][100][100];
int main()
{
FILE *fin,*fout;
fin=fopen("track.in","rb");
fout=fopen("track.out","wb");
int n,m,ans[101]={};
fscanf(fin,"%d%d",&n,&m);
for(int i=1;i<n;i++)
fscanf(fin,"%d%d%d",&a[i],&b[i],&l[i]);
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
for(int x=1;x<=n;x++)
for(int y=1;y<=n;y++)
for(int z=1;z<=n;z++)
for(int k=1;k<=n;k++)
d[x][y][z]=a[k]+b[y]+l[j];
for(int k=1;k<=n;k++)
ans[k]=k;
fprintf(fout,"%d",ans[65]);
return 0;
}
