#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int n;
vector<int> v;

void solve(){
    cin >> n;
    v.resize(n);
    vector<ll> pref(n + 1);
    int i = 1;
    for(int& el: v) cin >> el, pref[i] = pref[i-1] + el, i ++;
    
    int ini, u;
    auto val = [&](int x){
        ll tot = pref[x + 1] - pref[ini];
        return (tot < u);
    };

    int q; cin>> q;
    while(q --){
        cin>> ini >> u;
        ini --;
        // if(u == 1){
        //     cout << ini + 1 << " ";
        //     return;
        // }

        int l = ini, r = n-1;
        while(l + 1 < r){
            int m = (l + r)/2;
            if(val(m)) l = m;
            else r = m;
        }
        ll tot1 = pref[l + 1] - pref[ini];
        ll val1 = (u + (u - tot1 + 1))*tot1/2;
    
        ll tot2 = pref[r + 1] - pref[ini];
        ll val2 = (u + (u - tot2 + 1))*tot2/2;

        if(val1 >= val2) cout << l + 1 << " ";
        else cout << r + 1 << " ";
    }
}

int main(){ //_
    int t; cin >> t;
    while(t --) solve(), cout << endl;
    return 0;
} 
