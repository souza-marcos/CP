// https://atcoder.jp/contests/abc147/tasks/abc147_d?lang=en
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

const int MOD = 1e9 + 7;

ll mul(ll a, ll b){
    return ((a % MOD) * (b % MOD)) % MOD;
}

int main(){ _ 

    int n ; cin >> n;
    vector<ll> arr(n); for(auto& el: arr) cin >> el;

    ll res = 0;
    ll tp = 1;
    for(int i = 0; i < 60; i ++){
        ll one = 0, zero = 0, val = 0;
        for(int j = 0; j < n; j ++){
            if((arr[j] >> i) & 1ll){
                val += zero;
                one ++;
            } else val += one, zero ++;
        }
        res += mul(val, tp);
        if(res >= MOD) res -= MOD;
        tp = mul(tp, 2);
    }

    cout << res << endl;

}