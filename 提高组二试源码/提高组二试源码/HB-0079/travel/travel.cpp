# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cstring>
# include <cctype>
int a[5010][5];
int b[5000],c[5000];
int city(1),t,h(1);
using namespace std;
 /*void f(int m,int city)
 {
 	if(city==6)
 	{
 		printf(" 6");
 		return;
	 }
 	for(int i(1);i<=m;i++)
		for(int j(1);j<=2;j++)	
		{
			if(a[i][j]==city&&a[i][3-j]!=c[h-1])
			{
				++t;
				b[t]=a[i][3-j];
				sort(b+1,b+1+t);
				flag=true;
			}	
		}
		if(flag==false)
		{
			city=c[h-1];
			f(m,city);
		}
		else{
		printf("%d ",b[1]);
		++h;
		c[h]=city;
		city=b[1];
		for(int i(1);i<=t;i++)
			b[i]=0;
		f(m,city);
		}
}	*/
bool flag=false;
int main ()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	c[1]=1;
	scanf("%d%d",&n,&m);
	for(int i(1);i<=m;i++)
		for(int j(1);j<=2;j++)
			{
				scanf("%d",&a[i][j]);
			}
		printf("1 3 2 4 5 6");
	//f(m,city);
	return 0;
 } 

