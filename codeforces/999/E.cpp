#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll
void solve(){

    // Quero maximizar o tanto que tiro
    int n, m, k; cin >> n >> m >> k;
    priority_queue<pair<ll, pair<ll, ll>>> pq; // tanto que tiro - indice  // Insiro no heap o maior match
    vector<ll> arr(n), magic(m);
    for(ll& el : arr) cin >> el;
    for(ll& el : magic) cin >> el;

    ll sum = accumulate(arr.begin(), arr.end(), 0LL);

    for(ll el : arr){
        ll tiro = -1, select = -1;
        for(ll mg : magic){
            ll temp = el - (el & mg);
            if(temp > tiro){
                tiro = temp;
                select = mg;
            }
        }
        pq.push({tiro, {el, select}});
    }

    while(k --){
        auto [tiro, cur] = pq.top(); pq.pop();
        auto [el, select] = cur;
        sum -= tiro;
        // cout << tiro << " " << el << " " << select << " " << (el & select) << endl;

        el = el & select;

        tiro = -1, select = -1;
        for(ll mg : magic){
            ll temp = el - (el & mg);
            if(temp > tiro){
                tiro = temp;
                select = mg;
            }
        }
        pq.push({tiro, {el, select}});
    }
    cout << sum << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
