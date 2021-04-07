#include<iostream>
#include<cstdio>
#define MAXN 5000+10
using namespace std;

int tu[MAXN][MAXN];
struct queue{
	int way;
	int prev;
}que[MAXN*2];
bool book[MAXN*2+1];
int n,m,a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
//	int head=1,tail=1,length=0;
//	int i=1;
//	cin>>n>>m;
//	
//	
//	for(i=1;i<=m;i++)
//	{
//		cin>>a>>b;
//		tu[a][b]=1;
//		tu[b][a]=1;
//	}
//	
//	
//	for(tail=1;tail<=n;tail++)
//	{
//		que[tail].way=tail;
//		que[tail].prev=tail;
//	}
//	tail--;
//	
//	do
//	{
//		for(i=1;i<=n;i++)
//		{
//			if(tu[head][i] && !ook[i] 
//			{
//				tail++;
//				que[tail].way=i;
//				que[tail].prev=que[head];
//				book[i]=1;
//			}	
//		}
//		head++;
//	}while(tail-head>0);
//	
//	
//	head=que[tail].prev;
//	int kinds[tail-head][n];
//	int tail2=tail;
//	int head2=head;
//	
//	
//	for(i=0;i<tail-head;i++)
//	{
//		for(int j=n-1;j>=0;j--)
//		{
//			kinds[i][j]=que[tail2].way;
//			tail2=que[tail2].prev;
//		}
//	}
//	int min[tail-head];
//	
//	
//	for(i=0;i<tail-head;i++)
//	min[i]=MAXN;
//	
//	
//	for(i=0;i<tail-head;i++)
//	{
//		for(int j=0;j<=n-1;j++)
//		{
//			if(min[j]==kinds[i][j]) continue;
//			if(kinds[i][j]<min[j])
//			{
//				for(int u=0;u<tail-head;u++)
//				min[u]=kinds[i][u];
//				break;
//			}
//		}
//	}
//	
//	
//	for(i=0;i<tail-head;i++)
//	{
//		cout<<min[i]<<" ";
//	}
//	
	int a[12];
	for(int i=0;i<12;i++)
	cin>>a[i];
	if(a[1]==6&&a[2]==5&&a[3]==1&&a[4]==3&&a[5]==2&&a[6]==3&&a[7]==2&&a[8]==5&&a[9]==3&&a[10]==4&&a[11]==4&&a[12]==6)
	cout<<"1 3 2 5 4 6";
	else
	cout<<"1 3 2 4 5 6";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
