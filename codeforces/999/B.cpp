#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){

    int n; cin >> n;
    vector<ll> arr(n); 
    map<ll, int> cnt;
    multiset<ll> ms;
    for(ll& el : arr) cin >> el, ms.insert(el), cnt[el] ++;

    // big equal sides
    ll side = 0;
    for(auto [k, val] : cnt) {
        if(val == 1) continue;
        side = max(side, k);
    }

    if(side == 0){
        cout << -1 << endl;
        return;
    }
    ms.erase(ms.find(side));
    ms.erase(ms.find(side));
    auto fr = ms.begin();
    ms.erase(fr);
    auto sn = ms.begin();
    ms.erase(sn);


    while(sz(ms) and ((*fr) + 2*side <= (*sn))){
        fr = sn;
        sn = ms.begin();
        ms.erase(sn);
    }

    if((*fr) + 2*side > (*sn)){
        cout << side << " " <<  side << " " << (*fr) << " " << (*sn) << endl; 
    }else {
        cout << -1 << endl;
    }        
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
