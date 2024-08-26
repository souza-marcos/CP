#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

struct Point{
    ll x, y;
    Point(ll x = 0, ll y = 0) : x(x), y(y){}
};

ll dist_2(Point a, Point b){
    return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}

int n;

void solve(){
    vector<Point> v(n);
    for(auto& el: v){
        int x, y; cin >> x >> y;
        el = Point(x, y);
    }

    map<ll, ll> dist;
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        dist.clear();
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            dist[dist_2(v[i], v[j])] ++;
        }
        for(auto [ds, cn_p] : dist){
            // C(n, 2)
            cnt += (cn_p * (cn_p - 1)/2);
        }
    }

    cout << cnt << endl;
}

int main(){ _
    while(cin >> n and n != 0) solve();
    return 0;
} 
