#include<bits/stdc++.h>
using namespace std;
#define fre(a) ifstream cin(a".in");ofstream cout(a".out")
#define FOR(i,a,b) for(i=a;i<=b;++i)
//struct edge{
//	int next,to;
//}a[100001];
long long ans,sum;
struct tt{
	int w,p;
};
int head[100001],tot;
int de[10001];
int p[10001];
tt ton[10001];
int a[5001][5001];
int u[10001],v[10001],n;
int p1,f1,q,f2;
bool cmp(tt a,tt b)
{
	return a.w>b.w;
}
int depend()
{
	if(f1==0)
	{
		if(de[p1])return 0;
	}
	if(f2==0)
	{
		if(de[q])return 0;
	}
	if(f1==1){
			if(!de[p1]){return 0;}	
				}
				if(f2==1)
					{
						if(!de[q]){return 0;}
					}
					int j;
			FOR(j,1,n-1)
			{
				if(de[u[j]]||de[v[j]]);
				else {return 0;}
			}
			return 1;
}
void f(int pl)
{
	if(pl>n&&depend())
	{
		ans=0;
		int i;
		FOR(i,1,n)
		if(de[i])
		ans+=p[i];
		sum=max(sum,ans);
	}
	else if(pl>n)return;
	for(de[pl]=0;de[pl]<=1;++de[pl])
	{
		f(pl+1);
	}
}
int main()
{
	char c;
	int flag,m,x,i,j;
	fre("defense");
	cin>>n>>m>>c>>x;
	FOR(i,1,n)
	cin>>p[i];
	FOR(i,1,n-1)
	{cin>>u[i]>>v[i];
	a[u[i]][v[i]]=1;
	a[v[i]][u[i]]=1;
	}
	FOR(i,1,n)
	ton[i].p=i;
	FOR(i,1,n)
	FOR(j,1,n)
	{if(a[i][j])ton[i].w+=p[j];
	ton[i].w-=p[i];}
	sort(ton+1,ton+n+1,cmp);
	FOR(i,1,m)
	{
		cin>>p1>>f1>>q>>f2;
		if(a[p1][q]&&f1==0&&f2==0){cout<<-1;continue;}
		FOR(i,1,n)
		{
			sum=0;
			f(1);
			cout<<sum<<endl;
		}
	}
	return 0;
}
