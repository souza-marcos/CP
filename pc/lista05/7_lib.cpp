#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

// Minimum Enclosing Circle
//
// O(n) com alta probabilidade

const double EPS = 1e-12;
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

bool eq(double a, double b){
    return abs(a - b) <= EPS;
}

struct pt {
	double x, y;
	pt(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
	pt operator + (const pt& p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt& p) const { return pt(x-p.x, y-p.y); }
	pt operator * (double c) const { return pt(x*c, y*c); }
	pt operator / (double c) const { return pt(x/c, y/c); }


    bool operator<(const pt& other) const {
        if(!eq(x, other.x)) return x < other.x;
        if(!eq(y, other.y)) return y < other.y;
        return false;
    }

    bool operator==(const pt other){
        return (eq(x, other.x) and eq(y, other.y));
    }
};

double dot(pt p, pt q) { return p.x*q.x+p.y*q.y; }
double cross(pt p, pt q) { return p.x*q.y-p.y*q.x; }
double dist(pt p, pt q) { return sqrt(dot(p-q, p-q)); }

pt center(pt p, pt q, pt r) {
	pt a = p-r, b = q-r;
	pt c = pt(dot(a, p+r)/2, dot(b, q+r)/2);
	return pt(cross(c, pt(a.y, b.y)), cross(pt(a.x, b.x), c)) / cross(a, b);
}

struct circle {
	pt cen;
	double r;
	circle(pt cen_, double r_) : cen(cen_), r(r_) {}
	circle(pt a, pt b, pt c) {
		cen = center(a, b, c);
		r = dist(cen, a);
	}
	bool inside(pt p) { return dist(p, cen) < r+EPS; }
};

circle minCirc(vector<pt> v) {
	shuffle(v.begin(), v.end(), rng);
	circle ret = circle(pt(0, 0), 0);
	for (int i = 0; i < sz(v); i++) if (!ret.inside(v[i])) {
		ret = circle(v[i], 0);
		for (int j = 0; j < i; j++) if (!ret.inside(v[j])) {
			ret = circle((v[i]+v[j])/2, dist(v[i], v[j])/2);
			for (int k = 0; k < j; k++) if (!ret.inside(v[k]))
				ret = circle(v[i], v[j], v[k]);
		}
	}
	return ret;
}

inline int cmp(double x, double y = 0){
    return ((x <=y + EPS) ? (x + EPS < y)? -1: 0: 1);
}

int ccw(pt a, pt b, pt c){
    return cmp(cross(b-a, c-b));
}

vector<pt> convex_hull(vector<pt> v){
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if(sz(v) <= 1) return v;

    vector<pt> l, u;
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
    for(pt i: u) l.push_back(i);
    return l;
}

int n, ins = 0;

void solve(){
    vector<pt> v(n);
    for(auto& el: v){
        double x, y; cin >> x >> y;
        el = pt(x, y);
    }

    v = convex_hull(v);
    auto c = minCirc(v);
    cout << "Instancia " << ins << endl;
    cout << c.cen.x << " " << c.cen.y << " " << c.r << endl;
    cout << endl;
    // for(auto [x, y] :v) cout << x << " " << y << endl;
}


int main(){ _
    cout << fixed << setprecision(2);
    while(cin >> n and n != 0) ins ++, solve();

    return 0;
} 
