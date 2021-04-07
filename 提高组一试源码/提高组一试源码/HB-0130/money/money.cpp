#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#define N 1000010
#define maxn 30000
using namespace std;
int n,a[N],T,pri[N],vis[N],hav[N],hs[N],zs[N],Min,MMin,vv[N],lim=999999999,ans[N],lima,limb;

int get(int aa,int bb)
{
	if(bb==0) return aa;
	else return get(bb,aa%bb);
}

void work()
{
	for(int i=2; i<=maxn; i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			pri[++pri[0]]=i;
			hav[i]=1;
		}
		for(int j=1; j<=pri[0] && i*pri[j]<=maxn ; j++)
		{
			vis[i*pri[j]]=1;
			if(i%pri[j]==0) break;
		}
	}
}

void work_zs()
{
	sort(zs+1,zs+zs[0]+1);
	if(zs[0]>=1) Min=zs[1];
	if(zs[0]>=2)
	{
		MMin=zs[2];
		lim=Min*MMin-Min-MMin;
		lima=MMin;
		limb=Min;
	}
}

void work_hs()
{
	sort(hs+1,hs+hs[0]+1);
	if(hs[0]==1)
	{
		printf("2\n");
		return ;
	}
	if(zs[0]>=1)
	{
		for(int i=1; i<=hs[0]; i++)
		{
			if(hs[i]%Min==0 || Min%hs[i]==0) continue;
			if(lim>Min*hs[i]-Min-hs[i])
			{
				lim=Min*hs[i]-Min-hs[i];
				lima=hs[i];
				limb=Min;
			}
		}
	}
	for(int i=1; i<hs[0]; i++)
		for(int j=i+1; j<=hs[0]; j++)
		{
			if(hs[j]%hs[i]==0) continue;
			int g=get(hs[i],hs[j]);
			if(g==1)
			{
				if(lim>Min*hs[i]-Min-hs[i])
				{
					lim=Min*hs[i]-Min-hs[i];
					lima=hs[i];
					limb=hs[j];
				}
				continue;
			}
			int A=hs[i]/g,B=hs[j]/g;
			int tmp=A*B-A-B;
			for(int k=tmp+1; k<=99999999; k++)
			{
				if(k*g>lim) break;
				vv[k*g]=1;
			}
		}
	for(int i=1; i<=lim; i++)
		if(vv[i]==1) ans[++ans[0]]=i;
	int Ans=0;
	for(int i=1; i<=ans[0]; i++)
	{
		int flag=1;
		for(int j=1; j<i; j++)
			if(ans[i]%ans[j]==0)
			{
				flag=0;
				break;
			}
		if(flag==1) Ans++;
	}
	for(int i=1; i<=10000; i++)
		for(int j=1; j<=10000; j++)
		{
			if(lima*i+limb*j<=lim && vv[lima*i+limb*j]==1) Ans--; 
			else break;
		}
	if(Ans>=n) Ans=n;
	printf("%d\n",Ans);
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	work();
	while(T--)
	{
		hs[0]=0;
		zs[0]=0;
		ans[0]=0;
		MMin=0;
		Min=0;
		lim=999999999;
		memset(vv,0,sizeof(vv));
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&a[i]);
			vv[a[i]]=1;
			if(hav[a[i]]) zs[++zs[0]]=a[i];
			else hs[++hs[0]]=a[i];
		}
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		else if(n==2)
		{
			int aaa=2;
			if(a[1]%a[2]==0 || a[2]%a[1]==0) aaa--;
			printf("%d\n",aaa);
			continue;
		}
		work_zs();
		work_hs();
	}
	return 0;
}




