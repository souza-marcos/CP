#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

const double EPS = 1e-12;

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
double dist(pt p, pt q) { return sqrt(dot(p-q, p-q)); }


int main(){ _
    int n; cin >> n;
    cout << fixed << setprecision(9);
    double total_cost = 0;
    pt last{0,0};    
    for(int i = 0; i < n; i ++){
        pt cur;
        cin >> cur.x >> cur.y;
        total_cost += dist(last, cur);
        last = cur;
    }
    total_cost += dist(last, {0,0});
    cout << total_cost << endl;
    return 0;
} 
