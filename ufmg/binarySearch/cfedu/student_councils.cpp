#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()
ll k, n;
vector<ll> st;

bool valid(ll guess){
    ll spaces = guess * k; 
    for(auto el: st){
        spaces -= min(el, guess);
    }
    return (spaces <= 0);
}

int main(){ _
    cin >> k >> n;
    st.assign(n, 0);
    for(auto& el : st) cin >> el;
    sort(st.begin(), st.end(), greater<>());

    ll l = 0, r = 1LL;
    while(valid(r)) r *= 2;

    while(l + 1 < r){
        ll m = (l + r)/2;
        if(valid(m)) l = m;
        else r = m;
    }

    cout << l << endl;
    return 0;
} 
