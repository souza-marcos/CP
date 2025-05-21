#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _ 
    
    int n, k; cin >> n >> k;
    vector<ll> arr(n); for(auto &el : arr) cin >> el;

    auto test = [&](ll chute) -> bool {
        ll tot = 0;
        for(auto el: arr) tot += min(el, chute);
        return (tot >= chute * k);
    };

    ll l = 0, r = 1;
    while(test(r)) r <<= 1;

    while(l + 1 < r){
        ll m = (l + r)/2;
        if(test(m)) l = m;
        else r = m;
    }
    cout << l << endl;

} 
