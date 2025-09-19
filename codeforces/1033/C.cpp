#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
// #define int ll

void solve(){
    // Quero construir um caminho 
    //  n, n-1 ... 1
    // 

    ll n, m; cin >> n >> m;
    if(m < n or m > (n + 1)*n/2){
        cout << -1 << endl;
        return;
    }

    set<ll> s;
    for(int i = 1; i < n; i ++){
        s.insert(i);
    }

    vector<ll> choosen;

    m -= n;
    while(m > 0 and sz(s)){
        auto it = s.lower_bound(m);
        if(it == s.end() or *it > m) --it;
        choosen.push_back((*it));
        m -= *it;
        s.erase(*it);
    }

    choosen.push_back(0);
    for(ll el : s){
        choosen.push_back(el);
    }
    cout << choosen[0] + 1 << endl;
    for(int i = 0; i < n-1; i ++){
        cout << choosen[i] + 1 << " " << choosen[i+1] + 1 << endl;
    }
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
