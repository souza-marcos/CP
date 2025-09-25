#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n, k, a, b; cin >> n >> k >> a >> b;
    vector<int> arr(n);
    for(int& el : arr) cin >> el;
    
    map<int, int> freql, freqr;
    int res = 0;
    int l = 0, r = 0;
    
    int curkl = 0, curkr = 0;
    for(int i = 0; i < n; i ++){
        while(l < n and curkl < k){
            if(freql[arr[l]] == 0){
                curkl ++;
            }
            freql[arr[l]]++;
            l ++;
        }
        if(curkl < k && l == n) break;

        while(r < n and curkr <= k){
            if(freqr[arr[r]] == 0){
                curkr ++;
            }
            freqr[arr[r]]++;
            r ++;
        }
        
        int lb = max(l-1, a + i-1);
        int ub = min((curkr > k ? r - 2 : r - 1), min(b + i-1, n-1));
        
        // cout << i << " " << l << " " << r << "\n";
        // cout << i << " " << lb << " " << ub << "\n";
        
        res += max(0ll, ub - lb + 1);
        
        if(freql[arr[i]] == 1){
            curkl --;
        }
        if(freqr[arr[i]] == 1){
            curkr --;
        }
        freql[arr[i]] --, freqr[arr[i]] --;
    }
    cout << res << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
