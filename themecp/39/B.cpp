// https://codeforces.com/contest/1762/problem/C
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
    int n; cin >> n;
    string s; cin >> s;
    const int MOD = 998244353;
    ll res = 1, cur = 1;
    for(int i = 1; i < n; i ++){
        if(s[i] == s[i-1]) {
            cur = cur * 2 % MOD;
        }
        else cur = 1;
        res += cur;
        res %= MOD; 
    }
    cout << res << endl;
}

int32_t main(){ _ 
    int t; cin >> t;
    while(t--) solve();
} 
