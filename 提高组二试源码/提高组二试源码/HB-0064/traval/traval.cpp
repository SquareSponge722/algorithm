#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int SIZE = 1000000;
const int INF = 0x7fffffff;
int front[SIZE], to[SIZE], next[SIZE], vis[SIZE], inq[SIZE];
int stk[2 * SIZE];
int SP;
int vexnum, en = -1;


void make(int a){
    vexnum = a;
    memset(next, -1, sizeof(next));
    memset(vis, 0, sizeof(vis));
    memset(front, -1, sizeof(front));
    memset(stk, 0, sizeof(stk));
    return;
}
void add(int a, int b){
    en++, to[en] = b, next[en] = front[a], front[a] = en;
    return;
}

bool ifb(int a, int b){//if a > b!
    if(vis[a] == vis[b]){
	if(a < b)return true;
	else return false;
    }else if(vis[a] < vis[b]) return true;
    else return false;
}

int best(int a){
    int mn = a;//INF
    for(int i = front[a]; i >= 0; i = next[i]){
	printf("Search:%d",to[i]);
	if(ifb(to[i], mn))mn = to[i];
	//printf("i:%d\n",i);
    }
    printf("best:%d\n", mn);
    return mn;
}

bool cmp(int a, int b){
    return a > b;
}

struct node{
    int a;
    bool operator<(const node& t) const{
	return a > t.a;
    }
};
void show(){
    //printf("stk:\n");
    //for(int i = 0; i < SP || i < vexnum; i++)printf("%d ", stk[i]);
    printf("\nvis:\n");
    for(int i = 0; i < vexnum; i++)printf("%d\t", i); printf("\n");
    for(int i = 0; i < vexnum; i++)printf("%d\t", vis[i]);printf("\n");
}

int main(){
    freopen("traval.in", "r", stdin);
    freopen("traval.out", "w", stdout);
    int M, N;
    int zxd = INF;
    scanf("%d%d", &N, &M);
    make(N);
    for(int i = 0; i < M; i++){
	int a, b;
	scanf("%d%d", &a, &b);
	add(a, b);
	add(b, a);
	if(a < zxd) zxd = a;
	if(b < zxd) zxd = b;
	
    }
    priority_queue<node> q;
    q.push((node){zxd});
    inq[zxd] = 1;
    while(!q.empty()){
	int t = q.top().a;
	stk[SP++] = t;
	q.pop();
	for(int i = front[t]; i >= 0; i = next[i]){
	    //printf("s:%d\n",to[i]);
	    if(!inq[to[i]]){
		q.push((node){to[i]});
		inq[to[i]] = 1;
	    }
	}
    }

    for(int i = 0; i < SP; i++){
	printf("%d ", stk[i]);
    }

    return 0;
}

/*int main(){
    vis[1] = 2;
    vis[2] = 3;
    vis[3] = 3;
    printf("%d\n", ifb(1,2));//1
    printf("%d", ifb(2,3));//1
    return 0;
}*/
