#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>

const long long mod = (1e9)+7;

bool Check(int thisLine, int lastLine, const int &CompareBits){
	lastLine>>=1;
	for(int i=0;i<CompareBits;i++) {
		if((thisLine&1)>(lastLine&1)) return false;
		thisLine>>=1; lastLine>>=1;
	}
	return true;
}

long long D[2][1<<8];

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	int totLine, totList;
	
	scanf("%d%d", &totList, &totLine);	// Line > List !!!
	
	int now = 0, last = 1;
	for(int i=(1<<totList)-1;i>=0;i--) D[now][i] = 1;
	for(int i=1;i<totLine;i++){
		std::swap(now, last);
		memset(D[now],0,sizeof(D[now]));
		for(int S=(1<<totList)-1;S>=0;S--){
			for(int T=(1<<totList)-1;T>=0;T--)
				if(Check(S,T, totList-1)) {
					D[now][S] = (D[now][S] + D[last][T]) % mod;
				}
		}
	}
	
	long long cnt = 0;
	for(int i=(1<<totList)-1;i>=0;i--)
		cnt = (cnt+D[now][i]) % mod;
	printf("%lld\n", cnt);
	
	return 0;
}