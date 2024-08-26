#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

ll max_val(pair<int, int>a, pair<int, int>b, ll teto){
    // if(a.second > b.second) swap(a, b);

    ll val  = 0;
    for(int i = 0; i <= a.second; i ++){
        ll cost = i * a.first;
        if(cost > teto) break;
        ll qtd = min((ll)b.second, (teto - cost)/b.first) * b.first;
        val = max(qtd + cost, val);
    }

    return val;
}

void solve(){
    ll n, m; cin >> n >> m;
    map<int, int> flor;
    for(int i =0 ; i < n; i++){
        int val; cin >> val;
        flor[val] ++;
    }

    vector<pair<int, int>> v(sz(flor));
    int i = 0;
    for(auto [el, qtd]: flor) v[i ++] = {el, qtd};
    reverse(v.begin(), v.end());

    ll max_pet = min((ll)v[0].second, (m/ v[0].first) * v[0].first);
    for(int i = 0;i < sz(v)- 1; i++){
        auto [el, qtd] = v[i];
        auto [nextel, nextqtd] = v[i + 1];
        if(el > m) continue;

        ll val = min((ll)qtd, (m/el)) * el; // pets pegas
        if(el - nextel > 1) max_pet = max(max_pet, val); 
        else{
            max_pet = max(max_val(v[i], v[i + 1], m), max_pet);
            // max_pet = max(max_val(v[i + 1], v[i], m), max_pet);
        } 
    }
    cout << max_pet << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
