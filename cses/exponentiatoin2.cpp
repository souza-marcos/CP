// https://cses.fi/problemset/task/1712
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int MOD = 1e9 + 7;

ll fexp(ll el, int n){
    ll res = 1;
    while(n){
        if(n & 1) res *= el; 
        el *= el;
        if(res >= MOD) res %= MOD;
        if(el >= MOD) el %= MOD; 
        n >>= 1;
    }
    return res;
}

int main(){ _
    int n; cin >> n;
    while(n --){
        ll a, b, c; cin >> a >> b >> c;
        MOD --;
        ll exp = fexp(b, c);
        MOD ++;
        cout << fexp(a, exp) << endl;
    }
    return 0;
} 
