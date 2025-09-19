#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
// #define int ll

void solve(){
    int n; cin >> n;
    vector<int> arr(n); 
    for(int& el : arr) cin >> el;

    for(int i = 0; i < n-1; i ++){
        if(abs(arr[i]-arr[i+1]) <= 1){
            cout << 0 << endl;
            return;
        }
    }

    if(n == 2) {
        cout << -1 << endl;
        return;
    }
    int res = INF;
    for(int i = 0; i < n; i ++){
        int minv = INF, maxv = -INF;
        for(int j = i+1; j < n; j ++){
            minv = min(arr[j], minv);
            maxv = max(arr[j], maxv);
            if((minv <= arr[i]-1 and maxv >= arr[i]+1) or minv ==){
                res = min(res, j-i+1);
            }
        }
        minv = INF, maxv = -INF;
        for(int j = 0; j < i; j ++){
            minv = min(arr[j], minv);
            maxv = max(arr[j], maxv);
            if(minv <= arr[i]-1 and maxv >= arr[i]+1){
                res = min(res, i-j+1);
            }
        }
    }
    cout << res << endl;
    
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
