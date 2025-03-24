// https://www.spoj.com/problems/TRICOUNT/en/
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

ll binexp(ll n, ll e){
    ll ans = 1;
    if(e < 0) return 0;
    while(e){
        if(e & 1) ans *= n;
        n *= n;
        e >>= 1;
    }
    return ans;
}

int main(){ _ 
    int t; cin >> t;
    while(t --){
        ll n; cin >> n;
        cout << binexp(4, n-2) + n * n << endl;
    }
}