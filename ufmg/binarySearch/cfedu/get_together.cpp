#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int n; vector<pair<ll, ll>> v;
const double eps = 1e-8;

bool valid(double t){
    double minv = -INF, maxv = INF;
    for(auto [xi, vi] : v){
        minv = max(minv, xi - t * vi);
        maxv = min(maxv, xi + t * vi);
        if(minv >= maxv) return false;
    }
    return true;
}

int main(){ _
    cout << fixed << setprecision(10);
    cin >> n;
    v.resize(n);
    for(auto& [xi, vi]: v) cin >> xi >> vi;

    double l = 0, r = 1.0;
    while(!valid(r)) r *= 2;

    for(int i = 0; i< 100; i ++){
        double m = (l + r)/2.0;
        if(valid(m)) r = m;
        else l = m;
    }
    cout << (l + r)/2.0 << endl;
    return 0;
} 
