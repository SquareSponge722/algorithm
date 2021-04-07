#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 5010
struct edge{
	int from;
	int next;
	int to;
} e[N<<1];
int head[N];
bool flag[N];
int indegree[N];
int son[N][5];
int path[N]={0,1},tot;
int n,m,cnt;

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') { if(ch=='-')f=-1;ch=getchar(); }
	while(ch>='0' && ch<='9') { x=(x<<1)+(x<<3)+ch-'0';ch=getchar(); }
	return f*x;
}
void add(int a,int b){
	e[++cnt].to=b;
	e[cnt].next=head[a];
	e[cnt].from=a;
	head[a]=cnt;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	int a,b;
	if(m==n-1){
		for(int i=0;i<=n;i++)
			for(int j=0;j<=5;j++)
				son[i][j]=5010;
		for(int i=1;i<=m;i++){
			a=read();b=read();
			add(a,b);add(b,a);
			for(int i=1;i<=n;i++) 
				if(son[a][i]==5010) { son[a][i]=b;break; }
			for(int i=1;i<=n;i++) 
				if(son[b][i]==5010) { son[b][i]=a;break; }
		}
		for(int i=1;i<=n;i++)
			sort(son[i]+1,son[i]+6);
			
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=5;j++)
				cout<<son[i][j]<<" ";
			cout<<endl;
			}*/
		
		int root;
		for(int i=1;i<=n;i++) 
			if(indegree[i]<=2){ root=i;break; }
		
		//cout<<root<<endl;
		
		path[++tot]=root;flag[root]=1;
		int j=root;
		while(tot<n){
			int k;
			for(k=1;k<=5;k++){
				if(!flag[son[j][k]] && son[j][k]!=5010){
					flag[son[j][k]]=1;//path[++tot]=son[j][k];
					//cout<<flag[4]<<endl;
					//cout<<j<<" "<<k<<" "<<son[j][k]<<endl;
					break;
				} 				
			}
			if(son[j][k]<5010) j=son[j][k],path[++tot]=j;
			else{
				int r,i;
				for(i=1;i<=n;i++)
					for(r=1;r<=5;r++){
						if(!flag[son[i][r]] && son[i][r]!=5010){
							flag[son[i][r]]=1;
							break;
						}
					}
				j=son[i][r];path[++tot]=j;
			} 
		}
		for(int i=1;i<=tot;i++) cout<<path[i]<<" ";
	}
	return 0;
}
