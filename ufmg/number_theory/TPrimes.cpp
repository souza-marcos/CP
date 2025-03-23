#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
    
    vector<ll> tprimos;
    vector<bool> eh_primo(1e6+10, true);
    eh_primo[0] = eh_primo[1] = false;
    for(ll i = 2; i <= 1e6; i ++){
        if(eh_primo[i]){
            tprimos.emplace_back(i*i);
            for(ll j = i*i; j <= 1e6; j += i){
                eh_primo[j] = false;
            }
        }
    }


    int n ; cin >> n;
    for(int i = 0; i < n; i ++){
        ll a; cin >> a;

        auto lb = lower_bound(tprimos.begin(), tprimos.end(), a);
        cout << (*lb == a ? "YES\n" : "NO\n");
    }

    

    return 0;
} 
