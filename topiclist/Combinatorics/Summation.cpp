// https://www.spoj.com/problems/SUMMATION/
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _ 
    const int MOD = 100000007;
    ll tp[1001]; tp[0] = 1;
    for(int i = 0; i < 1000; i ++) tp[i + 1] = (tp[i] * 2)%MOD; 

    int t; cin >> t;
    for(int i = 1; i <= t; i ++){
        int n; cin >> n;
        ll sum = 0;
        vector<ll> arr(n); 
        for(auto&el:arr) cin >> el, sum = (sum + el)%MOD;
        cout << "Case " << i << ": ";
        cout << (sum * tp[n-1]) % MOD << endl;
    }
}