// https://codeforces.com/problemset/problem/1798/D
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int &el : arr) cin >> el;
    sort(arr.begin(), arr.end());

    int l = 0, r = n-1;
    vector<int> res;
    ll cur = 0;
    while(l <= r){
        while(l <= r and cur >= 0){
            cur += arr[l];
            res.push_back(arr[l]);
            l ++;
        }
        while(l <= r and cur < 0){
            cur += arr[r];
            res.push_back(arr[r]);
            r --;
        }
    }
    
    {
        bool ok = true;
        for(int i = 0; i < n; i ++) if(arr[i] != 0) ok = false;
        if(ok) return void(cout << "No\n");
    }
    cout << "Yes\n";
    for(int el : res) cout << el << " ";
    cout << endl;

}


int32_t main(){ _ 
    int t; cin >> t;
    while(t --) solve();
} 
