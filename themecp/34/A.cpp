#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    vector<int> cnt(n + 1);

    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        cnt[a] ++;
    }

    auto choose = [&](ll x, ll b) -> ll {
        if(x < b) return 0;
        if(b == 2) return x * (x-1) / 2;
        return x * (x - 1) * (x - 2) / 6;
    };

    ll res = 0, pref = 0;
    for(int i = 0; i <= n; i ++){
        res += choose(cnt[i], 3) + choose(cnt[i], 2) * pref;
        pref += cnt[i];
    }
    cout << res << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
