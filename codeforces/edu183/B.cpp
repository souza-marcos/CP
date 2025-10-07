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
    string s; cin >> s;
    vector<int> cnt(3);
    for(int i = 0; i < k; i ++) cnt[s[i]-'0'] ++;
    string res(n, '+');
    int l = 0, r = n-1;
    bool ok = n == k;
    
    while(cnt[0]--) res[l++]='-';
    while(cnt[1]--) res[r--]='-';
    
    while(l <= r and cnt[2]--) res[l++] = res[r--]= (ok ? '-' : '?'); 
    cout << res << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 


// nope