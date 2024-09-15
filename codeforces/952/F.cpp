#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sx(x) (int)x.size()
#define endl "\n"

int h, n;
vector<pair<ll, ll>> arma;

bool possible(ll chute){ // tempo   
    ll total = 0;
    for(auto[dam, col]:arma){
        total += dam * ceil(chute/(double)(col));
        if(total >= h) return true;
    }
    return false;
}

void solve(){
    cin >> h >> n;
    arma.resize(n);
    for(int i = 0; i < n;i++){
        cin >> arma[i].first;
    }

    for(int i = 0; i < n;i++){
        cin >> arma[i].second;
    }

    ll l = 0, r = 1e13;
    while(l + 1 < r){
        ll m = (l + r)/2;

        if(possible(m)) r = m;
        else l = m;
    } 

    cout << r << endl;

    // cout << possible(15) << possible(16) << possible(17);
}

int main(){ _

    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
