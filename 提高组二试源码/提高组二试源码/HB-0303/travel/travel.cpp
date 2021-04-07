#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<climits>

const int MAXN = 5500;
std::vector<int> G[MAXN];
std::vector<int> arr;

bool vis[MAXN];
void Solve(const int &nowAt) {
	arr.push_back(nowAt+1); vis[nowAt] = true;
	std::vector<int> que;
	for(int i=0;i<G[nowAt].size();i++)
		if(!vis[G[nowAt][i]]) que.push_back(G[nowAt][i]);
	std::sort(que.begin(), que.end());
	for(int i=0;i<que.size();i++) if(!vis[que[i]]) Solve(que[i]);
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	memset(vis,false,sizeof(vis));
	int totCity, totRoad, fr ,to;
	
	scanf("%d%d", &totCity, &totRoad);
	for(int i=0;i<totRoad;i++){
		scanf("%d%d", &fr, &to);
		G[--fr].push_back(--to); G[to].push_back(fr);
	}
	
	Solve(0);
	for(int i=0;i<arr.size();i++)
		printf("%d ", arr[i]);
	printf("\n");
	
	return 0;
}