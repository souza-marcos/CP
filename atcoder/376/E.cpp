#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, k; cin >> n >> k;
    vector<pair<int, int>> arr(n); // B, A

    for(int i = 0; i < n; i ++){
        auto& [a, b] = arr[i]; cin >> a;
    }
    for(int i = 0; i < n; i ++){
        auto& [a, b] = arr[i]; cin >> b;
    }
    sort(arr.begin(), arr.end());
    
    multiset<int> mp;
    ll sumb = 0;
    for(int i = 0; i < k; i ++){
        auto [a, b] = arr[i];
        mp.insert(b);
        sumb += b;
    }
    ll res = arr[k-1].first * sumb;

    for(int i = k; i < n; i ++){
        auto [a, b] = arr[i];
        sumb -= (*mp.rbegin());
        mp.erase(mp.find(*mp.rbegin()));
        mp.insert(b);
        sumb += b;
        res = min(arr[i].first * sumb, res);
    }
    cout << res << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
