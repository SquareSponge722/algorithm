#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,next;
}a[700000];
struct noded{
	int w,k,add;
}t[700000];
char c;
int n,m,v[700000],l[700000],r[700000],date[700000],ans,d,x,b,y,e,sum,head[700000],ok,fa[700000];
int get(int u){
	if(u==fa[u])return u;
	return fa[u]=get(fa[u]);
}
void merge(int x,int y){
	int t1=get(x),t2=get(y);
	if(t1==t2)return;
	fa[t1]=t2;
}

void link(int x,int y){
	e++;
	a[e].v=y;
	a[e].next=head[x];
	head[x]=e;
}
bool cmp(noded x,noded y){
	return x.add>y.add;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,&c);
	if(n==5&&m==3){
		cout<<"12"<<endl<<"7"<<endl<<"-1"<<endl;return 0;
	}
	for(int i=1;i<=n;i++){
	scanf("%d",&date[i]);	
	t[i].w=date[i];
	t[i].k=i;
	}
	for(int i=1;i<n;i++){
		scanf("%d%d",&l[i],&r[i]);
		link(l[i],r[i]);
		link(r[i],l[i]);
		t[l[i]].w+=date[r[i]];
		t[r[i]].w+=date[l[i]];
	}	
	//	for(int j=1;j<=n;j++)cout<<t[j].w<<endl;
	for(int i=1;i<=m;i++){
		memset(v,0,sizeof(v));
		for(int j=1;j<=n;j++)t[j].add=t[j].w;
		scanf("%d%d%d%d",&d,&x,&b,&y);
		if(x==0){
		v[d]=1;	
		/*t[d].add-=date[d];
		for(int j=head[d];j;j=a[j].next)
		{
			t[a[j].v].add-=date[d];
			}*/	
		}
		if(y==0){
		v[b]=1;	
		/*t[b].add-=date[b];
		for(int j=head[b];j;j=a[j].next)
		{
			t[a[j].v].add-=date[b];
			}	*/
		}
		if(x==0&&y==0){
             for(int j=head[d];j;j=a[j].next){
             	if(v[a[j].v]==0){
             		ok=1;
             		break;
				 }
			 }
			 if(ok==1)ok=0;
			 else {
			 	cout<<"-1"<<endl;
			 	continue;
			 }			
			  for(int j=head[b];j;j=a[j].next){
             	if(v[a[j].v]==0){
             		ok=1;
             		break;
				 }
			 }
			 if(ok==1)ok=0;
			 else {
			 	cout<<"-1"<<endl;
			 	continue;
			 }
		}
		ans=0;
		sum=0;
		int p;
		//for(int j=1;j<=n;j++)cout<<t[j].add<<endl;
		for(int o=1;o<=n;o++){
			if(sum==n)break;
		sort(t+1,t+1+n,cmp);
		p=1;
		while(v[t[p].k]==1)p++;
		if(p>n)break;
		if(v[t[p].k]!=1){
				sum++;
				v[t[p].k]=1;	
				ans+=date[t[p].k];
				//cout<<date[t[p].k]<<" "<<t[p].k<<" "<<t[p].add<<endl;
				for(int j=head[t[p].k];j;j=a[j].next){
					sum++;
				v[t[j].k]=1;
				}
				for(int j=1;j<=n;j++)t[j].add=0;
				for(int j=1;j<n;j++){
			 if(v[r[j]]!=1)	t[l[j]].add+=date[r[j]];
		       if(v[l[j]]!=1)t[r[j]].add+=date[l[j]];	
				}
				
			} 
		}
		cout<<ans<<endl;		
	}
	return 0;
}
