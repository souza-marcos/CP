// https://codeforces.com/contest/1475/problem/E
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
const int MOD = 1e9 + 7;

ll mul(ll a, ll b){ a %= MOD, b %= MOD; return (a * b) % MOD; }
ll add(ll a, ll b){ a += MOD, b += MOD; return (a + b) % MOD; }

ll binexp(ll a, ll e){
    ll ans = 1;
    while(e){
        if(e & 1) ans = mul(ans, a);
        a = mul(a, a);
        e >>= 1;
    }
    return ans;
}

ll inv(ll a){ return binexp(a, MOD - 2); }

const int MAX = 3e3;
ll fact[MAX], ifact[MAX]; 

ll choose(ll n, ll k){
    return (mul(mul(fact[n], ifact[n-k]), ifact[k]));
}

int main(){ _ 
    fact[0] = 1;
    for(int i = 1; i < MAX; i ++) fact[i] = mul(i, fact[i-1]);
    ifact[MAX-1] = inv(fact[MAX-1]);
    for(int i = MAX-2; i >= 0; i --) ifact[i] = mul(i+1, ifact[i+1]);

    int t; cin >> t;
    while(t --){
        int n, k; cin >> n >> k;
        vector<int> cnt(n+1, 0), appear;
        for(int i = 0; i < n; i ++){
            int a; cin >> a;
            if(cnt[a] == 0) appear.push_back(a);
            cnt[a] ++;
        }

        ll res = 0;
        sort(appear.rbegin(), appear.rend());
        for(int i = 0; i < sz(appear); i ++){
            
            if(cnt[appear[i]] >= k) {
                res = choose(cnt[appear[i]], k);
                break;
            }
            k -= cnt[appear[i]];
        }
        cout << res << endl;
    }


}