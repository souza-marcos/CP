#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

void solve(){

    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int& el : arr) cin >> el;

    auto doOp = [&](){
        vector<int> freq(n + 1);
        for(int el : arr) freq[el] += 1;
        int mex = -1;
        for(int i = 0; i <= n; i ++) if(freq[i] == 0) {
            mex = i;
            break;
        }
        for(int& el : arr){
            if(freq[el] > 1 or el > mex) el = mex;
        }
    };

    ll res = 0;
    for(int i = 0; i < min(k, 5ll); i ++) doOp();
    if(k%2 == 0 and k > 5){
        doOp();
    }
    res = accumulate(arr.begin(), arr.end(), 0LL);
    cout << res << endl;
}


int32_t main(){ _
    int t; cin >> t;
    while(t --) solve();
} 
