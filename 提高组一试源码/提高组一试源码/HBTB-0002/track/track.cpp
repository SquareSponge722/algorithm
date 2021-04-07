#include<bits/stdc++.h>
using namespace std;
struct node
{
	int end,weight;
	node(int a,int b)
	{
		end=a;
		weight=b;
	}
};
vector <node> v[100001];
queue <int> q;
int n,m,a,b,l,op,s;
int lo[100001],e[100001],dist[100001],pd[100001];
int lmax,lmax_a,lmax_b,ans_p;
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&l);
		v[a].push_back(node(b,l));
		v[b].push_back(node(a,l));
		if(l>lmax)
		{
			lmax=l;
			lmax_a=a;
			lmax_b=b;
		}
		op+=l;
		if(i==0)
		{
			s=a;
		}
	}
	pd[s]=1;
	dist[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int fa=q.front();
		q.pop();
		for(int i=0;i<v[fa].size();i++)
		{
			int ww=v[fa][i].weight;
			int son=v[fa][i].end;
		}
	}
	if(m==1)
	{
		cout<<op;
	}
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			cout<<i<<" "<<v[i][j].end<<" "<<v[i][j].weight<<endl;
		}
	}
	*/
	
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(v[i][j].weight>v[i][k].weight+v[k][j].weight)
				v[i][j].weight=v[i][k].weight+v[k][j].weight;
			}
		}
	}
	*/
	
}
