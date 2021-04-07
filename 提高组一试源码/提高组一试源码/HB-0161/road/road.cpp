#include <cstdio>
#include <vector>

const int inf =10005;

using namespace std;

int n;
int a[100005];
long long cont;
struct node 
{
	int idx;
	int v;
};

vector<int> pos;

node minN(int start, int end)
{
	node aa;
	aa.v = 10001;
	for(int i=start;i<=end;i++)
	{
		if(aa.v > a[i])
		{
			pos.clear();
			aa.v = a[i];
			aa.idx = i;
			pos.push_back(i);
		}
		else if(aa.v==a[i])
		{
			pos.push_back(i);
		}
	}
	return aa;
}

void deal(int start, int end, int shed)
{
	if(start > end) return ;
	if(start == end && a[start] == shed) return ;
	node minX = minN(start, end);
	cont += (minX.v - shed);
	vector<int> poss = pos;
	deal(start,minX.idx-1,minX.v);
	//for(int i=0;i<=poss.size()-1;i++) printf("%d ",poss[i]);
	//	printf("ed\n");
	for(int i=0;i<poss.size()-1;i++)
	{
		//printf("test start:%d end:%d int i:%d::\n",start,end,i+1);
		deal(poss[i]+1,poss[i+1]-1,minX.v);
	}
	deal(poss[poss.size()-1]+1,end,minX.v);
	//printf("%d %d shed:%d add:%d minX.v:%d\n", start, end, shed,minX.v - shed, minX.v);
	return ;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	int stS=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]+=1;
	}
	deal(1,n,0);
	
	printf("%lld\n",cont-1);
	return 0;
}
