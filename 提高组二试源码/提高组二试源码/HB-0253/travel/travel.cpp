#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;
bool g[5001][5001],vis[5001];
int pre[5001],n;
queue<int>step;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while((c<'0')||(c>'9')){if(c=='-') f=-1;c=getchar();}
	while((c>='0')&&(c<='9')){
		x=x*10+(int)(c-'0');
		c=getchar();
	}
	return x*f;
}
priority_queue<int,vector<int>,greater<int> >qq;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,u,v;
//	memset(pre,0x7f,sizeof(pre));
	n=read();m=read();
	for(int i=1;i<=m;i++){
		u=read();v=read();
		g[u][v]=g[v][u]=1;
	}
	qq.push(1);vis[1]=1;
	while(!qq.empty()){
		u=qq.top();qq.pop();
		step.push(u);
		for(int i=1;i<=n;++i){
			if((g[u][i])&&(!(vis[i]))){
				qq.push(i);
				vis[i]=1;
			}
		}
	}
	while(!step.empty()){
		printf("%d ",step.front());
		step.pop();
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
