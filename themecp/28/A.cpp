#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    vector<ll> v(3); cin >> v[0] >> v[1] >> v[2];
    ll k; cin >> k;
    sort(v.begin(), v.end());
    ll maxres = 0;
    for(int i = 1; i <= v[0]; i ++){
        if(k%i!=0) continue;
        
        ll res = k/i;
        for(int j = 1; j <= v[1]; j ++){
            if(res%j != 0 or res/j > v[2]) continue;
            maxres = max(maxres,
                (v[0]-i + 1) * (v[1]-j + 1) * (v[2]-res/j + 1)
            );
        } 

    }
    cout << maxres << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
