#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

void solve(){

    int n; cin >> n;
    vector<int> a(n), b(n);
    vector<ll> pref(n+1);
    pref[0] = 0;
    int i = 0;
    for(int& el: a) cin >> el, pref[i+1] = pref[i] + el, i ++;
    for(int& el: b) cin >> el;

    // Queremos minimizar a soma dos elementos skippeds

    vector<vector<pair<int, ll>>> g(n); // u, w 
    for(int i = 1; i < n; i ++)
        g[i].push_back({i-1, 0});
    
    for(int i = 0; i < n; i ++)
        if(b[i]-1 > i) g[i].push_back({b[i]-1, a[i]});
    
    priority_queue<pair<ll, int>> pq;
    vector<ll> dist(n, LINF);
    
    pq.push({-0, 0});
    while(!pq.empty()){
        auto [d, v] = pq.top();
        d = -d; pq.pop();
        if(d >= dist[v]) continue;
        dist[v] = d;
        for(auto [u, w] : g[v]){
            w += d;
            if(dist[u] > w) pq.push({-w, u});
        }
    }

    // for(ll& el: dist) cout << el << " ";
    // cout << endl;

    ll maxv = 0;
    for(int i = 0; i < n; i ++){
        ll val = pref[i+1] - dist[i];
        maxv = max(maxv, val);
    }

    cout << maxv << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
    return 0;
} 
