#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

ll choose[5001][5001];
int t, m; 

void solve(){
    
    int n; cin >> n;
    vector<int> arr(n);
    for(int& el : arr) cin >> el;
    int tot = accumulate(arr.begin(), arr.end(), 0ll);
    int res = 1;
    for(int i = 0; i < n; i ++){
        res = res * choose[tot][arr[i]] % m;
        tot -= arr[i];
    }
    
    cout << res << endl;
}


int32_t main(){ _ 
    cin >> t >> m;
    for(int i = 1; i <= 5000; i ++) choose[i][0] = 1;
    choose[1][1] = 1;
    for(int i = 2; i <= 5000; i ++){
        for(int j = 1; j <= i; j ++){
            // nCk = (n-1)C(k-1) + (n-1)Ck
            choose[i][j] = (choose[i-1][j-1] + choose[i-1][j]) % m;
        }
    }

    while(t --) solve();
    return 0;
}