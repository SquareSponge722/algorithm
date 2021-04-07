#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

struct node
{
    int z;
    node *next;
}t[5001],s[5001];

bool cmp(const int a,const int b)
{
	return a>b;
}

void dfs(int fjd)
{
	int right=1,i,dl[5001];
	printf("%d ",fjd);
	node *p;
	p=s[fjd].next;
	while(p!=NULL)
	{
		dl[right]=p->z;
		right++;
		p=p->next;
	}
	sort(dl+1,dl+right);
	for(i=1;i<right;i++)
		dfs(dl[i]);
	return;
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int m,n,i,j,a,b,left=1,right=1,flag2=0;
	scanf("%d%d",&n,&m);
	node *p,*q,*pq;
	int dl[n+1],flag1[n+1];
	for(i=1;i<=n;i++)
    {
        t[i].next=NULL;
        t[i].z=i;
        s[i].next=NULL;
        s[i].z=i;
        flag1[i]=0;
    }
	for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        p=new node;
        q=t[a].next;
        p->z=b;
        t[a].next=p;
        p->next=q;
        p=new node;
        q=t[b].next;
        p->z=a;
        t[b].next=p;
        p->next=q;
    }
    p=t[1].next;
    while(p!=NULL)
    {
        flag1[p->z]=1;
        pq=new node;
        pq->z=p->z;
        pq->next=s[1].next;
        s[1].next=pq;
        p=p->next;
    }
    for(i=n;i>=2;i--)
    {
    	if(flag1[i]==1)	continue;
		p=t[i].next;
    	right=1;
    	flag2=0;
    	while(p!=NULL)
    	{
    		if(flag1[p->z]==1)
    		{
    			pq=new node;
    			pq->z=t[i].z;
    			pq->next=s[p->z].next;
    			s[p->z].next=pq;
    			flag2=1;
    			break;
			}
    		dl[right]=p->z;
    		right++;
    		p=p->next;
		}
		if(flag2==1)	continue;
		sort(dl+1,dl+right,cmp);
		q=s[dl[1]].next;
		flag2=1;
		while(q!=NULL)
		{
			if(q->z==t[i].z)
			{
				flag2++;
				q=s[dl[flag2]].next;
			}
			q=q->next;
		}
		pq=new node;
		pq->z=t[i].z;
		pq->next=s[dl[flag2]].next;
		s[dl[flag2]].next=pq;
	}
    dfs(1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
