#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

void solve(){

    int n; cin >> n;
    vector<int> arr(n), freq(n + 1);
    for(int i = 0; i < n; i ++) cin >> arr[i], freq[arr[i]] ++;

    bool ok = true;
    for(int i = 1; i <= n; i ++){
        if(freq[i]%i != 0) ok = false;
    }

    if(ok == false){
        cout << -1 << endl;
        return;
    }

    int timer = 0;
    vector<int> cur(n+1);
    vector<int> res(n);
    for(int i = 0; i < n; i ++){
        if(freq[arr[i]]%arr[i] == 0){
            cur[arr[i]] = ++timer;
        }
        freq[arr[i]] --;
        res[i] = cur[arr[i]];
    }
    for(auto el : res) cout << el << " ";
    cout << endl;
}


int32_t main(){ _
    int t; cin >> t;
    while(t --) solve();
} 
