#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()
const long double eps = 1e-9;

struct Point{
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator- (Point other){
        return Point(x - other.x, y - other.y);
    }

    bool operator< (const Point other) const {
        if(x != other.x) return x < other.x;
        if(y != other.y) return y < other.y;
        return false;
    } 

    bool operator== (const Point other) const{
        return (x == other.x and y == other.y);
    }

}; 

inline int cmp(double x, double y=0){
    return ((x <= y + eps) ? (x + eps < y)? -1: 0: 1);
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
    
    // Pontos de baixo
    for(int i = 0; i < sz(v); i ++){
        while(sz(l) > 1 and ccw(l.end()[-2], l.end()[-1], v[i]) > 0)
            l.pop_back();
        
        l.push_back(v[i]);
    }

    // Pontos de cima
    for(int i = sz(v)-1; i >= 0; i --){
        while(sz(u) > 1 and ccw(u.end()[-2], u.end()[-1], v[i]) > 0)
            u.pop_back();
        
        u.push_back(v[i]);
    }
    l.pop_back(), u.pop_back();
    for(Point i: u) l.push_back(i);
    return l;
}


int n;
void solve(){

    set<Point> v;
    for(int i= 0; i < n; i ++){
        int x, y; cin >> x >> y;
        v.insert(Point(x, y));
    }

    int cnt = 0;
    while(sz(v)){
        vector<Point> q;
        for(auto p: v) q.push_back(p);
        auto res = convex_hull(q);
        for(Point el: res) v.erase(el); //, cout << "(" << el.x << " - " << el.y << "), ";
        // cout << endl;
        cnt++;
    }

    if(cnt & 1) cout << "Take this onion to the lab!\n";
    else cout << "Do not take this onion to the lab!\n";
}

int main(){ _
    while(cin >> n and n != 0) solve();
    return 0;
} 
