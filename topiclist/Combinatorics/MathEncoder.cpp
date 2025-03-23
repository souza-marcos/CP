// https://vjudge.net/problem/Baekjoon-23992
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

const int MOD = 1e9 + 7;

ll mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD;}
ll add(ll a, ll b) { a %= MOD, b %= MOD; return ((a + b + MOD + MOD) % MOD);}


int main(){ _ 
    int t; cin >> t;
    const int MAX = 10000 + 10;
    ll tp[MAX];
    tp[0] = 1;
    for(int i = 0; i < MAX-1; i ++) tp[i + 1] = mul(tp[i], 2), tp[i] = add(tp[i], -1);
    for(int tt = 1; tt <= t; tt ++){

        int n; cin >> n;
        
        ll res = 0, val;
        for(int i = 0; i < n; i ++){
            ll a; cin >> a;
            val = add(mul(a, tp[i]), mul(-a, tp[n-i-1])); 
            res = add(res, val);
        }
        cout << "Case #" << tt << ": " << res << endl;
    }
}