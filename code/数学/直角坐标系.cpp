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
};
struct Line{
    Point a, b; //a点为靠近原点的点
    Point direction; //方向向量

    Line() {}
    Line(Point a, Point b) : a(a), b(b) {
        direction = Point(a,b);
    }

    Point calcDirection(){ //计算方向向量
        return direction = Point(a,b);
    }
    bool parallel(const Line &ot){ //判断直线是否平行
        return zero(direction.crossProduct(ot.direction));
    }
    bool pointInLeft(const Point &p){ //判断点是否在直线左侧
        Point vec = Point(a,p);
        return direction.crossProduct(vec) > 0;
    }
    bool pointInLine(Point &p){ //判断点是否在直线上
        return p.inLine(a,b);
    }
    Point intersectionBeeline(const Line &ot){ //求两直线的交点，斜率相同的话res=a
        Point res = a;
        Point vec = direction;
        double t = Point(ot.a,a).crossProduct(Point(ot.a,ot.b)) / Point(b,a).crossProduct(Point(ot.a,ot.b));
        vec *= t;
        res += vec;
        return res;
    }
};

int double_cmp(double a){ //判断double正负
    if (zero(a)) return 0;
    return a > 0 ? 1 : -1;
}

bool point_incircle(Point o, double r, Point p, bool edgeTrue = true){ //点p在圆内或圆上(edgeTrue = true)
    double d2 = p.distance(o);
    double r2 = r;
    if(edgeTrue) return d2 < r2 || zero(d2 - r2);
    else return d2 < r2;
}

bool circumcentre(Point p1, Point p2, Point p3, Point &o, double &r){ //求三角形外心
    if (p1.inLine(p2,p3)) return false;

    Point v12 = Point(p1,p2);
    Point v13 = Point(p1,p3); 
    Point vert_v12 = Point(-v12.y,v12.x);
    Point vert_v13 = Point(-v13.y,v13.x);

    Point t = Point((p1.x + p2.x) / 2,(p1.y + p2.y) / 2);
    Line u = Line(t,t + vert_v12);

    t = Point((p1.x + p3.x) / 2,(p1.y + p3.y) / 2);
    Line v = Line(t,t + vert_v13);

    o = u.intersectionBeeline(v);
    r = o.distance(p1);
    return true;
}

int t;
Point p[4],o;

int main()
{
    scanf("%d",&t);
    for(int cas = 1;cas <= t;cas++){
        bool needCircuCalc = true;
        double dis = 0;
        for(int i = 0;i < 4;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
        
        for(int i = 0;i < 3;i++){
            Point v1 = Point(p[i],p[(i + 1) % 3]);
            Point v2 = Point(p[i],p[(i + 2) % 3]);
            if(double_cmp(v1.dotProduct(v2)) <= 0){ //钝角三角形最小圆心在钝角对应的边上
                o.x = (p[(i + 1) % 3].x + p[(i + 2) % 3].x) / 2;
                o.y = (p[(i + 1) % 3].y + p[(i + 2) % 3].y) / 2;
                dis = o.distance(p[(i + 1) % 3]);
                needCircuCalc = false;
            }
        }
        if(needCircuCalc) circumcentre(p[0],p[1],p[2],o,dis);
        
        if(point_incircle(o,dis,p[3])) printf("Case #%d: Danger\n",cas);
        else printf("Case #%d: Safe\n",cas);
    }
    return 0;
}

//Naive and Silly Muggles
//2021-5-15