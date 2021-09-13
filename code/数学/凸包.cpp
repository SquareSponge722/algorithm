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
#include <ctime>

#define eps 1.0E-8
#define zero(x) (((x) > 0 ? (x) : -(x)) < eps)
using namespace std;

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
	bool operator < (const Point &a) const{
		if(zero(x - a.x)) return y < a.y;
		return x < a.x;
	}
};

const int N = 1e5 + 10;

int n;
Point po[N];
int sta[N];
bool used[N];

int main(){

	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%lf %lf",&po[i].x,&po[i].y);
	sort(po,po + n);
	int pos = 0;
	for(int i = 1;i < n;i++){
		while(pos && Point(po[sta[pos]],po[sta[pos - 1]]).crossProduct(Point(po[i],po[sta[pos - 1]])) <= 0){
			used[sta[pos]] = false;
			pos--;
		}
		used[i] = true;
		sta[++pos] = i;
	}
	int lim = pos;
	for(int i = n - 1;i >= 0;i--){
		if(used[i]) continue;
		while(pos > lim && Point(po[sta[pos]],po[sta[pos - 1]]).crossProduct(Point(po[i],po[sta[pos - 1]])) <= 0){
			used[sta[pos]] = false;
			pos--;
		}
		used[i] = true;
		sta[++pos] = i;
	}
	double ans = 0;
	for(int i = 0;i < pos;i++) ans += po[sta[i]].distance(po[sta[i + 1]]);
	printf("%.2lf\n",ans);

	return 0;
}

//凸包求周长模板

//洛谷 P2742

//2021-9-5