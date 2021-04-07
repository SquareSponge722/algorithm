# include <iostream>
# include <cstdio>
using namespace std;
const long int maxn=1000;
static int day=0;
long int n,di[1000],a[1000][1000];
int main()
{
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
long int n;
long int max=0;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>di[i];
for(int i=0;i<n;i++)
    if(max<di[i]) max=di[i];
    
for(int i=0;i<n;i++)
   for(int c=0;c<di[i];c++)
    a[c][i]=1;
    
for(int i=0;i<max;i++)
{
	for(int c=0;c<n;c++)
	{if(a[i][c]==0&&c==0) day--;
	if(a[i][c]==1&&c!=n-1) continue;
else if(c==n-1&&a[i][c]==1) day++;
	else if(a[i][c]==0&&a[i][c]!=a[i][c+1])day++;
}
}
cout<<day;
return 0;
}






















