#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> suff(n + 1);
    suff[n] = 0;

    vector<int> posi;
    for(int i = n-1; i > 0; i--){
        suff[i]= suff[i + 1] + (s[i]=='1'? 1: -1);
        // cout << suff[i] << " "; 
        if(suff[i] > 0) posi.push_back(suff[i]);
    }
    // cout << endl;

    ll cur = 0; // 1 block
    sort(posi.rbegin(), posi.rend());

    int cnt = 1;
    for(int i=0; i < sz(posi); i ++){
        if(cur >= k) break; 
        cnt ++;
        cur += posi[i];
    }
    if(cur >= k) cout << cnt << endl;
    else cout << -1 << endl;
}

int main(){ // _
    int t; cin >> t;
    while( t--) solve();
    return 0;
} 
