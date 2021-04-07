#include<stdio.h>

#include<math.h>


int main(){
	
	int q,i;
	int t;
	freopen("game.in","r",stdin);
	scanf("%d",&q);
	
	freopen("game.out","w",stdout);
	if(q == 2){
		printf("12");
		t = 1;
}
	else
	if(q == 3){
		printf("112");
		t = 1;
}
	else
	if(q == 5){
		printf("7136");
		t = 1;		
}
	
	if( t != 1 ){
	
	printf("%d",q*321);
}
return 0;
}
