#include<bits/stdc++.h>
using namespace std;
int n,m,d[50002],fa,son,val,v[50002];
bool ok,iswa[500002];
struct node
{
	int son,val;
	node(int son1,int val1){son=son1;val=val1;}
};
vector<node>edge[50002];
void check(int x)
{
	int sum=0,num=0;
	for(int i=1;i<=n-1;i++)
	{
		sum+=v[i];
		if(sum>=x)sum=0,num++;
		if(num==m){ok=1;return;}
	}
	return;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int l=2147483600,r=0;
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&fa,&son,&val);
		edge[fa].push_back(node(son,val));
		edge[son].push_back(node(fa,val));
		v[i]=val;
		l=min(l,val);r+=val;
	}
	while(l<r)
	{
		int mid=(l+r+1)/2;ok=0;
		check(mid);
		if(ok)l=mid;
		else r=mid-1;
	}
	printf("%d",l);
	return 0;
}
