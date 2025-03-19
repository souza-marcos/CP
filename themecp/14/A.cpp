#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    // cout << "______________________________________________\n";
    ll x; cin >> x;

    if(x == 1) {
        cout << 0 << endl;    
        return ;
    }


    auto par = [&](ll n){
        n /= 2;
        ll res = 4 * (1 + n)*n + 1;
        // cout << "N: " << n*2<< " " << res << endl;
        return (res > 0 and res >= x); 
    };

    auto impar = [&](ll n){
        ll res = (1 + n)*(n + 1);
        // cout << "N: " << n<< " " << res << endl;
        return (res > 0 and res >= x); 
    };

    auto binsearch = [&](){
        ll l = 0, r = 1e9;
        while(l + 1 < r){
            ll m = (l + r)/2;
            if(m&1){
                if(impar(m)) r=m;
                else l = m;
            }
            else{
                if(par(m)) r=m;
                else l = m;
            } 
        }
        return r;
    };
    ll res = binsearch();
    
    for(ll i = max(0ll,res - 4); i <= max(0ll,res + 4); i ++){
        if(i&1 and impar(i)){
            cout << i << endl; 
            return;
        }
        else if(i%2 == 0 and par(i)){
            cout << i << endl;
            return;
        }
    }

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
