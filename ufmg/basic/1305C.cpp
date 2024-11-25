#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl "\n"

int main(){ _

    int n, m; cin >> n >> m;
    vector<ll> arr(n); for(ll& el : arr) cin >> el;

    if(n > m) cout << 0 << endl;
    else{

        ll res = 1;
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n; j ++){
                res *= abs(arr[i] - arr[j]);
                if(res >= m) res %= m;
            }
        }
        cout << res << endl;
    }

    return 0;
} 
