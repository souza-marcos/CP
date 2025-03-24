#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){

    int n, m; cin >> n >> m;
    vector<int> appear(n + m + 1, -1), count(n + m + 1, 0);
    vector<int> arr(n);
    for(int i = 0; i < n; i ++){
        cin >> arr[i];  
        appear[arr[i]] = 0;
    }
    for(int i = 0; i < m; i ++){
        int j, val; cin >> j >>val; j --;
        count[arr[j]] += (i + 1 - appear[arr[j]]); 
        appear[arr[j]] = -1;
        appear[val] = i + 1;
        arr[j] = val;
    }

    ll total = 1LL * m * (m + 1) / 2;
    ll res = 0;
    for(int i = 0; i <= n + m; i ++){
        if(appear[i] != -1){
            count[i] += m - appear[i] + 1;
        }
        ll x = m - count[i];
        ll dontAppear = x * (x + 1)/2;
        res += total - dontAppear;
    }

    cout << res << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
