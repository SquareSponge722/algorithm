#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <iostream>

using namespace std;
#define eps 1.0E-8
#define zero(x) (((x) > 0 ? (x) : -(x)) < eps)

const int INF = 0x3f3f3f3f;
const int N = 100;
const int M = 4e4 + 10;

struct Point{ //点 向量
    double x,y;
    
    Point() {}
    Point(double x,double y) : x(x),y(y) {} //构造坐标点
    Point(const Point &a,const Point &b){ //构造向量
        x = b.x - a.x;
        y = b.y - a.y;
    }

    double distance(const Point &ot){ //两点间距离
        return Point(*this,ot).module();
    }
    bool inLine(const Point &p1,const Point &p2){ //三点共线
        return zero(Point(*this,p1).crossProduct(Point(*this,p2)));
    }

    double module(){ //向量模
        return sqrt(x * x + y * y);
    }
    double crossProduct(const Point &ot){ //叉乘 左旋
        return x * ot.y - ot.x * y;
    }
    double dotProduct(const Point &ot){ //点乘
        return x * ot.x + y * ot.y;
    }

    Point operator - (const Point &a){
        return Point(x - a.x,y - a.y);
    }
    Point operator -= (const Point &a){
        return *this = *this - a;
    }
    Point operator + (const Point &a){
        return Point(x + a.x,y + a.y);
    }
    Point operator += (const Point &a){
        return *this = *this + a;
    }
    Point operator * (const double a){
        return Point(x * a,y * a);
    }
    Point operator *= (const double a){
        return *this = *this * a;
    }
    bool operator == (const Point &a) const{
        return zero(x - a.x) && zero(y - a.y);
    }
}per[N];

struct edge{
	int next,to,cap,val;
	edge(){}
	edge(int next,int to,int cap,int val) :
		next(next),to(to),cap(cap),val(val) {}
}ed[M];
int tot = 1;
int head[N],pre[N],flow[N];

int dis[N];
bool vis[N];
int s,t;

int k,n;
map <string,int> mapId;
int rel[N][N];

bool spfa();
int ek();

inline void addEdge(int u,int v,int cap,int val){
	ed[++tot] = edge(head[u],v,cap,val);
	head[u] = tot;

	ed[++tot] = edge(head[v],u,0,-val);
	head[v] = tot;
}
inline void toLowerStr(string &str){
	for(int i = 0;i < str.length();i++){
		str[i] = tolower(str[i]);
	}
}
int main(){
	cin >> k >> n;
	t = (n << 1) + 1;
	int x,y;
	string str,str1;
	for(int i = 1;i <= (n << 1);i++){
		cin >> x >> y >> str;
		toLowerStr(str);
		per[i] = Point(x,y);
		mapId[str] = i;
	}
	while(true){
		cin >> str;
		toLowerStr(str);
		if(str == "end") break;
		cin >> str1 >> x;
		toLowerStr(str1);
		int k1 = mapId[str],k2 = mapId[str1];
		if(k1 > k2) swap(k1,k2);
		rel[k1][k2] = x;
	}
	for(int i = 1;i <= n;i++){
		addEdge(s,i,1,0);
		addEdge(i + n,t,1,0);
		for(int j = n + 1;j <= (n << 1);j++){
			bool isOk = per[i].distance(per[j]) <= k;
			for(int k = 1;k <= (n << 1);k++){
				if(!isOk) break;
				if(k == i || k == j) continue;
				if(zero(per[k].distance(per[i]) + per[k].distance(per[j]) - per[i].distance(per[j]))) isOk = false;
			}
			if(!isOk) continue;
			addEdge(i,j,1,rel[i][j] ? rel[i][j] : 1);
		}
	}

	int ans = 0;
	while(spfa()){
		ans += ek();
	}

	cout << ans << endl;

	return 0;
}
bool spfa(){
	memset(dis,-0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	queue <int> q;
	flow[t] = dis[s] = 0;
	flow[s] = INF;
	q.push(s);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		vis[cur] = false;
		for(int i = head[cur];i;i = ed[i].next){
			if(ed[i].cap && dis[ed[i].to] < dis[cur] + ed[i].val){
				dis[ed[i].to] = dis[cur] + ed[i].val;
				flow[ed[i].to] = min(flow[cur],ed[i].cap);
				pre[ed[i].to] = i;
				if(!vis[ed[i].to]) q.push(ed[i].to);
				vis[ed[i].to] = true;
			}
		}
	}
	return flow[t];
}
int ek(){
	int sum = 0;
	for(int u = t;u != s;u = ed[pre[u] ^ 1].to){
		ed[pre[u]].cap -= flow[t];
		ed[pre[u] ^ 1].cap += flow[t];
		sum += flow[t] * ed[pre[u]].val;
	}
	return sum;
}

//最大流最大费用
//以贪心的策略优先找最长的增广路
//这傻逼题男女缘分会重复，但以最后一次出现为准

//洛谷-P1500
//2021-7-14