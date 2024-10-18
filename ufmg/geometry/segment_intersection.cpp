#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

struct pt {
    ll x, y;
    pt(): x(0), y(0) {}
    pt(ll x, ll y): x(x), y(y) {}

    pt operator-(const pt& other){
        return pt(x-other.x, y-other.y);
    }
};

ll cross(pt a, pt b){
    return a.x*b.y - a.y*b.x;
}

int ccw(pt a, pt b){
    ll val = cross(a, b);
    return (val==0?0:val/abs(val));
}

int sgn(ll val){
    return (val > 0?1:val?-1:0);
}

bool intersect_segment(pt a1, pt a2, pt b1, pt b2){
    ll val1 = cross(a2-a1, b2-a1);
    ll val2 = cross(a2-a1, b1-a1);

    auto inter_axis = [](pt p1, pt p2){
        if(p1.x > p1.y) swap(p1.x, p1.y);
        if(p2.x > p2.y) swap(p2.x, p2.y);

        return max(p1.x, p2.x) <= min(p1.y, p2.y);
    };

    if(!val1 and !val2){ // Colinear
        return inter_axis({a1.x, a2.x}, {b1.x, b2.x}) 
            and inter_axis({a1.y, a2.y}, {b1.y, b2.y});
    } 

    pt v1 = a2-a1, v2 = b2-b1; // vectors
    ll d1 = cross(v1, b1-a1);
    ll d2 = cross(v1, b2-a1);

    ll d3 = cross(v2, a1-b1);
    ll d4 = cross(v2, a2-b1);

    if(sgn(d1) != sgn(d2) and sgn(d3) != sgn(d4)) return true;
    return false;
}

pt a, b, c, d;

int main(){ _
    int t; cin >> t;
    while(t --){
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        cout << (intersect_segment(a,b,c,d)?"YES":"NO")<< endl;
    }

    return 0;
} 
