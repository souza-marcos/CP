// https://cses.fi/problemset/task/2189
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

struct pt{
    ll x, y;

    pt(): x(0), y(0){}
    pt(ll x, ll y) : x(x), y(y) {}

    pt operator-(const pt& other){
        pt res(x-other.x, y-other.y);
        return res;
    }

};

pt l1, l2, pt3;

ll cross(pt a, pt b){
    return a.x*b.y - a.y*b.x;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        cin >> l1.x >> l1.y >> l2.x >> l2.y >> pt3.x >> pt3.y;
        ll val = cross(l2 - l1, pt3 - l1);
        cout << (val == 0? "TOUCH": val > 0? "LEFT" : "RIGHT" ) << endl;
    }
    return 0;
} 
