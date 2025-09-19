#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    int n; cin >> n;
    map<int, int> cnt;
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        cnt[a] ++;
    }
    const int MOD = 1e9 + 7;
    ll res = 1;
    for(auto [k, val] : cnt){
        res = (res * (val + 1)) % MOD;
    }
    res --;
    cout << res << endl;
    return 0;       
}
