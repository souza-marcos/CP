#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll k, n;
vector<ll> st_group;

bool valid(ll conc){
    ll spaces = conc * k;
    sort(st_group.begin(),st_group.end(), greater<>());
    for(auto el: st_group){
        spaces -= min(el, conc);
    }
    return spaces <= 0;
}

int main(){ _

    cin >> k >> n;
    st_group.resize(n);

    for(auto& el: st_group){
        cin >> el;
    } 
    ll l = 0, r = 1;
    while(valid(r)) r *= 2;
    // good     bad
    while(r > l + 1){
        ll m = (l + r)/2;
        if(valid(m)) l = m;
        else r = m;
    }

    cout << l << endl;
    return 0;
} 
