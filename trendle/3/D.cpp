#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){

    int n, k; cin >> n >> k;

    vector<int> cnt(n + 1); // Color assigned

    vector<tuple<int, int, int>> edges(n-1);
    for(auto&[w,a,b] : edges){
        cin >> a >> b >> w;
    }
    sort(edges.rbegin(), edges.rend());

    ll res = 0;
    for(auto [w, a, b] : edges){
        if(cnt[a] >= k or cnt[b] >= k) continue;
        res += w;
        cnt[a] ++, cnt[b] ++;
    }
    cout << res << endl;
}

int main(){ _ 
    int t; cin >> t;
    while(t --) solve();
} 
