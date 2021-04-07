#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;
int const N=5001;
struct nd{
	bool usn;
	int las;
	queue <int> nt;
}d[N];
int m,n,mi,mi_wz,wzs;
void inn()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		d[x].nt.push(y); 
		d[y].nt.push(x);
	}
}
int t,f;
queue <int> q;
bool dfs1(int wz,int la)
{
	if(wz>n)
		return false;
	else
	{
		if(!d[wz].usn)
		{
			q.push(wz);
			d[wz].usn=true;
			d[wz].las=la;
			wzs++;
			if(wzs==n)
				return true;
		}
		else
		{
			if(d[wz].las!=la&&wz!=la)
				return false;
		}
		mi=-1;
		bool fi=true;
		while(!d[wz].nt.empty())
		{
			if(mi==-1)
			{
				mi=d[wz].nt.front();
				d[wz].nt.pop();
			}
			else
			{
				if(d[wz].nt.front()<mi)
				{
					d[wz].nt.push(mi);
					mi=d[wz].nt.front();
					d[wz].nt.pop();
				}
				else
				{
					if(fi)
					{
						fi=false;
						f=d[wz].nt.front();
					}
					else
					{
						if(d[wz].nt.front()==f)
							break;
					}
					t=d[wz].nt.front();
					d[wz].nt.pop();
					d[wz].nt.push(t);
				}
			}
		}
		if(mi==-1)
			return false;
		if(dfs1(mi,wz))
			return true;
		if(dfs1(wz,wz))
			return true;
		return false;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	inn();
	dfs1(1,1);
	while(!q.empty())
	{
		printf("%d ",q.front());
		q.pop();
	}
	return 0;
}
