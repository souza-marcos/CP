#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

const int MAX = 1e6;

int main(){ _ 
    int n; cin >> n; 

    vector<int> div(MAX + 1), cnt(MAX+1);
    iota(div.begin(), div.end(), 0);
    for(ll i = 2; i <= MAX; i ++){
        if(div[i] == i)
        for(ll j = i*i; j <= MAX; j += i){
            div[j] = i;
        }
    }
    
    for(int i = 0; i < n; i ++) {
        int a; cin >> a;
        cnt[a] ++;
    }

    auto nC2 = [&](ll n) -> ll {
        if(n <= 0) return 0;
        return n * (n-1) / 2;
    };
    auto getdiv = [&](ll x) -> ll{
        set<ll> d;
        while(x > 1) {
            if(d.count(div[x])) return 0;
            d.insert(div[x]), x /= div[x];
        }
        return (sz(d)%2 ? 1 : -1);
    };

    ll res = nC2(n);

    for(int i = 2; i <= MAX; i += 1){
        ll sub = 0;
        for(int j = i; j <= MAX; j += i) {
            sub += cnt[j];
        }
        if(sub <= 1) continue;
        // cout << i << " " << sub << endl;
        res -= getdiv(i) * nC2(sub);
    }

    cout << res << endl;
    return 0;
} 
