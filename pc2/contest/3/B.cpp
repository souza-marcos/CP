#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
#define int ll

int32_t main(){  _
    
    int n, k, m; cin >> n >> k >> m;
    vector<int> arr(n);
    for(auto& el : arr) cin >> el;
    sort(arr.rbegin(), arr.rend()); 
    
    long double res = 0;
    ll sum = 0;
    for(int i = 0; i < n; i ++){
        sum += arr[i];
        int to_del = n - (i + 1);
        if(to_del > m) continue;
        int rem = m - to_del;

        long double agora = (min(max(0ll, rem), k * (i + 1)) + sum)/(long double)(i + 1); 
        res = max(res, agora);
    }


    cout << fixed << setprecision(50);
    cout << res << endl;
    return 0;
} 
// 00000000000000000000
// 00000000000000000000