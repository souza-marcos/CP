#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1);
const double eps = 1e-5;
#define sz(x) (int)x.size()

bool eq(double a, double b){
    return abs(a - b) <= eps;
}

struct Point{
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}

    bool operator<(const Point& other) const {
        if(!eq(x, other.x)) return x < other.x;
        if(!eq(y, other.y)) return y < other.y;
        return false;
    }

    bool operator==(const Point other){
        return (eq(x, other.x) and eq(y, other.y));
    }

    Point operator-(const Point& o) const{
        return Point(x-o.x, y-o.y);
    }

    Point operator+(const Point& o) const{
        return Point(x+o.x, y+o.y);
    }

    Point operator/(double c) const{
        return Point(x/c, y/c);
    }

    Point operator*(double c) const{
        return Point(x*c, y*c);
    }
};

inline int cmp(double x, double y = 0){
    return ((x <=y + eps) ? (x + eps < y)? -1: 0: 1);
}

double dot(Point a, Point b){
    return a.x * b.x + a.y + b.y;
}

double cross(Point a, Point b){
    return a.x*b.y - a.y*b.x;
}

int ccw(Point a, Point b, Point c){
    return cmp(cross(b-a, c-b));
}

vector<Point> convex_hull(vector<Point> v){
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if(sz(v) <= 1) return v;

    vector<Point> l, u;
    for(int i =0; i < sz(v); i ++){
        while(sz(l) > 1 and ccw(l.end()[-2], l.end()[-1], v[i]) > 0){
            l.pop_back();
        }
        l.push_back(v[i]);
    }
    
    for(int i =sz(v)-1; i >= 0; i --){
        while(sz(u) > 1 and ccw(u.end()[-2], u.end()[-1], v[i]) > 0){
            u.pop_back();
        }
        u.push_back(v[i]);
    }
    l.pop_back(), u.pop_back();
    for(Point i: u) l.push_back(i);
    return l;
}

struct Circle{
    Point C; double R;
    Circle(Point C, double R) : C(C), R(R) {}
};

double dist_2(Point a, Point b){
    return dot(a - b, a - b);
}

double dist(Point a, Point b){
    return sqrt(dist_2(a, b));
}

bool is_inside(Circle c, Point p){
    return cmp(dist(c.C, p), c.R) <= 0;
}

Point get_circle_center(Point p, Point q, Point r){
    Point a = p-r, b = q-r;
    Point c = Point(dot(a, p + r)/2.0, dot(b, q + r)/2.0);
    // Maybe check the points are colinear
    return Point(cross(c, Point(a.y, b.y)),
                 cross(Point(a.x, b.x), c)) / cross(a, b);
}

Circle circle_from(Point a, Point b, Point c){
    Point i = get_circle_center(a, b, c);
    return Circle(i,dist(i, c));
}


Circle circle_from(Point a, Point b){
    Point c = (a + b)/2.0;
    return Circle(c, dist(a, b)/2.0);
}

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

Circle minimum_enclosing_circle(vector<Point>& v){
    shuffle(v.begin(), v.end(), rng);
    Circle ans = Circle(Point(0, 0), 0);

    for(int i = 0; i < sz(v); i ++) if(!is_inside(ans, v[i])){
        ans = Circle(v[i], 0);

        for(int j = 0; j < i; j++) if(!is_inside(ans, v[j])){
            ans = circle_from(v[i], v[j]);
            for(int k = 0; k < j; k++) if(!is_inside(ans, v[k])){
                ans = circle_from(v[i], v[j], v[k]);
            }
        }
    }
    return ans;
}

int n, ins = 0;

void solve(){
    vector<Point> v(n);
    for(auto& el: v){
        double x, y; cin >> x >> y;
        el = Point(x, y);
    }

    // v = convex_hull(v);
    auto c = minimum_enclosing_circle(v);
    cout << "Instancia " << ins << endl;
    cout << c.C.x << " " << c.C.y << " " << c.R << endl;
    cout << endl;
    for(auto [x, y] :v) cout << x << " " << y << endl;
}


int main(){ _
    cout << fixed << setprecision(2);
    while(cin >> n and n != 0) ins ++, solve();

    return 0;
} 
