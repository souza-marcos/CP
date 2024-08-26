#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18

bool valid(vector<ll> &tank, ll x, ll h){
    
    for(auto el: tank){
        if(h < el) return true;
        x -= h - el;
        if(x < 0) return false;
    }
    return true;
    //Cuidado aqui
}

void solve(){   
    ll n, x; cin >> n >> x;
    vector<ll> tank(n);
    for(auto &el: tank) cin >> el;
    sort(tank.begin(), tank.end());
    
    // Busca binaria na resposta

    ll l = 0, r = LINF;
    while(l + 1 < r){
        ll m = (l + r)/2;
        if(valid(tank, x, m)) l = m;
        else r = m;
    }
    //cout << (valid(tank, x, l)?"true":"false") << endl;
    cout << l << endl;

}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
} 
