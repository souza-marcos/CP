#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    ll n; cin >> n;
    
    ll MAX = 1e6 + 100;
    vector<ll> primes;
    vector<bool> is_prime(MAX, true);
    // primes.push_back(1);
    for(ll i = 2; i < MAX; i ++){
        if(is_prime[i]){
            primes.push_back(1LL * i * i);
            for(ll j = i * i; j < MAX; j += i)
                is_prime[j] = false;
        }
    }

    ll ans = 0;
    for(int i = 0; i < sz(primes); i ++){
        for(int j = i + 1; j < sz(primes); j ++){
            ll val = primes[i] * primes[j];
            if(val > n or val < 0) break;
            ans ++;
        }
    }

    auto calc = [&](ll b) {
        return b * b * b * b;
    };

    for(auto el : primes){
        ll val = calc(el);
        if(val > n) break;
        ans++;
    }

    cout << ans << endl;

    return 0;
} 
