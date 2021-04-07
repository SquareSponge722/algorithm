#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k[100010],s[100010];
int mark[100010],sum;
struct ha{
	int t,v;
};
vector<ha>q[100010];
bool cmp(int x,int y){
	return k[x]>k[y];
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	char xx,xy;
	cin>>n>>m>>xx>>xy;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		s[i]=i;
		sum+=k[i];
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n-1;i++){
		int b,c;
		cin>>b>>c;
		ha r;r.t=c;r.v=0;
		q[b].push_back(r);
		r.t=b;
		q[c].push_back(r);
	}
	while(m--){
		memset(mark,-1,sizeof(mark));
		int a,b,x,y,fl=0;
		cin>>a>>x>>b>>y;
		mark[a]=x;mark[b]=y;
		if(xy=='1') mark[1]=1;
		if(x==0&&y==0)
			for(int i=0;i<q[a].size();i++)
				if(q[a][i].t==b){
					fl=1;
					break;
				}
		if(fl){
			cout<<-1<<endl;
			continue;
		}
		for(int ii=1;ii<=n;ii++){
			int i=s[ii];
			if(mark[i]==-1||mark[i]==0){
				int fl=0;
				for(int j=0;j<q[i].size();j++)
					if(q[i][j].v) fl=1;
				if(fl&&mark[i]==-1) break;
				for(int	j=0;j<q[i].size();j++){
					int t=q[i][j].t;q[i][j].v=1;
					for(int kkk=0;kkk<q[t].size();kkk++)
						if(q[t][kkk].t==j) q[t][kkk].v=1;
					sum-=k[j];
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
