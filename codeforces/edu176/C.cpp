#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n, m; cin >> n >> m;
    map<int, int> numbers;
    vector<int> arr(m); for(auto& el: arr) cin >> el, numbers[el] ++;
    vector<int> cnt(n + 1, 0);
    int j = 0, acc = m;
    vector<pair<int, int>> vec;
    for(auto [k, val] : numbers)
        vec.push_back({k, val});

    sort(vec.begin(), vec.end());

    for(int i = 0; i < sz(vec); i ++){
        while(j <= vec[i].first) cnt[j] = acc, j ++;
        acc -= vec[i].second;
    }

    // prefix sum
    vector<ll> pre(n+1, 0);
    for(int i = 1; i <= n; i ++){
        pre[i] = cnt[i] + pre[i-1];
    }

    ll res = 0;
    for(int i = 0; i < m; i ++){
        ll x = arr[i];
        res += (pre[n] - pre[max(0ll, n-x-1)]) - max(0ll, 2 * x - n + 1);
    }

    cout << res << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
