#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) (int)x.size()

int main(){ _
    unsigned long long n, k; cin >> n >> k;
    vector<ll> arr(k); for(auto &el: arr) cin >> el;

    unsigned long long res = 0;
    for(int i = 1; i < (1 << k); i ++){
        int get = (__builtin_popcount(i)&1 ? +1 : -1);
        __uint128_t val = 1;
        for(unsigned j = 0; j < k; j ++){
            if((i >> j) & 1) val *= arr[j];
            if(val > n) break;
        }
        res += get * (n/val);
        // cout << val << " => " << n/val << endl;
    }
    cout << res << endl;

    return 0;
} 
