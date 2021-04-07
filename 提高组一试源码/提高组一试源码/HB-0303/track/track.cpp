#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<string>
#include<climits>
#include<algorithm>

const int MAXN = 50000+500;

struct Road{int to,len; Road& operator () (const int &a,const int &b){to = a;len = b;return *this;}};
std::vector<Road> G[MAXN];
int cnt[MAXN], len[MAXN]; bool vis[MAXN];
void dfs(const int &nowAt,const int &minLen){
	vis[nowAt] = true;
	
	std::vector<int> arr; std::vector<bool> book;
	for(int i=0;i<G[nowAt].size();i++){
		Road& it = G[nowAt][i];
		if(!vis[it.to]){
			dfs(it.to, minLen); 
			len[it.to] += it.len; cnt[nowAt] += cnt[it.to];
			if(len[it.to] >= minLen) ++cnt[nowAt];
			else arr.push_back(len[it.to]);
		}
	} book.resize(arr.size());
	
	std::sort(arr.begin(),arr.end());
	int cur = 1;
	for(int i = 0;i<arr.size();i++){
		if(book[i]) continue;
		for(int j=i+1;j<arr.size();j++){
			if(book[j] || arr[i]+arr[j] < minLen)continue;
			book[j] = true; book[i] = true;
			++cnt[nowAt]; break;
		}
	}
	
	int max = 0;
	for(int i=0;i<arr.size();i++)
		if(!book[i] && arr[i] > max) max = arr[i];
	len[nowAt] = max;
}

bool Solve(const int &minLen, const int &totRoad) {
	memset(vis,false,sizeof(vis)); memset(cnt,0,sizeof(cnt)); memset(len,0,sizeof(len));
	dfs(0, minLen); 
	return (*cnt) >= totRoad;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	int totNodes,f,t,len,fr = 0,to = 0,mid, totRoad;
	
	Road temp;
	scanf("%d%d",&totNodes,&totRoad);
	for(int i=1;i<totNodes;i++){
		scanf("%d%d%d",&f,&t,&len);
		G[--f].push_back(temp(--t,len)); G[t].push_back(temp(f,len));
		to+=len;
	}
	
	for(++to;fr<to;){
		mid = ((fr+to)>>1) + 1;
		if(Solve(mid, totRoad)) fr = mid;
		else to = mid-1;
	}
	
	printf("%d\n",fr);
	return 0;
}