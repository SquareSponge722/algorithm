#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
ifstream fin;ofstream fout;
const int _=50000+7;
struct Edge{int to,next,w;}e[_+_];
struct Queue{int len,now;}q[_+_];
int n,m,head[_],a[_],b[_],l[_],dist[_],total;
bool vis[_];
inline void add(int u,int v,int ww)
{
	e[++total].to=v;
	e[total].w=ww;
	e[total].next=head[u];
	head[u]=total;
}
void BFS()
{
	int start=0,tail=1,pointer,maxlen=0;
	q[1].now=1;vis[1]=true;
	while(start<tail)
	{
		start++;
		if(q[start].len>maxlen)
		{
			maxlen=q[start].len;
			pointer=q[start].now;
		}
		for(int i=head[q[start].now];i;i=e[i].next)
			if(!vis[e[i].to])
			{
				q[++tail].now=e[i].to;
				q[tail].len=q[start].len+e[i].w;
				vis[e[i].to]=true;
			}
	}
	memset(vis,0,sizeof(vis));
	start=0;tail=1;maxlen=0;
	q[1].now=pointer;vis[pointer]=true;
	while(start<tail)
	{
		start++;
		if(q[start].len>maxlen)
		{
			maxlen=q[start].len;
		}
		for(int i=head[q[start].now];i;i=e[i].next)
			if(!vis[e[i].to])
			{
				q[++tail].now=e[i].to;
				q[tail].len=q[start].len+e[i].w;
				vis[e[i].to]=true;
			}
	}
	fout<<maxlen;
}
bool ytd(int tt)
{
	int noww=0,ato=0;
	for(register int i=1;i<n;i++)
	{
		if(noww+dist[i]<tt)
			noww+=dist[i];
		else
		{
			noww=0;
			ato++;
		}
	}
	return ato>=m;
}
int main()
{
	fin.open("track.in");
	fout.open("track.out");
	fin>>n>>m;bool flag=1;
	for(register int i=1;i<n;i++)
	{
		fin>>a[i]>>b[i]>>l[i];
		add(a[i],b[i],l[i]);add(b[i],a[i],l[i]);
		if(b[i]!=a[i]+1)
			flag=0;
	}
	if(m==1)
	{
		BFS();
		return 0;
	}
	if(flag)
	{
		int sum=0;
		for(int i=1;i<n;i++)
			dist[a[i]]=l[i],sum+=l[i];
		int small=0,big=sum+1,mid;
		while(small<big)
		{
			mid=(small+big+1)/2;
			if(ytd(mid))
				small=mid;
			else
				big=mid-1;
		}
		fout<<small;
		return 0;
	}
	fin.close();
	fout.close();
	return 0;
}
/*
8 5
2 3 3
4 5 6
1 2 4
7 8 2
3 4 5
6 7 7
5 6 8
*/
