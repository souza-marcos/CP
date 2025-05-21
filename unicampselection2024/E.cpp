#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

ll gcd(ll a, ll b, ll& x, ll& y){
    if(b == 0){
        x = 1, y = 0; return a;
    }   
    ll x1, y1;

    ll d = gcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll general_gcd(vector<ll>& cofs, vector<ll>& vars){
    int n = sz(cofs);
    ll g = cofs[0];
    vars.assign(n, 0); vars[0] = 1;

    for(int i = 1; i < n; i ++){
        ll x, y;
        g = gcd(g, cofs[i], x, y);
        for(int j = 0; j < i; j ++)
            vars[j] *= x;

        vars[i] = y;
    }
    return g;
}

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> arr(n); for(auto &el : arr) cin >> el;

    vector<ll> res;
    ll g = general_gcd(arr, res);
    if(k % g != 0) cout << "NO\n";
    else{
        cout << "YES\n";
        ll fact = k/g;
        for(int i = 0; i < n; i ++)
            cout << res[i] * fact << " \n"[i == n-1];
    }
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
} 
