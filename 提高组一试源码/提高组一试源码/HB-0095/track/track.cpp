#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;
struct node
{
	int right,left,head;
}r[10005],w[10005];
int n,m,a[100005],maxn,sum,cnt;
void dfs(int x)
{
	if(r[x].head)
	{
		sum+=w[x].head;
		dfs(r[x].head);
	}
	if(r[x].left)
	{
		sum+=w[x].left;
		dfs(r[x].left);
	}
	if(r[x].right)
	{
		sum+=w[x].right;
		dfs(r[x].right);
	}
	if(sum>maxn) 
	{
		maxn=sum;
	}
	return;
}
int main() 
{
	freopen("money.in",r,"stdin")
	freopen("money.out",w,"stdout")
	cin>>n>>m;
	for(int i=1;i<=n-1;i++)
	{
		int a,b,l;
		cin>>a>>b>>l;
		if(a>b) swap(a,b);
		if(r[a].head==0)
		{
			r[a].head=b;
			w[a].head=l;
		}
		else if(r[a].left==0)
		{
			r[a].left=b;
			w[a].left=l;
		}
		else if(r[a].right==0)
		{
			r[a].right=b;
			w[a].right=l;
		}
	}
	for(int i=1;i<=n-1;i++)
	{
		if((r[i].left!=0&&r[i].right==0&&r[i].head==0)||(r[i].left==0&&r[i].right!=0&&r[i].head==0)||(r[i].left==0&&r[i].right==0&&r[i].head!=0))
		{
			a[++cnt]=i;
		}
	}
	dfs(a[1]);
	cout<<maxn<<endl;
	return 0;
}
