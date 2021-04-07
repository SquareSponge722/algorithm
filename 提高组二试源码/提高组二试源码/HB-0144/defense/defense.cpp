#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 2000

using namespace std;

int esum=99999999;
int head=1,tail=1;
bool a[N+50][N+50];
int n,m,_type,k,t,x,v,y;
int book[N+50];
int W[N+50]; 

struct wk
{
	int hao;
	int mark;
} w[N+50];

void print()
{
	int i;
	for(i=1;i<=n;i++)
		printf("%d ",book[i]);
	printf("\n");
	return;
}

void bfs()
{
	head=1;
	int fee=0;
	int flag,i,sum,kflag;
	
	while(head<tail)
	{
		if(book[w[head].hao]) 
		{
			head++;
			continue;
		}
		flag=0;sum=0;kflag=1;
		for(i=1;i<=n;i++)
		{
			if(a[i][w[head].hao]==1)
			{
				if(book[i]==1) 
				{
					kflag=0;
					break;
				}
				else if(book[i]!=-1)
				{
					sum++;
					if(!flag) flag=i;
				}
			}
		}
		if(sum==0 && kflag==1) book[w[head].hao]=1;
		else if(sum==1 && kflag==1) book[flag]=1;
	//	print();
		head++;
	}
	
	for(i=1;i<=n;i++)
	{
		if(book[i]==1)
		{
			//printf("%d ",i);
			fee+=W[i]; 
		} 
	}
	
	memset(book,0,sizeof(book));
	printf("%d\n",fee);
	return;
}

int mycmp(const wk &x, const wk &y)
{
	return x.mark>y.mark;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int i,j,k1,k2;
	scanf("%d%d",&n,&m);
	scanf("%c%c%c",&_type,&_type,&k);
	for(i=1;i<=n;i++) 
	{
		scanf("%d",&W[i]);
		w[tail].mark=W[i];
		w[tail].hao=i;
		tail++;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&k1,&k2);
		a[k1][k2]=true;a[k2][k1]=true;
	}
	
	sort(w+1,w+1+n,mycmp);
/*	printf("#diulei=\n");
	for(i=1;i<=n;i++)
	{
		printf("i=%d hao%d feng=%d\n",i,w[i].hao,w[i].mark);
	}*/

	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&t,&x,&v,&y);
		if(x==0 && y==0 && a[t][v]==1) 
		{
			printf("-1");	
		} 
		else
		{
			if(x==1) book[t]=1;
			else book[t]=-1;
			if(y==1) book[v]=1;
			else book[v]=-1;
			bfs();
		} 
	}
	return 0;
}
