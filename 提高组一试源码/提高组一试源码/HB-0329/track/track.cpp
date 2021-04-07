#include<cstdio>
#include<algorithm>
#define N 50005
#define For(i,j,n) for(int i=j;i<=n;i++)
using namespace std;
int fa[N][10],num[N],dis[N][10],le[N];
int Ans;

int read(){
	int p=1,q=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')p=-1;c=getchar();}
	while(c>='0'&&c<='9'){q=q*10+c-'0';c=getchar();}
	return p*q;
}

bool cmp(int x,int y){return x>y;}

void dfs(int x,int y,int father){
	if(num[x]==1&&fa[x][1]==father){
		Ans=max(Ans,y);return;
	}
	int ans=y;
	for(int i=1;i<=num[x];i++){
		if(fa[x][i]!=father){
			y=ans;
			y+=dis[x][i];
			dfs(fa[x][i],y,x);
		}
	}
}

int main()
{	
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m,a,b,l;
	n=read();m=read();
	if(m==1){
		For(i,1,n-1){
			a=read();b=read();l=read();
			fa[a][++num[a]]=b;
			dis[a][num[a]]=l;
			fa[b][++num[b]]=a;
			dis[b][num[b]]=l;
			
		}
		For(i,1,n){
			if(num[i]==1){
				dfs(i,0,0);printf("%d",Ans);break;
			}
		}
	}
	else{
		For(i,1,n-1){
			a=read();b=read();le[i]=read();
		}
		sort(le+1,le+n,cmp);
		printf("%d",le[m]); 
	}
	return 0;
}
