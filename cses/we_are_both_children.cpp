// https://codeforces.com/contest/1850/problem/F
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

void solve(){
    int n; cin >> n;
    map<int, int> mp;
    int i = n;
    while(i --){
        int a; cin >> a;
        if(a > n) continue;
        mp[a] ++;
    }

    vector<int> arr(n + 10, 0);
    int maxv = 0;
    for(auto [k, val] : mp){
        for(int j = k; j <= n; j += k) arr[j] += val, maxv = max(maxv, arr[j]);
    }
    cout << maxv << endl;
}

int main(){ _ 
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
