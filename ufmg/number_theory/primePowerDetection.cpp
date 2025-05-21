#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

ll bin_exp(__int128_t el, __int128_t exp){
    __int128_t res = 1;
    while(exp){
        if(exp&1) res *= el;
        el *= el;
        exp >>= 1;
        if(el > LINF or res > LINF) return -1;
    }
    return (ll)res;
}

int groot(ll el, ll exp){
    int l = 0, r = 1e9;
    while(l + 1 < r){
        int m = (l + r)/2;
        ll val = bin_exp(m, exp);
        if(val == -1 or val > el) r=m;
        else l=m;
    }
    return l;
}

int main(){
    ll n; cin >> n;

    int limit_exponent = ceil(log2(n));
    for(int test = 2; test <= limit_exponent; test++){
        int nroot = groot(n, test); 
        if(bin_exp(nroot, test) == n){
            cout << nroot << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}