#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    
    const int MAX = 5e5;
    vector<bool> ehprimo(MAX, true);
    vector<int> primos;
    
    for(ll i = 2; i < MAX; i ++){
        if(ehprimo[i]){
            primos.push_back(i);
            for(ll j = i * i; j < MAX; j += i) ehprimo[j] = false;
        }
    }
    

    vector<ll> ok;
    for(ll i = 0; i < sz(primos); i ++){
        ll cur = primos[i] * primos[i];
        ll power = cur;
        for(; cur <= 1e12; cur *= power){
            for(ll j = i + 1; j < sz(primos); j ++){
                ll powery = primos[j]*primos[j];
                ll cury = powery;
                for(;cury <= 1e12 and cury * cur <= 1e12; cury *= powery){
                    ok.push_back(cur * cury);
                }
            }

        }
    }

    sort(ok.begin(), ok.end());
    ok.erase(unique(ok.begin(), ok.end()), ok.end());

    int q; cin >> q;
    while(q --){
        ll a; cin >> a;
        auto it = lower_bound(ok.begin(), ok.end(), a);
        if(*it > a) --it;
        cout << *it << endl;
    }

    return 0;
} 
