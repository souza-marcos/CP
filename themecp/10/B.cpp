#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

vector<ll> prec;

void solve(){
    ll w, b; cin >> w >> b;
    ll n = w + b;

    auto it = lower_bound(prec.begin(), prec.end(), n);

    if(*it > n) --it;
    cout << it - prec.begin() << endl;
}

int main(){ _
    
    prec.push_back(0);
    for(ll i = 1; i < 1e6; i ++){
        prec.push_back(prec.back() + i);
        if(prec.back() > 2e9) break;
    }
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
