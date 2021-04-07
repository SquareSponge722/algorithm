#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5001;
int n,m;
bool r[N][N],flag[N];//r数组为道路数组，k数组为标记数组 
int a[N],b[N];//a[n]为经过的城市,b[n]为级数 
int main()
{freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	cin>>n>>m;int p,q;if(n!=m) return 0;
	for(int i=1;i<=m;i++) {cin>>p>>q;r[p][q]=true;r[q][p]=true;}
	int head=0,tail=1,k=0;
	a[1]=1;b[1]=1;flag[1]=1;//起点为1,深度为1 
	while(head<tail)
	{
		head++;int shi=0;
		for(int i=2;i<=n;i++)
		{
		if(i==a[head]) {}
		if(r[a[head]][i]&&!flag[i])
		{
			shi++;tail++;
			a[tail]=i;b[tail]=b[head]+1;flag[i]=1;
			if(tail==n) {k=1;break;}
		}
		if(k) break;
	}
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}
