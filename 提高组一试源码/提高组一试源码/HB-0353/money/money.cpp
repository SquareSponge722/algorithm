#include <cstdio>
#include <cstdlib>
using namespace std;
const int N=110;
int data[N];
void init(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&data[i]);
}
void bfs(){
	int m;
}
int main (){
	freopen("money.in","r",sdtin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		init();
		work();
	}
	return ;
}
