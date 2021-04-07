#include<bits/stdc++.h>
using namespace std;

void splay()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}

int i1,i2;char ch;
inline int read()
{
	i1=i2=ch=0;
	while(!isdigit(ch))	i1|=ch=='-',ch=getchar();
	while(isdigit(ch))	i2=(i2<<1)+(i2<<3)+(ch^48),ch=getchar();
	return i1? -i2:i2;
}
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define derep(i,j,k) for(int i=j;i>=k;i--)
#define pic(i,j) for(int i=lin[j];i;i=e[i].nxt)

int n;
struct blocc
{
	int d,l,r;
	bool operator > (const blocc &kkk) const {return this->d>kkk.d;}
	bool operator < (const blocc &kkk) const {return this->d<kkk.d;}
}e[100010];
priority_queue<blocc,vector<blocc>,less<blocc> > q;

int fa[100010];
int chf[100010];

int gf(int k){return k==fa[k]?k:fa[k]=gf(fa[k]);}

void merge(int x,int y)
{
	int fx=gf(x),fy=gf(y);
	if(fx==fy) return;
	e[fy].l=e[fx].l=min(e[fx].l,e[fy].l);
	e[fy].r=e[fx].r=max(e[fy].r,e[fx].r);
	fa[fx]=fy;
}

int main()
{
	splay();
	
	n=read();
	rep(i,1,n) fa[i]=e[i].l=e[i].r=i,
	e[i].d=read(),chf[i]=e[i].d-e[i-1].d,q.push(e[i]);
	chf[n+1]=-e[n].d;
	
	blocc tmp;
	register int del,blo_l,blo_r;
	register long long tot=0;
	while(1)
	{
		tmp=q.top();q.pop();
		if(tmp.d==0) break;
		if(tmp.d^e[gf(tmp.l)].d) continue;
		if(tmp.l==1&&tmp.r==n){tot+=tmp.d;break;}
		
		blo_l=gf(tmp.l-1);blo_r=gf(tmp.r+1);
		del=tmp.d-max(e[blo_l].d,e[blo_r].d);
		
		tot+=1ll*del;
		chf[tmp.l]-=del,chf[tmp.r+1]+=del;
		
		if(!chf[tmp.l]) merge(tmp.l,tmp.l-1);
		if(!chf[tmp.r+1]) merge(tmp.r,tmp.r+1);
		
		q.push(e[gf(tmp.l)]);
	}
	
	printf("%d\n",tot);
	
	return 0;
}
