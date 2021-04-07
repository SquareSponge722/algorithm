#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
int T,n,a[200],st[200],top;

inline int getnum()
{
	int s=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s;
}

int dfs(int pos,int x,int s)
{
	if (s==x) return 1;
	if (pos==top+1) return 0;
	if ((x-s)%st[pos]==0) return 1;
	for (int i=0; i<=(x-s)/st[pos]; ++i)
	    {
	    	if (dfs(pos+1,x,s+st[pos]*i)) return 1;
		}
	return 0;
}

void work()
{
	memset(st,0,sizeof(st)); top=1;
	st[1]=a[1];
	for (int i=2; i<=n; ++i)
	    {
	    	if (!dfs(1,a[i],0)) st[++top]=a[i]; 
		}
	printf("%d\n",top);
}

void get_work()
{
	int t;
	T=getnum();
	while (T--)
	    {
	    	n=getnum(); memset(a,0,sizeof(a));
	    	for (int i=1; i<=n; i++) a[i]=getnum();
	    	sort(a+1,a+n+1);
	    	if (n==1) printf("1\n");
	    	else if (n==2)
	    	         {
	    	         	if (a[2]%a[1]==0) printf("1\n");
	    	         	else printf("2\n");
					 }
			else if (n==3)
			         {
			         	if (a[2]%a[1]==0)
			         	    {
			         	    	if (a[3]%a[1]==0) printf("1\n");
			         	    	else printf("2\n");
							}
						else
						    {
						    	int flag=0;
						    	for (int i=0; i<=a[3]/a[1]&&(!flag); i++)
						    	    {
						    	    	if ((a[3]-(a[1]*i))%a[2]==0) flag=1;
									}
								if (flag) printf("2\n");
								else printf("3\n");
							}
					 }
			else 
			    {
			    	work();
				}
		}
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);

	get_work();

	return 0;
}
