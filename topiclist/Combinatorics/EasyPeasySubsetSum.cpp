// https://toph.co/p/easy-peasy-subset-sum
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
const int MOD = 1e9 + 7;

ll add(ll a, ll b) { return (a + b + MOD) % MOD; };
ll mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; };

int main(){ _ 

    int n; cin >> n;
    vector<ll> arr(n); for(auto& el: arr) cin >> el;

    if(n == 1) return cout << 0 << endl, 0;

    ll tp[n + 1]; tp[0] = 1;
    for(int i = 0; i < n; i ++) tp[i + 1] = mul(tp[i], 2);

    sort(arr.begin(), arr.end());
    ll res = 0, val;
    for(int i = 0; i < n; i ++){
        val = mul(2ll*i - n + 1, arr[i]);
        res = add(res, val);
    }
    cout << mul(tp[n-2], res) << endl;
}