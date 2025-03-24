// https://codeforces.com/gym/348180/problem/D
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// Generating the divisors might be faster  

int main(){ _

    ll n; cin >> n;
    vector<ll> res;

    auto calc = [n](ll step_size, ll num_steps){
        return (1 + (n-step_size + 1)) * num_steps/2;
    };
    for(ll i = 1; i*i <= n; i ++){
        if(n % i == 0){
            res.push_back(calc(n/i, i));
            if(n/i != i) res.push_back(calc(i, n/i));
        }
    }
    sort(res.begin(), res.end());
    for(auto el : res) cout << el << " ";
    cout << endl;
    return 0;
}
